int myD2=2;
int myD3=3;
int myD4=4;
int myD5=5;
int myD6=6;
int myD9=9;
int myD10=10;
int myD11=11;
int myD12=12; //dg1
int myD13 = 13; //dg2
int myD14 = 14; //dg3
int myD15 = 15; //dg4


void setup() {
  pinMode(myD2,OUTPUT);
  pinMode(myD3,OUTPUT);
  pinMode(myD4,OUTPUT);
  pinMode(myD5,OUTPUT);
  pinMode(myD6,OUTPUT);
  pinMode(myD9,OUTPUT);
  pinMode(myD10,OUTPUT);
  pinMode(myD11,OUTPUT);
  pinMode(myD12,OUTPUT);
  pinMode(myD13,OUTPUT);
  pinMode(myD14,OUTPUT);
  pinMode(myD15,OUTPUT);
}

void loop() {
  firstPart(); 

}

void ZERO() {
  digitalWrite(myD2, HIGH);   // a
  digitalWrite(myD3, HIGH);   // b
  digitalWrite(myD4, HIGH);   // c
  digitalWrite(myD5, HIGH);   // d
  digitalWrite(myD6, HIGH);   // e
  digitalWrite(myD9, HIGH);   // f
  digitalWrite(myD10, LOW);   // g
  digitalWrite(myD11, HIGH);   // dp

}

void ONE() {
  digitalWrite(myD2, LOW);    // a
  digitalWrite(myD3, HIGH);   // b
  digitalWrite(myD4, HIGH);   // c
  digitalWrite(myD5, LOW);    // d
  digitalWrite(myD6, LOW);    // e
  digitalWrite(myD9, LOW);    // f
  digitalWrite(myD10, LOW);   // g
  digitalWrite(myD11, LOW);   // dp

}

void TWO() {
  digitalWrite(myD2, HIGH);   // a
  digitalWrite(myD3, HIGH);   // b
  digitalWrite(myD4, LOW);    // c
  digitalWrite(myD5, HIGH);   // d
  digitalWrite(myD6, HIGH);   // e
  digitalWrite(myD9, LOW);    // f
  digitalWrite(myD10, HIGH);  // g
  digitalWrite(myD11, LOW);   // dp
  
}

void THREE() {
  digitalWrite(myD2, HIGH);   // a
  digitalWrite(myD3, HIGH);   // b
  digitalWrite(myD4, HIGH);   // c
  digitalWrite(myD5, HIGH);   // d
  digitalWrite(myD6, LOW);    // e
  digitalWrite(myD9, LOW);    // f
  digitalWrite(myD10, HIGH);  // g
  digitalWrite(myD11, LOW);   // dp
 
}

void FOUR() {
  digitalWrite(myD2, LOW);    // a
  digitalWrite(myD3, HIGH);   // b
  digitalWrite(myD4, HIGH);   // c
  digitalWrite(myD5, LOW);    // d
  digitalWrite(myD6, LOW);    // e
  digitalWrite(myD9, HIGH);   // f
  digitalWrite(myD10, HIGH);  // g
  digitalWrite(myD11, LOW);   // dp

}
void FIVE() {
  digitalWrite(myD2, HIGH);   // a
  digitalWrite(myD3, LOW);    // b
  digitalWrite(myD4, HIGH);   // c
  digitalWrite(myD5, HIGH);   // d
  digitalWrite(myD6, LOW);    // e
  digitalWrite(myD9, HIGH);   // f
  digitalWrite(myD10, HIGH);  // g
  digitalWrite(myD11, LOW);   // dp

}

void SIX() {
  digitalWrite(myD2, HIGH);   // a
  digitalWrite(myD3, LOW);    // b
  digitalWrite(myD4, HIGH);   // c
  digitalWrite(myD5, HIGH);   // d
  digitalWrite(myD6, HIGH);   // e
  digitalWrite(myD9, HIGH);   // f
  digitalWrite(myD10, HIGH);  // g
  digitalWrite(myD11, LOW);   // dp

}

void SEVEN() {
  digitalWrite(myD2, HIGH);   // a
  digitalWrite(myD3, HIGH);   // b
  digitalWrite(myD4, HIGH);   // c
  digitalWrite(myD5, LOW);    // d
  digitalWrite(myD6, LOW);    // e
  digitalWrite(myD9, LOW);    // f
  digitalWrite(myD10, LOW);   // g
  digitalWrite(myD11, LOW);   // dp

}

void EIGHT() {
  digitalWrite(myD2, HIGH);   // a
  digitalWrite(myD3, HIGH);   // b
  digitalWrite(myD4, HIGH);   // c
  digitalWrite(myD5, HIGH);   // d
  digitalWrite(myD6, HIGH);   // e
  digitalWrite(myD9, HIGH);   // f
  digitalWrite(myD10, HIGH);  // g
  digitalWrite(myD11, HIGH);  // dp

}

void NINE(){
  digitalWrite(myD2, HIGH);   // a
  digitalWrite(myD3, HIGH);   // b
  digitalWrite(myD4, HIGH);   // c
  digitalWrite(myD5, HIGH);   // d
  digitalWrite(myD6, LOW);    // e
  digitalWrite(myD9, HIGH);   // f
  digitalWrite(myD10, HIGH);  // g
  digitalWrite(myD11, LOW);  // dp

}

void firstPart(){
  D1_on();
  NINE();
  delay(1000);
  allOFF();
  D2_on();
  SEVEN();
  delay(1000);
  allOFF();
  D3_on();
  FIVE();
  delay(1000);
  allOFF();
  D4_on();
  THREE();
  delay(1000);
  allOFF();
}


void D1_on() {
  digitalWrite(myD12, LOW);  // Turn the LED on (HIGH is the voltage level)
  digitalWrite(myD13, HIGH);  // Turn the LED on (HIGH is the voltage level)
  digitalWrite(myD14, HIGH);  // Turn the LED on (HIGH is the voltage level)
  digitalWrite(myD15, HIGH);  // Turn the LED on (HIGH is the voltage level)
}

void D2_on() {
  digitalWrite(myD12, HIGH);  // Turn the LED on (HIGH is the voltage level)
  digitalWrite(myD13, LOW);  // Turn the LED on (HIGH is the voltage level)
  digitalWrite(myD14, HIGH);  // Turn the LED on (HIGH is the voltage level)
  digitalWrite(myD15, HIGH);  // Turn the LED on (HIGH is the voltage level)

}

void D3_on() {
  digitalWrite(myD12, HIGH);  // Turn the LED on (HIGH is the voltage level)
  digitalWrite(myD13, HIGH);  // Turn the LED on (HIGH is the voltage level)
  digitalWrite(myD14, LOW);  // Turn the LED on (HIGH is the voltage level)

}

void D4_on() {
  digitalWrite(myD12, HIGH);  // Turn the LED on (HIGH is the voltage level)
  digitalWrite(myD13, HIGH);  // Turn the LED on (HIGH is the voltage level)
  digitalWrite(myD14, HIGH);  // Turn the LED on (HIGH is the voltage level)
  digitalWrite(myD15, LOW);  // Turn the LED on (HIGH is the voltage level)

}

void allOFF(){
  digitalWrite(myD12,HIGH);
  digitalWrite(myD13,HIGH);
  digitalWrite(myD14,HIGH);
  digitalWrite(myD15,HIGH);
}




