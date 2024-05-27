/**
 * @file grafo.h
 * @author Hugo Cruz (a23010)
 * @brief Ficheiro de cabeçalho para a estrutura de dados Grafo e funcionalidades.
 * @version 88.1
 * @date 2024-05-24
 *
 * @copyright Copyright (c) 2024
 *
 */

#ifndef GRAFO_H
#define GRAFO_H

/**
 * @def MAX
 * @brief Define um valor.
 *
 *  Esta macro define um valor maximo de 10.
 */
#define MAX 10

#include "vertices.h"

/**
 * @brief Estrutura de dados para um Grafo.
 *
 * A estrutura Grafo é uma representação de um grafo em memória, onde
 * inicioGrafo é um apontador para o primeiro vértice do grafo.
 *
 *
 */
typedef struct Grafo
{
	Vertice *inicioGrafo; ///< Apontador para o primeiro vértice do grafo.

} Grafo;

/**
 * @brief Apaga um grafo e limpa a memória alocada.
 *
 * Esta função apaga um grafo e liberta a memória alocada. Ela percorre todos os 
 * vértices e adjacências do grafo, apagando-os um a um
 * 
 * @param g Apontador para o grafo a ser apagado
 */
void ApagaGrafo(Grafo *g);

/**
 * @brief Cria um novo grafo.
 *
 * Esta função cria um novo grafo. Ela aloca memória para um novo grafo e 
 * retorna um apontador para o grafo criado.
 * 
 * @param inf Apontador para uma variável booleana que será definida como true se a criação do grafo for bem-sucedida, e false caso contrário.
 * @return Apontador para o novo grafo criado.
 */
Grafo *CriarGrafo(bool *inf);

/**
 * @brief Insere um novo vértice no grafo
 *
 * Esta função insere um novo vértice no grafo. Ela verifica se o valor do novo 
 * vértice já existe e, em seguida, insere-o no fim da lista de vertices.
 * 
 * @param g Apontador para o grafo onde o vértice será inserido.
 * @param novo O valor do novo vértice a ser inserido.
 * @param inf Apontador para uma variável booleana que será definida como true se a inserção for bem-sucedida, e false caso contrário.
 * @return Apontador para o grafo com o novo vértice inserido.
 */
Grafo *InserirVerticeGrafo(Grafo *g, int novo, bool *inf);

/**
 * @brief Insere uma nova aresta no grafo.
 *
 * Esta função insere uma nova aresta no grafo. Ela verifica se os vértices de 
 * origem e destino são válidos e, em seguida, insere a aresta entre eles.
 * 
 * @param g Apontador para o grafo onde a aresta será inserida.
 * @param origem O valor do vértice de origem da aresta.
 * @param destino O valor do vértice de destino da aresta.
 * @param peso O peso da aresta a ser inserida.
 * @param inf Apontador para uma variável booleana que será definida como true se a inserção for bem-sucedida, e false caso contrário.
 * @return Apontador para o grafo com a nova aresta inserida.
 */
Grafo *InserirAdjGrafo(Grafo *g, int origem, int destino, int peso, bool *inf);

/**
 * @brief Elimina um vértice do grafo.
 *
 * Esta função elimina um vértice do grafo. Ela verifica se o vértice a 
 * ser eliminado existe e, em seguida, remove-o do grafo.
 * 
 * @param g Apontador para o grafo do qual o vértice será eliminado.
 * @param id O valor do vértice a ser eliminado.
 * @param inf Apontador para uma variável booleana que será definida como true se a eliminação for bem-sucedida, e false caso contrário.
 * @return Apontador para o grafo com o vértice eliminado.
 */
Grafo *EliminaVerticeGrafo(Grafo *g, int id, bool *inf);

/**
 * @brief Elimina uma aresta do grafo.
 *
 * Esta função elimina uma aresta do grafo. Ela verifica se a aresta a ser eliminada
 * existe e, em seguida, remove-a do grafo.
 * 
 * @param g Apontador para o grafo do qual a aresta será eliminada.
 * @param origem O valor do vértice de origem da aresta.
 * @param destino O valor do vértice de destino da aresta.
 * @param inf Apontador para uma variável booleana que será definida como true se a eliminação for bem-sucedida, e false caso contrário.
 * @return Apontador para o grafo com a aresta eliminada.
 */
Grafo *EliminaAdjGrafo(Grafo *g, int origem, int destino, bool *inf);

/**
 * @brief Verifica se existe uma aresta entre dois vértices.
 *
 *  Esta função verifica se existe uma aresta entre dois vértices. Ela percorre todos os vértices e
 *  adjacências do grafo, procurando uma aresta entre os vértices de origem e destino.
 * 
 * @param inicio Apontador para o primeiro vértice do grafo.
 * @param origem O valor do vértice de origem da aresta.
 * @param destino O valor do vértice de destino da aresta.
 * @return bool  Retorna true se existe uma aresta entre os vértices origem e destino, e false caso contrário.
 */
bool ExisteAdjDoisVertices(Vertice *inicio, int origem, int destino);

#endif
