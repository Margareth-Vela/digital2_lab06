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

const int P1 = 36;
const int P2 = 37;

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

  pinMode(P1,OUTPUT);
  pinMode(P2,OUTPUT);
  
  pinMode(SW1, INPUT_PULLUP);
  pinMode(SW2, INPUT_PULLUP);

  attachInterrupt(digitalPinToInterrupt(SW1), button1, RISING);
  attachInterrupt(digitalPinToInterrupt(SW2), button2, RISING);
  
}

void loop() {
  // put your main code here, to run repeatedly: 

  if (flag == 1){
    clean1();
    clean2();
    digitalWrite(LED1, HIGH);
    delay(1000);
    digitalWrite(LED2, HIGH);
    delay(1000);
    digitalWrite(LED3, HIGH);
    delay(1000);
    flag = 2;
  }
  
  if(cont1 == 1){
    clean1();
    digitalWrite(Ld1, HIGH);
    }
  else if(cont1 == 2){
    clean1();
    digitalWrite(Ld2, HIGH);
    }
  else if(cont1 == 3){
    clean1();
    digitalWrite(Ld3, HIGH);
    }
  else if(cont1 == 4){
    clean1();
    digitalWrite(Ld4, HIGH);
    }
  else if(cont1 == 5){
    clean1();
    digitalWrite(Ld5, HIGH);
    }
  else if(cont1 == 6){
    clean1();
    digitalWrite(Ld6, HIGH);
    }
  else if(cont1 == 7){
    clean1();
    digitalWrite(Ld7, HIGH);
    }
  else if(cont1 == 8){
    clean1();
    digitalWrite(Ld8, HIGH);
    }
  else if(cont1 == 9){
    clean1();
    clean2();
    digitalWrite(P1, HIGH);
    flag = 3;
  }

  if(cont2 == 1){
    clean2();
    digitalWrite(Ld9, HIGH);
    }
  else if(cont2 == 2){
    clean2();
    digitalWrite(Ld10, HIGH);
    }
  else if(cont2 == 3){
    clean2();
    digitalWrite(Ld11, HIGH);
    }
  else if(cont2 == 4){
    clean2();
    digitalWrite(Ld12, HIGH);
    }
  else if(cont2 == 5){
    clean2();
    digitalWrite(Ld13, HIGH);
    }
  else if(cont2 == 6){
    clean2();
    digitalWrite(Ld14, HIGH);
    }
  else if(cont2 == 7){
    clean2();
    digitalWrite(Ld15, HIGH);
    }
  else if(cont2 == 8){
    clean2();
    digitalWrite(Ld16, HIGH);
    }
  else if(cont2 == 9){
    clean1();
    clean2();
    digitalWrite(P2, HIGH);
    flag = 3;
}
}

void clean1(){
          digitalWrite(Ld1, LOW);
          digitalWrite(Ld2, LOW);
          digitalWrite(Ld3, LOW);
          digitalWrite(Ld4, LOW);
          digitalWrite(Ld5, LOW);
          digitalWrite(Ld6, LOW);
          digitalWrite(Ld7, LOW);
          digitalWrite(Ld8, LOW);
}

void clean2(){
          digitalWrite(Ld9, LOW);
          digitalWrite(Ld10, LOW);
          digitalWrite(Ld11, LOW);
          digitalWrite(Ld12, LOW);
          digitalWrite(Ld13, LOW);
          digitalWrite(Ld14, LOW);
          digitalWrite(Ld15, LOW);
          digitalWrite(Ld16, LOW);
}


void button1(){
  if(flag != 2 || flag != 3){
     flag = 1; 
    }
    if(flag == 2){
      cont1++;
      delay(100);
      }
}

void button2(){
  if(flag != 2 || flag != 3){
     flag = 1; 
    }
    if(flag == 2){
      cont2++;
      delay(100);
      }
}
