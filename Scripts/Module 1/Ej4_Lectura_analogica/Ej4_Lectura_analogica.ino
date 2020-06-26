/*
  Curso básico de Arduino Módulo 1 -  Ejemplo 4: Lectura analógica
    Julián Andrés Castro
    Universidad Nacional de Colombia
    CEIMTUN -  RAS, IEEE
	
	Este código de ejemplo está en el dominio público.
    https://www.arduino.cc/en/Tutorial/HomePage
	
	-----------------------------
	Control ON/OFF potenciómetro
	-----------------------------
*/

int pinLED = 13;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);   // Inicia comunicación serial a 9600 baudios
  pinMode(pinLED, OUTPUT); // Configura el pin 13 como una salida
}

void loop() {
  // Guardar en una variable el valor de la lectura del puerto análogo
  int valor = analogRead(A0);
  double voltaje = valor * 5 / 1023;
  Serial.print(valor); // Imprime el valor por la consola serial
  Serial.print(" ");
  Serial.println(voltaje);

  // Si el valor es mayor o igual a 500
  if (valor >= 500) {
    digitalWrite(pinLED, HIGH); // Enciende el LED
  } // Si el valor es menor a 500
  else {
    digitalWrite(pinLED, LOW); // Apaga el LED
  }
  delay(100); // Retardo de 100ms para ver los datos de la consola
}
