#include <stdio.h>
#include <stdbool.h>
#include <limits.h>
#define V 100


int minKey(int key[], bool mstSet[], int vertices) {
	// Write your code here...
	 int min = INT_MAX, min_index;

    for (int v = 0; v < vertices; v++) {
        if (mstSet[v] == false && key[v] < min) {
            min = key[v];
            min_index = v;
        }
    }

    return min_index;



}


void printTree(int parent[], int graph[V][V], int vertices) {
    printf("Edge \tWeight\n");
    for (int i = 1; i < vertices; i++)
        printf("%d - %d \t%d \n", parent[i], i, graph[i][parent[i]]);
}
void prim(int graph[V][V], int vertices) {
	// Write your code here...
	int parent[V];     // stores MST
    int key[V];        // minimum weight
    bool mstSet[V];    // included in MST or not

    // initialize
    for (int i = 0; i < vertices; i++) {
        key[i] = INT_MAX;
        mstSet[i] = false;
    }

    // start from vertex 0
    key[0] = 0;
    parent[0] = -1;

    // MST will have V-1 edges
    for (int count = 0; count < vertices - 1; count++) {

        int u = minKey(key, mstSet, vertices);  // pick min
        mstSet[u] = true;

        // update adjacent vertices
        for (int v = 0; v < vertices; v++) {

            if (graph[u][v] && mstSet[v] == false && graph[u][v] < key[v]) {
                parent[v] = u;
                key[v] = graph[u][v];
            }
        }
    }

    printTree(parent, graph, vertices);



    }

int main() {
    int vertices;
    int graph[V][V];

    printf("No of vertices: ");
    scanf("%d", &vertices);

    printf("Adjacency matrix elements (row wise):\n");
    for (int i = 0; i < vertices; i++) {
        for (int j = 0; j < vertices; j++) {
            scanf("%d", &graph[i][j]);
        }
    }

    prim(graph, vertices);

    return 0;
}