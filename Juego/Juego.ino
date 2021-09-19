/*Autor: Margareth Vela
 *Dispositivo: Launchpad Tiva C  
 *
 *Programa: Juego de Carreras
 *Hardware: Leds
 *
 *Creado: Agosto 18, 2021
 *Ultima modificacion: Agosto 18, 2021
 */

//Definir los pines de los switches y las leds
#define SW1 PF_4
#define SW2 PF_0

#define LED1 RED_LED
#define LED2 BLUE_LED
#define LED3 GREEN_LED

#define Ld1 PB_0
#define Ld2 PB_1
#define Ld3 PE_4
#define Ld4 PE_5
#define Ld5 PB_4
#define Ld6 PA_5
#define Ld7 PA_6
#define Ld8 PA_7

#define Ld9 PD_0
#define Ld10 PD_1
#define Ld11 PD_2
#define Ld12 PD_3
#define Ld13 PE_1
#define Ld14 PE_2
#define Ld15 PE_3
#define Ld16 PA_2

// variables will change:
int buttonState1 = 0;         // variable for reading the pushbutton status
int buttonState2 = 0; 
int cont1 = 0;
int cont2 = 0;

int flag = 0;
volatile byte state = LOW;

void setup() {
  // put your setup code here, to run once:
  pinMode(LED1,OUTPUT);
  pinMode(LED2,OUTPUT);
  pinMode(LED3,OUTPUT);
  
  pinMode(Ld1, OUTPUT);
  pinMode(Ld2, OUTPUT);
  pinMode(Ld3, OUTPUT);
  pinMode(Ld4, OUTPUT);
  pinMode(Ld5, OUTPUT);
  pinMode(Ld6, OUTPUT);
  pinMode(Ld7, OUTPUT);
  pinMode(Ld8, OUTPUT);

  pinMode(Ld9, OUTPUT);
  pinMode(Ld10, OUTPUT);
  pinMode(Ld11, OUTPUT);
  pinMode(Ld12, OUTPUT);
  pinMode(Ld13, OUTPUT);
  pinMode(Ld14, OUTPUT);
  pinMode(Ld15, OUTPUT);
  pinMode(Ld16, OUTPUT);
  
  pinMode(SW1, INPUT_PULLUP);
  pinMode(SW2, INPUT_PULLUP);

  attachInterrupt(digitalPinToInterrupt(SW1), button1, RISING);
  attachInterrupt(digitalPinToInterrupt(SW2), button2, RISING);
  
}

void loop() {
  // put your main code here, to run repeatedly: 

  if (flag == 1){
    digitalWrite(LED1, HIGH);
    delay(1000);
    digitalWrite(LED2, HIGH);
    delay(1000);
    digitalWrite(LED3, HIGH);
    delay(1000);
    flag = 2;
  }
  
  if(cont1 == 1){
    digitalWrite(Ld1,HIGH);
    digitalWrite(Ld8,LOW);}
  else if(cont1 == 2){
    digitalWrite(Ld2,HIGH);
    digitalWrite(Ld1,LOW);}
  else if(cont1 == 3){
    digitalWrite(Ld3,HIGH);
    digitalWrite(Ld2,LOW);}
  else if(cont1 == 4){
    digitalWrite(Ld4,HIGH);
    digitalWrite(Ld3,LOW);}
  else if(cont1 == 5){
    digitalWrite(Ld5,HIGH);
    digitalWrite(Ld4,LOW);}
  else if(cont1 == 6){
    digitalWrite(Ld6,HIGH);
    digitalWrite(Ld5,LOW);}
  else if(cont1 == 7){
    digitalWrite(Ld7,HIGH);
    digitalWrite(Ld6,LOW);}
  else if(cont1 == 8){
    digitalWrite(Ld8,HIGH);
    digitalWrite(Ld7,LOW);}
  else if(cont1 == 9){
    if(LED3 == LOW){
    digitalWrite(LED2, HIGH);}
    cont1=0;}

  if(cont2 == 1){
    digitalWrite(Ld9,HIGH);
    digitalWrite(Ld16,LOW);}
  else if(cont2 == 2){
    digitalWrite(Ld10,HIGH);
    digitalWrite(Ld9,LOW);}
  else if(cont2 == 3){
    digitalWrite(Ld11,HIGH);
    digitalWrite(Ld10,LOW);}
  else if(cont2 == 4){
    digitalWrite(Ld12,HIGH);
    digitalWrite(Ld11,LOW);}
  else if(cont2 == 5){
    digitalWrite(Ld13,HIGH);
    digitalWrite(Ld12,LOW);}
  else if(cont2 == 6){
    digitalWrite(Ld14,HIGH);
    digitalWrite(Ld13,LOW);}
  else if(cont2 == 7){
    digitalWrite(Ld15,HIGH);
    digitalWrite(Ld14,LOW);}
  else if(cont2 == 8){
    digitalWrite(Ld16,HIGH);
    digitalWrite(Ld15,LOW);}
  else if(cont2 == 9){
    if(LED2 == LOW){
    digitalWrite(LED3, HIGH);}
    cont2=0;}
  
}

void button1(){
  if(flag != 2){
     flag = 1; 
    }
    if(flag == 2){
      cont1++;}
}

void button2(){
  if(flag != 2){
     flag = 1; 
    }
    if(flag == 2){
      cont2++;}
}
