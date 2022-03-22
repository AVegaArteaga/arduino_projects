void setup()
{
}
void loop(){
  //#define delayTime 1000;
  for(int i=200;i<=800;i++){ //Increase the frequency from 200HZ to 800HZ in a loop{
  pinMode(8,OUTPUT);
  tone(8,i); //Output frequency on port 8 delay(5); //This frequency ismaintained for 5 milliseconds
  }
  delay(4000); //Hold for 4 seconds at the highest frequency

  
  for(int i=800;i>=200;i--)
    {
      pinMode(8,OUTPUT); 
      tone(8,i);
      delay(10);
    }
}
