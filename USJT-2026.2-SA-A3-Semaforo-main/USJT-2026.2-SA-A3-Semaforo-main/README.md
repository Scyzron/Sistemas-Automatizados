# Projeto A3 — Semáforo inteligente

**Sistemas Automatizados — USJT 2026.2 — turma ESO1AN-MCE3 — Prof. Robson Calvetti**

Espaço da equipe para o projeto da A3 com o tema **semáforo inteligente**. Aqui ficam as
**versões editáveis** do relatório, da apresentação e do programa, para quem quiser revisar ou
alterar, e, quando a equipe fechar o trabalho, a **versão final** na pasta [`final/`](final/).

**Estado:** versão **preliminar** gerada em 12/10/2026. A capa ainda traz "Versão preliminar —
integrantes do grupo a definir", porque faltam os nomes dos integrantes. O conteúdo técnico já
foi validado no simulador (ver *Validação*).

## O que tem aqui

| Caminho | O que é | Como editar |
|---|---|---|
| [`projeto/documentos/relatorio.docx`](projeto/documentos/relatorio.docx) | Relatório técnico ABNT (20 páginas) | Word |
| [`projeto/documentos/apresentacao.pptx`](projeto/documentos/apresentacao.pptx) | Apresentação (13 slides, com anotações do apresentador) | PowerPoint |
| [`projeto/documentos/relatorio.pdf`](projeto/documentos/relatorio.pdf), [`apresentacao.pdf`](projeto/documentos/apresentacao.pdf) | Os mesmos documentos em PDF, versão preliminar | gerados a partir dos editáveis |
| [`projeto/documentos/figuras/`](projeto/documentos/figuras/) | GRAFCET e arquitetura usados no relatório | imagens |
| [`projeto/plc-simulator/semaforo.json`](projeto/plc-simulator/semaforo.json) | Programa Ladder, cópia fiel no formato do PLC Simulator Online | ver *Programa Ladder* |
| [`projeto/README.md`](projeto/README.md) | Descrição técnica: problema, tags, GRAFCET, rungs, decisões e testes | Markdown |
| [`projeto/casos_teste.csv`](projeto/casos_teste.csv), [`projeto/testes/`](projeto/testes/) | Casos de teste com esperado, obtido e situação; resultados com SHA-256 | gerados pela validação |
| [`projeto/evidencias/`](projeto/evidencias/) | 9 capturas do simulador nos estados decisivos | imagens |
| [`final/`](final/) | Versão final, a ser colocada pela equipe | ver *Versão final* |

## Como editar os documentos

**Caminho simples (Word e PowerPoint).** Abra o `.docx` ou o `.pptx`, faça as alterações,
salve e exporte de novo o PDF (Arquivo → Exportar → PDF). No relatório, antes de exportar,
atualize o sumário e os campos (clique com o botão direito no sumário → Atualizar campo →
Atualizar o índice inteiro). Depois, faça commit dos dois arquivos, o editável e o PDF, com uma
mensagem que diga o que mudou.

**Caminho do gerador (consistência total).** Os documentos foram gerados por código, no
repositório [`MarceloMarcolino/SistemasAutomatizados`](https://github.com/MarceloMarcolino/SistemasAutomatizados),
pasta `Entregas/A3/documentos`. O conteúdo do tema fica em `temas/01-semaforo.mjs` e os dados
do grupo em `comum/grupo.mjs`. Para gerar de novo, dentro dessa pasta: `npm ci` e depois
`node gera.mjs 01-semaforo`. O próprio gerador já converte para PDF pelo Word e pelo PowerPoint
(Windows) e grava as saídas **no repositório de trabalho**, em
`Entregas/A3/projetos/01-semaforo/documentos/`. Confira o resultado e copie os arquivos para
`projeto/documentos/` deste repositório. Atenção: gerar de novo **substitui** o `.docx` e o
`.pptx`. Uma edição feita à mão no Word se perde, a menos que seja levada também para o arquivo
do tema.

**Cuidados que valem para os dois caminhos:**
- os números do texto (casos, varreduras, invariantes, mutantes, capturas) precisam continuar
  iguais aos de [`projeto/testes/resultados.json`](projeto/testes/resultados.json);
- citações só das referências que já estão no relatório; nada copiado do material do professor;
- antes de mexer no mesmo arquivo que outra pessoa, combine no grupo: o git não junta alterações
  em `.docx` e `.pptx`. Se duas pessoas alterarem o mesmo arquivo, o segundo envio é recusado ou
  pede resolução de conflito, e aí é preciso escolher uma das versões e refazer à mão as mudanças
  da outra. Um editor por vez em cada documento evita isso.

## Programa Ladder

O programa abre sem login no PLC Simulator Online:
<https://app.plcsimulator.online/wuPLOb3XvySEne6i8krQ>.

O link é um **retrato** gravado no momento do compartilhamento e não muda com edições
posteriores. Para alterar o programa:
1. abra o link;
2. edite no simulador;
3. compartilhe com a sua conta, o que gera um link novo;
4. atualize o link neste README, no `projeto/README.md` e nos documentos.

Qualquer mudança na lógica pede que os testes sejam refeitos, e os números do relatório mudam
junto. O arquivo `semaforo.json` é a cópia de referência do programa validado.

## Versão final

Pendências para fechar a entrega:
1. **nomes completos dos integrantes**, para a capa, a folha de rosto e o slide de abertura;
2. retirar a marca de versão preliminar e gerar os documentos de novo (ou editar a capa à mão);
3. revisão final do grupo e ensaio da apresentação (10 a 15 minutos);
4. colocar em [`final/`](final/) o relatório em PDF, a apresentação (PPTX e PDF) e o link do
   programa.

A entrega e a apresentação são em **02/12/2026**, conforme a especificação do projeto na
disciplina. Cada integrante também publica o trabalho no próprio repositório de entregas.

## Validação (já feita, versão preliminar)

O programa foi validado no motor nativo do simulador:
- **90/90** casos, cada um com o esperado escrito antes da execução;
- **32 683/32 683** registros de varredura idênticos aos de um interpretador independente;
- **8/8** invariantes sem violação e **6/6** mutantes reprovados;
- **9** capturas conferidas.

Detalhes em [`projeto/README.md`](projeto/README.md) e [`projeto/testes/casos-de-teste.md`](projeto/testes/casos-de-teste.md).

## Combinados do repositório

- Não colocar aqui material do professor (PDFs da disciplina, gabaritos).
- Dados pessoais: só os nomes necessários para a capa.
- Para mudanças grandes, prefira um branch e um pull request para o grupo revisar.
