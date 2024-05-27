/**
 * @file grafo.c
 * @author Hugo Cruz (a23010)
 * @brief Ficheiro de implementação das funções que manipulam a estrutura de dados Grafo.
 * @version 156.1
 * @date 2024-05-24
 *
 * @copyright Copyright (c) 2024
 *
 */
#include "grafo.h"

 /**
  * @brief Apaga um grafo e limpa a memória alocada.
  *
  * Esta função apaga um grafo e liberta a memória alocada. Ela percorre todos os
  * vértices e adjacências do grafo, apagando-os um a um
  *
  * @param g Apontador para o grafo a ser apagado
  */
void ApagaGrafo(Grafo* g)
{
	if (g == NULL)
		return;

	Vertice* v = g->inicioGrafo;

	//Apagar todos os vertices e adjacências
	while (v != NULL)
	{
		Adjacente* a = v->nextA;
		while (a != NULL)
		{
			Adjacente* temp = a;
			a = a->next;
			ApagarAdjacencia(temp);
		}

		Vertice* tempV = v;
		v = v->nextV;
		ApagarVertice(tempV);
	}

	free(g);
}

/**
 * @brief Cria um novo grafo.
 *
 * Esta função cria um novo grafo. Ela aloca memória para um novo grafo e
 * retorna um apontador para o grafo criado.
 *
 * @param inf Apontador para uma variável booleana que será definida como true se a criação do grafo for bem-sucedida, e false caso contrário.
 * @return Apontador para o novo grafo criado.
 */
Grafo* CriarGrafo(bool* inf)
{
	*inf = false;

	Grafo* aux = (Grafo*)malloc(sizeof(Grafo)); //Aloca memória para um grafo

	if (aux == NULL)
	{
		*inf = false;
		return NULL;
	}

	aux->inicioGrafo = NULL;

	*inf = true;
	return aux;
}

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
Grafo* InserirVerticeGrafo(Grafo* g, int novo, bool* inf)
{
	*inf = false;

	if (g == NULL)
	{
		return NULL;
	}
	else
	{
		//Insere o novo vértice na lista de vertices do grafo
		g->inicioGrafo = InserirVerticeLista(g->inicioGrafo, novo, &inf);

		if (g->inicioGrafo != NULL)
		{
			*inf = true;
		}
	}

	return g;
}

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
Grafo* InserirAdjGrafo(Grafo* g, int origem, int destino, int peso, bool* inf)
{
	*inf = false;

	if (g == NULL)
	{
		return NULL;
	}
	
	//Coloca se no posição de origem 
	Vertice* origemVertice = ColocaNumaPosicaoLista(g->inicioGrafo, origem, &inf);

	if (origemVertice == NULL)
	{
		*inf = false;
		return g;
	}

	//Coloca se no posição de destino
	Vertice* destinoVertice = ColocaNumaPosicaoLista(g->inicioGrafo, destino, &inf);

	if (destinoVertice == NULL)
	{
		*inf = false;
		return g;
	}

	//Insere uma adjacência
	origemVertice->nextA = InserirAdjacenciaLista(origemVertice->nextA, destino, peso, &inf);

	return g;
}

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
Grafo* EliminaVerticeGrafo(Grafo* g, int id, bool* inf)
{
	*inf = false;

	if (g == NULL )
	{
		return NULL;
	}

	//Elimina o vértice da lista de vertices do grafo
	g->inicioGrafo = EliminarVertice(g->inicioGrafo, id, &inf);
	//Apaga todas as adjacências relacionadas com o id
	g->inicioGrafo = EliminarTodasAdjacenciasVertice(g->inicioGrafo, id, &inf);
	
	return g;
}

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
Grafo* EliminaAdjGrafo(Grafo* g, int origem, int destino, bool* inf)
{
	*inf = false;

	if (g == NULL)
	{
		return NULL;
	}

	//Coloca se no posição de origem
	Vertice* origemVertice = ColocaNumaPosicaoLista(g->inicioGrafo, origem, &inf);

	if (origemVertice == NULL)
	{
		*inf = false;
		return g;
	}

	//Coloca se no posição de destino
	Vertice* destinoVertice = ColocaNumaPosicaoLista(g->inicioGrafo, destino, &inf);

	if (destinoVertice == NULL)
	{
		*inf = false;
		return g;
	}

	//Apaga um adjacência entre dois vértices
	origemVertice->nextA = EliminaUmaAdj(origemVertice->nextA, destino, &inf);

	return g;
}

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
bool ExisteAdjDoisVertices(Vertice* inicio, int origem, int destino)
{
	if (inicio == NULL )
	{
		return false;
	}

	if (ExisteVertice(inicio, origem))
	{
		Vertice* auxV = inicio;

		while (auxV)
		{
			Adjacente* auxA = auxV->nextA;

			while (auxA)
			{
				//Procura dois vértices e  informa se os mesmos existem
				if (auxV->id == origem && auxA->id == destino)
				{
					if (auxA->peso > 0)
					{
						return true;
					}
				}

				auxA = auxA->next;
			}

			auxV = auxV->nextV;
		}

		return false;
	}
	else
	{
		return false;
	}
}