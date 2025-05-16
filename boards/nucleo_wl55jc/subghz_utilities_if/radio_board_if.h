#ifndef RADIO_BOARD_IF_H
#define RADIO_BOARD_IF_H

#ifdef __cplusplus
extern "C" {
#endif

#include <board_config.h>

#if defined(USE_BSP_DRIVER)

#define RBI_CONF_RFO_LP_HP  RADIO_CONF_RFO_LP_HP
#define RBI_CONF_RFO_LP     RADIO_CONF_RFO_LP
#define RBI_CONF_RFO_HP     RADIO_CONF_RFO_HP
#else

#define RBI_CONF_RFO_LP_HP  0
#define RBI_CONF_RFO_LP     1
#define RBI_CONF_RFO_HP     2

#endif 

#if defined(USE_BSP_DRIVER)

#else

/* Indicates the type of switch between the ones proposed by CONFIG Constants */
#define RBI_CONF_RFO                        RBI_CONF_RFO_HP

/* Indicates whether or not TCXO is supported by the board
 * 0: TCXO not supported
 * 1: TCXO supported
 */
#define IS_TCXO_SUPPORTED                   1U

/* Indicates whether or not DCDC is supported by the board
 * 0: DCDC not supported
 * 1: DCDC supported
 */
#define IS_DCDC_SUPPORTED                   0U

#endif

#if defined(USE_BSP_DRIVER)

#else
#warning user to provide its board definitions pins
#endif

#if defined(USE_BSP_DRIVER)
typedef enum
{
  RBI_SWITCH_OFF    = RADIO_SWITCH_OFF,
  RBI_SWITCH_RX     = RADIO_SWITCH_RX,
  RBI_SWITCH_RFO_LP = RADIO_SWITCH_RFO_LP,
  RBI_SWITCH_RFO_HP = RADIO_SWITCH_RFO_HP,
} RBI_Switch_TypeDef;

typedef enum
{
  RBI_RFO_LP_MAXPOWER = RADIO_RFO_LP_MAXPOWER,
  RBI_RFO_HP_MAXPOWER = RADIO_RFO_HP_MAXPOWER,
} RBI_RFOMaxPowerConfig_TypeDef;

#else

typedef enum
{
  RBI_SWITCH_OFF    = 0,
  RBI_SWITCH_RX     = 1,
  RBI_SWITCH_RFO_LP = 2,
  RBI_SWITCH_RFO_HP = 3,
} RBI_Switch_TypeDef;

typedef enum
{
  RBI_RFO_LP_MAXPOWER = 0,
  RBI_RFO_HP_MAXPOWER = 1,
} RBI_RFOMaxPowerConfig_TypeDef;

#endif

/**
  * @brief  Init Radio Switch
  * @return BSP status
  */
int32_t RBI_Init(void);

/**
  * @brief  DeInit Radio Switch
  * @return BSP status
  */
int32_t RBI_DeInit(void);

/**
  * @brief  Configure Radio Switch.
  * @param  Config: Specifies the Radio RF switch path to be set.
  *         This parameter can be one of following parameters:
  *           @arg RADIO_SWITCH_OFF
  *           @arg RADIO_SWITCH_RX
  *           @arg RADIO_SWITCH_RFO_LP
  *           @arg RADIO_SWITCH_RFO_HP
  * @return BSP status
  */
int32_t RBI_ConfigRFSwitch(RBI_Switch_TypeDef Config);

/**
  * @brief  Return Board Configuration
  * @retval RBI_CONF_RFO_LP_HP
  * @retval RBI_CONF_RFO_LP
  * @retval RBI_CONF_RFO_HP
  */
int32_t RBI_GetTxConfig(void);

/**
  * @brief  Get If TCXO is to be present on board
  * @note   never remove called by MW,
  * @retval return 1 if present, 0 if not present
  */
int32_t RBI_IsTCXO(void);

/**
  * @brief  Get If DCDC is to be present on board
  * @note   never remove called by MW,
  * @retval return 1 if present, 0 if not present
  */
int32_t RBI_IsDCDC(void);

/**
  * @brief  Return RF Output Max Power Configuration of matching circuit
  * @note   never remove called by MW,
  * @retval return Max Power configuration of matching circuit for Low Power or High Power mode in dBm
  */
int32_t RBI_GetRFOMaxPowerConfig(RBI_RFOMaxPowerConfig_TypeDef Config);

#ifdef __cplusplus
}
#endif

#endif
