/**
 * @file adjacente.c
 * @author Hugo Cruz (a23010)
 * @brief Implementação de funções para manipular listas de adjacências.
 * @version 93.0
 * @date 2024-05-15
 *
 * @copyright Copyright (c) 2024
 *
 */
#include "adjacente.h"

 /**
  * @brief Liberta a memória alocada para a lista
  *
  * Esta função liberta a memória alocada para a lista de adjacências.
  *
  * @param a Apontador para a lista a eliminar
  */
void ApagarAdjacencia(Adjacente* a)
{
	if (a != NULL)
	{
		free(a); //Liberta a memória alocada
	}
}

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
Adjacente* CriarAdjacencia(int idDestino, int peso, bool* inf)
{
	*inf = false;

	Adjacente* aux = (Adjacente*)malloc(sizeof(Adjacente)); // Aloca memória para a estrura Adjacente
	if (aux == NULL) return NULL;

	aux->id = idDestino; //Atribui valor a nova adjacência
	aux->peso = peso;
	aux->next = NULL; //Inicializa o apontador para next com um valor nulo

	*inf = true;
	return aux;
}


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
Adjacente* InserirAdjacenciaLista(Adjacente* inicio, int idDestino, int peso, bool* inf)
{
	*inf = false;

	Adjacente* adj = CriarAdjacencia(idDestino, peso, inf); //Cria uma adjacências

	if (adj == NULL)
	{
		perror("CriarAdjacencia");
		return NULL;
	}

	if (inicio == NULL)
	{
		inicio = adj;
	}
	else
	{
		Adjacente* aux = inicio;

		while (aux->next != NULL) //Coloca-se no fim da lista
		{
			aux = aux->next;
		}

		aux->next = adj; //Adiciona a lista
	}

	*inf = true;
	return inicio;
}

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
Adjacente* EliminaUmaAdj(Adjacente* inicio, int idDestino, bool* inf)
{
	*inf = false;

	if (inicio == NULL)
	{
		return NULL;
	}

	Adjacente* aux = inicio;//Guarda a adjacências atual 
	Adjacente* ant = NULL; //Guarda a adjacências anterior 

	while (aux && aux->id != idDestino) // Anda até encontar o destino ou o fim da lista
	{
		ant = aux;
		aux = aux->next;
	}

	//Não encontrou o vertice a ser removido
	if (aux == NULL)
	{
		*inf = false;
		return inicio;
	}

	if (ant == NULL) //Insere no topo da lista
	{
		inicio = aux->next;
	}
	else
	{
		ant->next = aux->next;
	}

	ApagarAdjacencia(aux);
	*inf = true;
	return inicio;
}

/**
 * @brief Apaga todas as adjacências de uma lista.
 *
 * Esta função remove todas as adjacências de uma lista.
 *
 * @param adj Apontador para o início da lista de adjacências.
 * @param inf Apontador para um bool que indica se a execução foi bem sucedida.
 * @return NULL após apagar todas as adjacências.
 */
Adjacente* ElimanaTodasAdj(Adjacente* adj, bool* inf)
{
	*inf = false;

	if (adj == NULL) return NULL;

	Adjacente* aux = adj;

	//Corre a lista de adjacências até ao fim e apaga todas as adjacências.
	while (aux)
	{
		if (aux)
		{
			adj = aux->next;
		}

		ApagarAdjacencia(aux);
		aux = adj;
	}

	adj = NULL;
	*inf = true;
	return adj;
}

