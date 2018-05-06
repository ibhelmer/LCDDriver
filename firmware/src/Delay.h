/* 
 * File:   Delay.h
 * Author: IHN
 *
 * Created on 11. april 2018, 10:23
 */

#ifndef DELAY_H
#define	DELAY_H

#ifdef	__cplusplus
extern "C" {
#endif

#include <xc.h>
#include <stdint.h>
#define MY_SYS_CLK_FREQ 80000000

#define READ_CORE_TIMER()    _CP0_GET_COUNT()       // Read the MIPS Core Timer

void DelayMs(uint16_t  milliseconds)
{
    uint32_t time;
    time = READ_CORE_TIMER(); // Read Core Timer
    time += (MY_SYS_CLK_FREQ / 2 / 1000) * milliseconds; // calc the Stop Time
    while ((int32_t)(time - READ_CORE_TIMER()) > 0){};
}
void DelayUs(uint16_t microseconds)
{
uint32_t time;
    time = READ_CORE_TIMER(); // Read Core Timer
    time += (MY_SYS_CLK_FREQ / 2 / 1000000) * microseconds; // calc the Stop Time
    while ((int32_t)(time - READ_CORE_TIMER()) > 0){};
}
void DelayNs(uint16_t nanoseconds)
{
uint32_t time;
    time = READ_CORE_TIMER(); // Read Core Timer
    time += (MY_SYS_CLK_FREQ / 2 / 1000000000) * nanoseconds; // calc the Stop Time
    while ((int32_t)(time - READ_CORE_TIMER()) > 0){};
}

#ifdef	__cplusplus
}
#endif

#endif	/* DELAY_H */

