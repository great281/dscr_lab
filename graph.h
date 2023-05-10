#ifndef GRAPH_H
#define GRAPH_H

#include <stdlib.h>
#include <stdio.h>


typedef struct Graph {
	int vertices;
	int *m;
	int *visited;
}graph;

void graph_free(graph *g);

graph *graph_create(int vertices);

void graph_set_edge(graph *g, int i, int j, int w);

int graph_get_edge(graph *g, int i, int j);

#endif