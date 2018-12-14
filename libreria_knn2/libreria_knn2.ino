#include <knn.h>

/*
  numero de filas de la matriz de entrenamiento  I = 120
  numero de columnas de la matriz de entrenamiento = 5
  k-vecinos = 1,3,5,7
  numero de etiquetas matriz entrenamiento = 3 -> tipo float
  vector de nuevos datos  = 4 datos -> ancho y largo del sépalo ; ancho y largo del pétalo
*/
float vector[30][5]={
{5.1,3.5,1.4,0.2,1},
{4.9,3,1.4,0.2,1},
{4.7,3.2,1.3,0.2,1},
{4.6,3.1,1.5,0.2,1},
{5,3.6,1.4,0.2,1},
{5.4,3.9,1.7,0.4,1},
{4.6,3.4,1.4,0.3,1},
{5,3.4,1.5,0.2,1},
{4.4,2.9,1.4,0.2,1},
{4.9,3.1,1.5,0.1,1},
{7,3.2,4.7,1.4,2},
{6.4,3.2,4.5,1.5,2},
{6.9,3.1,4.9,1.5,2},
{5.5,2.3,4,1.3,2},
{6.5,2.8,4.6,1.5,2},
{5.7,2.8,4.5,1.3,2},
{6.3,3.3,4.7,1.6,2},
{4.9,2.4,3.3,1,2},
{6.6,2.9,4.6,1.3,2},
{5.2,2.7,3.9,1.4,2},
{6.3,3.3,6,2.5,3},
{5.8,2.7,5.1,1.9,3},
{7.1,3,5.9,2.1,3},
{6.3,2.9,5.6,1.8,3},
{6.5,3,5.8,2.2,3},
{7.6,3,6.6,2.1,3},
{4.9,2.5,4.5,1.7,3},
{7.3,2.9,6.3,1.8,3},
{6.7,2.5,5.8,1.8,3},
{7.2,3.6,6.1,2.5,3}};
int on=0;
int ac=0;
int fall=0;
float result;
int total=0;
void setup() {
  Serial.begin(9600);
  
}
void loop() {
  
if(on==0){
  for(int i=0;i<=29;i++){
    result=knn(5,5,3,3,vector[i]);
    if(result==vector[i][4]){
      ac++;}else{fall++;}
    }
    
    Serial.println("aciertos");
    Serial.println(ac); 
    Serial.println("fallas");
    Serial.println(fall); 
    total = (ac*100)/30;
    Serial.println("% aciertos");
    Serial.println(total); 
    on=1;
  }
 

}
