
#include <LiquidCrystal.h>    // Librería para la LCD

LiquidCrystal lcd(13, 12, 11, 10, 9, 8); //Pines que usamos para el LCD
void setup() {
  Serial.begin(9600); 
  lcd.begin(20,4);               // Iniciamos comunicación serial y podemos ingresar una palabra de máximo 8 caracteres
  lcd.setCursor(0,0);
  
  
}

void loop() {
      
        String string = Serial.readStringUntil(':');
        if(string != ""){
            
            String pos = Serial.readStringUntil('&');
            int int_pos=pos.toInt();
            Serial.println("Pos");
            Serial.println(int_pos);                                 // Ingresamos la palabra que se va a visualizar en el LCD
            Serial.println(string);
            Serial.println(string.length());
             lcd.clear();
             char vector[string.length()] {};
            for(int i=0; i<=(string.length()-1); i++) {              
             vector[i]=string.charAt(i);
                Serial.println(vector[i]);
        }

         for(int i=0; i<=(string.length()-1); i++) {
             vector[i]=string.charAt(i);                          // Desplazamos la palabra a la derecha de la LCD
             lcd.setCursor(i,0);
              lcd.print(vector[i]);
              delay(200);              
        }


           for(int i=(string.length()-1); i>=0; i--) {                //  Rotamos la palabra ingresada
             
             lcd.setCursor(i,0);
              lcd.print(" ");
              delay(200);              
        }



        for(int i=(string.length()-1); i>=0; i--) {                 // Desplazamos la palabra rotada a la izquierda de la LCD
             vector[i]=string.charAt(i);
             lcd.setCursor(i,0);
              lcd.print(vector[i]);
              delay(200);              
        }
        
    }


 
  
}
