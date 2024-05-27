/**
 * @file caminhos.h
 * @author Hugo Cruz (a23010)
 * @brief Este arquivo de cabeçalho define as estruturas de dados e as funções para manipular caminhos num grafo.
 * @version 48.1
 * @date 2024-05-24
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#ifndef CAMINHOS_H
#define CAMINHOS_H

#include "grafo.h"

/**
 * @brief Inicializa os arrays de distâncias.
 * 
 * Esta função inicializa os arrays de distâncias, atribuindo a cada elemento o valor máximo de um inteiro.
 * 
 * @param dis Array de distâncias a ser inicializado.
 */
void InicializarArrays(int* dis[]);

/**
 * @brief Conta o número de vértices num grafo.
 * 
 * Esta função conta o número de vértices num grafo. Retorna o número de vértices no grafo.
 * 
 * @param g O grafo a ser analisado.
 * @return int O número de vértices no grafo.
 */
int ContadorVertices(Grafo* g);

/**
 * @brief Encontra a o vértice com a distância mínima
 * 
 * Esta função encontra o vértice com a distância mínima, a partir do conjunto de vértices ainda não 
 * incluídos no caminho mais curto. Retorna o id do vértice com a distância mínima.
 * 
 * @param distancia Array com as distâncias acumuladas de cada vértice.
 * @param visitado Array que indica se um vértice foi ou não visitado.
 * @param n Número total de vértices.
 * @return int O id do vértice com a distância mínima.
 */
int DistanciaMinima(int distancia[], bool visitado[], int n);

/**
 * @brief Algoritmo de Dijkstra
 *
 * Esta função implementa o algoritmo de Dijkstra, que é usado para encontrar os caminhos mais curtos de um vértice de origem para todos os outros vértices num grafo.
 *
 * @param g Apontador para o grafo no qual o algoritmo de Dijkstra será executado
 * @param origem O vértice de origem para o qual os caminhos mais curtos serão calculados
 * @param distanciasFinais Array que será preenchido com as distâncias mais curtas da origem para cada vértice
 */
void Dijkstra(Grafo* g, int origem, int distanciasFinais[]);

/**
 * @brief Calcula a distância mínima entre dois vértices num grafo
 *
 * Esta função calcula a distância mínima entre dois vértices num grafo. O grafo, o vértice de origem e o
 * vértice de destino são passados como argumentos. A função retorna a distância mínima entre os vértices de origem e destino.
 *
 * @param g Apontador para o grafo onde a operação será realizada
 * @param origem Vértice de origem
 * @param destino Vértice de destino
 * @return int A distância mínima entre os vértices de origem e destino.
 */
int DistanciaMinimaEntreVertices(Grafo* g, int origem, int destino);

/**
 * @brief Verifica se existe um caminho entre dois vértices num grafo
 *
 * @param g Apontador para o grafo onde a operação será realizada
 * @param origem Vértice de origem
 * @param destino Vértice de destino
 * @return true Se existir um caminho válido entre os vértices de origem e destino
 * @return false Se não existir um caminho válido entre os vértices de origem e destino
 */
bool ExisteCaminhoGrafo(Grafo* g, int origem, int destino);

/**
 * @brief Cria um grafo com os caminhos mais curto para cada vertice
 *
 * @param g Apontador para o grafo original
 * @return Grafo* Apontador para o novo grafo criado
 */
Grafo* CriarGrafoCaminhoMaisCurto(Grafo* g);

#endif
