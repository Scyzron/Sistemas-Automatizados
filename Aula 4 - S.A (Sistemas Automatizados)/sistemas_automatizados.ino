/*
  Semana 3 - Sistemas Automatizados
  Aquisição, escalonamento e classificação
*/

#include <DHT.h>

#define DHTPIN 4
#define DHTTYPE DHT22

DHT dht(DHTPIN, DHTTYPE);

const int BTN = 2;
const int LED = 8;
const int POT = A0;

void setup() {
  Serial.begin(9600);
  pinMode(BTN, INPUT_PULLUP);
  pinMode(LED, OUTPUT);
  dht.begin();
  Serial.println("Sistema iniciado");
}

void loop() {
  // botão (INPUT_PULLUP: pressionado = LOW)
  bool botao = (digitalRead(BTN) == LOW);
  digitalWrite(LED, botao);

  // potenciômetro
  int bruto = analogRead(POT);
  float pct = 100.0 * bruto / 1023.0;
  float temp = pct;   // 0 a 100 °C

  // DHT (só pra detectar falha)
  float tempDHT = dht.readTemperature();

  // classificação com prioridade
  String status;
  if (isnan(tempDHT) || bruto < 0 || bruto > 1023) {
    status = "FALHA";
  } else if (pct >= 85.0) {
    status = "PERIGO";
  } else if (pct >= 70.0) {
    status = "ATENCAO";
  } else {
    status = "NORMAL";
  }

  // serial
  Serial.print(status);
  Serial.print(" | ");
  Serial.print(bruto);
  Serial.print(" | ");
  Serial.print(pct, 1);
  Serial.print("% | ");
  Serial.print(temp, 1);
  Serial.print(" C | ");
  if (isnan(tempDHT)) Serial.print("INVALIDA");
  else {
    Serial.print(tempDHT, 1);
    Serial.print(" C");
  }
  Serial.print(" | Botao: ");
  Serial.println(botao ? "ON" : "OFF");

  delay(1000);
}
