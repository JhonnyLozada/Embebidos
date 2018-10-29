/*
   programa para manejo de LCD
*/

#include <LiquidCrystal.h>
//inicializar LCD
LiquidCrystal lcd (13, 12, 11, 10, 9, 8); //RS,E,D4,D5,D6,D7
char vector [] = {'C', 'I', 'E', 'R', 'C', 'O', 'M'}; //vector de juego
int i = 0; //variable de recorrido del vector
int j = 6;
int on; //encendido del sistema
void setup() {
  lcd.begin(16, 2); //definir forma de trabajo de la matriz
  attachInterrupt(0, encender, LOW);
}

void loop() {
  if (on == 1) {
    lcd.setCursor(0, 1);
    lcd.print(analogRead(0));
    for (; i < 7; i++) {
      lcd.setCursor (i, 0);
      lcd.print(vector[i]);
      delay (100);
      lcd.setCursor(i, 0);
      lcd.print (' ');
      delay(100);
    }
    for (; j > 0; j--) {
      lcd.setCursor (j, 0);
      lcd.print(vector[j]);
      delay (100);
      lcd.setCursor(j, 0);
      lcd.print (' ');
      delay(100);
    }
    i = 0;
    j = 6;

  }
  else
    lcd.clear();


}




void encender () {
  on = 1 - on;
}


