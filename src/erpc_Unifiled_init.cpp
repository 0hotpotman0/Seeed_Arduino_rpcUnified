
/*
    The MIT License (MIT)
    Copyright (C) 2020  Seeed Technology Co.,Ltd.
*/


#include "erpc_arduino_uart_transport.h"
#include "erpc_basic_codec.h"
#include "erpc_arbitrated_client_manager.h"
#include "erpc_threading.h"
#include "erpc_simple_server.h"
#include "erpc_transport_arbitrator.h"
#include "erpc_port.h"
#include "rtl_ble/rtl_ble_unified.h"
#include "erpc_shim/erpc_shim_unified.h"

using namespace erpc;

class MyMessageBufferFactory : public MessageBufferFactory
{
public:
    virtual MessageBuffer create()
    {
        uint8_t *buf = new uint8_t[1024];
        return MessageBuffer(buf, 1024);
    }

    virtual void dispose(MessageBuffer *buf)
    {
        if (*buf)
        {
            delete[] buf->get();
        }
    }
};

// Uart ble_uart(&SERCOM_GPIO_SERIAL_X, PIN_GPIO_SERIAL_X_RX, PIN_GPIO_SERIAL_X_TX, PAD_GPIO_SERIAL_X_RX, PAD_GPIO_SERIAL_X_TX);
// INTERRUPT_HANDLER_IMPLEMENT_GPIO_SERIAL_X(ble_uart)

#define PIN_BLE_SERIAL_X_RX (84ul)
#define PIN_BLE_SERIAL_X_TX (85ul)
#define PAD_BLE_SERIAL_X_RX (SERCOM_RX_PAD_2)
#define PAD_BLE_SERIAL_X_TX (UART_TX_PAD_0)
#define SERCOM_BLE_SERIAL_X sercom0
#define INTERRUPT_HANDLER_IMPLEMENT_BLE_SERIAL_X(uart) \
 void SERCOM0_0_Handler() \
 { \
  (uart).IrqHandler(); \
 } \
 void SERCOM0_1_Handler() \
 { \
  (uart).IrqHandler(); \
 } \
 void SERCOM0_2_Handler() \
 { \
  (uart).IrqHandler(); \
 } \
 void SERCOM0_3_Handler() \
 { \
  (uart).IrqHandler(); \
 }

Uart ble_uart(&SERCOM_BLE_SERIAL_X, PIN_BLE_SERIAL_X_RX, PIN_BLE_SERIAL_X_TX, PAD_BLE_SERIAL_X_RX, PAD_BLE_SERIAL_X_TX);
extern "C"
{
INTERRUPT_HANDLER_IMPLEMENT_BLE_SERIAL_X(ble_uart)
}

UartTransport g_transport(&ble_uart, 115200);
MyMessageBufferFactory g_msgFactory;
BasicCodecFactory g_basicCodecFactory;
ArbitratedClientManager *g_client;
TransportArbitrator g_arbitrator;
SimpleServer g_server;
Crc16 g_crc16;

// setup and loop code block
extern void _real_body();

/**
 * @brief  Initialize erpc server task
 * @return void
 */
void add_services(erpc::SimpleServer *server)
{
    server->addService(static_cast<erpc::Service *>(create_rpc_ble_callback_service()));
}

void runClient(void *arg)
{
   _real_body();
}

void runServer(void *arg)
{
    Serial.println("start erpc server");
    /* run server */
    while (true)
    {
        g_server.poll();
        delay(20);
    }
}

Thread serverThread(&runServer, configMAX_PRIORITIES - 1, 4096, "runServer");
Thread clientThread(&runClient, configMAX_PRIORITIES - 2, 4096, "runClient");

void erpc_init()
{
    Serial.printf("erpc init\n\r");
    pinMode(RTL8720D_CHIP_PU, OUTPUT);
    digitalWrite(RTL8720D_CHIP_PU, LOW);
    delay(100);
    digitalWrite(RTL8720D_CHIP_PU, HIGH);
    delay(100);
    g_transport.init();
    g_arbitrator.setSharedTransport(&g_transport);
    g_arbitrator.setCodec(g_basicCodecFactory.create());

    g_client = new ArbitratedClientManager();
    g_client->setArbitrator(&g_arbitrator);
    g_client->setCodecFactory(&g_basicCodecFactory);
    g_client->setMessageBufferFactory(&g_msgFactory);

    g_arbitrator.setCrc16(&g_crc16);

    g_server.setTransport(&g_arbitrator);
    g_server.setCodecFactory(&g_basicCodecFactory);
    g_server.setMessageBufferFactory(&g_msgFactory);

    add_services(&g_server);

    serverThread.start();
    clientThread.start();

    g_client->setServer(&g_server);
    g_client->setServerThreadId(serverThread.getThreadId());
}

void _wrap_body()
{
    Serial.begin(115200);

    erpc_init();
    
    vTaskStartScheduler();

    while (1)
        ;

    return;
}
