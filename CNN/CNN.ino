#include "datos_silla.h"
// definición de matrices de CNN
float matriz_s [60][5]; // datos válidos
float matriz_d [308][5]; // datos de desecho
int col = 0; // variable de recorrido de columnas
int fil = 0; // variable de recorrido de filas
int col_s = 0; // variable para matriz s
int fil_s = 0; // variable para matriz s
float promedio; // variable de promedio
float sumatoria = 0;
int etiqueta = 1;
int i = 0;
float distancia = 0;
float distancia_total;
float dist_mayor = 2000;
float label = 0;
void setup() {
  Serial.begin(9600);
  for (; etiqueta < 4; etiqueta++) {
    for (; col < 4; col++) {
      for (fil = i; fil < 30 * etiqueta; fil++) {
        sumatoria = sumatoria + matriz[fil][col];
      }
      promedio = sumatoria / 30;
      matriz_s[etiqueta - 1][col] = promedio; // almacenar promedios en matriz s
      Serial.println(promedio);
      sumatoria = 0;
      fil = 0;
    }
    col = 0;
    i = 30 * etiqueta;
  }
  col = 0;
  fil = 0;
  for (; fil < 3; fil++) {
    matriz_s[fil][4] = fil + 1; //llenar etiquetas en matriz s
    //    for(;col<4;col++){
    //      Serial.print(matriz_s[fil][col]);
    //      Serial.print(',');
    //    }
    //    Serial.println(' ');
    //    col=0;
    //
  }
  fil = 0;
}

void loop() {
  for (; fil < 308; fil++) {
    for (; fil_s < 3; fil_s++) {

      for (; col_s < 4; col_s++) {
        distancia = distancia + pow(matriz[fil][col_s] - matriz_s[fil_s][col_s], 2);
      }

      distancia_total = sqrt(distancia);
      if (distancia_total < dist_mayor) {
        dist_mayor = distancia_total;
        label = matriz_s[fil_s][4];
      } // endif
      distancia = 0;
      col_s = 0;
    } //end for de fil_s
    fil_s = 0;
    dist_mayor = 2000;

    if (label == matriz[fil][4]) {
      Serial.print(fil);
      Serial.print(':');
      Serial.println('D');
    }
    else {
      Serial.print(fil);
      Serial.print(':');
      Serial.println('S');
    }

  }


}
