#include "alog.h"
#include <Arduino.h>

#ifdef ALOG_LEVEL

void alog(const char *tag, const char *file, const int line,
          const char *function, const char *format, ...)
{
  char buf[ALOG_BUFFER_SIZE];
  va_list args;
  Serial.printf("[%d][%lu][%s][%s:%d] %s(): ", (int)xPortGetCoreID(), millis(),
                tag, file, line, function);
  va_start(args, format);
  vsnprintf(buf, ALOG_BUFFER_SIZE - 1, format, args);
  va_end(args);
  Serial.println(buf);
}

void alog_hex(uint8_t *ptr, size_t length)
{
  Serial.println();
  size_t index = 0;
  while (index < length)
  {
    if ((index % 16) == 0)
    {
      if( index > 0)
        Serial.println();
      Serial.printf("%08x: ", index);
    }

    if (((index + 8) % 16) == 0)
    {
      Serial.print("- ");
    }

    Serial.printf("%02x ", ptr[index]);

    if (index > 0 && ((index+1) % 16) == 0)
    {
      Serial.print("|");
      for (int i = 0; i < 16; i++)
      {
        char c = ptr[index - 15 + i];
        if (isprint(c))
        {
          Serial.print(c);
        }
        else
        {
          Serial.print('.');
        }
      }
      Serial.print("|");
    }

    index++;
  }

  int rest = index % 16;

  if (rest > 0)
  {
    for (int i = 0; i < (16 - rest); i++)
    {
      if (i == 7)
        Serial.print("  ");
      Serial.print("   ");
    }

    Serial.print("|");

    for (int i = 0; i < rest; i++)
    {
      char c = ptr[index - rest + i];
      if (isprint(c))
      {
        Serial.print(c);
      }
      else
      {
        Serial.print('.');
      }
    }

    for (int i = 0; i < (16 - rest); i++)
    {
      Serial.print(" ");
    }

    Serial.println("|");
  }
  Serial.println();
}

#endif
