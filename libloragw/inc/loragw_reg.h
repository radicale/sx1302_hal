/*
 / _____)             _              | |
( (____  _____ ____ _| |_ _____  ____| |__
 \____ \| ___ |    (_   _) ___ |/ ___)  _ \
 _____) ) ____| | | || |_| ____( (___| | | |
(______/|_____)_|_|_| \__)_____)\____)_| |_|
  (C)2018 Semtech

Description:
    TODO

License: Revised BSD License, see LICENSE.TXT file include in the project
*/


#ifndef _LORAGW_REG_H
#define _LORAGW_REG_H

/* -------------------------------------------------------------------------- */
/* --- DEPENDANCIES --------------------------------------------------------- */

#include <stdint.h>     /* C99 types */
#include <stdbool.h>    /* bool type */

#include "config.h"     /* library configuration options (dynamically generated) */

/* -------------------------------------------------------------------------- */
/* --- INTERNAL SHARED TYPES ------------------------------------------------ */

struct lgw_reg_s {
    int8_t   page;        /*!< page containing the register (-1 for all pages) */
    uint16_t addr;        /*!< base address of the register (15 bit) */
    uint8_t  offs;        /*!< position of the register LSB (between 0 to 7) */
    bool     sign;        /*!< 1 indicates the register is signed (2 complem.) */
    uint8_t  leng;        /*!< number of bits in the register */
    bool     rdon;        /*!< 1 indicates a read-only register */
    int32_t  dflt;        /*!< register default value */
};

/* -------------------------------------------------------------------------- */
/* --- INTERNAL SHARED FUNCTIONS -------------------------------------------- */

int reg_w_align32(void *spi_target, uint8_t spi_mux_target, struct lgw_reg_s r, int32_t reg_value);
int reg_r_align32(void *spi_target, uint8_t spi_mux_target, struct lgw_reg_s r, int32_t *reg_value);

/* -------------------------------------------------------------------------- */
/* --- PUBLIC CONSTANTS ----------------------------------------------------- */

#define LGW_REG_SUCCESS  0
#define LGW_REG_ERROR    -1

