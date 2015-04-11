//A simple code to blink the led at pin13 on the celestino board for 1 second
void setup()
{
pinMode(13, OUTPUT);
}
void loop()
{
digitalWrite(13,HIGH);
delay(1000);
digitalWrite(13,LOW);
delay(1000);
}
