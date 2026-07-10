#include "types.h"
#include "eeprom.h"
#include "rtc.h"
#include "logger.h"

#define EEPROM_PTR_ADDR        0x0010U
#define EEPROM_LOG_START_ADDR  0x0012U
#define EEPROM_MAX_ADDR        0x7FFFU
#define LOG_ENTRY_SIZE         7U

static u16 g_logPtr = EEPROM_LOG_START_ADDR;

void Logger_Init(void)
{
    u8 ptrH, ptrL;
    u16 ptr;

    if (EEPROM_ReadByte(EEPROM_PTR_ADDR, &ptrH) && EEPROM_ReadByte((u16)(EEPROM_PTR_ADDR + 1U), &ptrL))
    {
        ptr = (u16)((ptrH << 8U) | ptrL);
        if ((ptr >= EEPROM_LOG_START_ADDR) && (ptr <= (EEPROM_MAX_ADDR - LOG_ENTRY_SIZE)))
        {
            g_logPtr = ptr;
        }
        else
        {
            g_logPtr = EEPROM_LOG_START_ADDR;
            EEPROM_WriteByte(EEPROM_PTR_ADDR, (u8)(g_logPtr >> 8U));
            EEPROM_WriteByte((u16)(EEPROM_PTR_ADDR + 1U), (u8)(g_logPtr & 0xFFU));
        }
    }
}

void Logger_LogEvent(u8 event_id)
{
    RTC_Time time;
    u8 buf[LOG_ENTRY_SIZE];

    RTC_GetTime(&time);

    buf[0] = (u8)(time.year > 2000U ? time.year - 2000U : 0U);
    buf[1] = time.month;
    buf[2] = time.dom;
    buf[3] = time.hour;
    buf[4] = time.min;
    buf[5] = time.sec;
    buf[6] = event_id;

    if (EEPROM_WritePage(g_logPtr, buf, LOG_ENTRY_SIZE))
    {
        g_logPtr = (u16)(g_logPtr + LOG_ENTRY_SIZE);
        if (g_logPtr > (EEPROM_MAX_ADDR - LOG_ENTRY_SIZE))
        {
            g_logPtr = EEPROM_LOG_START_ADDR;
        }
        
        EEPROM_WriteByte(EEPROM_PTR_ADDR, (u8)(g_logPtr >> 8U));
        EEPROM_WriteByte((u16)(EEPROM_PTR_ADDR + 1U), (u8)(g_logPtr & 0xFFU));
    }
}
