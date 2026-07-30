#include<stdio.h>

#define MAX 10
#define INF 9999

int main()
{
    int cost[MAX][MAX], distance[MAX], visited[MAX];
    int n, i, j, source;
    int count, mindistance, nextnode;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter the cost matrix:\n");
    for(i = 0; i < n; i++)
    {
        for(j = 0; j < n; j++)
        {
            scanf("%d", &cost[i][j]);

            if(cost[i][j] == 0 && i != j)
                cost[i][j] = INF;
        }
    }

    printf("Enter the source vertex: ");
    scanf("%d", &source);

    for(i = 0; i < n; i++)
    {
        distance[i] = cost[source][i];
        visited[i] = 0;
    }

    distance[source] = 0;
    visited[source] = 1;
    count = 1;

    while(count < n - 1)
    {
        mindistance = INF;

        for(i = 0; i < n; i++)
        {
            if(distance[i] < mindistance && !visited[i])
            {
                mindistance = distance[i];
                nextnode = i;
            }
        }

        visited[nextnode] = 1;

        for(i = 0; i < n; i++)
        {
            if(!visited[i])
            {
                if(mindistance + cost[nextnode][i] < distance[i])
                {
                    distance[i] = mindistance + cost[nextnode][i];
                }
            }
        }

        count++;
    }

    printf("\nShortest distances from source vertex %d:\n", source);

    for(i = 0; i < n; i++)
    {
        if(i != source)
        {
            printf("%d -> %d = %d\n", source, i, distance[i]);
        }
    }

    return 0;
}
