/*
 * Generated by erpcgen 1.7.4 on Wed Aug 12 16:43:22 2020.
 *
 * AUTOGENERATED - DO NOT EDIT
 */


#if !defined(_rpc_ble_api_h_)
#define _rpc_ble_api_h_

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include "erpc_version.h"

#if 10704 != ERPC_VERSION_NUMBER
#error "The generated shim code version is different to the rest of eRPC code."
#endif

#if !defined(ERPC_TYPE_DEFINITIONS)
#define ERPC_TYPE_DEFINITIONS

// Enumerators data types declarations
/** @brief GAP Cause List */
typedef enum RPC_T_GAP_CAUSE
{
    RPC_GAP_CAUSE_SUCCESS = 0,//!< Operation success.
    RPC_GAP_CAUSE_ALREADY_IN_REQ = 1,//!< Operation already in progress.
    RPC_GAP_CAUSE_INVALID_STATE = 2,//!< Invalid state.
    RPC_GAP_CAUSE_INVALID_PARAM = 3,//!< Invalid parameter.
    RPC_GAP_CAUSE_NON_CONN = 4,//!< No connection establishment.
    RPC_GAP_CAUSE_NOT_FIND_IRK = 5,//!< IRK not found.
    RPC_GAP_CAUSE_ERROR_CREDITS = 6,//!< Credits error.
    RPC_GAP_CAUSE_SEND_REQ_FAILED = 7,//!< Send Request failed.
    RPC_GAP_CAUSE_NO_RESOURCE = 8,//!< No resource.
    RPC_GAP_CAUSE_INVALID_PDU_SIZE = 9,//!< Invalid PDU size.
    RPC_GAP_CAUSE_NOT_FIND = 10,//!< Not Found.
    RPC_GAP_CAUSE_CONN_LIMIT = 11,//!< Connection reachs limited count.
    RPC_GAP_CAUSE_NO_BOND = 12,//!< No Bond.
    RPC_GAP_CAUSE_ERROR_UNKNOWN = 255//!< Unknown error.
} RPC_T_GAP_CAUSE;

/** @brief LE advertising parameter types */
typedef enum RPC_T_LE_ADV_PARAM_TYPE
{
    RPC_GAP_PARAM_ADV_LOCAL_ADDR_TYPE = 608, //!< Advertisement used local bluetooth device address type. Read/Write Size is uint8.
    RPC_GAP_PARAM_ADV_DATA = 609, //!< Advertisement Data. Read/Write. Max size is uint8[GAP_MAX_ADV_LEN]. Default is "02:01:05", which means that it is a Limited Discoverable Advertisement.
    RPC_GAP_PARAM_SCAN_RSP_DATA = 610, //!< Scan Response Data. Read/Write. Max size is uint8[GAP_MAX_ADV_LEN]. Defaults to all 0.
    RPC_GAP_PARAM_ADV_EVENT_TYPE = 611, //!< Advertisement Type. Read/Write. Size is uint8.  Default is GAP_ADTYPE_ADV_IND (@ref T_GAP_ADTYPE).
    RPC_GAP_PARAM_ADV_DIRECT_ADDR_TYPE = 612, //!< Direct Advertisement Address Type. Read/Write. Size is uint8.
    RPC_GAP_PARAM_ADV_DIRECT_ADDR = 613, //!< Direct Advertisement Address. Read/Write. Size is uint8[GAP_BD_ADDR_LEN]. Default is NULL.
    RPC_GAP_PARAM_ADV_CHANNEL_MAP = 614, //!< Which channels to advertise on. Read/Write Size is uint8. Default is GAP_ADVCHAN_ALL (@ref ADV_CHANNEL_MAP)
    RPC_GAP_PARAM_ADV_FILTER_POLICY = 615, //!< Filter Policy. Ignored when directed advertising is used. Read/Write. Size is uint8. Default is GAP_ADV_FILTER_ANY (@ref T_GAP_ADV_FILTER_POLICY).
    RPC_GAP_PARAM_ADV_INTERVAL_MIN = 616, //!< Minimum advertising interval for undirected and low duty cycle directed advertising. Value range: 0x0020 - 0x4000 (20ms - 10240ms 0.625ms/step),Read/Write Size is uint16_t.
    RPC_GAP_PARAM_ADV_INTERVAL_MAX = 617 //!< Maximum advertising interval for undirected and low duty cycle directed  advertising. Value range: 0x0020 - 0x4000 (20ms - 10240ms 0.625ms/step)),Read/Write Size is uint16_t.
} RPC_T_LE_ADV_PARAM_TYPE;

