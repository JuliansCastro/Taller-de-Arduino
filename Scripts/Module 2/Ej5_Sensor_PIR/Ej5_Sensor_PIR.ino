/*
  Curso básico de Arduino Módulo 2 -  Ejemplo 5: Sensor PIR
    Julián Andrés Castro
    Universidad Nacional de Colombia
    CEIMTUN -  RAS, IEEE

  Este código de ejemplo está en el dominio público.
  https://www.arduino.cc/en/Tutorial/HomePage

  ------------------------
  SENSOR PIR
  ------------------------
*/
//Declaramos pines 
int sensorpir = 12;
int led = 13;
//----

void setup()
{
  //Asignamos las entradas y salidas
  pinMode(sensorpir,INPUT);
  pinMode(led,OUTPUT);
  Serial.begin(9600);
  digitalWrite(led,LOW);
}


void loop()
{
   
  digitalWrite(led,LOW);
  Serial.println(sensorpir);//El valor del sensor 
  if(digitalRead(sensorpir) == HIGH)//Cuando el sensor detecte algun movimiento entrara al if
  {//Dentro del if lo que pasará es que el sensor pir detectó movimento y el led parpadeara hasta que deje de detectar movimiento
    Serial.println("Detectado movimiento por el sensor pir");
    digitalWrite(led,HIGH);
    delay(1000);
    digitalWrite(led,LOW);
  }
  
}
