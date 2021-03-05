long cm = 0;

long readUltrasonicDistance(int triggerPin, int echoPin)
{
  pinMode(triggerPin, OUTPUT);  
  digitalWrite(triggerPin, LOW);
  delayMicroseconds(2);
  digitalWrite(triggerPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(triggerPin, LOW);
  pinMode(echoPin, INPUT);
  return (pulseIn(echoPin, HIGH)*0.01723);
  
}

void setup()
{
  Serial.begin(9600);

  pinMode(8, OUTPUT);
  pinMode(9, OUTPUT);
}

void loop()
{
  cm =readUltrasonicDistance(4, 5);

  Serial.print(cm);
  Serial.println("cm");
  
  if (cm < 200) {
    digitalWrite(9, HIGH);
  }
  if (cm >= 200) {
    digitalWrite(8, HIGH);
  }

  delay(100); 
}
