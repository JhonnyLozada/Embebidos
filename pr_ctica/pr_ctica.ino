/*
   SECCIONES DEL PROGRAMA
   1. INCLUIR LIBRERIAS -> local y global
      local -> include "librería"
      global -> include <librería>
   2. VARIABLES
        tipo de variable + nombre de la variable + valor de la variable
        int i=0;
        int i;
   3. CONFIGURACIÓN -> Seleccionar el tipo de recurso a utilizar
      -> Puerto E/S
      -> Cx serial
      -> CAD
      -> Timer
   4. ciclo infinito
      el sistema funcione en reiteradas ocasiones mientras sea energizado
*/
int i = 0; // variable de conteo
int j = 0;
int k;
int leds [6] = {13, 12, 11, 10, 9, 8}; //inicializo puertos
int sw [4] = {7, 6, 5, 4}; // pines como entrada
void setup() {
  // encender leds
  for (; i < 6; i++) {
    pinMode(leds [i], OUTPUT); //configuración del puerto
    delay (50);
  }
  i = 0;
  for (; i < 6; i++) {
    pinMode(sw [i], INPUT); //configuración del puerto
    delay (50);
  }
  i = 0;

}

void loop() {
  if (digitalRead(sw[0]) == HIGH && digitalRead(sw[1]) == LOW && digitalRead(sw[2]) == LOW)
      juego1() ;
  if (digitalRead(sw[0]) == LOW &&  digitalRead(sw[2]) == LOW && digitalRead(sw[1]) == HIGH)
            juego2() ;
  if (digitalRead(sw[0]) == LOW &&  digitalRead(sw[1]) == LOW && digitalRead(sw[2]) == HIGH)
                  juego3() ;
    }
void juego1() {
  // juego1
  for (; i < 6; i++) {
    digitalWrite (leds[i], HIGH);
    delay (200);
    digitalWrite (leds[i], LOW);
    delay (200);
  }
  i = 0;
}
void juego2() {
  //JUEGO 2
  for (; j < 6; j++) {
    digitalWrite (leds[i], HIGH);
    delay (200);
  }
  for (; j >= 0; j--) {
    digitalWrite (leds[i], LOW);
    delay (200);
  }
}
// juego 3
void juego3() {
  for (; i < 6; i++) {
    k = random (0, 5);
    digitalWrite (leds [k], HIGH);
    delay (200);
    digitalWrite (leds [k], LOW);
    delay (200);
  }
}
