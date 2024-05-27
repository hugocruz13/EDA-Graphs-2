/**
 * @file InputOutput.c
 * @author Hugo Cruz (a23010)
 * @brief Este ficheiro contém funções para carregar e mostrar dados. As funções de carregamento podem ler dados a partir de ficheiros.
 * @version 445.1
 * @date 2024-05-24
 *
 * @copyright Copyright (c) 2024
 *
 */
#include "InputOutput.h"

 /**
  * @brief Função para mostar vértices as adjacências.
  *
  * Esta função recebe um apontador para um vértice e imprime o vértice e as suas adjacências. Percorre a lista de vértices e para cada vértice, percorre a lista de adjacências, imprimindo as.
  *
  * @param grafo Apontador para o vértice a ser mostrado.
  */
void MostraVertice(Vertice* grafo)
{
	Vertice* aux = grafo;

	//Avança na lista de vertices e arestas e mostra todos os pesos das adjacência
	while (aux != NULL)
	{
		printf("\nVertice: %d\n\n", aux->id);

		Adjacente* adj = aux->nextA;

		while (adj)
		{
			if (adj->peso > 0 && adj->peso != INT_MAX)
			{
				printf("\tAdj: %d - (%d)\n", adj->id, adj->peso);

			}
			adj = adj->next;
		}

		aux = aux->nextV;
	}
	printf("\n");
}

/**
 * @brief Função para mostra um grafo.
 *
 * Esta função recebe um apontador para um grafo e imprime o grafo chamando a função MostraVertice para o vértice inicial do grafo.
 *
 * @param g Apontador  para o grafo a ser mostrado
 */
void MostraGrafo(Grafo* g)
{
	MostraVertice(g->inicioGrafo);
}

/**
 * @brief  Função para ler um arquivo.
 *
 * Esta função recebe o nome de um ficheiro, lê o ficheiro e retorna os dados lidos. Se o ficheiro não puder ser aberto, retorna NULL. Caso contrário, lê o ficheiro inteiro para uma string e retorna essa string.
 *
 * @param file Nome do arquivo a ser lido.
 * @return char* Retorna os dados lidos do arquivo.
 */
char* ReadFile(char* file)
{
	FILE* ficheiro = fopen(file, "r");
	if (ficheiro == NULL) return NULL;

	fseek(ficheiro, 0, SEEK_END); //Coloca o apontador para fille no fim do arquivo
	int tamanho = ftell(ficheiro); //Calcula o tamanho em bytes 
	fseek(ficheiro, 0, SEEK_SET); //Coloca o apontador para fille no início do arquivo

	char* dados = (char*)malloc(sizeof(char) * tamanho + 1); //Aloca memória para o tamanho do ficheiro + 1

	//Informa me o tamanho lido em bytes coloca o final da string como NULL
	if (dados != NULL)
	{
		size_t bytesRead = fread(dados, 1, tamanho, ficheiro);
		dados[bytesRead] = '\0';
	}
	else
	{
		free(dados);
		dados = NULL;
	}

	fclose(ficheiro);
	return dados;
}

/**
 * @brief Função para contar o número de linhas e colunas em uma string.
 *
 * Esta função recebe uma string de dados e dois apontadores para inteiros. Conta o número de linhas e colunas na string de dados e armazena esses valores nos inteiros apontados pelos apontadores.
 *
 * @param dados Dados a serem contados.
 * @param linha Apontador para o número de linhas.
 * @param coluna Apontador para o número de colunas.
 */
void Contador(char* dados, int* linha, int* coluna)
{
	char* saveptr_linha = NULL;
	char* saveptr_coluna = NULL;
	int colunasNaLinha = 0;
	*linha = 0;
	*coluna = 0;

	//Divide uma string em tokens separados por \n
	dados = strtok_s(dados, "\n", &saveptr_linha);

	while (dados != NULL)
	{
		(*linha)++;

		//Divide uma string em tokens separados por ;
		dados = strtok_s(dados, ";", &saveptr_coluna);

		while (dados != NULL)
		{
			colunasNaLinha++;
			//Coloca NULL e avança
			dados = strtok_s(NULL, ";", &saveptr_coluna); 
		}

		//Guarda o número maior de linhas contadas
		if (colunasNaLinha > *coluna)
		{
			*coluna = colunasNaLinha;
		}

		colunasNaLinha = 0;

		dados = strtok_s(NULL, "\n", &saveptr_linha);
	}

}

