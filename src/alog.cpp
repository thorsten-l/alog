#include <Arduino.h>
#include "alog.h"

#ifdef ALOG_LEVEL 

void alog(const char *tag, const char *file, const int line, const char *function, const char *format, ...)
{
  char buf[ALOG_BUFFER_SIZE];
  va_list args;
  Serial.printf("[%d][%lu][%s][%s:%d] %s(): ", (int)xPortGetCoreID(), millis(), tag, file, line, function);
  va_start(args, format);
  vsnprintf(buf,ALOG_BUFFER_SIZE-1,format,args);
  va_end(args);
  Serial.println(buf);
}

void alog_hex( uint8_t *ptr, size_t length )
{
  size_t index = 0;
  while ( index < length )
  {
    if (( index % 16 ) == 0 )
    {
      Serial.printf( "%08x : ", index );
    }
    index ++;
  }
}

#endif
