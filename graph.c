#include <math.h>

#include "graph.h"

int getrand(int min, int max)
{
    return (double)rand() / (RAND_MAX + 1.0) * (max - min) + min;
}

graph *graph_create(int vertices)
{
    graph *g;
    g = malloc(sizeof(graph *));
    g->vertices = vertices;
    g->visited = malloc(sizeof(int) * (vertices + 1));
    g->m = calloc(sizeof(int), vertices * vertices);
    return g;
}

void graph_free(graph *g)
{
    free(g->m);
    free(g->visited);
    free(g);
}

void graph_set_edge(graph *g, int i, int j, int w)
{
    g->m[(i - 1) * g->vertices + (j - 1)] = w;
    g->m[(j - 1) * g->vertices + (i - 1)] = w;
}

int graph_get_edge(graph *g, int i, int j)
{
    return g->m[(i - 1) * g->vertices + (j - 1)];
}