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

//Leds ganadoras
const int P1 = 36;
const int P2 = 37;

//Variables del programa
int cont1 = 0;
int cont2 = 0;
int flag = 0;
volatile byte state = LOW;

void setup() {
 //Definir entradas y salidas
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

  //Definir interrupciones
  attachInterrupt(digitalPinToInterrupt(SW1), button1, RISING);
  attachInterrupt(digitalPinToInterrupt(SW2), button2, RISING);
  
}

void loop() {

  //Bandera para que comience la secuencia del semáforo
  if (flag == 1){
    clean1();
    clean2();
    digitalWrite(LED1, HIGH);
    delay(1000);
    digitalWrite(LED3, HIGH);
    delay(1000);
    digitalWrite(LED1, LOW);
    digitalWrite(LED3, HIGH);
    delay(1000);
    digitalWrite(LED3, LOW);
    flag = 2;
  }

  //Determina que led del jugador 1 debe prenderse
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
    clean1(); //Apagar las leds
    digitalWrite(Ld8, HIGH);
    digitalWrite(P1, HIGH); //Encender la led ganadora del jugador 1
    clean2(); //Se apagan todas las leds
    digitalWrite(Ld8, LOW);
    flag = 3; //No se permite que ningún jugador siga incrementando el contador
  }

  //Determina que led del jugador 2 debe prenderse
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
    clean2(); //Apagar las leds
    digitalWrite(Ld16, HIGH); 
    digitalWrite(P2, HIGH); //Se enciende la led ganadora del jugador 2
    clean1(); //Se apagan las demás leds
    digitalWrite(Ld16, LOW);
    flag = 3; //No se permite que ningún jugador siga incrementando el contador
}
}

void clean1(){ //Rutina para apagar las leds del jugador 1
          digitalWrite(Ld1, LOW);
          digitalWrite(Ld2, LOW);
          digitalWrite(Ld3, LOW);
          digitalWrite(Ld4, LOW);
          digitalWrite(Ld5, LOW);
          digitalWrite(Ld6, LOW);
          digitalWrite(Ld7, LOW);
          digitalWrite(Ld8, LOW);
}

void clean2(){ //Rutina para apagar las leds del jugador 2
          digitalWrite(Ld9, LOW);
          digitalWrite(Ld10, LOW);
          digitalWrite(Ld11, LOW);
          digitalWrite(Ld12, LOW);
          digitalWrite(Ld13, LOW);
          digitalWrite(Ld14, LOW);
          digitalWrite(Ld15, LOW);
          digitalWrite(Ld16, LOW);
}


void button1(){ //Rutina de interrupción para el jugador 1
  if(flag == 0){
     flag = 1; //Se ejecuta la rutina del semáforo
    }
  if(flag == 2){
    cont1++; //Se incrementa el contador 1
    delay(100);
    }
}

void button2(){ //Rutina de interrupción para el jugador 2
  if(flag == 0){
     flag = 1; //Se ejecuta la rutina del semáforo
    }
  if(flag == 2){
    cont2++; //Se incrementa el contador 2
    delay(100);
      }
}
