#include <Arduino.h>
#include <alog.h>

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
  ALOG_E( "number: %d", 404 );
  ALOG_W( "number: %d", 42 );
  ALOG_I( "%s", "this is alog" );
  ALOG_D( "%s : %d", "time_t", millis() );
  ALOG_D_HEAP();
  ALOG_V( "password: %s", "very secret" );
}

void loop()
{
  delay(25);
}