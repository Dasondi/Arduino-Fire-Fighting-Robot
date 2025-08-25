#include <SoftwareSerial.h>

  #define enA 10
  #define in1 9 
  #define in2 8 
  #define in3 7 
  #define in4 6 
  #define enB 5 
  #define ir_R A0
  #define ir_F A1
  #define ir_L A2
  #define servo A4
  #define pump A5
  int Speed = 180;
  int s1, s2, s3;

  SoftwareSerial sim800(0, 1);


  void setup(){ 
    Serial.begin(9600); 
    pinMode(ir_R, INPUT);
    pinMode(ir_F, INPUT);
    pinMode(ir_L, INPUT);
    pinMode(enA, OUTPUT); 
    pinMode(in1, OUTPUT); 
    pinMode(in2, OUTPUT); 
    pinMode(in3, OUTPUT); 
    pinMode(in4, OUTPUT);
    pinMode(enB, OUTPUT); 
    pinMode(servo, OUTPUT);
    pinMode(pump, OUTPUT);

    for (int angle = 90; angle <= 140; angle += 5) {
    servoPulse(servo, angle); }

    for (int angle = 140; angle >= 40; angle -= 5) {
    servoPulse(servo, angle); }

    for (int angle = 40; angle <= 95; angle += 5) {
    servoPulse(servo, angle); }

    analogWrite(enA, Speed); 
    analogWrite(enB, Speed);

    delay(50);
  }


  void loop(){

    s1 = analogRead(ir_R);
    s2 = analogRead(ir_F);
    s3 = analogRead(ir_L);

    Serial.print(s1);
    Serial.print("\t");
    Serial.print(s2);
    Serial.print("\t");
    Serial.println(s3);

    delay(50);

    if(s1<700){
      backward();
      digitalWrite(pump, 1);

      for(int angle = 90; angle >= 40; angle -= 3){
      servoPulse(servo, angle);}

      for(int angle = 40; angle <= 90; angle += 3){
      servoPulse(servo, angle);}

      sendSMS("Fire detected! Taking action.");
      }

    else if(s2<700){
      backward();
      digitalWrite(pump, 1);

      for(int angle = 90; angle <= 140; angle += 3){
      servoPulse(servo, angle);}

      for(int angle = 140; angle >= 40; angle -= 3){
      servoPulse(servo, angle);}

      for(int angle = 40; angle <= 90; angle += 3){
      servoPulse(servo, angle); }

      sendSMS("Fire detected! Taking action.");
    }

    else if(s3<700){
      backward();
      digitalWrite(pump, 1);
      for(int angle = 90; angle <= 140; angle += 3){
      servoPulse(servo, angle);
      }
      for(int angle = 140; angle >= 90; angle -= 3){
      servoPulse(servo, angle);}

      sendSMS("Fire detected! Taking action.");
      }

    else if(s1>=700 && s1<=700){
      digitalWrite(pump, 0);
      backward();
      delay(50);
      turnRight();
      delay(50);

      sendSMS("Fire detected! Taking action.");
    }

    else if(s2>=700 && s2<=800){
      digitalWrite(pump, 0);
      forward();
      sendSMS("Fire detected! Taking action.");
    }

    else if(s3>=700 && s3<=700){
      digitalWrite(pump, 0);
      backward();
      delay(50);
      turnLeft();
      delay(50);
      sendSMS("Fire detected! Taking action.");
    }

    else{
      digitalWrite(pump, 0);
      Stop();
    }

    delay(10);
  }

  void servoPulse (int pin, int angle){
    int pwm = (angle*11) + 500;
    digitalWrite(pin, HIGH);
    delayMicroseconds(pwm);
    digitalWrite(pin, LOW);

    delay(50); 
  }

  void forward(){ 
    digitalWrite(in1, HIGH); 
    digitalWrite(in2, LOW); 
    digitalWrite(in3, LOW); 
    digitalWrite(in4, HIGH);
  }
  void backward(){ 
    digitalWrite(in1, LOW); 
    digitalWrite(in2, HIGH); 
    digitalWrite(in3, HIGH);
    digitalWrite(in4, LOW); 
  }
  void turnRight(){ 
    digitalWrite(in1, LOW); 
    digitalWrite(in2, HIGH); 
    digitalWrite(in3, LOW); 
    digitalWrite(in4, HIGH); 
  }
  void turnLeft(){ 
    digitalWrite(in1, HIGH); 
    digitalWrite(in2, LOW); 
    digitalWrite(in3, HIGH);
    digitalWrite(in4, LOW); 
  }
  void Stop(){ 
    digitalWrite(in1, LOW); 
    digitalWrite(in2, LOW); 
    digitalWrite(in3, LOW); 
    digitalWrite(in4, LOW); 
  }

  void sendSMS(String message) {
    sim800.println("AT+CMGF=1");    
    delay(100);
    sim800.println("AT+CMGS=\"+9810390122\"");  
    delay(100);
    sim800.println(message);        
    delay(100);
    sim800.write(26);               
    delay(100);                    
}
