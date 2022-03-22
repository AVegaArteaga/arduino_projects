const int ledPin = 13;//the led attach to
void setup()
{
pinMode(ledPin,OUTPUT); // the light on the board lighting
pinMode(4,INPUT); //the input to the device
digitalWrite(4, HIGH); // the power to the device
}
void loop()
{
int digitalVal = digitalRead(4);
if(HIGH == digitalVal)
{
digitalWrite(ledPin,LOW); //turn the led off
}
else
{
digitalWrite(ledPin,HIGH); //turn the led on
}
}
