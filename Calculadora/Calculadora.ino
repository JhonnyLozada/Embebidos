/*****************************************
    MI PRIMERA CALCULADORA-Electrotec
*****************************************/

#include <LiquidCrystal.h> // Librería para el control del LCD
#include <Keypad.h> // Librería para el control del keypad

LiquidCrystal lcd(8, 9, 10, 11, 12, 13); // varible LCD y pines
const byte filas = 4; // número de filas '4'
const byte columnas = 4; // número de columans '4'

char teclado [filas][columnas]={
{'1','2','3','+'},
{'4','5','6','-'},
{'7','8','9','x'},
{'*','0','=','/'}
}; //variable teclado

byte filaPines[filas]={0,1,2,3}; //configuración de filas
byte columnaPines[columnas]={4,5,6,70}; // configuración de columnas

Keypad calcu = Keypad (makeKeymap(teclado),filaPines, columnaPines, filas, columnas);

boolean inicio = false; 
boolean final = false; // variables de control

String num1, num2;
int ans;
char op;

void setup()
{
  lcd.begin(16,2);
  lcd.setCursor(0,0);
  lcd.print("Hola Mundo"); //Prendido de pantalla
  delay (2500);
  lcd.clear();
}

void loop()
{
  char key = calcu.getKey();
  
  if (key != NO_KEY && (key=='1' || key=='2' || key=='3' || key=='4' || key=='5' || key=='6' || key=='7' || key=='8' || key=='9' || key=='0'))
  {
    if(inicio == false)
      {num1 = num1 + key;
      int numLength = num1.length();
      lcd.setCursor(15-numLength,0);
      lcd.print(num1); 
  }
     else
     {num2 = num2 + key;
      int numLength = num2.length();
      lcd.setCursor(15-numLength,1);
      lcd.print(num2);
      final = true;
  }
}
if (inicio == false && key != NO_KEY && (key == '+' || key == '-' || key == 'x' || key == '/'))

{inicio = true;
 op = key;
 lcd.setCursor(15,0);
 lcd.print (op); 

}
if (final == true && key !=NO_KEY && key == '=')
{
    if (op == '+')
    {ans= num1.toInt() + num2.toInt();}
    if (op == '-')
    {ans= num1.toInt() - num2.toInt();}
    if (op == 'x')
    {ans= num1.toInt() * num2.toInt();}
    if (op == '/')
    {ans= num1.toInt() / num2.toInt();}
    
    lcd.clear();
    lcd.setCursor(15,0);
    lcd.autoscroll();
    lcd.print(ans);
    lcd.noAutoscroll();    
}
if(key !=NO_KEY && key == '*')
{
  lcd.clear();
  inicio = false;
  final = false;
  num1 = "";
  num2 = "";
  ans = 0;
  op = ' ';
}
}

