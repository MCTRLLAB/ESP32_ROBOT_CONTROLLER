int i = 0;
void setup() {
  pinMode(47,OUTPUT);
  pinMode(48,OUTPUT);
  digitalWrite(47,LOW);
  digitalWrite(48,LOW);
   delay(2000);
  Serial.begin(115200);
  delay(1000);

 
  //Serial.println(i);

}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(47,HIGH);
  digitalWrite(48,LOW);
  delay(500);
  digitalWrite(47,LOW);
  digitalWrite(48,HIGH);
  delay(500);
  Serial.println(i);
  i = i+1;
  if (i > 100) i = 0;
}
