int needWater = 8 ; //Red LED
int tooMuchWater = 9 ; //Blue LED
int aLittleDry = 10 ; //Yellow LED
int enoughWater = 11 ; //Green LED

void setup() {
  Serial.begin(9600);
  pinMode(needWater, OUTPUT);
  pinMode(enoughWater, OUTPUT);
  pinMode(tooMuchWater, OUTPUT);
  pinMode(aLittleDry, OUTPUT);

}

void loop() {
  int rawMoisture = analogRead(A0);
  int mappedMoisture = map(rawMoisture,1023,0,0, 100);
  Serial.println(mappedMoisture);
  changeLED(mappedMoisture);
  delay(500);

}

//Function to switch LED based on moisture level
void changeLED(int mappedMoisture){
  //No water at all
  if(mappedMoisture <= 40){
    digitalWrite(needWater,HIGH);
    digitalWrite(tooMuchWater,LOW);
    digitalWrite(aLittleDry,LOW);
    digitalWrite(enoughWater,LOW);
    tone(12,262,2000);
    delay(5000);
    noTone(12);
  }
    //Alittle dry
  else if(mappedMoisture >= 41 && mappedMoisture <= 57){
    digitalWrite(needWater,LOW);
    digitalWrite(tooMuchWater,LOW);
    digitalWrite(aLittleDry,HIGH);
    digitalWrite(enoughWater,LOW);
  }
    //Enough Water
  else if(mappedMoisture >= 58 && mappedMoisture <=74){
    digitalWrite(needWater,LOW);
    digitalWrite(tooMuchWater,LOW);
    digitalWrite(aLittleDry,LOW);
    digitalWrite(enoughWater,HIGH);
        tone(12,500,1000);
    delay(5000);
    noTone(12);
  }
  //Too much water
  else if(mappedMoisture >= 75){
    digitalWrite(needWater,LOW);
    digitalWrite(tooMuchWater,HIGH);
    digitalWrite(aLittleDry,LOW);
    digitalWrite(enoughWater,LOW);
  }
}

