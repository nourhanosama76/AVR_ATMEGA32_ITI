
#ifndef WDT_INTERFACE_H_
#define WDT_INTERFACE_H_

#define SLEEP_TIME_1SEC        6

/* this function shall enable wdt*/
void WDT_voidEnable(void);

/* this function shall disable wdt*/
void WDT_voidDisable(void);

/*this function shall run WDT with specific sleep time*/
void WDT_voidSetSleepTime(u8 Copy_u8SleepTime);

#endif /* WDT_INTERFACE_H_ */
