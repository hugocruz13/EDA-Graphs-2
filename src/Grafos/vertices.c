/**
 * @file vertices.c
 * @author Hugo Cruz (a23010)
 * @brief  Implementação de funções para manipular vértices
 * @version 170.0
 * @date 2024-05-23
 *
 * @copyright Copyright (c) 2024
 *
 */
#include "vertices.h"

 /**
  * @brief Liberta a memória alocada para um vértice.
  *
  * Esta função liberta memória alocada para um vértices
  *
  * @param v Apontador para o vértice (Vertice) a ser liberado.
  */
void ApagarVertice(Vertice* v)
{
	free(v);
}

/**
 * @brief Aloca memória para um novo vértice.
 *
 * Esta função aloca memória para um novo vértice. Retorna um apontador para o vértice
 * criado e atualiza o valor de inf para indicar o sucesso ou falha na criação do vértice.
 *
 * @param id Aloca memória para um novo vértice.
 * @return Apontador para o vértice criado.
 */
Vertice* CriarVertice(int id)
{
	Vertice* aux = (Vertice*)malloc(sizeof(Vertice)); //Aloca memória para uma estrutura vertice

	if (aux == NULL) return NULL;

	aux->id = id;
	aux->nextV = NULL;
	aux->nextA = NULL;

	return aux;
}

/**
 * @brief Verifica a existência de um vértice com um determinado identificador.
 *
 * Esta função verifica a existência de um vértice com um determinado identificador na lista de vértices. Retorna verdadeiro se o vértice existir, falso caso contrário.
 *
 * @param inicio Apontador para o início da lista de vértices.
 * @param id Identificador único do vértice a ser verificado.
 * @return Retorna verdadeiro se o vértice existir, falso caso contrário.
 */
bool ExisteVertice(Vertice* inicio, int id)
{
	Vertice* aux = inicio;

	//Corre a lista até encontar o vertice procurado
	while (aux)
	{
		if (aux->id == id)
		{
			return true;
		}

		aux = aux->nextV;
	}

	return false;

}

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
Vertice* InserirVerticeLista(Vertice* inicio, int id, bool* inf)
{
	*inf = false;

	Vertice* novo = CriarVertice(id);

	*inf = false;


	if (novo == NULL)
	{
		return inicio;
	}

	//Coloca o novo vertice no inicio da lista
	if (inicio == NULL)
	{
		inicio = novo;
		*inf = true;
		return inicio;
	}
	
	// Se o vertice já existir não cria elimina o vertice criado 
	if (ExisteVertice(inicio, novo->id))
	{
		free(novo);
		return inicio;
	}
	else
	{
		//Ajuda a encontar a posição para inserir o vértice
		Vertice* ant = NULL;
		Vertice* aux = inicio;

		// Percorre a lista até encontrar um vértice com um id maior que o novo vértice
		while (aux != NULL && aux->id < novo->id)
		{
			ant = aux;
			aux = aux->nextV;
		}

		// Se o ant for null insere no início da lista
		if (ant == NULL)
		{
			novo->nextV = inicio;
			inicio = novo;
		}
		else
		{
			// Caso contrário, insere o novo vértice na posição correta
			novo->nextV = aux;
			ant->nextV = novo;
		}

		*inf = true;
		return inicio;
	}
}

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
Vertice* ColocaNumaPosicaoLista(Vertice* inicio, int id, bool* inf)
{
	*inf = false;

	if (inicio == NULL)
	{
		*inf = false;
		return NULL;
	}

	Vertice* aux = inicio;

	//Encontra uma posição e retorna a posição atual e não o inicio da lista
	while (aux)
	{
		if (aux->id == id)
		{
			*inf = true;
			return aux;
		}
		aux = aux->nextV;
	}

	*inf = false;
	return NULL;
}

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
Vertice* EliminarVertice(Vertice* inicio, int id, bool* inf)
{
	*inf = false;

	if (inicio == NULL)
	{
		return NULL;
	}

	//Ajuda a encontar a posição para inserir o vértice
	Vertice* ant = NULL;
	Vertice* aux = inicio;


	while (aux->id != id)
	{
		ant = aux;
		aux = aux->nextV;
	}

	if (!aux)
	{
		return inicio;
	}

	// Se o vértice a ser removido é o primeiro da lista
	if (ant == NULL)
	{
		aux->nextA = ElimanaTodasAdj(aux->nextA, &inf);
		if (*inf == false) return inicio;
		inicio = aux->nextV;
	}
	else
	{
		// Caso contrário, remove o vértice da lista
		ant->nextV = aux->nextV;
	}

	// Elimina todas as adjacências do vértice e apaga o vértice
	ApagarVertice(aux);
	*inf = true;
	return inicio;
}

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
Vertice* EliminarTodasAdjacenciasVertice(Vertice* inicio, int id, bool* inf)
{
	*inf = false;

	if (inicio == NULL)
	{
		return NULL;
	}

	// Percorre todos os vértices da lista
	Vertice* aux = inicio;

	while (aux)
	{
		// Remove a adjacência do vértice atual
		aux->nextA = EliminaUmaAdj(aux->nextA, id, &inf);
		aux = aux->nextV;
	}

	*inf = true;

	return inicio;
}