/**
 * @brief Função para criar vértices a partir de um arquivo CSV
 *
 * Esta função conta as linhas e colunas de um token e cria memória para um grafo.
 * Após a criação do mesmo carrega os vertices de um ficheiro CSV.
 *
 * @param dados Dados do arquivo CSV.
 * @return Grafo* Retorna um apontador para o grafo criado.
 */
Grafo* CriarVerticesCSV(char* dados)
{
	bool inf;
	int linhas = 0;
	int colunas = 0;

	//Conta linhas e colunas
	Contador(dados, &linhas, &colunas);

	Grafo* g = CriarGrafo(&inf);

	if (linhas == NULL || colunas == NULL) return NULL;
	//Cria o número de vertices que corresponde ao maior valor
	if (linhas <= colunas)
	{
		for (int i = 1; i <= colunas; i++)
		{
			g = InserirVerticeGrafo(g, i, &inf);

		}
	}
	else
	{
		for (int i = 1; i <= linhas; i++)
		{
			g = InserirVerticeGrafo(g, i, &inf);

		}
	}

	free(dados);
	return g;

}

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
Grafo* CarregaDadosCSV(char* file)
{
	bool inf;

	int linhas = 0, colunas = 0;
	char* saveptr_linha = NULL;
	char* saveptr_coluna = NULL;

	char* dados = ReadFile(file); //Le tudo do ficheiro csv
	char* dados_copy = strdup(dados); // Cria uma c�pia da string lida
	Grafo* g = CriarVerticesCSV(dados_copy); // Conta e cria os vertices

	//Divide uma string em tokens separados por \n
	dados = strtok_s(dados, "\n", &saveptr_linha);

	while (dados != NULL)
	{
		linhas++;
		dados = strtok_s(dados, ";", &saveptr_coluna); //Divide uma string em tokens separados por ;

		while (dados != NULL)
		{
			colunas++;
			g = InserirAdjGrafo(g, linhas, colunas, atoi(dados), &inf); //Tranforma uma string em inteiro
			dados = strtok_s(NULL, ";", &saveptr_coluna); //Coloca NULL e avança
		}
		colunas = 0;
		dados = strtok_s(NULL, "\n", &saveptr_linha);
	}

	free(dados);
	return g;

}

/**
 * @brief Função para guardar vértices em um ficheiro binário.
 *
 * Esta função guarda os vértices de um grafo num ficheiro binário. Percorre
 * todos os vértices do grafo e escreve-os no ficheiro.
 *
 * @param g Apontador para o grafo a guardar.
 * @param file Nome do arquivo.
 */
void GuardaVertices(Grafo* g, char* file)
{
	FILE* ficheiro = fopen(file, "wb");

	if (ficheiro == NULL) return;

	Vertice* auxV = g->inicioGrafo; 
	VerticeFile auxVF; // Estrutura sem apontadores

	//Adicina um cabeçalho para garantir que le o ficheiro correto
	auxVF.id = -7;
	fwrite(&auxVF, sizeof(VerticeFile), 1, ficheiro);

	//Escreve todos os vertices em modo binário
	while (auxV)
	{
		auxVF.id = auxV->id;
		fwrite(&auxVF, sizeof(VerticeFile), 1, ficheiro);
		auxV = auxV->nextV;
	}

	fclose(ficheiro);  // Fecha o ficheiro após a escrita
}

/**
 * @brief Função para carregar vértices de um arquivo
 *
 * Esta função carrega os vértices de um ficheiro binário para um grafo. Lê o
 * ficheiro e adiciona cada vértice ao grafo.
 *
 * @param file Nome do arquivo
 * @return Grafo* Retorna um apontador para o grafo criado
 */
Grafo* CarregaVertices(char* file)
{
	bool inf;
	FILE* ficheiro = fopen(file, "rb");

	if (ficheiro == NULL) return;

	Grafo* g = CriarGrafo(&inf);//Cria um grafo 

	VerticeFile auxVF;
	Vertice* novo = NULL;

	//Le o cabeçalho
	fread(&auxVF, sizeof(auxVF), 1, ficheiro) == 1;

	//Se for o ficheiro correto contínua a ler 
	if (auxVF.id == -7)
	{
		while (fread(&auxVF, sizeof(auxVF), 1, ficheiro) == 1)
		{
			g = InserirVerticeGrafo(g, auxVF.id, &inf);
		}
	}
	else
	{
		return NULL;
	}

	fclose(ficheiro);//Fecha o ficheiro 
	return g;
}

/**
 * @brief Função para guardar adjacências em um ficheiro binário
 *
 * Esta função guarda as adjacências de um grafo num ficheiro binário. Percorre todos
 * os vértices e as suas adjacências e escreve-os no ficheiro.
 *
 * @param g Apontador para o grafo a guardar
 * @param file  Nome do arquivo
 */
