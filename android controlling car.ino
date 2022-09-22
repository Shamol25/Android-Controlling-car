
String voice;
int
in1 = 2, //Connect To Pin #2
in2 = 3, //Connect  To Pin #3
in3 = 4, //Connect To Pin #4
in4 = 5; //Connect  To Pin #5
int trig = 12;
int echo = 11;
int duration = 0;
int distance = 0;
void setup() {
  Serial.begin(9600);
  pinMode(trig , OUTPUT);
  pinMode(echo , INPUT);
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);
} 

void loop() {

  digitalWrite(trig , HIGH);
  delayMicroseconds(1000);
  digitalWrite(trig , LOW);
  duration = pulseIn(echo , HIGH);
  distance = (duration / 2) / 28.5 ;
  Serial.println(distance);
  while (Serial.available())
  {
  delay(10); //Delay added to make thing stable
  char c = Serial.read(); //Conduct a serial read
  if (c == '#') {break;} //Exit the loop when the # is detected after the word
  voice += c; //Shorthand for voice = voice + c
  } 
  
  if (voice.length() > 0) {
    Serial.println(voice);
//-----------------------------------------------------------------------//   
  //----------Control Multiple Pins----------// 
      
if(voice =="*sensor")
{
  if ( distance < 170)
    {     
      digitalWrite(in1,HIGH);
      digitalWrite(in2,LOW);
      digitalWrite(in3,HIGH);
      digitalWrite(in4,LOW);
      delay(300);
     digitalWrite(in1,LOW);
    digitalWrite(in2,HIGH);
    digitalWrite(in3,HIGH);
    digitalWrite(in4,LOW);
    delay(200);
  }
  else if ( distance >  170 )
  {
    digitalWrite(in1,LOW);
      digitalWrite(in2,HIGH);
        digitalWrite(in3,LOW);
          digitalWrite(in4,HIGH);
              
  }
}
     else if(voice =="*up")
    { 
       digitalWrite(in1,LOW);
      digitalWrite(in2,HIGH);
       digitalWrite(in3,LOW);
       digitalWrite(in4,HIGH);
           delay(100);    
    } 
     else if(voice=="*right")
     {
      digitalWrite(in1,LOW);
     digitalWrite(in2,HIGH);
      digitalWrite(in3,LOW);
       digitalWrite(in4,LOW);
         delay(100);
   }
   
   else if(voice=="*come_right")
   {
     digitalWrite(in1, LOW);
    digitalWrite(in2,LOW);
    digitalWrite(in3,LOW); 
     digitalWrite(in4,HIGH);
     delay(100);
   }
    else if(voice=="*back_right")
     {
        digitalWrite(in1, HIGH);
    digitalWrite(in2,LOW);
    digitalWrite(in3,LOW); 
     digitalWrite(in4,LOW);
      delay(100);
   }
   else if(voice=="*down")
   {
     digitalWrite(in1, HIGH);
    digitalWrite(in2,LOW);
    digitalWrite(in3,HIGH); 
     digitalWrite(in4,LOW);
      delay(100);
   }
   else if(voice=="*left")
   {
    digitalWrite(in1, LOW);
    digitalWrite(in2,LOW);
    digitalWrite(in3,LOW); 
     digitalWrite(in4,HIGH);
     delay(100);
   }
   else if(voice=="*come_left")
     {
      digitalWrite(in1,LOW);
     digitalWrite(in2,HIGH);
      digitalWrite(in3,LOW);
       digitalWrite(in4,LOW);
         delay(100);
   }
   else if(voice=="*back_left")
   {
     digitalWrite(in1,LOW);
    digitalWrite(in2,LOW);
    digitalWrite(in3,HIGH);
     digitalWrite(in4,LOW);
      delay(100);
   }
   else if(voice =="*rotate")
   { 
    digitalWrite(in1,HIGH);
    digitalWrite(in2,LOW);
     digitalWrite(in3,LOW);
      digitalWrite(in4,HIGH);
        delay(100);
   }
   else if(voice == "*stop")
   { 
    digitalWrite(in2,LOW);
      digitalWrite(in4,LOW);
        digitalWrite(in1,LOW);
          digitalWrite(in3,LOW);
   }
  
voice="";}} //Reset the variable after initiating//Reset the variable after initiating

