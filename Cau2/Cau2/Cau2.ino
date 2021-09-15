byte pin[] = {13,12,11,10,9,8,7,6};
int button = 4;
void setup() {
  for(int i = 0 ; i < sizeof(pin) ; i++){
    pinMode(pin[i],OUTPUT);
    digitalWrite(pin[i],0);
  }
  pinMode(button, INPUT);
  Serial.begin(9600);
}
void loop() {
  int n = random(5000,10000);
  int m;
  int ledRD = random(0,sizeof(pin)-1);
  
  //Cau2b
  if(digitalRead(button)==1){
    long timeRun = millis();
    for(int i = sizeof(pin) ; i > 0 ; i--){
      digitalWrite(pin[i],1);
      delay(300);
      digitalWrite(pin[i],0);
      delay(300);
    }
  //Cau2c
  if(timeRun <= n || timeRun >=n || timeRun == n ){
    m=n/1.5;
    Serial.println(m);
    delay(3000);
  }
 }
}
