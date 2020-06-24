/*
    Curso básico de Arduino Módulo 1 -  Ejemplo 2: Control PWM
    Julián Andrés Castro
    Universidad Nacional de Colombia
    CEIMTUN -  RAS, IEEE
  
  Este código de ejemplo está en el dominio público.
  https://www.arduino.cc/en/Tutorial/HomePage
  
  --------------------------------------------
  Enciende/Apaga un LED de forma proporcional.
  
  Este ejemplo muestra cómo atenuar un LED en el pin 9
  usando la función analogWrite ().
  La función analogWrite () usa PWM, así que si
  desea cambiar el pin que está utilizando, asegúrese de
  use otro pin compatible con PWM. En la mayoría de Arduino,
  los pines PWM se identifican con un signo "~",
  como ~ 3, ~ 5, ~ 6, ~ 9, ~ 10 y ~ 11.
  --------------------------------------------
*/


// Declara puertos de entrada/salida y variables

int brillo = 0;
int variacion = 5; // Incremento configurado de 5 en 5
int LED = 9;       // Pin donde se encuentra el LED, salida PWM("~")

// Función de configuración
void setup() {
  // put your setup code here, to run once:
  pinMode(LED, OUTPUT); // Configura el pin LED como una salida
}

void loop() {
  // put your main code here, to run repeatedly:

  analogWrite(LED, brillo); // Escritura análoga (PWM) en el pin LED

  brillo = brillo + variacion;
  if (brillo == 0 || brillo == 255) // Si el brillo es 0 o 255
    variacion = -variacion; 		// Se invierte el sentido de la variación
  delay(30);                		// Tiempo de incremento en el brillo
}
