# Semana 3 - Sistemas Automatizados

-O que foi feito-
Evoluí a estação da semana 2 pra adquirir, escalonar e classificar a variável do potenciômetro.

-Hardware-
- Botão no D2 (INPUT_PULLUP)
- LED no D8
- Potenciômetro no A0
- DHT22 no D4 (só pra detectar falha)

-Escalonamento-
```
percentual = 100.0 * bruto / 1023.0
temperatura = percentual   // 0 a 100 °C
```

-Estados (prioridade)-
1. FALHA → DHT inválido
2. PERIGO → % >= 85
3. ATENÇÃO → % >= 70
4. NORMAL → % < 70

-Como testar-
1. Abre o Wokwi e roda a simulação
2. Gira o pot e aperta o botão
3. Olha o Serial Monitor

-Arquivos-
- `sistemas_automatizados.ino` → código
- `diagram.json` → circuito
- `Planilha_Semana3_Aquisicao.xlsx` → planilha com amostras e gráfico