/** @brief  GAP LE Parameter Types List.*/
typedef enum RPC_T_GAP_LE_PARAM_TYPE
{
    RPC_GAP_PARAM_DEV_STATE = 544, //!< Device's current GAP device state. Read/Write. Size is sizeof(TGapDevState).
    RPC_GAP_PARAM_APPEARANCE = 545, //!< Local Device's Appearance. Read/Write. size is uint16. Appearance value please refer to GAP Appearance Values.(@ref GAP_LE_APPEARANCE_VALUES)
    RPC_GAP_PARAM_DEVICE_NAME = 546, //!< Local Device's Name. Write Only. Name string length is GAP_DEVICE_NAME_LEN.
    RPC_GAP_PARAM_SLAVE_INIT_GATT_MTU_REQ = 547, //!< Slave initiate the GATT exchange MTU procedure. Write Only.
    RPC_GAP_PARAM_RANDOM_ADDR = 548, //!< Random address. Write Only.
    RPC_GAP_PARAM_LATEST_CONN_BD_ADDR = 550, //!< Latest connected bluetooth devive address. Read Only.
    RPC_GAP_PARAM_LATEST_CONN_BD_ADDR_TYPE = 551, //!< Latest connected bluetooth devive address type. Read Only.
    RPC_GAP_PARAM_HANDLE_CREATE_CONN_IND = 552, //!< App handle the create connection indication message.
    RPC_GAP_PARAM_DEFAULT_PHYS_PREFER = 553, //!< Preferred values for the transmitter PHY and receiver PHY to be used for all subsequent connections over the LE transport.
    RPC_GAP_PARAM_DEFAULT_TX_PHYS_PREFER = 554, //!< The transmitter PHYs that the Host prefers the Controller to use.
    RPC_GAP_PARAM_DEFAULT_RX_PHYS_PREFER = 555, //!< The receiver PHYs that the Host prefers the Controller to use.
    RPC_GAP_PARAM_DEFAULT_DATA_LEN_MAX_TX_OCTETS = 558,
    RPC_GAP_PARAM_DEFAULT_DATA_LEN_MAX_TX_TIME = 559,
    RPC_GAP_PARAM_LOCAL_FEATURES = 560, //!< Local supported features.
    RPC_GAP_PARAM_DS_POOL_ID = 561, //!< Downstream PoolID.  Read only.  size is uint16.
    RPC_GAP_PARAM_DS_DATA_OFFSET = 562, //!< Downstream pool buffer data offset.  Read only.  size is uint16.
    RPC_GAP_PARAM_LE_REMAIN_CREDITS = 563, //!< Remain credits avaiable for TX.  Read only.  size is uint16.
    RPC_GAP_PARAM_MAX_WL_SIZE = 564 //!< Max white list size.  Read only.  size is uint16.
} RPC_T_GAP_LE_PARAM_TYPE;

/** @brief LE scan parameter type */
typedef enum RPC_T_LE_SCAN_PARAM_TYPE
{
    RPC_GAP_PARAM_SCAN_LOCAL_ADDR_TYPE = 576,  //!< The type of address being used in the scan request packets. Read/Write.
    RPC_GAP_PARAM_SCAN_MODE = 577,  //!< Scan mode. Read/Write. Size is uint8. Default is GAP_SCAN_MODE_ACTIVE (@ref T_GAP_SCAN_MODE).
    RPC_GAP_PARAM_SCAN_INTERVAL = 578,  //!< Scan Interval. Read/Write. Size is uint16_t. Default is 0x10. Value range: 0x0004 - 0x4000 (2.5ms - 10240ms 0.625ms/step).
    RPC_GAP_PARAM_SCAN_WINDOW = 579,  //!< Scan Window. Read/Write. Size is uint16_t. Default is 0x10. Value range: 0x0004 - 0x4000 (2.5ms - 10240ms 0.625ms/step).
    RPC_GAP_PARAM_SCAN_FILTER_POLICY = 580,  //!< Scan Filter Policy.Read/Write. Size is uint8_t. Default is GAP_SCAN_FILTER_ANY (@ref T_GAP_SCAN_FILTER_POLICY).
    RPC_GAP_PARAM_SCAN_FILTER_DUPLICATES = 581   //!< Scan Filter Duplicates.Read/Write. Size is uint8_t. Default is GAP_SCAN_FILTER_DUPLICATE_DISABLE (@ref T_GAP_SCAN_FILTER_DUPLICATE).
} RPC_T_LE_SCAN_PARAM_TYPE;

/** @brief  Definition of LE white list operation.*/
typedef enum RPC_T_GAP_WHITE_LIST_OP
{
    RPC_GAP_WHITE_LIST_OP_CLEAR = 0,    /**<  Clear white list. */
    RPC_GAP_WHITE_LIST_OP_ADD = 1,          /**<  Add a device to the white list. */
    RPC_GAP_WHITE_LIST_OP_REMOVE = 2        /**<  Remove a device from the white list. */
} RPC_T_GAP_WHITE_LIST_OP;

/** @brief GAP Remote Address Type */
typedef enum RPC_T_GAP_REMOTE_ADDR_TYPE
{
    RPC_GAP_REMOTE_ADDR_LE_PUBLIC = 0, /**< LE Public device address type. */
    RPC_GAP_REMOTE_ADDR_LE_RANDOM = 1 /**< LE Random device address type. */
} RPC_T_GAP_REMOTE_ADDR_TYPE;

