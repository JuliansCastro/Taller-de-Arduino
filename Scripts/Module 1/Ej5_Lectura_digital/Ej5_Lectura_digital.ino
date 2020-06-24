/*
  Curso básico de Arduino Módulo 1 -  Ejemplo 5: Lectura digital
    Julián Andrés Castro
    Universidad Nacional de Colombia
    CEIMTUN -  RAS, IEEE

    Este código de ejemplo está en el dominio público.
    https://www.arduino.cc/en/Tutorial/HomePage
	
    Enciende y apaga un diodo emisor de luz (LED)
    conectado al pin digital 13, al presionar un
    pulsador conectado al pin 2.

    El circuito:
    LED conectado desde el pin 13 y a tierra
    pulsador conectado al pin 2 desde + 5V
    Resistencia de 10K conectada al pin 2 desde tierra
    Nota: en la mayoría de los Arduinos ya hay un LED
    en el tablero unido al pin 13.
	
	--------------------
	CONTADOR DE PULSOS
	--------------------
*/

// Declara puertos de entrada/salida y variables
int LED = 13;     // Pin para el LED
int PULSADOR = 2; // Pin para el pulsador
int contador = 0; // Guarda el conteo de los pulsos

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);       // Inicializa la comunicación serial
  pinMode(PULSADOR, INPUT); // Configura el pin 2 como entrada para el pulsador
  pinMode(LED, OUTPUT);     // Configura el pin 13 como salida para el LED
}

void loop() {
  // put your main code here, to run repeatedly:

  // Si el pulsador está oprimido
  if (digitalRead(PULSADOR) == HIGH) {
    // Si el pulsador deja de oprimirse, flanco de bajada
    if (digitalRead(PULSADOR) == LOW) {
      contador++;               // Incrementa en 1 el contador
      Serial.println(contador); // Imprime el valor en la consola serial
      delay(50);               // Espera 100ms
    }
  }

  // Si el valor del contador es 5
  if (contador == 5) {
    digitalWrite(LED, HIGH); // Enciende el LED
  } // Si el valor del contador es 8
  if (contador == 8) {
    digitalWrite(LED, LOW);  // Apaga el LED
  }
}
