/*
  Curso básico de Arduino Módulo 2 -  Ejemplo 2: Temperatura con LM35
    Julián Andrés Castro
    Universidad Nacional de Colombia
    CEIMTUN -  RAS, IEEE

  Este código de ejemplo está en el dominio público.
    https://www.arduino.cc/en/Tutorial/HomePage

  ------------------------
  MEDICIÓN DE TEMPERATURA
  ------------------------
*/

// Variables globales
float medida, temperaturaC;       // Almacena el valor obtenido del sensor (0 a 1023)
int pinLM35 = A0;                 // Pin de entrada del sensor (A0)
float t_ref = 100.0;              // float t_ref =96.0; //°C

void setup() {
  analogReference(INTERNAL);      // Cambio de referencia entradas analógicas (1.1v)
  Serial.begin(9600);             // Configura el puerto serial a 9600 bps
}

void loop() {
  medida = analogRead(pinLM35);   // analogRead lee el sensor (0-1023)
  temperaturaC = (1.1 * medida * t_ref) / 1024.0; // Calcula la temperatura

//  Serial.print(1.1 * medida / 1024.0); // Envía el dato crudo
//  Serial.print(" mV   ");
  Serial.print(temperaturaC);     // Envía el dato al puerto serial
  Serial.println(" °C");

  delay(1000);                    // Espera 1s para repetir el loop
}
