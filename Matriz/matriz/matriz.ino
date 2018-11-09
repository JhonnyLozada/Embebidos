int matrizDatos[10][4]= { {3,5,-6,7}, {3,8,6,17}, {2,-4,4,27}, {2,4,8,10}, {2,4,-2,5}, {4,5,6,7}, {5,-8,6,-7}, {1,5,16,8}, {0,5,12,7}, {4,5,16,7}};  //Declaro la matriz
int valorMax = 0; //inicio con el valor minimo que pueden tener los elementos de la matriz
int valorMin = 40; //inicio con el valor maximo que pueden tener los elementos de la matriz
int elementoMin, elementoMax; // para almacenar los indices
int suma = 0;
int suma1 = 0;
int suma2 = 0;
int suma3 = 0;
int y=0;
int y1=0;
int y2=0;
int y3=0;
void setup() {
  Serial.begin(9600); //Inicio el monitor serie a 9600 baudios
  Serial.println("Los valores de la matriz son:");
  for (int x = 0; x < 10; x++) {
      for (int z = 0; z < 4; z++) { //Asigno valores aleatorios a los elementos de la matriz
      Serial.print(x, z);  //imprimo el contenido de cada elemento de la matriz
      Serial.print(" Valor: ");
      Serial.println(matrizDatos[x][z]);
    }
  }
   for (int h = 0; h < 10; h++) {
     suma = suma + matrizDatos[h][0];
     suma1 += matrizDatos[h][0];
     suma2 += matrizDatos[h][0];
     suma3 = suma3 + matrizDatos[h][0];
        
     }
     Serial.print("El valor promedio col 0: ");
     Serial.println(suma/10); 
//     y = suma/10;
//     y1 = suma1/10;
//     y2 = suma2/10;
//     y3 = suma3/10;
//  y = prom;
//  suma1 = prom;
//  suma2 = prom;
//  suma3 = prom;
//  
  // Este el algoritmo de minimos y maximos
  for (int i = 0; i < 10; i++) { //se evalua cada elemento de la matriz
    for (int j = 0; j < 4; j++) {
      // Guarda el valor maximo en matriz
      if (matrizDatos[i][j] > valorMax) {
        valorMax = matrizDatos[i][j]; // si es mayor guardo el valor y el indice del elemento de la matriz
        elementoMax = i ,j;
      }
      // Guarda el valor minimo en matriz
      if (matrizDatos[i][j] < valorMin) {
        valorMin = matrizDatos[i][j]; // si es menor guardo el valor y el indice del elemento de la matriz
        elementoMin = i, j;
      }
    }
  }
//   Serial.print("El valor promedio col 0: ");
//   Serial.println(y); 
//    Serial.print("El valor promedio col 1: ");
//    Serial.println(y1);
//     Serial.print("El valor promedio col 2: ");
//   Serial.println(y2); 
//   Serial.print("El valor promedio col 3: ");
//   Serial.println(y3);
    // Imprimo el resultado para el maximo
  
  Serial.print("El valor maximo es: ");
  Serial.print(valorMax);
  Serial.print(" y es el elemento: ");
  Serial.print(elementoMax);
  Serial.println(" de la matriz");
  // Imprimo el resultado para el minimo
  Serial.print("El valor minimo es: ");
  Serial.print(valorMin);
  Serial.print(" y es el elemento: ");
  Serial.print(elementoMin);
  Serial.println(" de la matriz");

}

void loop() {

}



//int prom (){
// // Para el promedio de cada columna
//  for (byte h = 0; h < 10; h++) {
//     suma += matrizDatos[h][0];
//     suma1 += matrizDatos[h][0];
//     suma2 += matrizDatos[h][0];
//     suma3 += matrizDatos[h][0];
//        
//     }
//     y = suma/10;
    
//       
//
//     suma1 = matrizDatos[10][1];
//     y1 = suma/10;
//     return y1;
//
//     suma2 = matrizDatos[10][2];
//     y2 = suma/10;
//     return y2;
//
//     suma3 = matrizDatos[10][3];
//     y3 = suma/10;
//     return y3;
       
    
//}
