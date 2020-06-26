char estado;

void setup() {
  Serial.begin(9600);
}

void loop() {
  if (Serial.available() > 0) { // lee el bluetooth y almacena en estado
    estado = Serial.read();
    Serial.println(estado);
  }

}
