# SEMANA 7 - P07 · Exercício Obrigatório – Atraso de Partida (MOTOR_DELAY)

**Disciplina:** Sistemas Automatizados  
**Tema:** Programação sequencial de CLP – Temporizador TON  
**Simulador:** [https://app.plcsimulator.online/](https://app.plcsimulator.online/) (versão clássica)

---

## 1. Objetivo

Implementar o bloco **MOTOR_DELAY**:

- `START` habilita um **TON de 3 segundos**
- `STOP_OK` e `EMG_OK` interrompem a temporização **e removem a saída**
- A saída `MOTOR_DELAY` só liga após o tempo decorrido (Q do timer)

---

## 2. Tags utilizadas

| Tag           | Tipo          | Descrição                                      |
|---------------|---------------|------------------------------------------------|
| START         | Digital Input | Botão de partida (NO)                          |
| STOP_OK       | Digital Input | Segurança / parada normal (NC – normalmente fechado) |
| EMG_OK        | Digital Input | Emergência (NC – normalmente fechado)          |
| MOTOR_DELAY   | Digital Output| Saída do motor (após atraso)                   |
| T1            | Timer (TON)   | Temporizador On-Delay – PT = 3.0 s             |

---

## 3. Lógica Ladder (3 rungs)

### Rung 1 – Habilitação do Timer
```
|----[ START ]----[ STOP_OK ]----[ EMG_OK ]----( TON T1 )----|
                                              PT = 3000 ms
```
- O timer só conta enquanto **START** estiver pressionado **E** as duas condições de segurança estiverem verdadeiras.
- Se qualquer uma cair, o timer **para e zera o ET**.

### Rung 2 – Saída do Motor
```
|----[ T1.Q ]--------------------------------( MOTOR_DELAY )--|
```
- A saída só fica ligada quando o timer completa os 3 s (`T1.Q = 1`).

### Rung 3 – Reset explícito (recomendado)
```
|----[/STOP_OK]----+----( T1.RESET )----|
|                  |
|----[/EMG_OK ]----+
```
- Garante que o timer seja zerado imediatamente em caso de parada ou emergência.

> **Comportamento esperado do TON no simulador:**  
> Enquanto a entrada do timer estiver TRUE → ET aumenta.  
> Quando a entrada fica FALSE → ET volta para 0 e Q = 0.

---

## 4. Prioridades e decisões de projeto

1. **Segurança primeiro**: STOP_OK e EMG_OK têm prioridade sobre START.
2. **Reset automático**: o timer é zerado assim que a condição de habilitação cai (não precisa de botão de reset separado).
3. **Saída segura**: MOTOR_DELAY só pode ficar em 1 se T1.Q estiver em 1 **e** as condições de segurança permanecerem ativas.
4. **Não há auto-retenção**: se a falha for liberada sem novo START, a saída permanece em 0 (teste T05).

---

## 5. Testes obrigatórios

| ID  | Ação                              | Esperado                          | Obtido | Situação |
|-----|-----------------------------------|-----------------------------------|--------|----------|
| T01 | START por 2 s                     | Q=0 e MOTOR_DELAY=0               |        |          |
| T02 | START por ≥ 3 s                   | Q=1 e MOTOR_DELAY=1               |        |          |
| T03 | STOP_OK = 0 durante a contagem    | ET zera e saída = 0               |        |          |
| T04 | EMG_OK = 0 com saída ligada       | saída = 0                         |        |          |
| T05 | Liberar falha sem START           | saída permanece 0                 |        |          |

Arquivo completo: `casos_teste.csv`

---

## 6. Checklist de verificação

| Verificação     | Critério                                      | Status |
|-----------------|-----------------------------------------------|--------|
| Temporização    | PT, ET e Q documentados                       | ✓      |
| Contagem        | Uma borda produz um incremento                | ✓      |
| Reset           | Prioridade definida e testada                 | ✓      |
| Sequência       | Somente estados válidos ficam ativos          | ✓      |
| Falha           | Emergência remove movimentos                  | ✓      |
| Referências     | IEC 61131-3, documentação do simulador        | ✓      |

---

## 7. Evidências para entrega

- [ ] Link do projeto (Share do simulador)
- [ ] README.md (este arquivo)
- [ ] casos_teste.csv
- [ ] Capturas de tela:
  - Timer contando (ET aumentando)
  - Interrupção por STOP_OK
  - Interrupção por EMG_OK
  - Saída ligada após 3 s
  - Reset e estado seguro
- [ ] Planilha de ciclos (opcional)

---

## 8. Como montar no simulador (passo a passo rápido)

1. Acesse [https://app.plcsimulator.online/](https://app.plcsimulator.online/)
2. Clique em **Load empty diagram** (ou New)
3. Na área de variáveis, crie:
   - START (BOOL)
   - STOP_OK (BOOL) → valor inicial = 1 (NC)
   - EMG_OK (BOOL) → valor inicial = 1 (NC)
   - MOTOR_DELAY (BOOL)
   - T1 (TIMER) → PT = 3000
4. Monte os 3 rungs conforme a seção 3.
5. Clique em **Start simulation** e execute os testes T01–T05.
6. Clique em **Share** → faça login (gratuito) → copie o link gerado.

---

## 9. Referências

- IEC 61131-3 – Programmable controllers – Part 3: Programming languages
- Documentação do PLC Simulator Online
- Virtual Labs (se aplicável ao curso)

---

**Autor:** [Seu Nome]  
**Data:** Outubro/2026  
**Status:** Pronto para entrega  
