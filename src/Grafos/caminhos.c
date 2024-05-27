/**
 * @file caminhos.c
 * @author Hugo Cruz (a23010)
 * @brief Este ficheiro contém funções para manipular caminhos num grafo.
 * @version 210.1
 * @date 2024-05-19
 *
 * @copyright Copyright (c) 2024
 *
 */

#include "caminhos.h"

 /**
  * @brief Inicializa os arrays de distâncias.
  *
  * Esta função inicializa os arrays de distâncias, atribuindo a cada elemento o valor máximo de um inteiro.
  *
  * @param dis Array de distâncias a ser inicializado.
  */
void InicializarArrays(int* dis[])
{
	if (dis == NULL)
	{
		return;
	}

	//Inicializa um arrays no valor maximo de um inteiro
	for (int i = 0; i < MAX; i++)
	{
		dis[i] = INT_MAX;
	}
}

/**
 * @brief Conta o número de vértices num grafo.
 *
 * Esta função conta o número de vértices num grafo. Retorna o número de vértices no grafo.
 *
 * @param g O grafo a ser analisado.
 * @return int O número de vértices no grafo.
 */
int ContadorVertices(Grafo* g)
{
	if (g == NULL)
	{
		return 0;
	}

	int contador = 0;

	Vertice* aux = g->inicioGrafo;

	//Avança na lista e conta o número de vertices.
	while (aux)
	{
		contador++;
		aux = aux->nextV;
	}

	return contador;
}

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
int DistanciaMinima(int distancia[], bool visitado[], int n)
{
	if (distancia == NULL || visitado == NULL)
	{
		return -1;
	}

	int min = INT_MAX;
	int posicao = -1;

	//Corre o arrays de booleanos verifica se o vértice já foi visitado e encontrar o valor mínimo das adjacências
	for (int i = 1; i <= n; i++)
	{
		if (visitado[i] == false && distancia[i] <= min)
		{
			min = distancia[i];
			posicao = i;
		}
	}

	return posicao;
}


/**
 * @brief Algoritmo de Dijkstra
 * 
 * Esta função implementa o algoritmo de Dijkstra, que é usado para encontrar os caminhos mais 
 * curtos de um vértice de origem para todos os outros vértices num grafo.
 * 
 * @param g Apontador para o grafo no qual o algoritmo de Dijkstra será executado
 * @param origem O vértice de origem para o qual os caminhos mais curtos serão calculados
 * @param distanciasFinais Array que será preenchido com as distâncias mais curtas da origem para cada vértice
 * @param verticeAnt Array que será preenchido com os antecessores de cada vértice
 */
void Dijkstra(Grafo* g, int origem, int distanciasFinais[], int verticeAnt[])
{
	if (g == NULL)
	{
		return;
	}

	//Arrays temporario
	int distancias[MAX];
	bool inf, visitado[MAX] = { false };

	InicializarArrays(distancias);

	int numVertices = ContadorVertices(g);

	//O peso das origens é sempre 0
	distancias[origem] = 0;
	distanciasFinais[origem] = 0;

	for (int i = 0; i < numVertices; i++)
	{
		//Encontra a posição da adjacência com menor valor
		int verticeAtual = DistanciaMinima(distancias, visitado, numVertices);

		visitado[verticeAtual] = true; //Coloca como visitado 

		//Colocamos no vertice
		Vertice* auxV = ColocaNumaPosicaoLista(g->inicioGrafo, verticeAtual, &inf);
		if (auxV == NULL) return;
		Adjacente* auxA = auxV->nextA;

		//Avançamos com as adjacências
		while (auxA)
		{
			//Se o vertice não foi visitado e o peso anterior mais o atual é maior que o guardado  
			if (!visitado[auxA->id] && distancias[verticeAtual] + auxA->peso < distancias[auxA->id])
			{
				//Verifica se existe adjacências entre a origem e adjacência atual
				if (ExisteAdjDoisVertices(auxV, verticeAtual, auxA->id))
				{
					//Soma e guarda o necessário
					distancias[auxA->id] = distancias[verticeAtual] + auxA->peso;
					distanciasFinais[auxA->id] = distancias[auxA->id];
					verticeAnt[auxA->id] = verticeAtual;
				}
			}
			auxA = auxA->next;
		}
	}
}

