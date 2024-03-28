const int potpin=14;
int potval=0;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);//yaani na9ra 115200 instruction par sec
  delay(1000);
}

void loop() {
  // put your main code here, to run repeatedly:
  potval=analogRead(potpin);

  Serial.println(potval);
  delay(400); // this speeds up the simulation
}
// great work just so far but it's recommended to map the value so it can be used somewhere else by using the map function 