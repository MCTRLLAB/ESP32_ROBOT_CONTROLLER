// This example is used to control motor
// 
// Define PWM pin's name to gpio number
#define PWM1 4  
#define PWM2 5 
#define PWM3 6 
#define PWM4 7 


void setup() {
  // set PWM pins as output pins
  pinMode(PWM1, OUTPUT);
  pinMode(PWM2, OUTPUT);
  pinMode(PWM3, OUTPUT);
  pinMode(PWM4, OUTPUT);
}

void loop(){
  // Forward
  for(int dutyCycle = 0; dutyCycle <= 255; dutyCycle++){   
    // changing speed with PWM
    analogWrite(PWM1, dutyCycle); // drive
    delay(50);
  }
  
  delay(1000);
  analogWrite(PWM1, 0); // drive stop
  // Reverse
  for(int dutyCycle = 255; dutyCycle >= 0; dutyCycle--){
    // changing the speed with PWM
    analogWrite(PWM2, dutyCycle); // drive
    delay(50);
  }
  delay(1000);
  analogWrite(PWM2, 0); // drive stop
  
}
