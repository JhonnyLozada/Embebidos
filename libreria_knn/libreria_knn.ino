#include"datos_entrenamiento"


/*
  numero de filas de la matriz de entrenamiento  I = 120
  numero de columnas de la matriz de entrenamiento = 5
  k-vecinos = 1,3,5,7
  numero de etiquetas matriz entrenamiento = 3 -> tipo float
  vector de nuevos datos  = 4 datos -> ancho y largo del sépalo ; ancho y largo del pétalo
*/
float vector[4]={5.8,2.7,5.1,1.9}; //1
int on=0;
float result;
void setup() {
  Serial.begin(9600);

}

void loop() {
  if(on==0){
    result=knn(120,5,3,3,vector);
    Serial.println(result);
    on=1;
  }

}
float knn(int fila, int col, int k, int label, float datos[]){
  int c=0; // movernos en columnas
  int f=0; // movernos en filas
  float k_vecinos_dist[k]; //vector de almacenamiento de k distancias menores
  float etiquetas[2][label]; //matriz de etiquetas y de conteo de etiquetas
  float dist=0; //variable que almacena cada distancia
  float dist_total=0; //variable para almacenamiento de distancia
  float eti_menor[k]; // vector de etiquetas de distancia menor 
  int k_cont=0;
  int i=0;
  float clase;                       //retornar etiqueta
  float comparacion;                 // comparar k -vecino mayor
  // llenar vector_k_vecinos_dist valores altos
  for(;c<k;c++){
    k_vecinos_dist[c]=2000+c; //valores altos y ordenados
  }
  c=0; //reiniciar variable
  // llenar matriz etiquetas
  for(;c<label;c++){
    etiquetas[0][c] = c+1;   // lleno con valores de etiquetas
    etiquetas[1][c] = 0;  // lleno con el conteo de etiquetas
  }
  c=0; //reinicio variable
  // distancias más corta del nuevo punto hacia la matriz
  for(;f<fila;f++){
    for(;c<col-1;c++){
      dist = dist + pow((matriz[f][c] - datos[c]),2);           //distancia entre dos puntos             // pow = potencia      
    }
    dist_total= sqrt(dist); //raiz de la formula
    for(;k_cont<k;k_cont++){ // determinar las distancias menores y ordenarlas
      if(dist_total<k_vecinos_dist[k_cont]){
        k_vecinos_dist[k_cont]=dist_total; //asignar nuevo valor a vector de distancias menores
        eti_menor[k_cont]=matriz[f][col-1];  
      }
    }
    k_cont=0;
    dist=0;
    dist_total=0;
    c=0;
  } // for fila
  //seleccion de los k vecinos
  for(;c<label;c++){                              //recorro cada posición de eti_menor y comparo con etiquetas y cuento si son iguales
    for(;k_cont<k;k_cont++){
      if(etiquetas[0][c]==eti_menor[k_cont]){
        i++;
        etiquetas[1][c]=i;
      }
    }
    k_cont=0;
    i=0;
  }
  c=1;
  comparacion = etiquetas[0][0];
  clase = etiquetas[0][0];
  for(;c<label;c++){                    //comparacion entre valores de suma de etiqueta
    if(etiquetas[1][c]>comparacion){  
      clase=etiquetas[0][c];    
      comparacion = etiquetas[1][c];
    }
  }
  comparacion=0;
  c=0;
  return clase;
}




