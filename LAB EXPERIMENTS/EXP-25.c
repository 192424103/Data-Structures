#include<stdio.h>

#define MAX 20
#define INF 9999

int parent[MAX];

int find(int i)
{
    while(parent[i])
        i = parent[i];
    return i;
}

int uni(int i, int j)
{
    if(i != j)
    {
        parent[j] = i;
        return 1;
    }
    return 0;
}

int main()
{
    int cost[MAX][MAX];
    int n, i, j;
    int min, mincost = 0;
    int a, b, u, v;
    int ne = 1;

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

    printf("\nEdges of Minimum Spanning Tree:\n");

    while(ne < n)
    {
        min = INF;

        for(i = 0; i < n; i++)
        {
            for(j = 0; j < n; j++)
            {
                if(cost[i][j] < min)
                {
                    min = cost[i][j];
                    a = u = i;
                    b = v = j;
                }
            }
        }

        u = find(u);
        v = find(v);

        if(uni(u, v))
        {
            printf("%d Edge (%d -> %d) = %d\n", ne++, a, b, min);
            mincost += min;
        }

        cost[a][b] = cost[b][a] = INF;
    }

    printf("\nMinimum Cost = %d\n", mincost);

    return 0;
}
