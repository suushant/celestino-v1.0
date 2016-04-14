//Code for LineFollower

/*
uses five Infrared sensors
1,2 right
3 center
4,5 left
ADC connections:
A0-1, A1-2, A2-3, A3-4, A4-5
*/

//motor1 to pins 11,13 .....this is the left motor
//motor2 to pins 2,3 ....this is the right motor

int m11=11;
int m12=13;
int m21=2;
int m22=3;

int white=60;    //Threshold for white
int black=450;   //Threshold for black
int r1, r2, r3, r4, r5;

void setup()
{
  Serial.begin(9600);
  pinMode(m11,OUTPUT);
  pinMode(m12,OUTPUT);
  pinMode(m21,OUTPUT);
  pinMode(m22,OUTPUT);
}

void straight(){
  digitalWrite(m11,HIGH);
  digitalWrite(m12,LOW);
  digitalWrite(m21,HIGH);
  digitalWrite(m22,LOW);
  delay(20);
}

void right(){
  //turn right
  digitalWrite(m11,HIGH);
  digitalWrite(m12,LOW);
  digitalWrite(m21,LOW);
  digitalWrite(m22,LOW);
  delay(20);
}

void left(){
  digitalWrite(m11,LOW);
  digitalWrite(m12,LOW);
  digitalWrite(m21,HIGH);
  digitalWrite(m22,LOW);
  delay(20);
}

void stop1(){
  digitalWrite(m11,LOW);
  digitalWrite(m12,LOW);
  digitalWrite(m21,LOW);
  digitalWrite(m22,LOW);
  delay(20);
}


void loop(){
  
  
  //read all receivers
  r1=analogRead(A0);
  r2=analogRead(A1);
  r3=analogRead(A2);
  r4=analogRead(A3);
  r5=analogRead(A4);
  
  //print receiver values
  Serial.print(r1);
  Serial.print(" ");
  Serial.print(r2);
  Serial.print(" ");
  Serial.print(r3);
  Serial.print(" ");
  Serial.print(r4);
  Serial.print(" ");
  Serial.print(r5);
  delay(50);
  
  //motor control
  
  //straight
  if(r1>black && r2<white && r3<white && r4<white && r5>black)
  {
    straight();
    Serial.println("straight");
  }
  
   else if(r1>black && r2>black && r3<white && r4<white && r5>black)
  {
    straight();
    Serial.println("straight");
  }
  
   else if(r1>black && r2<white && r3<white && r4>black && r5>black)
  {
    straight();
    Serial.println("straight");
  }
  
   else if(r1>black && r2>black && r3<white && r4>black && r5>black)
  {
    straight();
    Serial.println("straight");
  }



  //right
  else if(r1>black && r2>black && r3>black && r4>black && r5<white)
  {
    right();
    Serial.println("right");
  }

  else if(r1>black && r2>black && r3>black && r4<white && r5<white)
  {
    right();
    Serial.println("right");
  }  
  
  else if(r1>black && r2>black && r3<white && r4<white && r5<white)
  {
    right();
    Serial.println("right");
  }
  
  else if(r1>black && r2<white &&  r3<white && r4<white && r5<white)
  {
    right();
    Serial.println("right");
  }
  




  //left
  else if(r1<white && r2<white && r3<white && r4<white && r5>black)
  {
    left();
    Serial.println("left");
  }

  else if(r1<white && r2<white && r3<white && r4>black && r5>black)
  {
    left();
    Serial.println("left");
  }

  else if(r1<white && r2<white && r3>black && r4>black && r5>black)
  {
    left();
    Serial.println("left");
  }

  else if(r1<white && r2>black && r3>black && r4>black && r5>black)
  {
    left();
    Serial.println("left");
  }





  //other conditions
  else if(r2<white && r3<white && r4<white && r1<white && r5<white){  //all white go straight
    straight();
    Serial.println("straight");
  }
  
  else if(r2>black && r3>black && r4>black && r1>black && r5>black){  //all black stop
    stop1();
    Serial.println("stop");
  }
  
  else{
  Serial.println();
}

}
