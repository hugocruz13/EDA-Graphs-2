/**
 * @file adjacente.h
 * @author Hugo Cruz (a23010)
 * @brief Este ficheiro contém as definições das estruturas de dados para as adjacências num grafo.
 * @version 41.0
 * @date 2024-05-15
 *
 * @copyright Copyright (c) 2024
 *
 */

#ifndef ADJACENTE_H
#define ADJACENTE_H

#include <stdbool.h>
#include <stdlib.h>

/**
 * @brief Estrutura de uma adjacência num grafo.
 *
 * Esta estrutura representa uma adjacência num grafo. Cada adjacência tem um identificador único,
 * um peso associado à adjacência e um apontador para a próxima adjacência na lista de adjacências (next).
 */
typedef struct Adjacente
{
    int id;                 ///< Identificador único da adjacência.
    int peso;               ///< Peso associado à adjacência.
    struct Adjacente *next; ///< Apontador para a próxima adjacência na lista de adjacências.

} Adjacente;

/**
 * @brief Estrutura de uma adjacência utilizada para armazenar adjacências em um ficheiro binário.
 *
 */
typedef struct AdjacenteFile
{
    int id;   ///< Identificador único da adjacência.
    int peso; ///< Peso associado à adjacência.

} AdjacenteFile;

/**
 * @brief Liberta a memória alocada para a lista
 * 
 * Esta função liberta a memória alocada para a lista de adjacências.
 * 
 * @param a Apontador para a lista a eliminar
 */
void ApagarAdjacencia(Adjacente *a);

 /**
  * @brief Cria uma nova adjacência.
  *
  * Esta função cria uma nova adjacência com um identificador de destino e um peso. Também 
  * inicializa os apontadores para a proxima adjacência
  * 
  * @param idDestino Identificador do vértice de destino de uma adjacências.
  * @param peso Distância entre adjacências.
  * @param inf Apontador para o estado da funcionalidade.
  * @return Apontador para uma nova adjacência.
  */
Adjacente *CriarAdjacencia(int idDestino, int peso, bool *inf); // Cria uma adjcencia

/**
 * @brief Insere e cria uma nova adjacência e coloca a no final de uma lista.
 *
 * Esta função cria e insere uma nova adjacência com o identificador do vértice de destino
 * e a distância entre as adjacências no final de uma lista de adjacências.
 *
 * @param inicio Aponta para o início da lista de adjacências.
 * @param idDestino Identificador do vértice de destino da adjacência.
 * @param peso Distância entre as adjacências.
 * @param inf Apontador para o estado da funcionalidade.
 * @return Aponta para o início da lista de adjacências após a inserção.
 */
Adjacente *InserirAdjacenciaLista(Adjacente *inicio, int idDestino, int peso, bool *inf); // Cria e coloca na lista de adjacencias

/**
 * @brief Elimina uma adjacência da lista de adjacências.
 *
 *  Esta função remove uma adjacência específica da lista de adjacências.
 * 
 * @param inicio Apontador para o início de uma lista de adjacências.
 * @param idDestino Identificador do destino da adjacência a eliminar.
 * @param inf Apontador para um bool que indica se a execução foi bem sucedida.
 * @return Apontador para o início da lista de adjacências.
 */
Adjacente *EliminaUmaAdj(Adjacente *inicio, int idDestino, bool *inf); // Apaga uma adjacencia

/**
 * @brief Apaga todas as adjacências de uma lista.
 * 
 * Esta função remove todas as adjacências de uma lista.
 *
 * @param adj Apontador para o início da lista de adjacências.
 * @param inf Apontador para um bool que indica se a execução foi bem sucedida.
 * @return NULL após apagar todas as adjacências.
 */
Adjacente *ElimanaTodasAdj(Adjacente *adj, bool *inf); // Apaga listas de adjacencia toda

#endif
