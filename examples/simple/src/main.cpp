#include <Arduino.h>
#include <alog.h>
#include <string.h>

uint8_t *lorem_ipsum =
    (uint8_t
         *)"Lorem ipsum dolor sit amet, consetetur sadipscing elitr, "
           "sed diam nonumy eirmod tempor invidunt ut labore et dolore "
           "justo duo dolores et ea rebum. Stet clita kasd gubergren, no "
           "sea takimata sanctus est Lorem ipsum dolor si "
           "\r\n\r\n\rAX1234567890A\n\r";

void setup()
{
  Serial.begin(115200);

  while (!Serial.availableForWrite())
  {
    delay(100);
  }

  Serial.begin(115200);

  while (!Serial.availableForWrite())
  {
    delay(100);
  }

  ALOG_I("ALOG logging sample");

  ////
  ALOG_E("number: %d", 404);
  ALOG_W("number: %d", 42);
  ALOG_I("%s", "this is alog");
  ALOG_D("%s : %d", "time_t", millis());
  ALOG_D_HEAP();
  ALOG_V("password: %s", "very secret");
  ALOG_HEX(lorem_ipsum, strlen((char *)lorem_ipsum));
}

void loop()
{
  delay(25);
}
