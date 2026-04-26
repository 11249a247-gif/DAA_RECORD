#include <stdio.h>
// Number of vertices in our graph 
#define V 5 
void findVertexCover(int graph[V][V]) 
{ 
    int visited[V]; 

    for (int i = 0; i < V; i++) 
    { 
//Initialize a set C to be empty (this will hold our vertex cover). 
        visited[i] = 0; 
    } 

    for (int u = 0; u < V; u++) 
    { 
        for (int v = 0; v < V; v++) 
        { 
            if (graph[u][v] == 1 && !visited[u] && !visited[v]) 
            { 
                visited[u] = 1; 
                visited[v] = 1; 
            } 
        } 
    } 
 // Return the Cover Set C by printing all vertices we marked
    printf("Approximate Vertex Cover: "); 
    int count = 0; 
    for (int i = 0; i < V; i++) 
    { 
        if (visited[i]) 
        { 
            printf("%d ", i); 
            count++; 
        } 
    } 
    printf("\nTotal vertices in the cover: %d\n", count); 
} 

int main() 
{ 
// Adjacency Matrix
    int graph[V][V] = { 
        {0, 1, 0, 0, 0}, 
        {1, 0, 1, 1, 0}, 
        {0, 1, 0, 1, 1}, 
        {0, 1, 1, 0, 1}, 
        {0, 0, 1, 1, 0}}; 

    printf("Executing Vertex Cover Approximation...\n");
//function call 
    findVertexCover(graph); 
    return 0; 
}
