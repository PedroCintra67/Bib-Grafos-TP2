#ifndef GRAPH_H
#define GRAPH_H

#include <vector>
#include <fstream>
using namespace std;

// Funções de receber entrada

vector<vector<bool>> txt_to_adjacency_matrix(const string& nome_arquivo, string nome_do_arquivo_de_saida_principal = "resultados.txt");
vector<vector<int>> txt_to_adjacency_vector(const string& nome_arquivo, string nome_do_arquivo_de_saida_principal = "resultados.txt");

// Funções para obter informações básicas do grafo (vetor de adjacência):

int minDegree(const vector<vector<int>>& grafo);
int maxDegree(const vector<vector<int>>& grafo);
double averageDegree(const vector<vector<int>>& grafo);
double medianDegree(const vector<vector<int>>& grafo);

// Funções para percorrer o grafo (vetor de adjacência):

void BFS_tree_vector(const vector<vector<int>>& graph, int origem, string nome_do_arquivo_de_saida = "arvoreBFS.txt");
void DFS_tree_vector(const vector<vector<int>>& graph, int origem, string nome_do_arquivo_de_saida = "arvoreDFS.txt");

void Distancia_vector(const vector<vector<int>>& graph, int origem, int destino);
void Diametro_aproximado_vector(const vector<vector<int>>& graph);
void Diametro_vector(const vector<vector<int>>& graph);

// Funções para percorrer o grafo (matriz de adjacência):

void DFS_tree_matrix(const vector<vector<bool>>& matrix, int origem, string nome_do_arquivo_de_saida = "arvoreDFS.txt");
void BFS_tree_matrix(const vector<vector<bool>>& matrix, int origem, string nome_do_arquivo_de_saida = "arvoreBFS.txt");

void Distancia_matrix(const vector<vector<bool>>& matrix, int origem, int destino);
void Diametro_aproximado_matrix(const vector<vector<bool>>& matrix);
void Diametro_matrix(const vector<vector<bool>>& matrix);

// Contabilizando o tempo:

double DFS_tree_vector_with_execution_time(const vector<vector<int>>& graph, int origem, string nome_do_arquivo_de_saida = "arvoreDFS.txt");
double BFS_tree_vector_with_execution_time(const vector<vector<int>>& graph, int origem, string nome_do_arquivo_de_saida = "arvoreBFS.txt");

double DFS_tree_matrix_with_execution_time(const vector<vector<bool>>& matrix, int origem, string nome_do_arquivo_de_saida = "arvoreDFS.txt");
double BFS_tree_matrix_with_execution_time(const vector<vector<bool>>& matrix, int origem, string nome_do_arquivo_de_saida = "arvoreBFS.txt");


// TP2:

// Funções de receber entrada

vector<vector<float>> txt_to_weight_adjacency_matrix(const string& nome_arquivo);
vector<vector<pair<int, float>>> txt_to_weight_adjacency_vector(const string& nome_arquivo);

// Funções para percorrer o grafo (vetor de adjacência):

vector<float> Dijkstra_Vector_Vector(const vector<vector<pair<int,float>>>& graph, int origem);
vector<float> Dijkstra_Vector_Heap(const vector<vector<pair<int,float>>>& graph, int origem);
void Caminho_Minimo_Vector(const vector<vector<pair<int, float>>>& graph, int origem, int destino);

// Funções para percorrer o grafo (matriz de adjacência):

vector<float> Dijkstra_Matrix_Heap(const vector<vector<float>>& matrix, int origem);
vector<float> Dijkstra_Matrix_Vector(const vector<vector<float>>& matrix, int origem);
void Caminho_Minimo_Matrix(const vector<vector<float>>& matrix, int origem, int destino);

// Contabilizando o tempo:

double Dijkstra_Vector_Vector_With_Execution_Time(const vector<vector<pair<int,float>>>& graph, int origem);
double Dijkstra_Vector_Heap_With_Execution_Time(const vector<vector<pair<int,float>>>& graph, int origem);

double Dijkstra_Matrix_Vector_With_Execution_Time(const vector<vector<float>>& matrix, int origem);
double Dijkstra_Matrix_Heap_With_Execution_Time(const vector<vector<float>>& matrix, int origem);

// Tratando da Rede de colaboradores

vector<pair<int, string>> txt_to_dictionary(const string& nome_arquivo_grafo, const string& nome_arquivo_dicionario);
void Caminho_Minimo_Rede(const vector<vector<pair<int, float>>>& graph, string nome_origem, string nome_destino, const vector<pair<int,string>>& dict);

#endif
