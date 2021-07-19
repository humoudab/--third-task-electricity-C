long readDistance(int trigPin, int echoPin)
{
  pinMode(trigPin, OUTPUT);
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  pinMode(echoPin, INPUT);
  int duration = pulseIn(echoPin, HIGH)/2;
  return duration/29.1;
}

void setup()
{
  pinMode(13, OUTPUT);
  pinMode(5, OUTPUT);
  Serial.begin(9600);
  pinMode(13, OUTPUT);
}

void loop()
{
  int cm = readDistance(2,3);
  if(cm <= 100) // مسافة وقوف المقيم متر 
  {
    digitalWrite(5, HIGH);
    digitalWrite(13, HIGH);

  }else 
  {
    digitalWrite(5, LOW);
    digitalWrite(13, LOW);
    
  }
  delay(3000); // مدة الانتظار قبل الارسال ثلاث ثواني 
  
   
}


