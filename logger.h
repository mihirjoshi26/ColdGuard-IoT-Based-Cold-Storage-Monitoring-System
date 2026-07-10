#ifndef __LOGGER_H__
#define __LOGGER_H__

#include "types.h"
#include "rtc.h"

#define EVENT_ACCESS_GRANTED   1U
#define EVENT_ACCESS_DENIED    2U
#define EVENT_PASSWORD_CHANGED 3U

void Logger_Init(void);
void Logger_LogEvent(u8 event_id);

#endif /* __LOGGER_H__ */
