int sensor1=A0;
int sensor2=A1;
//no object 1015
void setup() {
  // put your setup code here, to run once:
   pinMode(sensor1, INPUT);
   pinMode(sensor2, INPUT);

   Serial.begin(9600);

}

void loop() {
  // put your main code here, to run repeatedly:
  int value1;
  int value2;
  value1=analogRead(sensor1);
  value2=analogRead(sensor2);
  int df=value1-value2;
  Serial.println(value1); 

}
