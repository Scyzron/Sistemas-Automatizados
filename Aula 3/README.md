Projeto Sistemas Automatizados

Projeto completo das Etapas 1 a 7 – Integração de botão, LED, potenciômetro e sensor DHT22 com lógica de decisão prioritária.

--Objetivo

Desenvolver um protótipo de sistema automatizado que:

- Controla um LED com um botão (com pull-up interno)
- Lê um potenciômetro e classifica o valor analógico
- Lê temperatura com DHT22
- Toma decisões com prioridade: **FALHA DE SENSOR > ALARME > ATENÇÃO > NORMAL**

--Componentes Necessários

| Componente          | Quantidade | Observação                          |
|---------------------|------------|-------------------------------------|
| Arduino Uno         | 1          | Wokwi               |
| Botão táctil        | 1          | Conectado com INPUT_PULLUP          |
| LED                 | 1          | Qualquer cor                        |
| Resistor 220Ω       | 1          | Para o LED                          |
| Potenciômetro 10kΩ  | 1          |                                     |
| Sensor DHT22        | 1          | Temperatura e umidade               |
| Jumpers             | Vários     |                                     |
| Protoboard          | 1          |                                     |

--Diagrama de Conexões (Wiring)

### Botão (Etapa 1)
- Um terminal do botão → Pino digital **2**
- Outro terminal do botão → **GND**
- Configuração: `INPUT_PULLUP` (não precisa resistor externo)

### LED (Etapa 1)
- Anodo do LED → Resistor 220Ω → Pino digital **8**
- Catodo do LED → **GND**

### Potenciômetro (Etapa 3)
- Terminal esquerdo → **5V**
- Terminal direito → **GND**
- Terminal central (wiper) → **A0**

### DHT22 (Etapa 5)
- VCC → **5V**
- GND → **GND**
- DATA → Pino digital **4**
- (Opcional) Resistor pull-up 4,7kΩ entre DATA e VCC (já interno em muitos módulos)

--Bibliotecas Necessárias

Wokwi:

1. Vá em **Sketch → Include Library → Manage Libraries**
2. Procure por **“DHT sensor library”** (Adafruit)
3. Instale também a dependência **“Adafruit Unified Sensor”**

No Wokwi basta adicionar no `diagram.json` ou usar o gerenciador de bibliotecas da plataforma.

--Executar no Wokwi

1. Acesse [https://wokwi.com](https://wokwi.com)
2. Crie um novo projeto **Arduino Uno**
3. Cole o conteúdo do arquivo `sistemas_automatizados.ino`
4. Monte o circuito conforme o diagrama acima (use os componentes: Button, LED, Potentiometer, DHT22)
5. Adicione a biblioteca DHT no painel de bibliotecas
6. Clique em **Start Simulation**
7. Abra o **Serial Monitor**
8. Interaja:
   - Gire o potenciômetro
   - Altere a temperatura do DHT22 (clique no sensor)
   - Pressione o botão

--Faixas de Operação do Protótipo

| Variável          | Normal          | Atenção              | Alarme/Falha          |
|-------------------|-----------------|----------------------|-----------------------|
| Potenciômetro     | 0 – 399         | 400 – 749            | 750 – 1023            |
| Temperatura       | < 30 °C         | 30 a < 40 °C         | ≥ 40 °C               |
| DHT inválido      | —               | —                    | FALHA DE SENSOR       |
| Botão             | Liberado        | —                    | Pressionado aciona LED|

--Lógica de Prioridade (Etapa 7)

```
SE leitura_DHT inválida          → "FALHA DE SENSOR"
SENÃO SE (temp ≥ 40 OU pot ≥ 750) → "ALARME"
SENÃO SE (temp ≥ 30 OU pot ≥ 400) → "ATENCAO"
SENÃO                             → "NORMAL"
```

O LED é controlado **apenas** pelo botão (independente do status).

--Casos de Teste Digitais (Etapas 1-2)

| Caso | Entrada observada              | Saída esperada     | Resultado |
|------|--------------------------------|--------------------|-----------|
| D1   | Botão liberado / HIGH          | LED apagado        | OK        |
| D2   | Botão pressionado / LOW        | LED aceso          | OK        |
| D3   | Cinco acionamentos             | Cinco respostas    | OK        |
| D4   | Botão mantido pressionado      | LED permanece aceso| OK        |

--Casos de Teste Integrados (Etapa 7)

| Caso | Pot  | Temp   | Botão | Resposta esperada      |
|------|------|--------|-------|------------------------|
| T1   | 200  | 25 °C  | Livre | NORMAL; LED off        |
| T2   | 500  | 25 °C  | Livre | ATENCAO                |
| T3   | 800  | 25 °C  | Livre | ALARME                 |
| T4   | 200  | 35 °C  | Livre | ATENCAO                |
| T5   | 200  | 45 °C  | Livre | ALARME                 |
| T6   | 200  | 25 °C  | Press.| NORMAL; LED on         |
| T7   | —    | inválida| Livre | FALHA DE SENSOR        |

--Estrutura de Arquivos

```
projeto-sistemas-automatizados/
├── sistemas_automatizados.ino   ← Código completo
├── README.md                    ← Este arquivo
├── ANALISE_LIMITACOES.md        ← Limitações da simulação
├── CASOS_DE_TESTE.md            ← Tabelas detalhadas
└── diagram.json                 ← (opcional) para importar no Wokwi
```