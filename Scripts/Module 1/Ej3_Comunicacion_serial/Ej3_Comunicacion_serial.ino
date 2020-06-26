/*
  Curso básico de Arduino Módulo 1 -  Ejemplo 3: COMUNICACIÓN SERIAL
    Julián Andrés Castro
    Universidad Nacional de Colombia
    CEIMTUN -  RAS, IEEE
	
	Este código de ejemplo está en el dominio público.
    https://www.arduino.cc/en/Tutorial/HomePage
	
	-------------------
	ESCRITURA SERIAL
	-------------------
*/
// Declara puertos de salida/entrada y variables
int pinLED = 13;              // Pin donde se encuentra conectado el LED
char leer;                 // Variable donde se almacena un caracter
boolean encendido = false; // Estado de inicio del LED (Apagado)

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);   // Inicia comunicación serial (Puerto USB, Pines Rx-Tx)
  pinMode(pinLED, OUTPUT); // Configura el pin LED como una salida
}

void loop() {
  // put your main code here, to run repeatedly:
  leer = Serial.read(); // Captura un caracter en el puerto serial

  // Si se recibe la letra 'a' y además el LED está apagado
  if ((leer == 'a') && (encendido == false)) {
    digitalWrite(pinLED, HIGH);    // Enciende el LED
    Serial.println("LED ON");   // Escribe en pantalla el texto
    encendido = true;           // Actualiza el estado del LED
  }

  // Si se recibe la letra 'a' y además el LED está encendido
  else if ((leer == 'a') && (encendido == true)) {
    digitalWrite(pinLED, LOW);     // Apaga el LED
    Serial.println("LED OFF");  // Escribe en pantalla el texto
    encendido = false;          // Actualiza el estado del LED
  }
}