#define SX1302_REG_COMMON_PAGE_PAGE 0
#define SX1302_REG_COMMON_CTRL0_CLK32_RIF_CTRL 1
#define SX1302_REG_COMMON_CTRL0_HOST_RADIO_CTRL 2
#define SX1302_REG_COMMON_CTRL0_RADIO_MISC_EN 3
#define SX1302_REG_COMMON_CTRL0_SX1261_MODE_RADIO_B 4
#define SX1302_REG_COMMON_CTRL0_SX1261_MODE_RADIO_A 5
#define SX1302_REG_COMMON_SPI_DIV_RATIO_SPI_HALF_PERIOD 6
#define SX1302_REG_COMMON_RADIO_SELECT_RADIO_SELECT 7
#define SX1302_REG_COMMON_GEN_GLOBAL_EN 8
#define SX1302_REG_COMMON_GEN_FSK_MODEM_ENABLE 9
#define SX1302_REG_COMMON_GEN_CONCENTRATOR_MODEM_ENABLE 10
#define SX1302_REG_COMMON_GEN_MBWSSF_MODEM_ENABLE 11
#define SX1302_REG_COMMON_VERSION_VERSION 12
#define SX1302_REG_AGC_MCU_CTRL_FORCE_HOST_FE_CTRL 13
#define SX1302_REG_AGC_MCU_CTRL_MCU_CLEAR 14
#define SX1302_REG_AGC_MCU_CTRL_HOST_PROG 15
#define SX1302_REG_AGC_MCU_MCU_AGC_STATUS_PARITY_ERROR 16
#define SX1302_REG_AGC_MCU_MCU_AGC_STATUS_MCU_AGC_STATUS 17
#define SX1302_REG_AGC_MCU_PA_GAIN_PA_B_GAIN 18
#define SX1302_REG_AGC_MCU_PA_GAIN_PA_A_GAIN 19
#define SX1302_REG_AGC_MCU_RF_EN_A_RADIO_RST 20
#define SX1302_REG_AGC_MCU_RF_EN_A_RADIO_EN 21
#define SX1302_REG_AGC_MCU_RF_EN_A_PA_EN 22
#define SX1302_REG_AGC_MCU_RF_EN_A_LNA_EN 23
#define SX1302_REG_AGC_MCU_RF_EN_B_RADIO_RST 24
#define SX1302_REG_AGC_MCU_RF_EN_B_RADIO_EN 25
#define SX1302_REG_AGC_MCU_RF_EN_B_PA_EN 26
#define SX1302_REG_AGC_MCU_RF_EN_B_LNA_EN 27
#define SX1302_REG_AGC_MCU_LUT_TABLE_A_PA_LUT 28
#define SX1302_REG_AGC_MCU_LUT_TABLE_A_LNA_LUT 29
#define SX1302_REG_AGC_MCU_LUT_TABLE_B_PA_LUT 30
#define SX1302_REG_AGC_MCU_LUT_TABLE_B_LNA_LUT 31
#define SX1302_REG_AGC_MCU_UART_CFG_MSBF 32
#define SX1302_REG_AGC_MCU_UART_CFG_PAR_EN 33
#define SX1302_REG_AGC_MCU_UART_CFG_PAR_MODE 34
#define SX1302_REG_AGC_MCU_UART_CFG_START_LEN 35
#define SX1302_REG_AGC_MCU_UART_CFG_STOP_LEN 36
#define SX1302_REG_AGC_MCU_UART_CFG_WORD_LEN 37
#define SX1302_REG_AGC_MCU_MCU_MAIL_BOX_WR_DATA_BYTE3_MCU_MAIL_BOX_WR_DATA 38
#define SX1302_REG_AGC_MCU_MCU_MAIL_BOX_WR_DATA_BYTE2_MCU_MAIL_BOX_WR_DATA 39
#define SX1302_REG_AGC_MCU_MCU_MAIL_BOX_WR_DATA_BYTE1_MCU_MAIL_BOX_WR_DATA 40
#define SX1302_REG_AGC_MCU_MCU_MAIL_BOX_WR_DATA_BYTE0_MCU_MAIL_BOX_WR_DATA 41
#define SX1302_REG_AGC_MCU_MCU_MAIL_BOX_RD_DATA_BYTE3_MCU_MAIL_BOX_RD_DATA 42
#define SX1302_REG_AGC_MCU_MCU_MAIL_BOX_RD_DATA_BYTE2_MCU_MAIL_BOX_RD_DATA 43
#define SX1302_REG_AGC_MCU_MCU_MAIL_BOX_RD_DATA_BYTE1_MCU_MAIL_BOX_RD_DATA 44
#define SX1302_REG_AGC_MCU_MCU_MAIL_BOX_RD_DATA_BYTE0_MCU_MAIL_BOX_RD_DATA 45
#define SX1302_REG_CLK_CTRL_CLK_SEL_CLKDIV_EN 46
#define SX1302_REG_CLK_CTRL_CLK_SEL_CLK_RADIO_B_SEL 47
#define SX1302_REG_CLK_CTRL_CLK_SEL_CLK_RADIO_A_SEL 48
#define SX1302_REG_CLK_CTRL_DUMMY_DUMMY 49
#define SX1302_REG_TX_TOP_A_TX_TRIG_TX_TRIG_GPS 50
#define SX1302_REG_TX_TOP_A_TX_TRIG_TX_TRIG_DELAYED 51
#define SX1302_REG_TX_TOP_A_TX_TRIG_TX_TRIG_IMMEDIATE 52
#define SX1302_REG_TX_TOP_A_TIMER_TRIG_BYTE3_TIMER_DELAYED_TRIG 53
#define SX1302_REG_TX_TOP_A_TIMER_TRIG_BYTE2_TIMER_DELAYED_TRIG 54
#define SX1302_REG_TX_TOP_A_TIMER_TRIG_BYTE1_TIMER_DELAYED_TRIG 55
#define SX1302_REG_TX_TOP_A_TIMER_TRIG_BYTE0_TIMER_DELAYED_TRIG 56
#define SX1302_REG_TX_TOP_A_TX_START_DELAY_MSB_TX_START_DELAY 57
#define SX1302_REG_TX_TOP_A_TX_START_DELAY_LSB_TX_START_DELAY 58
#define SX1302_REG_TX_TOP_A_TX_CTRL_WRITE_BUFFER 59
#define SX1302_REG_TX_TOP_A_TX_RAMP_DURATION_TX_RAMP_DURATION 60
#define SX1302_REG_TX_TOP_A_GEN_CFG_0_TX_RADIO_SEL 61
#define SX1302_REG_TX_TOP_A_GEN_CFG_0_MODULATION_TYPE 62
#define SX1302_REG_TX_TOP_A_GEN_CFG_0_TX_POWER 63
#define SX1302_REG_TX_TOP_A_TX_RFFE_IF_CTRL_PLL_DIV_CTRL 64
#define SX1302_REG_TX_TOP_A_TX_RFFE_IF_CTRL_TX_CLK_EDGE 65
#define SX1302_REG_TX_TOP_A_TX_RFFE_IF_CTRL_TX_MODE 66
#define SX1302_REG_TX_TOP_A_TX_RFFE_IF_CTRL_TX_IF_DST 67
#define SX1302_REG_TX_TOP_A_TX_RFFE_IF_CTRL_TX_IF_SRC 68
#define SX1302_REG_TX_TOP_A_TX_RFFE_IF_IQ_GAIN_IQ_GAIN 69
#define SX1302_REG_TX_TOP_A_TX_RFFE_IF_IQ_OFFSET_IQ_OFFSET 70
#define SX1302_REG_TX_TOP_A_TX_RFFE_IF_FREQ_RF_H_FREQ_RF 71
#define SX1302_REG_TX_TOP_A_TX_RFFE_IF_FREQ_RF_M_FREQ_RF 72
#define SX1302_REG_TX_TOP_A_TX_RFFE_IF_FREQ_RF_L_FREQ_RF 73
#define SX1302_REG_TX_TOP_A_TX_RFFE_IF_FREQ_DEV_H_FREQ_DEV 74
#define SX1302_REG_TX_TOP_A_TX_RFFE_IF_FREQ_DEV_L_FREQ_DEV 75
#define SX1302_REG_TX_TOP_A_TX_RFFE_IF_TEST_MOD_FREQ 76
#define SX1302_REG_TX_TOP_A_PKT_LEN_PKT_LENGTH 77
#define SX1302_REG_TX_TOP_A_FSK_CFG_0_TX_MODE 78
#define SX1302_REG_TX_TOP_A_FSK_CFG_0_CRC_IBM 79
#define SX1302_REG_TX_TOP_A_FSK_CFG_0_DCFREE_ENC 80
#define SX1302_REG_TX_TOP_A_FSK_CFG_0_CRC_EN 81
#define SX1302_REG_TX_TOP_A_FSK_CFG_0_PKT_MODE 82
#define SX1302_REG_TX_TOP_A_PREAMBLE_SIZE_MSB_PREAMBLE_SIZE 83
#define SX1302_REG_TX_TOP_A_PREAMBLE_SIZE_LSB_PREAMBLE_SIZE 84
#define SX1302_REG_TX_TOP_A_BIT_RATE_MSB_BIT_RATE 85
#define SX1302_REG_TX_TOP_A_BIT_RATE_LSB_BIT_RATE 86
#define SX1302_REG_TX_TOP_A_FSK_BT_FSK_REF_PATTERN_SIZE 87
#define SX1302_REG_TX_TOP_A_FSK_BT_FSK_PREAMBLE_SEQ 88
#define SX1302_REG_TX_TOP_A_FSK_BT_FSK_REF_PATTERN_EN 89
#define SX1302_REG_TX_TOP_A_FSK_BT_FSK_GAUSSIAN_SELECT_BT 90
#define SX1302_REG_TX_TOP_A_FSK_BT_FSK_GAUSSIAN_EN 91
#define SX1302_REG_TX_TOP_A_FSK_REF_PATTERN_BYTE7_FSK_REF_PATTERN 92
#define SX1302_REG_TX_TOP_A_FSK_REF_PATTERN_BYTE6_FSK_REF_PATTERN 93
#define SX1302_REG_TX_TOP_A_FSK_REF_PATTERN_BYTE5_FSK_REF_PATTERN 94
#define SX1302_REG_TX_TOP_A_FSK_REF_PATTERN_BYTE4_FSK_REF_PATTERN 95
#define SX1302_REG_TX_TOP_A_FSK_REF_PATTERN_BYTE3_FSK_REF_PATTERN 96
#define SX1302_REG_TX_TOP_A_FSK_REF_PATTERN_BYTE2_FSK_REF_PATTERN 97
#define SX1302_REG_TX_TOP_A_FSK_REF_PATTERN_BYTE1_FSK_REF_PATTERN 98
#define SX1302_REG_TX_TOP_A_FSK_REF_PATTERN_BYTE0_FSK_REF_PATTERN 99
#define SX1302_REG_TX_TOP_A_TX_STATUS_TX_STATUS 100
#define SX1302_REG_TX_TOP_A_TXRX_CFG0_0_MODEM_BW 101
#define SX1302_REG_TX_TOP_A_TXRX_CFG0_0_MODEM_SF 102
#define SX1302_REG_TX_TOP_A_TXRX_CFG0_1_PPM_OFFSET_HDR_CTRL 103
#define SX1302_REG_TX_TOP_A_TXRX_CFG0_1_PPM_OFFSET 104
#define SX1302_REG_TX_TOP_A_TXRX_CFG0_1_POST_PREAMBLE_GAP_LONG 105
#define SX1302_REG_TX_TOP_A_TXRX_CFG0_1_CODING_RATE 106
#define SX1302_REG_TX_TOP_A_TXRX_CFG0_2_FINE_SYNCH_EN 107
#define SX1302_REG_TX_TOP_A_TXRX_CFG0_2_MODEM_EN 108
#define SX1302_REG_TX_TOP_A_TXRX_CFG0_2_CADRXTX 109
#define SX1302_REG_TX_TOP_A_TXRX_CFG0_2_IMPLICIT_HEADER 110
#define SX1302_REG_TX_TOP_A_TXRX_CFG0_2_CRC_EN 111
#define SX1302_REG_TX_TOP_A_TXRX_CFG0_3_PAYLOAD_LENGTH 112
#define SX1302_REG_TX_TOP_A_TXRX_CFG1_0_INT_STEP_ORIDE_EN 113
#define SX1302_REG_TX_TOP_A_TXRX_CFG1_0_INT_STEP_ORIDE 114
#define SX1302_REG_TX_TOP_A_TXRX_CFG1_1_MODEM_START 115
#define SX1302_REG_TX_TOP_A_TXRX_CFG1_1_HEADER_DIFF_MODE 116
#define SX1302_REG_TX_TOP_A_TXRX_CFG1_1_ZERO_PAD 117
#define SX1302_REG_TX_TOP_A_TXRX_CFG1_2_PREAMBLE_SYMB_NB 118
#define SX1302_REG_TX_TOP_A_TXRX_CFG1_3_PREAMBLE_SYMB_NB 119
#define SX1302_REG_TX_TOP_A_TXRX_CFG1_4_AUTO_ACK_INT_DELAY 120
#define SX1302_REG_TX_TOP_A_TXRX_CFG1_4_AUTO_ACK_RX 121
#define SX1302_REG_TX_TOP_A_TXRX_CFG1_4_AUTO_ACK_TX 122
#define SX1302_REG_TX_TOP_A_TX_CFG0_0_CHIRP_LOWPASS 123
#define SX1302_REG_TX_TOP_A_TX_CFG0_0_PPM_OFFSET_SIG 124
#define SX1302_REG_TX_TOP_A_TX_CFG0_0_CONTCHIRP 125
#define SX1302_REG_TX_TOP_A_TX_CFG0_0_CHIRP_INVERT 126
#define SX1302_REG_TX_TOP_A_TX_CFG0_0_CONTINUOUS 127
#define SX1302_REG_TX_TOP_A_TX_CFG0_1_POWER_RANGING 128
#define SX1302_REG_TX_TOP_A_TX_CFG1_0_FRAME_NB 129
#define SX1302_REG_TX_TOP_A_TX_CFG1_1_HOP_CTRL 130
#define SX1302_REG_TX_TOP_A_TX_CFG1_1_IFS 131
#define SX1302_REG_TX_TOP_A_FRAME_SYNCH_0_AUTO_SCALE 132
#define SX1302_REG_TX_TOP_A_FRAME_SYNCH_0_DROP_ON_SYNCH 133
#define SX1302_REG_TX_TOP_A_FRAME_SYNCH_0_GAIN 134
#define SX1302_REG_TX_TOP_A_FRAME_SYNCH_0_PEAK1_POS 135
#define SX1302_REG_TX_TOP_A_FRAME_SYNCH_1_FINETIME_ON_LAST 136
#define SX1302_REG_TX_TOP_A_FRAME_SYNCH_1_TIMEOUT_OPT 137
#define SX1302_REG_TX_TOP_A_FRAME_SYNCH_1_PEAK2_POS 138
#define SX1302_REG_TX_TOP_B_TX_TRIG_TX_TRIG_GPS 139
#define SX1302_REG_TX_TOP_B_TX_TRIG_TX_TRIG_DELAYED 140
#define SX1302_REG_TX_TOP_B_TX_TRIG_TX_TRIG_IMMEDIATE 141
#define SX1302_REG_TX_TOP_B_TIMER_TRIG_BYTE3_TIMER_DELAYED_TRIG 142
#define SX1302_REG_TX_TOP_B_TIMER_TRIG_BYTE2_TIMER_DELAYED_TRIG 143
#define SX1302_REG_TX_TOP_B_TIMER_TRIG_BYTE1_TIMER_DELAYED_TRIG 144
#define SX1302_REG_TX_TOP_B_TIMER_TRIG_BYTE0_TIMER_DELAYED_TRIG 145
#define SX1302_REG_TX_TOP_B_TX_START_DELAY_MSB_TX_START_DELAY 146
#define SX1302_REG_TX_TOP_B_TX_START_DELAY_LSB_TX_START_DELAY 147
#define SX1302_REG_TX_TOP_B_TX_CTRL_WRITE_BUFFER 148
#define SX1302_REG_TX_TOP_B_TX_RAMP_DURATION_TX_RAMP_DURATION 149
#define SX1302_REG_TX_TOP_B_GEN_CFG_0_TX_RADIO_SEL 150
#define SX1302_REG_TX_TOP_B_GEN_CFG_0_MODULATION_TYPE 151
#define SX1302_REG_TX_TOP_B_GEN_CFG_0_TX_POWER 152
#define SX1302_REG_TX_TOP_B_TX_RFFE_IF_CTRL_PLL_DIV_CTRL 153
#define SX1302_REG_TX_TOP_B_TX_RFFE_IF_CTRL_TX_CLK_EDGE 154
#define SX1302_REG_TX_TOP_B_TX_RFFE_IF_CTRL_TX_MODE 155
#define SX1302_REG_TX_TOP_B_TX_RFFE_IF_CTRL_TX_IF_DST 156
#define SX1302_REG_TX_TOP_B_TX_RFFE_IF_CTRL_TX_IF_SRC 157
#define SX1302_REG_TX_TOP_B_TX_RFFE_IF_IQ_GAIN_IQ_GAIN 158
#define SX1302_REG_TX_TOP_B_TX_RFFE_IF_IQ_OFFSET_IQ_OFFSET 159
#define SX1302_REG_TX_TOP_B_TX_RFFE_IF_FREQ_RF_H_FREQ_RF 160
#define SX1302_REG_TX_TOP_B_TX_RFFE_IF_FREQ_RF_M_FREQ_RF 161
#define SX1302_REG_TX_TOP_B_TX_RFFE_IF_FREQ_RF_L_FREQ_RF 162
#define SX1302_REG_TX_TOP_B_TX_RFFE_IF_FREQ_DEV_H_FREQ_DEV 163
#define SX1302_REG_TX_TOP_B_TX_RFFE_IF_FREQ_DEV_L_FREQ_DEV 164
#define SX1302_REG_TX_TOP_B_TX_RFFE_IF_TEST_MOD_FREQ 165
#define SX1302_REG_TX_TOP_B_PKT_LEN_PKT_LENGTH 166
#define SX1302_REG_TX_TOP_B_FSK_CFG_0_TX_MODE 167
#define SX1302_REG_TX_TOP_B_FSK_CFG_0_CRC_IBM 168
#define SX1302_REG_TX_TOP_B_FSK_CFG_0_DCFREE_ENC 169
#define SX1302_REG_TX_TOP_B_FSK_CFG_0_CRC_EN 170
#define SX1302_REG_TX_TOP_B_FSK_CFG_0_PKT_MODE 171
#define SX1302_REG_TX_TOP_B_PREAMBLE_SIZE_MSB_PREAMBLE_SIZE 172
#define SX1302_REG_TX_TOP_B_PREAMBLE_SIZE_LSB_PREAMBLE_SIZE 173
#define SX1302_REG_TX_TOP_B_BIT_RATE_MSB_BIT_RATE 174
#define SX1302_REG_TX_TOP_B_BIT_RATE_LSB_BIT_RATE 175
#define SX1302_REG_TX_TOP_B_FSK_BT_FSK_REF_PATTERN_SIZE 176
#define SX1302_REG_TX_TOP_B_FSK_BT_FSK_PREAMBLE_SEQ 177
#define SX1302_REG_TX_TOP_B_FSK_BT_FSK_REF_PATTERN_EN 178
#define SX1302_REG_TX_TOP_B_FSK_BT_FSK_GAUSSIAN_SELECT_BT 179
#define SX1302_REG_TX_TOP_B_FSK_BT_FSK_GAUSSIAN_EN 180
#define SX1302_REG_TX_TOP_B_FSK_REF_PATTERN_BYTE7_FSK_REF_PATTERN 181
#define SX1302_REG_TX_TOP_B_FSK_REF_PATTERN_BYTE6_FSK_REF_PATTERN 182
#define SX1302_REG_TX_TOP_B_FSK_REF_PATTERN_BYTE5_FSK_REF_PATTERN 183
#define SX1302_REG_TX_TOP_B_FSK_REF_PATTERN_BYTE4_FSK_REF_PATTERN 184
#define SX1302_REG_TX_TOP_B_FSK_REF_PATTERN_BYTE3_FSK_REF_PATTERN 185
#define SX1302_REG_TX_TOP_B_FSK_REF_PATTERN_BYTE2_FSK_REF_PATTERN 186
#define SX1302_REG_TX_TOP_B_FSK_REF_PATTERN_BYTE1_FSK_REF_PATTERN 187
#define SX1302_REG_TX_TOP_B_FSK_REF_PATTERN_BYTE0_FSK_REF_PATTERN 188
#define SX1302_REG_TX_TOP_B_TX_STATUS_TX_STATUS 189
#define SX1302_REG_TX_TOP_B_TXRX_CFG0_0_MODEM_BW 190
#define SX1302_REG_TX_TOP_B_TXRX_CFG0_0_MODEM_SF 191
#define SX1302_REG_TX_TOP_B_TXRX_CFG0_1_PPM_OFFSET_HDR_CTRL 192
#define SX1302_REG_TX_TOP_B_TXRX_CFG0_1_PPM_OFFSET 193
#define SX1302_REG_TX_TOP_B_TXRX_CFG0_1_POST_PREAMBLE_GAP_LONG 194
#define SX1302_REG_TX_TOP_B_TXRX_CFG0_1_CODING_RATE 195
#define SX1302_REG_TX_TOP_B_TXRX_CFG0_2_FINE_SYNCH_EN 196
#define SX1302_REG_TX_TOP_B_TXRX_CFG0_2_MODEM_EN 197
#define SX1302_REG_TX_TOP_B_TXRX_CFG0_2_CADRXTX 198
#define SX1302_REG_TX_TOP_B_TXRX_CFG0_2_IMPLICIT_HEADER 199
#define SX1302_REG_TX_TOP_B_TXRX_CFG0_2_CRC_EN 200
#define SX1302_REG_TX_TOP_B_TXRX_CFG0_3_PAYLOAD_LENGTH 201
#define SX1302_REG_TX_TOP_B_TXRX_CFG1_0_INT_STEP_ORIDE_EN 202
#define SX1302_REG_TX_TOP_B_TXRX_CFG1_0_INT_STEP_ORIDE 203
#define SX1302_REG_TX_TOP_B_TXRX_CFG1_1_MODEM_START 204
#define SX1302_REG_TX_TOP_B_TXRX_CFG1_1_HEADER_DIFF_MODE 205
#define SX1302_REG_TX_TOP_B_TXRX_CFG1_1_ZERO_PAD 206
#define SX1302_REG_TX_TOP_B_TXRX_CFG1_2_PREAMBLE_SYMB_NB 207
#define SX1302_REG_TX_TOP_B_TXRX_CFG1_3_PREAMBLE_SYMB_NB 208
#define SX1302_REG_TX_TOP_B_TXRX_CFG1_4_AUTO_ACK_INT_DELAY 209
#define SX1302_REG_TX_TOP_B_TXRX_CFG1_4_AUTO_ACK_RX 210
#define SX1302_REG_TX_TOP_B_TXRX_CFG1_4_AUTO_ACK_TX 211
#define SX1302_REG_TX_TOP_B_TX_CFG0_0_CHIRP_LOWPASS 212
#define SX1302_REG_TX_TOP_B_TX_CFG0_0_PPM_OFFSET_SIG 213
#define SX1302_REG_TX_TOP_B_TX_CFG0_0_CONTCHIRP 214
#define SX1302_REG_TX_TOP_B_TX_CFG0_0_CHIRP_INVERT 215
#define SX1302_REG_TX_TOP_B_TX_CFG0_0_CONTINUOUS 216
#define SX1302_REG_TX_TOP_B_TX_CFG0_1_POWER_RANGING 217
#define SX1302_REG_TX_TOP_B_TX_CFG1_0_FRAME_NB 218
#define SX1302_REG_TX_TOP_B_TX_CFG1_1_HOP_CTRL 219
#define SX1302_REG_TX_TOP_B_TX_CFG1_1_IFS 220
#define SX1302_REG_TX_TOP_B_FRAME_SYNCH_0_AUTO_SCALE 221
#define SX1302_REG_TX_TOP_B_FRAME_SYNCH_0_DROP_ON_SYNCH 222
#define SX1302_REG_TX_TOP_B_FRAME_SYNCH_0_GAIN 223
#define SX1302_REG_TX_TOP_B_FRAME_SYNCH_0_PEAK1_POS 224
#define SX1302_REG_TX_TOP_B_FRAME_SYNCH_1_FINETIME_ON_LAST 225
#define SX1302_REG_TX_TOP_B_FRAME_SYNCH_1_TIMEOUT_OPT 226
#define SX1302_REG_TX_TOP_B_FRAME_SYNCH_1_PEAK2_POS 227

