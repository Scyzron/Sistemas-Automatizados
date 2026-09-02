/*
  FALHA DE SENSOR (leitura inválida do DHT22)
  
  NORMAL (todas as condições normais)
  ATENÇÃO (temperatura >= 30°C OU potenciômetro >= 400)
  ALARME (temperatura >= 40°C OU potenciômetro >= 750)
  
  O botão controla o LED de forma independente (pressionado = LED aceso).
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
  
  //Etapa 1 e 2
  pinMode(BTN, INPUT_PULLUP);
  pinMode(LED, OUTPUT);
  
  //Etapa 5 e 6
  dht.begin();
  
  Serial.println("=== Sistema Automatizado Iniciado ===");
  Serial.println("Prioridade: FALHA > ALARME > ATENCAO > NORMAL");
  Serial.println();
}

void loop() {

  //INPUT_PULLUP: liberado = HIGH, pressionado = LOW (inversão lógica)
  bool botaoPressionado = (digitalRead(BTN) == LOW);
  digitalWrite(LED, botaoPressionado);  // LED acende quando botão é pressionado
  
  //Etapa 3 e 4
  int bruto = analogRead(POT);  // 0 a 1023
  
  //Etapa 5 e 6
  float temperatura = dht.readTemperature();
  
  //Etapa 7
  String status;
  
  if (isnan(temperatura)) {
    //Prioridade máxima: falha do sensor
    status = "FALHA DE SENSOR";
  } 
  else if (temperatura >= 40.0 || bruto >= 750) {
    //Prioridade 2: ALARME
    status = "ALARME";
  } 
  else if (temperatura >= 30.0 || bruto >= 400) {
    //Prioridade 3: ATENÇÃO
    status = "ATENCAO";
  } 
  else {
    //Prioridade 4: NORMAL (só quando tudo tá normal)
    status = "NORMAL";
  }
  
  //Saída no Monitor Serial
  Serial.print("Status: ");
  Serial.print(status);
  Serial.print(" | Pot: ");
  Serial.print(bruto);
  Serial.print(" | Temp: ");
  
  if (isnan(temperatura)) {
    Serial.print("INVALIDA");
  } else {
    Serial.print(temperatura, 1);
    Serial.print(" C");
  }
  
  Serial.print(" | Botao: ");
  Serial.print(botaoPressionado ? "PRESSIONADO (LED ON)" : "LIBERADO (LED OFF)");
  Serial.println();
  
  delay(1000);  // Atualiza a cada 1 segundo (1000 ms = 1 seg)
}
