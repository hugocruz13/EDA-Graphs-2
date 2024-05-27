/**
 * @file vertices.h
 * @author Hugo Cruz (a23010)
 * @brief Este ficheiro contém as definições das estruturas de dados para os vértices num grafo.
 * @version 92.1
 * @date 2024-05-24
 *
 * @copyright Copyright (c) 2024
 *
 */

#ifndef VERTICE_H
#define VERTICE_H

#include "adjacente.h"

/**
 * @brief Estrutura de um vértice num grafo.
 *
 * Esta estrutura representa um vértice num grafo. Cada vértice tem um identificador único (id),
 * um apontador para o próximo vértice na lista de vértices (nextV), um apontador para o primeiro
 * adjacente na lista de adjacências (nextA) e um indicador se o vértice foi visitado ou não (visitado).
 */
typedef struct Vertice
{
	int id;				   ///< Identificador único do vértice.
	struct Vertice *nextV; ///< Apontador para o próximo vértice na lista de vértices.
	Adjacente *nextA;	   ///< Apontador para o primeiro adjacente na lista de adjacências.

} Vertice;

/**
 * @brief Estrutura de um vértice utilizada para armazenar vértices em um ficheiro binário.
 * 
 */
typedef struct VerticeFile
{
	int id; ///< Identificador único do vértice.

} VerticeFile;

/**
 * @brief Liberta a memória alocada para um vértice.
 *
 * Esta função liberta memória alocada para um vértices
 *
 * @param v Apontador para o vértice (Vertice) a ser liberado.
 */
void ApagarVertice(Vertice *v);

/**
 * @brief Aloca memória para um novo vértice.
 *
 * Esta função aloca memória para um novo vértice. Retorna um apontador para o vértice 
 * criado e atualiza o valor de inf para indicar o sucesso ou falha na criação do vértice.
 * 
 * @param id Aloca memória para um novo vértice.
 * @return Apontador para o vértice criado.
 */
Vertice* CriarVertice(int id);

/**
 * @brief Verifica a existência de um vértice com um determinado identificador.
 *
 * Esta função verifica a existência de um vértice com um determinado identificador na lista de vértices. Retorna verdadeiro se o vértice existir, falso caso contrário.
 * 
 * @param inicio Apontador para o início da lista de vértices.
 * @param id Identificador único do vértice a ser verificado.
 * @return Retorna verdadeiro se o vértice existir, falso caso contrário.
 */
bool ExisteVertice(Vertice *inicio, int id);

/**
 * @brief Insere um novo vértice na lista de vértices.
 *
 * Esta função cria e insere um novo vértice na lista de vértices. Retorna um apontador
 * para o início da lista de vértices e atualiza o valor de inf para indicar o sucesso 
 * ou falha na inserção do vértice.
 * 
 * @param inicio Apontador para o início da lista de vértices.
 * @param id Identificador único do novo vértice.
 * @param inf Apontador para um bool que indica se a execução correu bem.
 * @return Apontador para um booleano que indica o sucesso ou falha na inserção do vértice.
 */
Vertice *InserirVerticeLista(Vertice *inicio, int id, bool *inf);

/**
 * @brief Posiciona a lista no vértice com o identificador fornecido.
 *
 * Esta função posiciona a lista no vértice com o identificador fornecido. Retorna um 
 * apontador para o vértice encontrado ou NULL se não for encontrado e atualiza o valor
 *  de inf para indicar o sucesso ou falha na operação.
 * 
 * @param inicio Apontador para o início da lista de vértices.
 * @param id Identificador único do vértice a ser encontrado.
 * @param inf Apontador para um booleano que indica o sucesso ou falha na operação.
 * @return Apontador para o vértice encontrado ou NULL se não for encontrado.
 */
Vertice *ColocaNumaPosicaoLista(Vertice *inicio, int id, bool *inf);

/**
 * @brief Elimina um vértice da lista de vértices.
 * 
 * Esta função elimina um vértice da lista de vértices. Retorna um apontador para 
 * o início da lista de vértices e atualiza o valor de inf para indicar o sucesso ou falha na operação.
 * 
 * @param inicio Apontador para o início da lista de vértices.
 * @param id Identificador único do vértice a ser eliminado.
 * @param inf Apontador para um booleano que indica o sucesso ou falha na operação.
 * @return Apontador para o início da lista de vértices.
 */
Vertice *EliminarVertice(Vertice *inicio, int id, bool *inf);

/**
 * @brief Elimina todas as adjacências de um vértice.
 * 
 * sta função elimina todas as adjacências de um vértice. Retorna um apontador para o início 
 * da lista de vértices e atualiza o valor de inf para indicar o sucesso ou falha na operação.
 * 
 * @param inicio Apontador para o início da lista de vértices.
 * @param id Identificador único do vértice cujas adjacências serão eliminadas.
 * @param inf Apontador para um booleano que indica o sucesso ou falha na operação.
 * @return Apontador para o início da lista de vértices.
 */
Vertice *EliminarTodasAdjacenciasVertice(Vertice *inicio, int id, bool *inf);

#endif
