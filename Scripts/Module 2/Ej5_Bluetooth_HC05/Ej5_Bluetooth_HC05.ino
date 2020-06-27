/*
  Curso básico de Arduino Módulo 2 -  Ejemplo 4: Bluetooth (Control motor)
    Julián Andrés Castro
    Universidad Nacional de Colombia
    CEIMTUN -  RAS, IEEE

  Este código de ejemplo está en el dominio público.
  https://www.arduino.cc/en/Tutorial/HomePage

  ------------------------
  BLUETOOTH (CONTROL DE MOTOR)
  ------------------------
*/

int IN3 = 5;    // Input3 conectada al pin 5
int IN4 = 4;    // Input4 conectada al pin 4
int ENB = 3;    // ENB conectada al pin 3 de Arduino
char leer;    // Variable para almacenar dato bluetooth

void setup() {
  Serial.begin(9600); // Inia comunicación serial
  pinMode (ENB, OUTPUT);
  pinMode (IN3, OUTPUT);
  pinMode (IN4, OUTPUT);

}

void loop() {
  if (Serial.available() > 0) { // lee el bluetooth y almacena en estado
    leer = Serial.read();
  }

  //Preparamos la salida para que el motor gire en un sentido
  digitalWrite (IN3, HIGH);
  digitalWrite (IN4, LOW);


  // Si se recibe la letra 'a' motor con V 55
  if (leer == 'a') {
    // Aplicamos PWM al pin ENB, haciendo girar el motor, cada 2 seg aumenta la velocidad
    analogWrite(ENB, 55);
    Serial.print("Velocidad PWM: ");
    Serial.println(55);
  }

  // Si se recibe la letra 'b' motor con V 105
  else if (leer == 'b') {
    analogWrite(ENB, 105);
    Serial.print("Velocidad PWM: ");
    Serial.println(105);
  }

  // Si se recibe la letra 'c' motor con V 255(Maxima)
  else if (leer == 'c') {
    analogWrite(ENB, 255);
    Serial.print("Velocidad Maxima: ");
    Serial.println(255);
  }
}
