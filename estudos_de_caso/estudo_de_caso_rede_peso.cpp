#include <bits/stdc++.h>
#include "graph_lib.h"
#include <chrono>
typedef long long ll;
using namespace std;

using namespace std;

string nome_arquivo = "grafo_rede.txt";
string nome_arquivo2 = "grafo_rede_vertices.txt";
string saida_arquivo = "estudo_de_caso_rede_peso.txt";


// Função para ler os nomes dos vértices de um arquivo
map<int, string> readVertexNames(const string& nome_arquivo2) {
    ifstream file(nome_arquivo2);
    map<int, string> vertexNames;
    int index;
    string name;

    while (file >> index >> name) {
        vertexNames[index] = name;
    }
    return vertexNames;
}



int main() {

    vector<vector<int>> graph = readGraph(nome_arquivo);
    map<int, string> vertexNames = readVertexNames(nome_arquivo2);
    
    vector<vector<pair<int, float>>> grafo_rede_vector = txt_to_weight_adjacency_vector(nome_arquivo);

    ofstream arquivo_de_saida_2(saida_arquivo, std::ios::app);

    // Lista de pares de vértices de origem e destino
    vector<pair<int, int>> pares = {
        {2722, 11365},
        {2722, 471365},
        {2722, 5709},
        {2722, 11386},
        {2722, 343930}
    };

    for (const auto& par : pares) {
        // Chama a função de caminho mínimo e captura o caminho retornado
        vector<int> caminho = Caminho_Minimo_Vector(grafo_rede_vector, par.first, par.second);
        
        // Imprime os nomes dos vértices do caminho no arquivo de saída
        arquivo_de_saida_2 << "Caminho de " << vertexNames[par.first] << " a " << vertexNames[par.second] << ": ";
        printCaminho(caminho, vertexNames, arquivo_de_saida_2);
    }

    arquivo_de_saida_2.close();

    return 0;
}
