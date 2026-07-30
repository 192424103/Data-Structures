#include<stdio.h>

#define MAX 10
#define INF 9999

int main()
{
    int cost[MAX][MAX];
    int visited[MAX];
    int n, i, j;
    int min, a, b, u, v;
    int ne = 1;
    int mincost = 0;

    printf("Enter the number of vertices: ");
    scanf("%d", &n);

    printf("Enter the cost adjacency matrix:\n");

    for(i = 0; i < n; i++)
    {
        for(j = 0; j < n; j++)
        {
            scanf("%d", &cost[i][j]);

            if(cost[i][j] == 0)
                cost[i][j] = INF;
        }
    }

    for(i = 0; i < n; i++)
        visited[i] = 0;

    visited[0] = 1;

    printf("\nEdges of Minimum Spanning Tree:\n");

    while(ne < n)
    {
        min = INF;

        for(i = 0; i < n; i++)
        {
            if(visited[i] == 1)
            {
                for(j = 0; j < n; j++)
                {
                    if(visited[j] == 0 && cost[i][j] < min)
                    {
                        min = cost[i][j];
                        a = u = i;
                        b = v = j;
                    }
                }
            }
        }

        printf("%d Edge (%d -> %d) = %d\n", ne++, a, b, min);

        mincost += min;
        visited[b] = 1;
    }

    printf("\nMinimum Cost = %d\n", mincost);

    return 0;
}
