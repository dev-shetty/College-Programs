#include <stdio.h>
#include <stdlib.h>

int q[20], adj[20][20], visited[20], front = 0, rear = 0, n, count = 0;

void bfs(int startNode) {
    int node;
    q[++rear] = startNode;
    visited[startNode] = 1;
    while (front <= rear) {
        node = q[front++];
        for (int i = 1; i <= n; i++) {
            if (adj[node][i] && !visited[i]) {
                q[++rear] = i;
                visited[i] = 1;
                printf(" -> %d", i);
            }
        }
    }
}

void dfs(int startNode) {
    visited[startNode] = 1;
    for (int i = 1; i <= n; i++) {
        if (adj[startNode][i] && !visited[i]) {
            printf(" -> %d", i);
            dfs(i);
        }
    }
}

void main() {
    int startNode;
    printf("Enter the number of officers: ");
    scanf("%d", &n);
    for (int i = 0; i <= n; i++) {
        q[i] = 0;
        visited[i] = 0;
    }
    printf(
        "Enter the graph data in matrix form indicating people who can "
        "communicate directly with each other: \n");
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            scanf("%d", &adj[i][j]);
        }
    }
    printf("Enter the officer as a starting node: ");
    scanf("%d", &startNode);
    if (startNode < 1 || startNode > n) {
        printf("Invalid node \n");
        return;
    }
    printf(
        "All the officers which are reachable from a given officer as a "
        "starting node using BFS algorithm \n%d",
        startNode);
    bfs(startNode);
    for (int i = 0; i <= n; i++) visited[i] = 0;
    printf(
        "\nAll the officers which are reachable from a given officer as a "
        "starting node using DFS algorithm \n%d",
        startNode);
    dfs(startNode);
    printf("\n");
}