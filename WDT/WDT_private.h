
#ifndef WDT_PRIVATE_H_
#define WDT_PRIVATE_H_

#define WDCTR                  *((volatile u8*)(0x41))

#define WDT_WDCTR_WDE          3
#define WDT_WDCTR_WDTOE        4

#endif /* WDT_PRIVATE_H_ */
