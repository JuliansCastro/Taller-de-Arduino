/* Curso básico de Arduino Módulo 1 -  Ejemplo 1: Blink
    Julián Andrés Castro
    Universidad Nacional de Colombia
    CEIMTUN -  RAS, IEEE
    El pin digital 13 está conenctado por defecto a una resitencia
    y un LED
	
	Este código de ejemplo está en el dominio público.
    https://www.arduino.cc/en/Tutorial/HomePage
*/

int LED = 13;

void setup()
{
  // Initialize digital Pin LED as an output.
  pinMode(LED, OUTPUT);
}

void loop()
{
  digitalWrite(LED, HIGH); // Turn the LED on (HIGH is the voltage level)
  delay(1000);             // Espera 1000 milisegundos = 1 second
  digitalWrite(LED, LOW);  // Turn the LED off by making the voltage LOW
  delay(1000);             // Espera 1000 milisegundos = 1 second
}
