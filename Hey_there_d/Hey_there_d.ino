void setup()
{
}

int ReadSens_and_Condition(){

}

void loop(){
  #define delayTime 1000
  #define dString 146.83 
  #define aString 110.00 

  
  pinMode(8,OUTPUT);
  pinMode(7,OUTPUT);
  

  
  tone(8,dString);
  delay(delayTime);
  tone(8,aString);
//  noTone(8);
  delay(delayTime);

  
//  for(int i=200;i<=800;i++){ //Increase the frequency from 200HZ to 800HZ in a loop{
//  pinMode(8,OUTPUT);
//  tone(8,i); //Output frequency on port 8 delay(5); //This frequency ismaintained for 5 milliseconds
//  }
//  delay(4000); //Hold for 4 seconds at the highest frequency
//
//  
//  for(int i=800;i>=200;i--)
//    {
//      pinMode(8,OUTPUT); 
//      tone(8,i);
//      delay(10);
//    }
}
