#include <bits/stdc++.h>
#include "graph_lib.h"
#include <chrono>
typedef long long ll;
using namespace std;

using namespace std;

int main() {

    string nome_arquivo = "grafo_W_1.txt";
    string saida_arquivo = "estudo_de_caso_1_peso.txt";
    
    vector<vector<pair<int, float>>> grafo1_vector = txt_to_weight_adjacency_vector(nome_arquivo);

    Caminho_Minimo_Vector(grafo1_vector, 10, 20);
    Caminho_Minimo_Vector(grafo1_vector, 10, 30);
    Caminho_Minimo_Vector(grafo1_vector, 10, 40);
    Caminho_Minimo_Vector(grafo1_vector, 10, 50);
    Caminho_Minimo_Vector(grafo1_vector, 10, 60);

    ofstream arquivo_de_saida_2(saida_arquivo, std::ios::app);

    // Teste de tempo do Dijkstra em vetores implementado com heap:

    double tempo_total_dijkstra_vector_heap = 0;
    
    srand(time(0));  

    for (int i = 0; i < 100; i++) {
        tempo_total_dijkstra_vector_heap += Dijkstra_Vector_Heap_With_Execution_Time(grafo1_vector, rand() % grafo1_vector.size());
    }

    double tempo_medio_dijkstra_vector_heap = tempo_total_dijkstra_vector_heap / 100;
    arquivo_de_saida_2 << "Tempo medio do Dijkstra em Vetor (implementado com Heap): " << tempo_medio_dijkstra_vector_heap << endl;

    // Teste de Tempo do Dijkstra em vetores implementado com vetor:

    double tempo_total_dijkstra_vector_vector = 0;
    
    srand(time(0));  

    for (int i = 0; i < 100; i++) {
        tempo_total_dijkstra_vector_vector += Dijkstra_Vector_Vector_With_Execution_Time(grafo1_vector, rand() % grafo1_vector.size());
    }

    double tempo_medio_dijkstra_vector_vector = tempo_total_dijkstra_vector_vector / 100;
    arquivo_de_saida_2 << "Tempo medio do Dijkstra em Vetor (implementado com Vetor): " << tempo_medio_dijkstra_vector_vector << endl;


    // Em matrizes:

    grafo1_vector = vector<vector<pair<int, float>>>();

    vector<vector<float>> grafo1_matrix = txt_to_weight_adjacency_matrix(nome_arquivo);

    // Teste de tempo do Dijkstra em matrizes implementado com heap:

    double tempo_total_dijkstra_matrix_heap = 0;
    
    srand(time(0));  

    for (int i = 0; i < 100; i++) {
        tempo_total_dijkstra_matrix_heap += Dijkstra_Matrix_Heap_With_Execution_Time(grafo1_matrix, rand() % grafo1_matrix.size());
    }

    double tempo_medio_dijkstra_matrix_heap = tempo_total_dijkstra_matrix_heap / 100;
    arquivo_de_saida_2 << "Tempo medio do Dijkstra em Matriz (implementado com Heap): " << tempo_medio_dijkstra_matrix_heap << endl;

    // Tesde de tempo do Dijkstra em matrizes implementado com vetor:

    double tempo_total_dijkstra_matrix_vector = 0;
    
    srand(time(0));  

    for (int i = 0; i < 100; i++) {
        tempo_total_dijkstra_matrix_vector += Dijkstra_Matrix_Vector_With_Execution_Time(grafo1_matrix, rand() % grafo1_matrix.size());
    }

    double tempo_medio_dijkstra_matrix_vector = tempo_total_dijkstra_matrix_vector / 100;
    arquivo_de_saida_2 << "Tempo medio do Dijkstra em Matriz (implementado com Vector): " << tempo_medio_dijkstra_matrix_vector << endl;

    arquivo_de_saida_2.close();

    return 0;
}
