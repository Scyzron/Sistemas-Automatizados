TP05 - Semáforo veicular e GRAFCET

        Thiago Viana Meira
        RA: 82424566
        
- E0: etapa inicial: VERMELHO = 1; VERDE = 0; AMARELO = 0.
- Após 8 seg, ocorre a transição para E1.
- E1: VERDE = 1; VERMELHO = 0; AMARELO = 0.
- Após 10 seg, ocorre a transição para E2.
- E2: AMARELO = 1; VERMELHO = 0; VERDE = 0.
- Após 3 s, ocorre o retorno para E0.

Tempo total nominal do ciclo: 21 s.

Hipóteses

1. Os temporizadores começam a contar quando a etapa correspondente é ativada.
2. A transição ocorre no limite definido (8 s, 10 s ou 3 s).
3. Não há duas etapas ativas simultaneamente.
4. Não existe amarelo e verde simultaneamente.
5. O ciclo é contínuo e retorna a E0.

Critérios de segurança

- Uma única cor ativa por etapa.
- Etapa inicial claramente identificada.
- Todas as transições possuem receptividade temporal testável.
- Ciclo fechado.
- Sem ambiguidades nas seleções.
- Em caso de falha/emergência, o comportamento seguro considerado é forçar o vermelho e interromper a progressão normal até intervenção do sistema de controle.

Evidências
- grafcet.drawio: fonte editável.
- grafcet.png: evidência visual.
- grafcet.pdf: versão para impressão/entrega.
- casos_teste.csv: cenários normais, limites e pós-transição.
- NOTAS.md: limites e melhorias.
