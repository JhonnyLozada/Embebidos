#include"datos_entrenamiento.h"
#include"datos_test.h"
int respuestas[100];
int posiciones[100];
int col = 0;
int row = 0;
float distancia;
float dist_menor = 1000;
int tcont = 0;
int res = 0;
int k = 3;
int res1 = 0;
int res2 = 0;
int res3 = 0;
int tval = 40;               // valor de prueba tomado desde datos_test
int runtime = 0;             
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
}

void loop() {

  while (runtime == 0) {

    kn(3);                              // En este apartado controlamos los vecinos más cercanos al punto de referencia llamando al método kn 

    runtime = 1;

    /*
       Lectura de datos
      for(;row<120;row++){ // contador de filas (for lento)
        for(;col<5;col++){ // contador de col (for rapido)
          Serial.print(matriz[row][col]);  // imprime dato de matriz
          Serial.print(',');            // separador de dato
          delay(25);
          }
          col=0;        // reinicio de columna
          Serial.println(' ');   // caracter en blanco de avance de linea
      }
    */
  }
}
void kn(int k) {                                                                  //Declaramos el método para controlar el número de vecinos

  for (; row < 120; row++) { // contador de filas (for lento)
    distancia = sqrt( pow((matriz[row][0] - prueba[tval][0]), 2) +
                      pow((matriz[row][1] - prueba[tval][1]), 2) +
                      pow((matriz[row][2] - prueba[tval][2]), 2) +
                      pow((matriz[row][3] - prueba[tval][3]), 2));
    if (distancia < dist_menor) {

      dist_menor = distancia;
      Serial.println(dist_menor);
      tcont = matriz[row][4];
      Serial.println(tcont);


      respuestas[res] = distancia;
      posiciones[res] = matriz[row][4];
      res++;


      Serial.println("Valores guardados:");
      Serial.println(res);



    }



  }



  for (int i = (res - 1); i >= (res - k); i--) {                 
    Serial.println("Valores vecinos");
    Serial.println(i);
    Serial.println(respuestas[i]);
    Serial.println(posiciones[i]);

    switch (posiciones[i]) {

      case 1:
        Serial.println("Setosa");
        res1++;
        break;
      case 2:
        Serial.println("Versicolor");
        res2++;
        break;
      case 3:
        Serial.println("Virginica");
        res3++;
        break;

    }

  }



}




