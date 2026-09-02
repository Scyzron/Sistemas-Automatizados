Casos de Teste

-- Parte A – Casos de Teste Digitais (Etapas 1 e 2)

**Objetivo**: Verificar o comportamento do botão com INPUT_PULLUP e o controle do LED.

| Caso | Entrada observada                     | Saída esperada              | Resultado | Observação |
|------|---------------------------------------|-----------------------------|-----------|------------|
| D1   | Botão liberado / HIGH                 | LED apagado                 | **OK**    | Pull-up ativo |
| D2   | Botão pressionado / LOW               | LED aceso                   | **OK**    | Inversão lógica confirmada |
| D3   | Cinco acionamentos consecutivos       | Cinco respostas corretas    | **OK**    | Sem falhas de leitura |
| D4   | Botão mantido pressionado             | LED permanece aceso         | **OK**    | Estado estável |

--Explicação da inversão lógica (Leitura de Engenharia)

Com `INPUT_PULLUP`:
- Botão **liberado** → pino em nível **HIGH** (5 V via resistor interno) → LED **apagado**
- Botão **pressionado** → pino em nível **LOW** (ligado ao GND) → LED **aceso**

Essa inversão é esperada e deve ser considerada no código (`digitalRead(BTN) == LOW`).

---

-- Parte B – Casos de Teste Integrados (Etapa 7)

**Objetivo**: Validar a lógica de prioridade completa com potenciômetro, temperatura e botão.

| Caso | Potenciômetro | Temperatura | Botão     | Status Esperado     | LED Esperado | Resultado | Observação |
|------|---------------|-------------|-----------|---------------------|--------------|-----------|------------|
| T1   | 200           | 25 °C       | Liberado  | NORMAL              | Apagado      | **OK**    | Tudo normal |
| T2   | 500           | 25 °C       | Liberado  | ATENCAO             | Apagado      | **OK**    | Pot na faixa de atenção |
| T3   | 800           | 25 °C       | Liberado  | ALARME              | Apagado      | **OK**    | Pot na faixa de alarme |
| T4   | 200           | 35 °C       | Liberado  | ATENCAO             | Apagado      | **OK**    | Temp na faixa de atenção |
| T5   | 200           | 45 °C       | Liberado  | ALARME              | Apagado      | **OK**    | Temp na faixa de alarme |
| T6   | 200           | 25 °C       | Pressionado | NORMAL            | Aceso        | **OK**    | Botão aciona LED independentemente |
| T7   | qualquer      | Inválida    | Liberado  | FALHA DE SENSOR     | Apagado      | **OK**    | Prioridade máxima respeitada |

-- Matriz de Prioridade Confirmada

1. **FALHA DE SENSOR** (isnan) → sobrescreve qualquer outra condição
2. **ALARME** (temp ≥ 40 **OU** pot ≥ 750)
3. **ATENÇÃO** (temp ≥ 30 **OU** pot ≥ 400)
4. **NORMAL** (somente quando nenhuma das condições acima for verdadeira)

---

-- Parte C – Tabela Variável × Sensor × Entrada × Resposta

| Variável / Sensor   | Entrada Física              | Faixa / Condição          | Resposta do Sistema      |
|---------------------|-----------------------------|---------------------------|--------------------------|
| Botão               | Liberado                    | HIGH                      | LED apagado              |
| Botão               | Pressionado                 | LOW                       | LED aceso                |
| Potenciômetro       | 0 – 399                     | Normal                    | Contribui para NORMAL    |
| Potenciômetro       | 400 – 749                   | Atenção                   | Contribui para ATENCAO   |
| Potenciômetro       | 750 – 1023                  | Alarme                    | Contribui para ALARME    |
| DHT22 (Temperatura) | < 30 °C                     | Normal                    | Contribui para NORMAL    |
| DHT22 (Temperatura) | 30 – 39,9 °C                | Atenção                   | Contribui para ATENCAO   |
| DHT22 (Temperatura) | ≥ 40 °C                     | Alarme                    | Contribui para ALARME    |
| DHT22               | Leitura inválida (NaN)      | Falha                     | FALHA DE SENSOR          |

---

## Como Reproduzir os Testes no Wokwi

1. Inicie a simulação.
2. Abra o **Serial Monitor**.
3. Para cada caso:
   - Ajuste o potenciômetro para o valor desejado (arraste o cursor).
   - Clique no DHT22 e defina a temperatura.
   - Pressione ou solte o botão.
4. Observe a mensagem no Serial Monitor e o estado do LED.
5. Registre o resultado (OK / Falha).

Todos os casos T1–T7 e D1–D4 foram validados com sucesso na lógica implementada.
