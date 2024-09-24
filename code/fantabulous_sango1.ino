// Definindo os pinos
const int sensorTempPin = A0;   // Sensor de temperatura no pino analógico A0
const int motorPin = 9;         // Motor de ventilador no pino digital 9
const int ledPin = 8;           // LED vermelho no pino digital 8
const int buzzerPin = 7;        // Buzina no pino digital 7

void setup() {
  pinMode(motorPin, OUTPUT);    // Definir o pino do motor como saída
  pinMode(ledPin, OUTPUT);      // Definir o pino do LED como saída
  pinMode(buzzerPin, OUTPUT);   // Definir o pino da buzina como saída
  Serial.begin(9600);           // Inicializar a comunicação serial para monitoramento
}

void loop() {
  int valorLido = analogRead(sensorTempPin);            // Leitura do sensor de temperatura
  float voltagem = (valorLido / 1024.0) * 5.0;          // Converter o valor lido para voltagem
  float temperaturaC = (voltagem - 0.5) * 100;          // Converter voltagem para temperatura em °C

  Serial.print("Temperatura: ");
  Serial.print(temperaturaC);
  Serial.println(" °C");

  if (temperaturaC >= 30) {
    digitalWrite(motorPin, HIGH);                       // Aciona o motor se a temperatura for >= 30 °C
  } else {
    digitalWrite(motorPin, LOW);                        // Desliga o motor se a temperatura for < 30 °C
  }

  if (temperaturaC > 50) {
    digitalWrite(ledPin, HIGH);                         // Aciona o LED e a buzina se a temperatura for > 50 °C
    digitalWrite(buzzerPin, HIGH);
  } else {
    digitalWrite(ledPin, LOW);                          // Desliga o LED e a buzina se a temperatura for <= 50 °C
    digitalWrite(buzzerPin, LOW);
  }

  delay(1000);  // Delay de 1 segundo entre as leituras
}
