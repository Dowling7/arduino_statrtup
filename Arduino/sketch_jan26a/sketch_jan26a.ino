int var=0;


void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
pinMode(A0,INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  var=analogRead(A0);
  Serial.print("Potential meter bit value: ");
  Serial.println(var);
  delay(1000);
}