#define LGW_TOTALREGS 228


/* -------------------------------------------------------------------------- */
/* --- PUBLIC FUNCTIONS PROTOTYPES ------------------------------------------ */

/**
@brief Connect LoRa concentrator by opening SPI link
@return status of register operation (LGW_REG_SUCCESS/LGW_REG_ERROR)
*/
int lgw_connect(void);

/**
@brief Disconnect LoRa concentrator by closing SPI link
@return status of register operation (LGW_REG_SUCCESS/LGW_REG_ERROR)
*/
int lgw_disconnect(void);

/**
@brief LoRa concentrator register write
@param register_id register number in the data structure describing registers
@param reg_value signed value to write to the register (for u32, use cast)
@return status of register operation (LGW_REG_SUCCESS/LGW_REG_ERROR)
*/
int lgw_reg_w(uint16_t register_id, int32_t reg_value);

/**
@brief LoRa concentrator register read
@param register_id register number in the data structure describing registers
@param reg_value pointer to a variable where to write register read value
@return status of register operation (LGW_REG_SUCCESS/LGW_REG_ERROR)
*/
int lgw_reg_r(uint16_t register_id, int32_t *reg_value);

/**
@brief LoRa concentrator register burst write
@param register_id register number in the data structure describing registers
@param data pointer to byte array that will be sent to the LoRa concentrator
@param size size of the transfer, in byte(s)
@return status of register operation (LGW_REG_SUCCESS/LGW_REG_ERROR)
*/
int lgw_reg_wb(uint16_t register_id, uint8_t *data, uint16_t size);

/**
@brief LoRa concentrator register burst read
@param register_id register number in the data structure describing registers
@param data pointer to byte array that will be written from the LoRa concentrator
@param size size of the transfer, in byte(s)
@return status of register operation (LGW_REG_SUCCESS/LGW_REG_ERROR)
*/
int lgw_reg_rb(uint16_t register_id, uint8_t *data, uint16_t size);


#endif

/* --- EOF ------------------------------------------------------------------ */
