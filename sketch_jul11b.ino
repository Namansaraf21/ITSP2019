#include<Servo.h>
Servo servo[4][3];
int servo_pin[4][3] = {{2,3,4}, {5,6,7}, {8,9,10},{11,12,13}};
int state = 0;
int pos[4][3] = {{90,90,90},{90,90,90},{90,90,90},{90,90,90}};
 
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  for(int i=0; i<4; i++){
    for(int j=0; j<3; j++){
      servo[i][j].attach(servo_pin[i][j]);
    }
  }
  Serial.println("Servos attached");
  for(int i=0; i<4; i++){
    for(int j=0; j<3; j++){
      servo[i][j].write(90);
    }
  }
  Serial.println("Servos innitialised");
}

void loop() {
  if(Serial.available()>0){
    state = Serial.read();
    Serial.println(state);
  }
  if(state == '1'){    // stand
    pos[0][0] = 135;
    pos[0][1] = 135;
    pos[1][0] = 45;
    pos[1][1] = 45;
    pos[2][1] = 45;
    pos[2][2] = 45;
    pos[2][0] = 135;
    pos[2][1] = 135;
    for(int i=0; i<4; i++){
      for(int j=0; j<3; j++){
        servo[i][j].write(pos[i][j]);
      }
    }
  }
  delay(2000);
  if(state == '3'){    // forward
    // back right leg
    servo[1][0].write((pos[1][0] - 10));
    servo[1][2].write((pos[1][2] - 10));
    delay(100);
    servo[1][0].write((pos[1][0]));
    delay(200);
    // front right leg
    servo[0][0].write((pos[0][0] - 10));
    servo[0][2].write((pos[0][2] - 10));
    delay(100);
    servo[0][0].write((pos[0][0]));
    delay(200);
    
    servo[0][2].write(pos[0][2]);
    servo[2][0].write(pos[2][0] - 10);
    servo[1][2].write(pos[1][2]);
    servo[3][2].write(pos[3][2] - 10);
    
    // back left leg
    servo[3][0].write((pos[3][0] + 10));
    servo[3][2].write((pos[3][2]));
    delay(100);
    servo[3][0].write((pos[3][0]));
    delay(200);
    // front left leg
    servo[2][1].write((pos[2][1] + 10));
    servo[2][0].write((pos[2][0]));
    delay(100);
    servo[2][1].write((pos[2][1]));
  }
  delay(2000);
  if(state == '4'){  // back
    // back right leg
    servo[1][0].write((pos[1][0] - 10));
    servo[1][2].write((pos[1][2] + 10));
    delay(100);
    servo[1][0].write((pos[1][0]));
    delay(200);
    // front right leg
    servo[0][0].write((pos[0][0] - 10));
    servo[0][2].write((pos[0][2] + 10));
    delay(100);
    servo[0][0].write((pos[0][0]));
    delay(200);
    
    servo[0][2].write(pos[0][2]);
    servo[2][0].write(pos[2][0] + 10);
    servo[1][2].write(pos[1][2]);
    servo[3][2].write(pos[3][2] + 10);
    
    // back left leg
    servo[3][0].write((pos[3][0] + 10));
    servo[3][2].write((pos[3][2]));
    delay(100);
    servo[3][0].write((pos[3][0]));
    delay(200);
    // front left leg
    servo[2][1].write((pos[2][1] + 10));
    servo[2][0].write((pos[2][0]));
    delay(100);
    servo[2][1].write((pos[2][1]));
  }
  delay(2000);
  if(state == '5'){ //turn left
 
  }
  delay(2000);
  if(state == '6'){ // turn right
  
  }
  delay(2000);
  if(state == '2'){ // sit
    pos[0][0] = 45;
    pos[0][1] = 45;
    pos[1][0] = 45;
    pos[1][1] = 45;
    pos[2][1] = 135;
    pos[2][2] = 135;
    pos[2][0] = 135;
    pos[2][1] = 135;
    for(int i=0; i<4; i++){
      for(int j=0; j<3; j++){
        servo[i][j].write(pos[i][j]);
      }
    }
  }
  delay(5000);
}
