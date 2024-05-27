/**
 * @file InputOutput.h
 * @author Hugo Cruz (a23010)
 * @brief Este ficheiro de cabeçalho define as funções para carregar e mostrar dados a partir de ficheiros.
 * @version 71.1
 * @date 2024-05-24
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#ifndef INPUTOUTPUT_H
#define INPUTOUTPUT_H

#include <stdio.h>
#include <string.h>
#include <locale.h>
#include "grafo.h"


/**
 * @brief Função para mostar vértices as adjacencias.
 * 
 * Esta função recebe um apontador para um vértice e imprime o vértice e as suas adjacências. Percorre a lista de vértices e para cada vértice, percorre a lista de adjacências, imprimindo as.
 * 
 * @param grafo Apontador para o vértice a ser mostrado.
 */
void MostraVertice(Vertice* grafo);

/**
 * @brief Função para mostra um grafo.
 * 
 * Esta função recebe um apontador para um grafo e imprime o grafo chamando a função MostraVertice para o vértice inicial do grafo.
 * 
 * @param g Apontador  para o grafo a ser mostrado
 */
void MostraGrafo(Grafo* g);


/**
 * @brief  Função para ler um arquivo.
 * 
 * Esta função recebe o nome de um ficheiro, lê o ficheiro e retorna os dados lidos. Se o ficheiro não puder ser aberto, retorna NULL. Caso contrário, lê o ficheiro inteiro para uma string e retorna essa string.
 * 
 * @param file Nome do arquivo a ser lido.
 * @return char* Retorna os dados lidos do arquivo.
 */
char* ReadFile(char* file);

/**
 * @brief Função para contar o número de linhas e colunas em uma string.
 * 
 * Esta função recebe uma string de dados e dois apontadores para inteiros. Conta o número de linhas e colunas na string de dados e armazena esses valores nos inteiros apontados pelos apontadores.
 * 
 * @param dados Dados a serem contados.
 * @param linha Apontador para o número de linhas.
 * @param coluna Apontador para o número de colunas.
 */
void Contador(char* dados, int* linha, int* coluna);

/**
 * @brief Função para criar vértices a partir de um arquivo CSV
 * 
 * Esta função conta as linhas e colunas de um token e cria memória para um grafo. 
 * Após a criação do mesmo carrega os vertices de um ficheiro CSV.
 * 
 * @param dados Dados do arquivo CSV.
 * @return Grafo* Retorna um apontador para o grafo criado.
 */
Grafo* CriarVerticesCSV(char* dados);

/**
 * @brief Função para carregar dados de um arquivo CSV.
 * 
 * Esta função recebe uma string de dados que representa um ficheiro CSV. Cria 
 * um grafo e insere vértices no grafo com base nos dados. O número de vértices inseridos 
 * é o maior entre o número de linhas e o número de colunas nos dados. Retorna um apontador para o grafo criado.
 * 
 * @param file Nome do arquivo CSV (argumento 1).
 * @return Grafo* Retorna um apontador para o grafo criado.
 */
Grafo* CarregaDadosCSV(char* file);

/**
 * @brief Função para guardar vértices em um ficheiro binário.
 * 
 * Esta função guarda os vértices de um grafo num ficheiro binário. Percorre 
 * todos os vértices do grafo e escreve-os no ficheiro.
 * 
 * @param g Apontador para o grafo a guardar.
 * @param file Nome do arquivo.
 */
void GuardaVertices(Grafo* g, char* file);

/**
 * @brief Função para carregar vértices de um arquivo
 * 
 * Esta função carrega os vértices de um ficheiro binário para um grafo. Lê o 
 * ficheiro e adiciona cada vértice ao grafo.
 * 
 * @param file Nome do arquivo
 * @return Grafo* Retorna um apontador para o grafo criado
 */
Grafo* CarregaVertices(char* file);


/**
 * @brief Função para guardar adjacências em um ficheiro binário
 * 
 * Esta função guarda as adjacências de um grafo num ficheiro binário. Percorre todos 
 * os vértices e as suas adjacências e escreve-os no ficheiro.
 * 
 * @param g Apontador para o grafo a guardar
 * @param file  Nome do arquivo
 */
void GuardarAdjacentes(Grafo* g, char* file);
/**
 * @brief Função para carregar adjacências de um arquivo num grafo.
 * 
 * Esta função carrega as adjacências de um ficheiro binário para um grafo. Lê o ficheiro 
 * e adiciona cada adjacência ao grafo correspondente.
 * 
 * @param grafo Apontador para o grafo onde seram carregado os dados. 
 * @param file  Nome do arquivo.
 * @return Grafo* Retorna um apontador para o grafo atualizado.
 */
Grafo* CarregaAdjacencias(Grafo* grafo, char* file);


/**
 * @brief Função para guardar um grafo em dois arquivos, um para vértices e outro para adjacências.
 * 
 *  Esta função guarda um grafo inteiro em dois ficheiros, um para os vértices e outro para 
 * as adjacências. Usa as funções GuardaVertices e GuardarAdjacentes
 * 
 * @param g Apontador para o grafo a guardar.
 * @param vertices Nome do arquivo para vértices.
 * @param adjacencias Nome do arquivo para adjacências.
 */
void GuardaGrafo(Grafo* g, char* vertices, char* adjacencias);
/**
 * @brief Função para carregar um grafo a partir de dois arquivos, um para vértices e outro para adjacências.
 * 
 * Esta função carrega um grafo inteiro a partir de dois ficheiros, um para os vértices e 
 * outro para as adjacências. Usa as funções CarregaVertices e CarregaAdjacencias
 * 
 * @param vertices Nome do arquivo para vértices.
 * @param adjacencias Nome do arquivo para adjacências.
 * @return Grafo* Retorna um apontador para o grafo com os valores carregados
 */
Grafo* CarregaGrafo(char* vertices, char* adjacencias);
/**
 * @brief Função para carregar dados de um arquivo ou de dois arquivos (vértices e adjacências), dependendo do que estiver disponível.
 * 
 * Esta função carrega dados de um arquivo ou de dois arquivos (vértices e adjacências), dependendo do
 *  que estiver disponível. Se os ficheiros de vértices e adjacências estiverem disponíveis, usa-os para 
 * carregar o grafo. Caso contrário, carrega os dados de um ficheiro CSV.
 * 
 * @param file  Nome do arquivo com dados (argumento).
 * @param vertices Nome do arquivo para vértices.
 * @param adjacencias Nome do arquivo para vértices.
 * @return Grafo* Retorna um apontador para o grafo criado.
 */
Grafo* CarregaDados(char* file, char* vertices, char* adjacencias);

/**
 * @brief Mostra o caminho de um vértice de origem a um vértice de destino.
 * 
 * @param verticeAnt Array que contém os antecessore de cada vertice
 * @param destino Destino final 
 */
void ImprimirCaminho(int verticeAnt[], int destino);

/**
 * @brief Mostra o caminho mais curto entre dois vértices num grafo.
 * 
 * Esta função recebe um grafo, um vértice de origem e um vértice de destino. Ela utiliza o algoritmo de Dijkstra
 * para calcular o caminho mais curto do vértice de origem ao vértice de destino e imprime esse caminho.
 * 
 * @param g O grafo.
 * @param origem O vértice de origem.
 * @param destino O vértice de destino.
 */
void MostrarCaminho(Grafo* g, int origem, int destino);




#endif