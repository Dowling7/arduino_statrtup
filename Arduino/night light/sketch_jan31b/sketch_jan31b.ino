int sensorValue = 0;
void setup()
{
  pinMode(A0, INPUT);
  pinMode(9, OUTPUT);
  Serial.begin(9600);
}
void loop()
{
  // read the value from the sensor
  sensorValue = analogRead(A0);
  // print the sensor reading so you know its range
  Serial.println(sensorValue);

   if (sensorValue<250){
    digitalWrite(9, HIGH);
   }else{
    digitalWrite(9, LOW);
   }
}
