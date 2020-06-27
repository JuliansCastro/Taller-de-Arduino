/*
  Curso básico de Arduino Módulo 2 -  Ejemplo 2: Luz con LDR
    Julián Andrés Castro
    Universidad Nacional de Colombia
    CEIMTUN -  RAS, IEEE

  Este código de ejemplo está en el dominio público.
  https://www.arduino.cc/en/Tutorial/HomePage

  ------------------------
  INTERRUPTOR CON LUZ Y LDR
  ------------------------
*/

int pinLedG = 2;                  // Pin conecta led Verde
int pinLedY = 3;                  // Pin conecta led Amarillo
int pinLedR = 4;                  // Pin conecta led Rojo

int pinLDR = A5;                  // Pin analógico entrada del LDR
int valorLDR = 0;                 // Almacena el valor del LDR
float voltajeLDR = 0.0;           // Almacena el valor del voltaje del LDR

void setup()
{
  pinMode(pinLedR, OUTPUT);       // Configura como salida el pin del led
  pinMode(pinLedY, OUTPUT);
  pinMode(pinLedG, OUTPUT);

  Serial.begin(9600);             //  Configura el puerto serial
}

void loop()
{
  digitalWrite(pinLedR, LOW);     // Apaga el led R al iniciar el ciclo
  digitalWrite(pinLedY, LOW);
  digitalWrite(pinLedG, LOW);

  valorLDR = analogRead(pinLDR);  // Lee el valor de voltaje del LDR
  voltajeLDR = valorLDR * 5.0 / 1024.0;

  Serial.print(valorLDR);
  Serial.print(" ADC ");
  Serial.print(voltajeLDR);       // Voltaje leído en el monitor serial
  Serial.println(" V");

  // Encender los leds de acuerdo al valor de ADC
  if (valorLDR > 256.0) {
    digitalWrite(pinLedR, HIGH);
  }
  if (valorLDR > 612.0) {
    digitalWrite(pinLedY, HIGH);
  }
  if (valorLDR > 850.0) {
    digitalWrite(pinLedG, HIGH);
  }
  delay(200); // Esperar 200 milisegundos antes de actualizar
}
