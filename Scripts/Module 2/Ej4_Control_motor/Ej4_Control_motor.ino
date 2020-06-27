/*
  Curso básico de Arduino Módulo 2 -  Ejemplo 4: Control motor con L298N
    Julián Andrés Castro
    Universidad Nacional de Colombia
    CEIMTUN -  RAS, IEEE

  Este código de ejemplo está en el dominio público.
  https://www.arduino.cc/en/Tutorial/HomePage

  ------------------------
  CONTROL DE MOTOR
  ------------------------
*/

int IN3 = 5;    // Input3 conectada al pin 5
int IN4 = 4;    // Input4 conectada al pin 4
int ENB = 3;    // ENB conectada al pin 3 de Arduino
void setup() {
  Serial.begin(9600); // Inia comunicación serial
  pinMode (ENB, OUTPUT);
  pinMode (IN3, OUTPUT);
  pinMode (IN4, OUTPUT);

}
void loop() {
  //Preparamos la salida para que el motor gire en un sentido
  digitalWrite (IN3, HIGH);
  digitalWrite (IN4, LOW);
  // Aplicamos PWM al pin ENB, haciendo girar el motor, cada 2 seg aumenta la velocidad
  analogWrite(ENB, 55);
  Serial.print("Velocidad PWM: ");
  Serial.println(55);
  delay(2000);
  analogWrite(ENB, 105);
  Serial.print("Velocidad PWM: ");
  Serial.println(105);
  delay(2000);
  analogWrite(ENB, 255);
  Serial.print("Velocidad PWM: ");
  Serial.println(255);
  delay(2000);
  
  // Apagamos el motor y esperamos 5 seg
  analogWrite(ENB, 0);
  delay(5000);
}