/** @brief Define random adress type */
typedef enum RPC_T_GAP_RAND_ADDR_TYPE
{
    RPC_GAP_RAND_ADDR_STATIC = 0,/**<  Static random device address. */
    RPC_GAP_RAND_ADDR_NON_RESOLVABLE = 1,/**<  Non resolvable random device address. */
    RPC_GAP_RAND_ADDR_RESOLVABLE = 2 /**<  Resolvable random device address. */
} RPC_T_GAP_RAND_ADDR_TYPE;

// Aliases data types declarations
typedef struct binary_t binary_t;

// Structures/unions data types declarations
struct binary_t
{
    uint8_t * data;
    uint32_t dataLength;
};


#endif // ERPC_TYPE_DEFINITIONS

/*! @brief host identifiers */
enum _host_ids
{
    khost_service_id = 1,
    khost__Ble_HostInitialize_id = 1,
};

/*! @brief rpc_gap_adv identifiers */
enum _rpc_gap_adv_ids
{
    krpc_gap_adv_service_id = 2,
    krpc_gap_adv_rpc_le_adv_set_param_id = 1,
    krpc_gap_adv_rpc_le_adv_get_param_id = 2,
    krpc_gap_adv_rpc_le_adv_start_id = 3,
    krpc_gap_adv_rpc_le_adv_stop_id = 4,
    krpc_gap_adv_rpc_le_adv_update_param_id = 5,
};

/*! @brief rpc_gap_le identifiers */
enum _rpc_gap_le_ids
{
    krpc_gap_le_service_id = 3,
    krpc_gap_le_rpc_le_gap_init_id = 1,
    krpc_gap_le_rpc_le_gap_msg_info_way_id = 2,
    krpc_gap_le_rpc_le_get_max_link_num_id = 3,
    krpc_gap_le_rpc_le_set_gap_param_id = 4,
    krpc_gap_le_rpc_le_get_param_id = 5,
    krpc_gap_le_rpc_modify_white_list_id = 6,
    krpc_gap_le_rpc_le_gen_rand_addr_id = 7,
    krpc_gap_le_rpc_le_set_rand_addr_id = 8,
};

/*! @brief rpc_gap_scan identifiers */
enum _rpc_gap_scan_ids
{
    krpc_gap_scan_service_id = 4,
    krpc_gap_scan_rpc_le_scan_set_param_id = 1,
    krpc_gap_scan_rpc_le_scan_get_param_id = 2,
    krpc_gap_scan_rpc_le_scan_start_id = 3,
    krpc_gap_scan_rpc_le_scan_stop_id = 4,
};

#if defined(__cplusplus)
extern "C" {
#endif

//! @name host
//@{
uint8_t _Ble_HostInitialize(void);
//@}

//! @name rpc_gap_adv
//@{
RPC_T_GAP_CAUSE rpc_le_adv_set_param(RPC_T_LE_ADV_PARAM_TYPE param, const binary_t * value);

RPC_T_GAP_CAUSE rpc_le_adv_get_param(RPC_T_LE_ADV_PARAM_TYPE param, binary_t * value);

RPC_T_GAP_CAUSE rpc_le_adv_start(void);

RPC_T_GAP_CAUSE rpc_le_adv_stop(void);

RPC_T_GAP_CAUSE rpc_le_adv_update_param(void);
//@}

//! @name rpc_gap_le
//@{
bool rpc_le_gap_init(uint8_t link_num);

void rpc_le_gap_msg_info_way(bool use_msg);

uint8_t rpc_le_get_max_link_num(void);

RPC_T_GAP_CAUSE rpc_le_set_gap_param(RPC_T_GAP_LE_PARAM_TYPE param, const binary_t * value);

RPC_T_GAP_CAUSE rpc_le_get_param(RPC_T_GAP_LE_PARAM_TYPE param, binary_t * value);

RPC_T_GAP_CAUSE rpc_modify_white_list(RPC_T_GAP_WHITE_LIST_OP operation, const binary_t * bd_addr, RPC_T_GAP_REMOTE_ADDR_TYPE bd_type);

RPC_T_GAP_CAUSE rpc_le_gen_rand_addr(RPC_T_GAP_RAND_ADDR_TYPE rand_addr_type, binary_t * random_bd);

RPC_T_GAP_CAUSE rpc_le_set_rand_addr(const binary_t * random_bd);
//@}

//! @name rpc_gap_scan
//@{
RPC_T_GAP_CAUSE rpc_le_scan_set_param(RPC_T_LE_SCAN_PARAM_TYPE param, const binary_t * value);

RPC_T_GAP_CAUSE rpc_le_scan_get_param(RPC_T_LE_SCAN_PARAM_TYPE param, binary_t * value);

RPC_T_GAP_CAUSE rpc_le_scan_start(void);

RPC_T_GAP_CAUSE rpc_le_scan_stop(void);
//@}

#if defined(__cplusplus)
}
#endif

#endif // _rpc_ble_api_h_