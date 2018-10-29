//Libreriras 
#include <TimerOne.h> // libreria de Timer1
#include <avr/sleep.h>
#include <avr/power.h>
#include <LiquidCrystal.h>
//Variables

const int rs = 13, en = 12, d4 = 11, d5 = 10, d6 = 9, d7 = 8;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);


boolean StadoS=false;                    // Estado Sistema

int cont=0;                              //Contador de T Sistema
int t1=0;
int t2=0;
int t3=0;

// Contador luz1
int luz1=0;
// Contador luz2
int luz2=0;
// Contador luz3
int luz3=0;



void setup() {
 
   Serial.begin(9600);                //Inicializa Serial
  
  //Timer1 Config 1S
   Timer1.initialize(1000000); 
   //Metodo
   Timer1.attachInterrupt(contador);
   
   //Asignacione Pines Digitales
   pinMode(7,OUTPUT);
   pinMode(6,OUTPUT);
   pinMode(5,OUTPUT);

   //LCD COMIENZO
   lcd.begin(20, 4);
   //genera interfaz
   lcd.setCursor(0,0);
   lcd.print("Tiempo:");
   lcd.setCursor(0,1);
   lcd.print(" #1:");
   lcd.setCursor(0,2);
   lcd.print(" #2:");
   lcd.setCursor(0,3);
   lcd.print(" #3:");

//Damos el valor inicial

   lcd.setCursor(11,1);
         lcd.print("OFF");
   lcd.setCursor(11,2);
         lcd.print("OFF");
   lcd.setCursor(11,3);
         lcd.print("OFF");
}


void loop() {
  
//condiciones primero
      if(cont==10){
        digitalWrite(7,HIGH);
        t1=cont;
        lcd.setCursor(11,1);
         lcd.print("ON");
      }
      if((cont-t1)==10){
         digitalWrite(7,LOW);
         lcd.setCursor(11,1);
         lcd.print("OFF");
      }

//Condiciones Segundo
      if(cont==25){
        digitalWrite(6,HIGH);
        t2=cont;
        lcd.setCursor(11,2);
         lcd.print("ON");
      }
      if((cont-t2)==15){
         digitalWrite(6,LOW);
         lcd.setCursor(11,2);
         lcd.print("OFF");
      }

//Condiciones Tercero
      if(cont==30){
        digitalWrite(5,HIGH);
        t3=cont;
        lcd.setCursor(11,3);
         lcd.print("ON");
      }
      if((cont-t3)==5){
         digitalWrite(5,LOW);
         lcd.setCursor(11,3);
         lcd.print("OFF");
      }
 
}




//Secuencia On/Off
void runtime(){
  StadoS=!StadoS; // varaible de encendido del sistema
  if(StadoS==true){
     Serial.println("SISTEMA ON");
    }
  else{
     Serial.println("SISTEMA OFF");
     cont=0;  
     luz1=0;
     luz2=0;
     luz3=0;

     }
  }

  void contador(){ // subrutina de timer1
  if(StadoS==true){
    cont++;    // varaible se incrementa de 1 en 1
    lcd.setCursor(8,0);
    lcd.print(cont);
    Serial.println(cont);
  }
}
