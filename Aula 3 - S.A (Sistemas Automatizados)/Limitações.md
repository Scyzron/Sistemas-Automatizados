Análise das Limitações da Simulação

--Limitações do Sensor DHT22 na Simulação

- No Wokwi, a temperatura e a umidade são **controladas manualmente** pelo usuário (clicando no componente).
- Não há variação automática realista de temperatura (inércia térmica, influência do ambiente, etc.).
- A leitura inválida (NaN) precisa ser forçada artificialmente ou ocorre apenas em condições específicas de configuração incorreta.
- O tempo de resposta do sensor real (~2 segundos) é simulado de forma simplificada.

--Limitações do Potenciômetro

- O valor analógico no Wokwi é ideal (sem ruído).
- Em hardware real existe ruído elétrico, especialmente se os cabos forem longos ou houver interferência.
- A resolução de 10 bits (0-1023) é respeitada, mas a linearidade do potenciômetro real pode apresentar pequenas não-linearidades.

--Limitações do Botão e LED

- O bounce (repique) mecânico do botão **não é simulado** por padrão no Wokwi.
- Em hardware real seria necessário implementar debounce por software ou hardware.
- O LED na simulação acende instantaneamente; no mundo real há um pequeno atraso e a corrente precisa ser limitada corretamente pelo resistor.

--Limitações Gerais da Plataforma Wokwi

| Aspecto                    | Simulação (Wokwi)          | Hardware Real                  |
|----------------------------|----------------------------|--------------------------------|
| Ruído elétrico             | Ausente                    | Presente                       |
| Debounce de botão          | Ideal (sem bounce)         | Necessário                     |
| Tempo de resposta sensores | Idealizado                 | Característico do componente   |
| Alimentação                | Estável                    | Pode ter variação / queda      |
| Temperatura ambiente       | Controlada manualmente     | Variável e influenciada        |
| Falhas de conexão          | Raras                      | Comuns (fios soltos, etc.)     |
| Consumo de corrente        | Não limitado               | Limitado pela fonte            |

--Impacto nas Decisões do Sistema

A lógica de prioridade implementada (FALHA > ALARME > ATENÇÃO > NORMAL) funciona corretamente na simulação, porém:

- Em ambiente real, leituras inválidas do DHT22 são mais frequentes
- O limiar de 750 no potenciômetro pode precisar de ajuste fino por causa do ruído
- Melhor ter um filtro de média móvel no potenciômetro e um mecanismo de debounce no botão para uso real

--Conclusão

A simulação no Wokwi é excelente para validar a lógica e a integração dos componentes, mas para um protótipo final é indispensável testar em hardware real para validar:

1. Estabilidade das leituras analógicas
2. Comportamento do DHT22 em diferentes condições ambientais
3. Debounce e confiabilidade do botão
4. Consumo e aquecimento dos componentes
