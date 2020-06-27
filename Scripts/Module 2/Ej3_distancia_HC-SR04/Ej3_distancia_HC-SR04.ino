/* Curso básico de Arduino Módulo 2 -  Ejemplo 3: Distancia con HC-SR04
    Julián Andrés Castro
    Universidad Nacional de Colombia
    CEIMTUN -  RAS, IEEE

   Este código de ejemplo está en el dominio público.
   Imprime la distancia leída por un sensor ultrasónico en
   centímetros. Son compatibles con cuatro sensor HC-SC04
   de ultrasonido de 4 pines y de 3 pines (Menos común).

   El circuito:
   Módulo HR-SC04 (4 pines), va conectado a los siguientes
   pines digitales de la siguiente manera:
   ---------------------
   | HC-SC04 | Arduino |
   ---------------------
   |   Vcc   |   5V    |
   |   Trig  |   12    |
   |   Echo  |   13    |
   |   Gnd   |   GND   |
   ---------------------
   Este código de ejemplo se publica con licencia MIT.
*/

// Variables globales
const int pinTrig = 12;                 // Pin de disparo del ultrasonido
const int pinEco = 13;
const long tiempoEspera = 30000;        // (30ms = 5m)~(3ms = 50cm)
int distancia;                          // Pin de recepción del eco

void setup() {
  pinMode(pinTrig, OUTPUT);
  pinMode(pinEco, INPUT);
  Serial.begin(9600);                   // Inicializa comunicación serial a 9600 bps
}

void loop() {
  distancia = medirDistancia();         // Mide la distancia en cm

  Serial.print("Distancia: ");
  Serial.print(distancia);              // Visualización en monitor serie
  Serial.println(" cm");
  delay(500);
}

long medirDistancia() {
  long tiempoPulso, distancia_cm;
  digitalWrite(pinTrig, LOW);           // Limpiar el disparador
  delayMicroseconds(4);
  digitalWrite(pinTrig, HIGH);
  delayMicroseconds(10);                // Tiempo del disparo 10 mS
  digitalWrite(pinTrig, LOW);
  //tiempoPulso = pulseIn(pinEco, HIGH, tiempoEspera);
  tiempoPulso = pulseIn(pinEco, HIGH);  // Lee la duración de un pulso
  if ( tiempoPulso == 0 ) {
    tiempoPulso = tiempoEspera;
  }
  /* La velocidad del sonido es de 340 m/s (29 uS/cm)
     Dividimos el tiempo del pulso entre 2*58, tiempo que tarda
     en recorrer ida y vuelta un centimetro la onda sonora.
  */
  distancia_cm = tiempoPulso / 29 / 2;   // Calcula la distancia
  return distancia_cm;
}
