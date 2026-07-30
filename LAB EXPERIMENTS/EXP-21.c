#include<stdio.h>

int queue[20], front = -1, rear = -1;
int visited[20];

void enqueue(int vertex)
{
    if(rear == 19)
        return;
    if(front == -1)
        front = 0;
    queue[++rear] = vertex;
}

int dequeue()
{
    return queue[front++];
}

int main()
{
    int adj[20][20], n, i, j;
    int start, vertex;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter adjacency matrix:\n");
    for(i = 0; i < n; i++)
    {
        for(j = 0; j < n; j++)
        {
            scanf("%d", &adj[i][j]);
        }
    }

    for(i = 0; i < n; i++)
        visited[i] = 0;

    printf("Enter starting vertex: ");
    scanf("%d", &start);

    enqueue(start);
    visited[start] = 1;

    printf("BFS Traversal: ");

    while(front <= rear)
    {
        vertex = dequeue();
        printf("%d ", vertex);

        for(i = 0; i < n; i++)
        {
            if(adj[vertex][i] == 1 && visited[i] == 0)
            {
                enqueue(i);
                visited[i] = 1;
            }
        }
    }

    return 0;
}
