#include <stdio.h>
#include <limits.h>
#include <string.h>
 
#define V 30
int parent[V];
 

int find(int i)
{
    while (parent[i] != i)
        i = parent[i];
    return i;
}
 

void union1(int i, int j)
{
    int a = find(i);
    int b = find(j);
    parent[a] = b;
}
 

void kruskalMST(int cost[][V], int n)
{
    int mincost = 0; 
    for (int i = 0; i < n; i++)
        parent[i] = i;
 
    
    int edge_count = 0;
    while (edge_count < n - 1) {
        int min = INT_MAX, a = -1, b = -1;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (find(i) != find(j) && cost[i][j] < min) {
                    min = cost[i][j];
                    a = i;
                    b = j;
                }
            }
        }
 
        union1(a, b);
        printf("Canh %d:(%d, %d) trong so:%d \n",
               ++edge_count, a, b, min);
        mincost += min;
    }
    printf("\nCay khung nho nhat = %d \n", mincost);
}
 

int main()
{
    int i,j,n;
    int Graph[V][V];
    char fn[101];  
  	printf("Enter the file name (*.INP): ");
	gets(fn);
	if (!strchr(fn,'.')) strcat(fn,".INP");
	freopen(fn,"r",stdin);
	scanf("%d",&n);
    for (i = 0; i < n; i++) {
		for (j = 0; j < n; j++){
			scanf("%d",&Graph[i][j]);
			if (Graph[i][j]==0) Graph[i][j] = INT_MAX;
		}
		Graph[i][i] = 0;
	}
  printf("n = %d\n", n);
	
	for (i = 0; i < n; i++) {
		for (j = 0; j < n; j++)
			if(Graph[i][j]!=INT_MAX)	printf("%d\t",Graph[i][j]);
			else printf("INF\t");
		printf("\n");
	}
 
    
    kruskalMST(Graph,n);
 
    return 0;
}