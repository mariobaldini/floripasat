/*
 * HAL_obdh.h
 *
 *  Created on: 27 de abr de 2016
 *      Author: mario
 */

#ifndef HAL_OBDH_H_
#define HAL_OBDH_H_

#include <msp430.h>

#define LED_ON				1
#define LED_OFF				0

#define SYSLED_PIN          BIT4		// LED connected to P5.4 (p 32) - OBDH SYSTEM LED
#define SYSLED_PORT_DIR 	P5DIR
#define SYSLED_PORT_OUT    	P5OUT

#define PAYLOAD_ENABLE_PIN          BIT7		// Payload Enable Pin: P1.7 (p 41)
#define PAYLOAD_ENABLE_PORT_DIR		P1DIR
#define PAYLOAD_ENABLE_PORT_OUT		P1OUT

#define UART_DEBUG_RX		1
#define UART_DEBUG_TX		0


// TI Compiler pre-processor is overflowing in the multiplication of long delay times.
// eg. __delay_cycles(60 * DELAY_1_S_IN_CYCLES) is generating different results than __delay_cycles(DELAY_60_S_IN_CYCLES)
//
// Default Internal Clock: MCLK and SMCLK to 1.048576 MHz
// (Time elaps) = (# of cycles) / (frequency)
// 1 Cycle = 1.0 / 1.048576*10^6 seconds  @~1Mhz default clock


// @ 4Mhz internal ref, 1 cycle ~= 0.25 uS
// Delays below adjusted empiricaly based on tests/mesurements (to fix internal clock drift)
#define DELAY_100_uS_IN_CYCLES        385
#define DELAY_500_uS_IN_CYCLES       1985
#define DELAY_1_MS_IN_CYCLES	     3964
#define DELAY_5_MS_IN_CYCLES	    19883
#define DELAY_10_MS_IN_CYCLES	    39783
#define DELAY_50_MS_IN_CYCLES	   198900
#define DELAY_100_MS_IN_CYCLES	   397900
#define DELAY_150_MS_IN_CYCLES	   596850
#define DELAY_1_S_IN_CYCLES	      3979750
#define DELAY_5_S_IN_CYCLES	     20000000
#define DELAY_60_S_IN_CYCLES    960000000
#define DELAY_120_S_IN_CYCLES  1920000000


//TODO: watchdog max times are hardcoded in the main loop
//	  use global defines below, in the hal file.
//	  must reference the WD definitions, because WD delay
//	  have its own special unit and are not in cycles
//#define TIMESLOT_OBDH_MAX			WD_250_mSEC
//#define TIMESLOT_EPS_MAX			WD_250_mSEC
//#define TIMESLOT_IMU_MAX			WD_250_mSEC
//#define TIMESLOT_RADIO_MAX			WD_250_mSEC
//#define TIMESLOT_ENCODEFRAME_MAX	WD_250_mSEC
//#define TIMESLOT_UGHOST_MAX			WD_250_mSEC
//#define TIMESLOT_FLASH_MAX			WD_250_mSEC
//#define TIMESLOT_SLEEP_MAX			WD_250_mSEC


#define OBDH_DATA_LENGTH	 7	//  7 B of payload
#define EPS_DATA_LENGTH 	23	// 17 B of payload + 2 * 3 Bytes of SOF and EOF
#define IMU_DATA_LENGTH 	14	// 6 B to Acc + 6 B to Gyr
#define RADIO_DATA_LENGTH 	 4	// 2 B to counter + 2 B fo signal dB
#define UG_FRAME_LENGTH		41	// SOF(3) + Payload(35) + EOF(3)


/*
 * FLASH MEMORY ADRESSES
 */

#define BANK0  0
#define BANK1  1
#define BANK2  2
#define BANK3  3

//128 KB banks
#define BANK0_ADDR      0x008000
#define BANK1_ADDR      0x028000
#define BANK2_ADDR      0x048000
#define BANK3_ADDR      0x068000
//128 B info segments
#define SEGA_ADDR       0x001800
#define SEGB_ADDR       0x001880
#define SEGC_ADDR       0x001900
#define SEGD_ADDR       0x001980
//512 B bootstrap segments
#define BSL0_ADDR       0x001600
#define BSL1_ADDR       0x001400
#define BSL2_ADDR       0x001200
#define BSL3_ADDR       0x001000
#define MASS_ERASE      0XFFFFFF

//first boot start adress
#define BOOT_ADDR               BANK1_ADDR
//flash pointer save adress
#define FLASH_PTR_ADDR          SEGC_ADDR
//overflow flag message adress
#define OVERFLOW_FLAG_ADDR      0x026000
//last adress that can write a data(beyond this will enter the overflow)
#define LAST_WRITE_ADDR         0x087FFF

/********************************************/


/*
 * IMU MEASUREMENTS RANGES
 */

#define IMU_ACC_RANGE	16.0
#define IMU_GYR_RANGE	2.0

/********************************************/

#endif /* HAL_OBDH_H_ */