/**
 * @brief Calcula a distância mínima entre dois vértices num grafo
 *
 * Esta função calcula a distância mínima entre dois vértices num grafo.
 * A função retorna a distância mínima entre os vértices de origem e destino.
 *
 * @param g Apontador para o grafo onde a operação será realizada
 * @param origem Vértice de origem
 * @param destino Vértice de destino
 * @return int A distância mínima entre os vértices de origem e destino.
 */
int DistanciaMinimaEntreVertices(Grafo* g, int origem, int destino)
{
	if (g == NULL)
	{
		return -1;
	}

	int valor = 0;
	int distanciasFinais[MAX];
	int verticeAnt[MAX];

	InicializarArrays(distanciasFinais);
	Dijkstra(g, origem, distanciasFinais, verticeAnt);

	//Verifica recebe o peso de uma adjacência
	if (distanciasFinais[destino] != INT_MAX && distanciasFinais[destino] > 0)
	{
		return distanciasFinais[destino];
	}
	else
	{
		return valor;
	}

}

/**
 * @brief Verifica se existe um caminho entre dois vértices num grafo
 *
 * Esta função verifica se existe um caminho entre dois vértices num grafo. O grafo, o vértice de origem
 * e o vértice de destino são passados como argumentos. A função retorna verdadeiro se existir um caminho
 *  válido entre os vértices de origem e destino, e falso caso contrário.
 *
 * @param g Apontador para o grafo onde a operação será realizada
 * @param origem Vértice de origem
 * @param destino Vértice de destino
 * @return true Se existir um caminho válido entre os vértices de origem e destino
 * @return false Se não existir um caminho válido entre os vértices de origem e destino
 */
bool ExisteCaminhoGrafo(Grafo* g, int origem, int destino)
{
	if (g == NULL)
	{
		return false;
	}

	int verticeAnt[MAX];
	int distanciasFinais[MAX];

	InicializarArrays(distanciasFinais);
	Dijkstra(g, origem, distanciasFinais, verticeAnt);

	//Verifica recebe o peso de uma adjacência e verifica se é valido 
	if (distanciasFinais[destino] != INT_MAX && distanciasFinais[destino] > 0)
	{
		return true;
	}
	else
	{
		return false;
	}
}

/**
 * @brief Cria um grafo com os caminhos mais curto para cada vertice
 *
 * Esta função cria um novo grafo com os caminhos mais curtos para cada vértice
 *
 * @param g Apontador para o grafo original
 * @return Grafo* Apontador para o novo grafo criado
 */
Grafo* CriarGrafoCaminhoMaisCurto(Grafo* g)
{
	bool inf;
	int distanciasFinais[MAX];
	int verticeAnt[MAX];

	int numVertices = ContadorVertices(g);

	Grafo* novo = CriarGrafo(&inf);

	//Cria os vertices
	for (int i = 1; i <= numVertices; i++)
	{
		novo = InserirVerticeGrafo(novo, i, &inf);
	}

	Vertice* aux = novo->inicioGrafo;

	//Quantos houver vertices
	while (aux)
	{

		InicializarArrays(distanciasFinais);
		Dijkstra(g, aux->id, distanciasFinais, verticeAnt); // Recebe um arrays com os valores mínimos de uma origem a todos os vertices

		for (int j = 1; j <= numVertices; j++)
		{
			if (distanciasFinais[j] == INT_MAX)
			{
				novo = InserirAdjGrafo(novo, aux->id, j, 0, &inf);
			}
			else
			{
				novo = InserirAdjGrafo(novo, aux->id, j, distanciasFinais[j], &inf);
			}
		}

		aux = aux->nextV;
	}

	return novo;
}