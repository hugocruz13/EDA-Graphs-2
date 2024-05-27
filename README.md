### Fase 2: Grafos

#### Instituto Politécnico do Cávado e do Ave (IPCA) - Barcelos

**Aluno:** Hugo Cruz (a23010)

---

### Introdução

Este projeto em C tem como objetivo calcular o somatório máximo possível de inteiros a partir de uma matriz de dimensões arbitrárias, considerando regras específicas de conexão entre os inteiros. Para isso, aplicamos conceitos avançados de teoria dos grafos e programação em C, utilizando estruturas de dados e algoritmos de procura.

---

### Estrutura do Projeto

- **doc/:** Documentação gerada pelo Doxygen.
- **src/:** Código fonte do projeto, incluindo uma biblioteca estática.
  - **Grafos/:** Código fonte utilizado para gerar (`Grafos.lib`)
  - **Main/:** Contém o código principal.
    - **libs/:** Biblioteca estática (`Grafos.lib`).

---

### Funcionalidades Implementadas

1. **Estrutura de Dados GR:** Definição de uma estrutura de dados GR para representar um grafo orientado capaz de suportar um número de vértices de forma dinâmica, incluindo funções básicas para a manipulação do grafo.

2. **Modelagem do Problema com Grafos:** Modelagem do problema utilizando grafos, onde cada elemento da matriz é representado por um vértice e as arestas são representadas por valores lidos.

3. **Carregamento de Dados:** Carregamento dos dados de uma matriz de inteiros a partir de um arquivo de texto, permitindo grafos de qualquer dimensão.

4. **Operações de Manipulação de Grafos:** Implementação de operações de manipulação de grafos, incluindo procura em profundidade ou em largura, para identificar todos os caminhos possíveis que atendem às regras de conexão definidas, e cálculo da soma dos valores dos vértices em um dado caminho.

5. **Encontrar o Caminho com a Menor Soma:** Utilização das estruturas e algoritmos desenvolvidos para encontrar o caminho que proporciona a maimenoror soma possível dos inteiros na estrutura GR, seguindo a regra de conexão estabelecida, fornecendo tanto a soma total quanto o caminho correspondente.

### Autores

- [Hugo Cruz (@hugoc03)](https://www.github.com/hugoc03)

---

