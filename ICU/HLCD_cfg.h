/*
 * HLCD_cfg.h
 *
 *  Created on: Mar 28, 2023
 *      Author: Mohamed
 */

#ifndef HLCD_CFG_H_
#define HLCD_CFG_H_

#define HLCD_DATA_PORT          DIO_PORTA
#define HLCD_CONTROL_PORT       DIO_PORTB

#define RS_PIN                  DIO_PIN2
#define RW_PIN                  DIO_PIN1
#define ENABLE_PIN              DIO_PIN0


/*this config is for MODE ofLCD*/
/*available options : 4-BIT, 8-BIT*/
#define MODE _8_BIT

#endif /* HLCD_CFG_H_ */
