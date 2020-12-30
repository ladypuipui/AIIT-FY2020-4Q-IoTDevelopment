#include <dht_nonblocking.h>
#include <LiquidCrystal.h>
#define DHT_SENSOR_TYPE DHT_TYPE_11

static const int DHT_SENSOR_PIN = 2;
static const int THERM_PIN = 0;

LiquidCrystal lcd(7, 8, 9, 10, 11, 12);
DHT_nonblocking dht_sensor { DHT_SENSOR_PIN, DHT_SENSOR_TYPE};


void setup() {
    lcd.begin(16, 2);     
}

void loop() {
  float temperature;
  float humidity;

if( measure_environment( &temperature, &humidity ) == true )
  {
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Temp         C  ");
    lcd.setCursor(6, 0);
    lcd.print(temperature);
    lcd.setCursor(0, 1);
    lcd.print("Humid        %  ");
    lcd.setCursor(6, 1);
    lcd.print(humidity);
    delay(2000);
  }
}

static bool measure_environment( float *temperature, float *humidity )
{
  static unsigned long measurement_timestamp = millis( );

  if( millis( ) - measurement_timestamp > 3000ul )
  {
    if( dht_sensor.measure( temperature, humidity ) == true )
    {
      measurement_timestamp = millis( );
      return( true );
    }
  }

  return( false );

}