void GuardarAdjacentes(Grafo* g, char* file)
{
	FILE* ficheiro = fopen(file, "wb");

	if (ficheiro == NULL) return;

	Vertice* auxV = g->inicioGrafo;
	AdjacenteFile auxAF; // Estrutura sem apontadores

	//Adicina um cabeçalho para garantir que le o ficheiro correto
	auxAF.id = -8;
	fwrite(&auxAF, sizeof(AdjacenteFile), 1, ficheiro);

	//Avança com os vertices, mas apenas escreve as adjacências
	while (auxV)
	{
		Adjacente* auxA = auxV->nextA;

		while (auxA)
		{
			auxAF.id = auxA->id;
			auxAF.peso = auxA->peso;

			fwrite(&auxAF, sizeof(AdjacenteFile), 1, ficheiro);

			auxA = auxA->next;
		}

		//Marca para sair do while na leitura
		auxAF.id = -1;
		fwrite(&auxAF, sizeof(AdjacenteFile), 1, ficheiro);

		auxV = auxV->nextV;
	}

	fclose(ficheiro);
}

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
Grafo* CarregaAdjacencias(Grafo* grafo, char* file)
{
	bool inf;
	FILE* ficheiro = fopen(file, "rb");
	if (ficheiro == NULL) return NULL;

	AdjacenteFile auxAF;

	//Le o cabeçalho
	fread(&auxAF, sizeof(auxAF), 1, ficheiro) == 1;

	//Se for o ficheiro com um id diferente de -8 não le
	if (auxAF.id != -8) return NULL;

	Vertice* aux = grafo->inicioGrafo;

	
	while (aux)
	{
		//Le até encontar o -1 
		while (fread(&auxAF, sizeof(auxAF), 1, ficheiro) == 1 && auxAF.id != -1)
		{
			grafo = InserirAdjGrafo(grafo, aux->id, auxAF.id, auxAF.peso, &inf);
		}
		aux = aux->nextV;
	}


	fclose(ficheiro);
	return grafo;
}

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
void GuardaGrafo(Grafo* g, char* vertices, char* adjacencias)
{
	GuardaVertices(g, vertices);
	GuardarAdjacentes(g, adjacencias);
}

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
Grafo* CarregaGrafo(char* vertices, char* adjacencias)
{
	Grafo* g = CarregaVertices(vertices);
	if (g == NULL)return NULL;
	Grafo* grafo = CarregaAdjacencias(g, adjacencias);

	return grafo;
}

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
Grafo* CarregaDados(char* file, char* vertices, char* adjacencias)
{
	bool inf;

	Grafo* g = CriarGrafo(&inf);

	g = CarregaGrafo(vertices, adjacencias);
	
	//Se ocorrer algum erro com os ficheiros le o csv
	if (g != NULL)
	{
		return g;
	}
	else
	{
		g = CarregaDadosCSV(file);
		return g;
	}

}

/**
 * @brief Mostra o caminho de um vértice de origem a um vértice de destino.
 * 
 * @param verticeAnt Array que contém os antecessore de cada vertice
 * @param destino Destino final 
 */
void ImprimirCaminho(int verticeAnt[], int destino)
{
	int caminho[MAX];
	int contador = 0;
	int atual = destino;

     // Coloca num arrays todos os anteriores a cada vertice
	while (atual != -1)
	{
		caminho[contador++] = atual;
		atual = verticeAnt[atual];
	}

 	// Imprime o caminho do vértice de origem ao vértice de destino
	for (int i = contador - 1; i >= 0; i--)
	{
		printf("%d ", caminho[i]);
	}
}

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
void MostrarCaminho(Grafo* g, int origem, int destino)
{
	if (g == NULL)
	{
		return;
	}

	int distanciasFinais[MAX];
	int verticeAnt[MAX];

	// Inicializa o array de vértices anteriores
	for (int i = 0; i < MAX; i++)
	{
		verticeAnt[i] = -1;
	}

 	// Inicializa o array de vértices anteriores
	InicializarArrays(distanciasFinais);

	Dijkstra(g, origem, distanciasFinais, verticeAnt);

	if (distanciasFinais[destino] == INT_MAX)
	{
		printf("Nao existe caminho de %d para %d\n", origem, destino);
	}
	else
	{
		printf("Caminho de %d para %d: ", origem, destino);
		ImprimirCaminho(verticeAnt, destino);
		printf("\nDistancia: %d\n", distanciasFinais[destino]);
	}
}
