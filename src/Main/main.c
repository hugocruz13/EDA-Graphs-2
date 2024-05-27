/**
 * @file main.c
 * @author Hugo Cruz (a23010)
 * @brief Arquivo principal do programa
 *
 * Este programa implementa um grafo orientado e pesado onde utiliza listas de adjac�ncias e listas de v�rtices para cria��o do mesmo.
 *
 * @version 20.1
 * @date 2024-05-24
 *
 * @copyright Copyright (c) 2024
 *
 */

#include "libs/InputOutput.h"
#include "libs/caminhos.h"
#include <locale.h>

#pragma comment (lib,"libs\\Grafos.lib")

 /**
  * @brief Função princial do programa
  *
  * @param argc Números de argumentos
  * @param argv Array de strings
  */
int main(int argc, char* argv[])
{
	setlocale(LC_ALL, "Portugues"); // Configura o idioma Portugues
	bool inf;

	//Carrega dos ficheiros binário (Primeiro Grafo)
	Grafo* g = CarregaDados(argv[1], "v1.bin", "a1.bin"); 

	g = InserirVerticeGrafo(g, 7, &inf);
	g = InserirAdjGrafo(g, 7, 1, 54, &inf);

	bool recebe2 = ExisteCaminhoGrafo(g, 3, 6);
	//g = EliminaAdjGrafo(g, 3,4,&inf);
	recebe2 = ExisteCaminhoGrafo(g, 3, 6);

	MostraGrafo(g);

	//GuardaGrafo(g, "v2.bin", "a2.bin");

	//Carrga dos ficheiro csv (Segundo Grafo)
	Grafo * g2 = CarregaDados(argv[1], "naoexiste.bin", "naoexiste.bin");

	bool recebe = ExisteCaminhoGrafo(g2, 1, 3);

	g2 = EliminaVerticeGrafo(g2, 3, &inf);

	recebe = ExisteCaminhoGrafo(g2, 1, 3);

	MostrarCaminho(g, 1, 4);

	int total = DistanciaMinimaEntreVertices(g2, 1, 4);

	Grafo *g3 = CriarGrafoCaminhoMaisCurto(g);

	MostraGrafo(g3);
	ApagaGrafo(g2);
	

}