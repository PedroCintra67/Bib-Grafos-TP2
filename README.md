# Biblioteca para manipulação de Grafos
Esse é o repositório para a parte 2 do trabalho da disciplina Teoria dos Grafos (2024.2). O trabalho foi feito por Daniel Barros e Pedro Cintra.

# Como utilizar a biblioteca?

Para utilizar a biblioteca, é necessário ter os arquivos `graph_lib.cpp` e `graph_lib.h` no mesmo repositório do arquivo que usará a biblioteca. Então, basta colocar 

```
#include "graph_lib.h"
```

no começo do arquivo para que o compilador reconheça de onde estão vindo as funções que serão utilizadas.

Para compilar, precisamos também explicitar o nome do arquivo ".cpp" que contém as funções da biblioteca.

Todos os arquivos ".txt" de saída serão criados na mesma pasta em que se encontram os dois arquivos necessários para a utilização da biblioteca.

```
g++ arquivo.cpp graph_lib.cpp
```

# Funções para receber entradas

Foram criadas 2 funções diferentes que recebem a string correspondente ao nome do arquivo de texto de entrada (ex.: `"grafo_teste.txt"`) e retornam o grafo em uma das duas representações pedidas (vetor de adjacência ou matriz de adjacência).

Quando qualquer uma das funções é chamada, é retornado um arquivo contendo algumas informações básicas sobre o grafo: número de vértices e arestas, grau máximo, grau mínimo, grau médio, mediana de grau e informações sobre componentes conexas.

1. `txt_to_adjacency_vector`
2. `txt_to_adjacency_matrix`

Ex.:

```
vector<vector<int>> grafo_teste = txt_to_adjacency_vector(nome_arquivo);
vector<vector<bool>> grafo_teste2 = txt_to_adjacency_matrix(nome_arquivo);
```

# Funções que geram árvores (BFS e DFS):

As funções a seguir percorrem o grafo através de uma Busca em Largura ou Busca em Profundidade a partir de um vértice escolhido pelo usuário e retornam um arquivo ".txt" contendo informações de nível e pai, representando a árvore relacionada à busca.

Por padrão (caso o usuário omita esse parâmetro), o nome do arquivo é "arvoreDFS.txt" ou "arvoreBFS.txt", mas o usuário pode passar a string correspondente ao nome do arquivo de saída como parâmetro para essas funções.

1. `BFS_tree_vector`
2. `DFS_tree_vector`
3. `BFS_tree_matrix`
4. `DFS_tree_matrix`

Ex.:

```
DFS_tree_vector(grafo_teste, 1, "arvoreDFS_grafo_teste.txt");
```

Ou, usando uma BFS para matriz de adjacência:

```
BFS_tree_matrix(grafo_teste2, 3, "arvoreBFS_grafo_teste.txt");
```

# Distância e Diâmetro:

Usando a Busca em Largura (BFS) como base, criamos a função Distancia, que calcula o comprimento do menor caminho entre dois vértices, e a função Diametro, que calcula a maior das menores distâncias entre dois vértices quaisquer de um grafo.

Novamente, implementamos essas duas funções para cada uma das representações possíveis.

Ex.:

```
Diameter_vector(grafo_teste);
Distance_matrix(grafo_teste2, 1, 3);
```

# Funções para cálculo de tempo de execução:

Por fim, modificamos um pouco as nossas funções de busca para retornarem o valor do tempo de execução do algoritmo. Essa parte está mais relacionada aos estudos de caso feitos no relatório.

Ex.:
```
`DFS_tree_vector_with_execution_time(grafo_teste, 1, "arvoreDFS_grafo_teste.txt")`;
`BFS_tree_matrix_with_execution_time(grafo_teste2, 3, "arvoreBFS_grafo_teste.txt")`;
```

# **Funções para grafos com pesos**

# Recebendo o grafo

Foram criadas 2 funções diferentes que recebem a string correspondente ao nome do arquivo de texto de entrada (ex.: `"grafo_W_teste.txt"`) e retornam o grafo em uma das duas representações pedidas (vetor de adjacência ou matriz de adjacência).

Ex.:
```
string nome_arquivo = "grafo_W_teste.txt";
vector<vector<pair<int, float>>> grafo_teste_vector = txt_to_weight_adjacency_vector(nome_arquivo);
vector<vector<float>> grafo_teste_matrix = txt_to_weight_adjacency_matrix(nome_arquivo);
```

# Dijkstra

Essa função retorna um vetor contendo a distância da origem para todos os vértices do grafo. Foram criadas 4 funções, para comtemplar as duas representações e as duas formas de implementação de Dijkstra (vetor e heap).

Para grafos representados como vetor:
```
vector<float> distancias = Dijkstra_Vector_Vector(grafo_teste_vector, 2);
vector<float> distancias = Dijkstra_Vector_Heap(grafo_teste_vector, 2);
```

E para matrizes: 

```
vector<float> distancias = Dijkstra_Matrix_Vector(grafo_teste_matrix, 2);
vector<float> distancias = Dijkstra_Matrix_Heap(grafo_teste_matrix, 2);
```


# Caminho_Minimo

Essa função imprime no terminal o caminho mínimo entre dois vértices, bem como o comprimento do caminho. 

Ex.:
```
Caminho_Minimo_Vector(grafo_teste_vector, 12, 14);
Caminho_Minimo_Matrix(grafo_teste_matrix, 1, 6);
```

# Funções para cálculo de tempo de execução (grafo com pesos):

Essas funções retornam um número (tipo double): o tempo para executar o algoritmo de Dijkstra na representação desejada e com a estrutura de dados auxiliar desejada.

```
double tempo_de_execucao_vector_com_heap = Dijkstra_Vector_Heap_With_Execution_Time(grafo_teste_vector, 4);
double tempo_de_execucao_matriz_com_heap = Dijkstra_Matrix_Heap_With_Execution_Time(grafo_teste_matrix, 2);
double tempo_de_execucao_vector_com_vector = Dijkstra_Vector_Vector_With_Execution_Time(grafo_teste_vector, 6);
double tempo_de_execucao_matriz_com_vector = Dijkstra_Matrix_Vector_With_Execution_Time(grafo_teste_matrix, 9);
```

# Funções para a rede de colaboração:

A função `txt_to_dictionary` recebe o grafo (da mesma forma que tem sido recebido até aqui) e um "dicionário" que relaciona o número de um vértice a uma string. Ela retorna um vetor de pair, relacionando o número a respectiva string.

A função `Caminho_Minimo_Rede` recebe o gráfico, dois vértices (origem e destino, representados na forma de string que está no dicionário) e o dicionário. Ela imprime o caminho mínimo, bem como seu comprimento, no terminal.

```
vector<pair<int, string>> dicionario = txt_to_dictionary("rede_de_colaboracao.txt", "rede_de_colaboracao_vertices.txt");
Caminho_Minimo_Rede(grafo_rede, "Daniel R. FIgueiredo", "Alan M. Turing" , dicionario);
```





