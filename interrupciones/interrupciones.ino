#include <TimerOne.h>
#include <avr/sleep.h>
#include <avr/power.h>


/*
    Interrupciones
    Arduino UNO tiene 2 interrupciones
    INT0-> pin 2
    INT1 -> pin3
    configuración
    attachInterrupt(interrupcion, metodo , tipo)
                    digitalToPinInterrupt(Interrupcion),  , LOW , RISING, FALLING)

   TimerOne
   contadores
   configuración
   -> añadir la libreria
   -> Timer1.initialize(periodo)
   -> Timer1.attachInterrupt(metodo);
   ->Timer1.start
   ->Timer1.stop
   ->Timer1.rsstart
   ->Timer.resume()

   MODO SLEEP
   Ahorro de la batería
   configurar
   -> librerías -> avr/sleep.h
   ->              avr/power.h
   set_sleep_mode()=indicar el modo de funcionamiento
    modos -> SLEEP_MODLE_IDLE, SLEEP_MODE_ADC , SLEEP_MODE_PWR_SAVE
             SLEEP_MODE_PWR_DOWN

    sleep_mode() = entrar el modod configurado
    sleep_disable()= salir del modo sleep configurado, el programa inicia esa función
    sleep_enable = habilitar modos sleep
*/
int on = 0;
int cont;
int config_t1 = 0; // variable para configurar timer1
void setup() {
  attachInterrupt(digitalPinToInterrupt (2), encendido, LOW); //configuración de int0
  attachInterrupt(digitalPinToInterrupt (3), config_timer, LOW); //configuración de TImer
  Timer1.initialize(1000000); //timer1 a 1 seg
  Timer1.attachInterrupt(contador);//metodo de timer
  set_sleep_mode(SLEEP_MODE_PWR_DOWN); // configuración sistema de ahorro de batería
  sleep_enable(); //habilita config sleep
  Serial.begin(9600);//habilital comunicación serial

}

void loop() {


}
// metodo de interrupcion
void encendido() {
  on = 1 - on;
  if (on == 1)
    Serial.println("Sistema ON");
  else {
    Serial.println("Sistema OFF");
    cont = 0 ;
    delay(200);
    sleep_mode(); // duerme el sistema

  }
}

void contador () {
  if (on == 1) {
    cont ++;
    Serial.println(cont);
  }
}

void config_timer() {
  switch (config_t1) {
    case 0:
      Serial.println("T1 STOP");
      Timer1.stop();
      config_t1++;
      break;
    case 1:
      Serial.println("T1 START");
      Timer1.start();
      config_t1++;
      break;



  }
}

