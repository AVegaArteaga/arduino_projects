//Apex r301 Prop
int latch=12; //74HC595 pin 9 STCP
int clock=13; //74HC595 pin 10 SHCP
int data=11; //74HC595 pin 8 DS
int bullet = 15;
const int X_pin = 0; // analog pin connected to X output

unsigned char table[]=
{0x3f,0x06,0x5b,0x4f,0x66,0x6d,0x7d,0x07,0x7f,0x6f,0x77,0x7c
,0x39,0x5e,0x79,0x71,0x00};
void setup() {
  
  Serial.begin(9600);

  pinMode(3,OUTPUT); //buzzer
  pinMode(4,INPUT_PULLUP); //Set port 4 as input
  pinMode(latch,OUTPUT);
  pinMode(clock,OUTPUT);
  pinMode(data,OUTPUT);
}

void Display(unsigned char num){
  digitalWrite(latch,LOW);
  shiftOut(data,clock,MSBFIRST,table[num]);
  digitalWrite(latch,HIGH);
  delay(200);
}

void Reload(){
  int n =digitalRead(4); //Create a variable n and assign it the state of the number 4digital port.
  if (n==LOW){ //To determine whether n is a high level, if the following statement isexecuted, then skip.
    bullet = 15;
     noTone(3);
  }

}

void loop() {


  
  Serial.println(analogRead(X_pin));
  Display(bullet);
  if(analogRead(X_pin) < 20 && bullet > 0){
      bullet--; 
      if( bullet == 0)
        tone(3,400);
    
  }

  Reload();

}
