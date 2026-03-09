#include <stdlib.h>
#include <stdio.h>

typedef struct node {
    int data;
    struct node **neighbours;   // array of pointers to neighbour nodes
    int num_neighbours;
    int capacity;               // allocated size of neighbours array
} node;

typedef struct graph {
    node **nodes;               // array of pointers to nodes
    int num_nodes;
} graph;

graph *creae_graph() {
    graph *g = (graph *)malloc(sizeof(graph));
    g->num_nodes = 0;
    g->nodes = NULL;

    return g;
}

node *create_node(int data) {
    node *n = (node *)malloc(sizeof(node));
    n->data = data;
    n->capacity = 4;
    n->num_neighbours = 0;
    n->neighbours = (node **)malloc(sizeof(node *) * n->capacity);

    return n;
}

void add_neighbour(node *n, node *neighbour)
{
    if (n->num_neighbours == n->capacity) {
        n->capacity *= 2;
        n->neighbours = (node **)realloc(n->neighbours,
                                          n->capacity * sizeof(node *));
    }
    n->neighbours[n->num_neighbours] = neighbour;
    n->num_neighbours++;
}

void add_node(graph *g, node *n)
{
    g->num_nodes++;
    g->nodes = (node **)realloc(g->nodes, g->num_nodes * sizeof(node *));
    g->nodes[g->num_nodes - 1] = n;
}

int find_index(graph *g, node *n)
{
    for (int i = 0; i < g->num_nodes; i++) {
        if (g->nodes[i] == n) {
            return i;
        }
    }
    return -1;
}

void dfs_rec(graph *g, node *n, int *visited)
{
    int idx = find_index(g, n);
    if (visited[idx]) {
        return;
    }
    printf("%d\n", n->data);
    visited[idx] = 1;

    for (int i = 0; i < n->num_neighbours; i++) {
        dfs_rec(g, n->neighbours[i], visited);
    }
}

int main()
{
    node *a = create_node(1);
    node *b = create_node(2);
    node *c = create_node(3);
    node *d = create_node(4);

    add_neighbour(a, b);
    add_neighbour(a, c);
    add_neighbour(b, d);
    add_neighbour(c, d);

    graph *g = create_graph();
    add_node(g, a);
    add_node(g, b);
    add_node(g, c);
    add_node(g, d);

    int *visited = (int *)calloc(g->num_nodes, sizeof(int));
    dfs_rec(g, g->nodes[0], visited);
    free(visited);
}