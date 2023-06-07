/*
 * HLCD_cfg.h
 *
 *  Created on: Mar 28, 2023
 *      Author: Mohamed
 */

#ifndef HLCD_CFG_H_
#define HLCD_CFG_H_

#define HLCD_DATA_PORT          DIO_PORTD
#define HLCD_CONTROL_PORT       DIO_PORTC

#define RS_PIN                  DIO_PIN7
#define RW_PIN                  DIO_PIN6
#define ENABLE_PIN              DIO_PIN5


/*this config is for MODE ofLCD*/
/*available options : 4-BIT, 8-BIT*/
#define MODE _8_BIT

#endif /* HLCD_CFG_H_ */
