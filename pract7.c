#include <stdio.h>

#define V 5

int graph[V][V];
int path[V];

int isSafe(int v, int pos) {
    if (graph[path[pos - 1]][v] == 0)
        return 0;
    for (int i = 0; i < pos; i++)
        if (path[i] == v)
            return 0;
    return 1;
}

int hamCycleUtil(int pos) {
    if (pos == V) {
        if (graph[path[pos - 1]][path[0]] == 1)
            return 1;
        else
            return 0;
    }
    for (int v = 1; v < V; v++) {
        if (isSafe(v, pos)) {
            path[pos] = v;
            if (hamCycleUtil(pos + 1) == 1)
                return 1;
            path[pos] = -1;
        }
    }
    return 0;
}

int hamCycle() {
    for (int i = 0; i < V; i++)
        path[i] = -1;
    path[0] = 0;
    if (hamCycleUtil(1) == 0) {
        printf("No Hamiltonian Cycle exists\n");
        return 0;
    }
    printf("Hamiltonian Cycle: ");
    for (int i = 0; i < V; i++)
        printf("%c ", path[i] + 'A');
    printf("%c\n", path[0] + 'A');
    return 1;
}

int main() {
    int choice;
    printf("Choose adjacency matrix:\n1) A B C D E\n2) T M S H C\n");
    scanf("%d", &choice);

    if (choice == 1) {
        int g[V][V] = {
            {0,1,1,0,1},
            {1,0,1,1,0},
            {1,1,0,1,0},
            {0,1,1,0,1},
            {1,0,0,1,0}
        };
        for (int i = 0; i < V; i++)
            for (int j = 0; j < V; j++)
                graph[i][j] = g[i][j];
    } else {
        int g[V][V] = {
            {0,1,1,0,1},
            {1,0,1,1,0},
            {1,1,0,1,1},
            {0,1,1,0,1},
            {1,0,1,1,0}
        };
        for (int i = 0; i < V; i++)
            for (int j = 0; j < V; j++)
                graph[i][j] = g[i][j];
    }

    hamCycle();
    return 0;
}
