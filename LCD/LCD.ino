#include <LiquidCrystal.h>
#include <dht_nonblocking.h>
#define DHT_SENSOR_TYPE DHT_TYPE_11
static const int DHT_SENSOR_PIN = 2;
DHT_nonblocking dht_sensor( DHT_SENSOR_PIN, DHT_SENSOR_TYPE );

// initialize the library with the numbers of the interface pins
LiquidCrystal lcd(7, 8, 9, 10, 11, 12);
void setup() {
  // set up the LCD's number of columns and rows:
  lcd.begin(16, 2);
  // Print a message to the LCD.
  lcd.print("Hello!");

  Serial.begin( 9600);
  }



/*
*Poll for a measurement, keeping the state machine alive.
*Returns true if a measurement is available.
*/
static bool measure_environment( float *temperature, float *humidity ){
  
  static unsigned long measurement_timestamp = millis( );
  /* Measure once every four seconds. */
  if( millis( ) - measurement_timestamp > 3000ul ){
    
    if( dht_sensor.measure( temperature, humidity ) == true ){
      measurement_timestamp = millis( ); return( true );
    }
  }
  
  return( false );
}


  
void loop() {
  float temperature; 
  float humidity;

  measure_environment( &temperature, &humidity);


 lcd.setCursor(0,0);
 lcd.print("Temp: ");
 lcd.print( temperature * (9/5) + 32 , 1 );
 lcd.print("F");
  // set the cursor to column 0, line 1
  // (note: line 1 is the second row, since counting begins with 0):
  lcd.setCursor(0, 1);
  // print the number of seconds since reset:
  lcd.print("Hum : ");
  lcd.print( humidity, 1.0 );
  lcd.print( "%" );
}
