#include <limits.h>
#include <stdio.h>
#include <string.h>

// Number of vertices in the graph
#define V 20
int n;

int minDistance(int dist[], bool sptSet[])
{
    // Initialize min value
    int min = INT_MAX, min_index;

    for (int v = 0; v < n; v++)
        if (sptSet[v] == false && dist[v] <= min)
            min = dist[v], min_index = v;

    return min_index;
}

void printSolution(int dist[])
{
	printf("Khoang cach ngan nhat tu dinh 1 den cac dinh khac\n");
    printf("Dinh \t\t Do dai duong di\n");
    for (int i = 1; i < n; i++)
        printf("%d \t\t\t %d\n", i+1, dist[i]);
}


void dijkstra(int graph[V][V], int src)
{
    int dist[V]; // The output array.  dist[i] will hold the
                 // shortest
    // distance from src to i

    bool sptSet[V]; // sptSet[i] will be true if vertex i is
                    // included in shortest
    // path tree or shortest distance from src to i is
    // finalized

    // Initialize all distances as INFINITE and stpSet[] as
    // false
    for (int i = 0; i < n; i++)
        dist[i] = INT_MAX, sptSet[i] = false;

    // Distance of source vertex from itself is always 0
    dist[src] = 0;

    // Find shortest path for all vertices
    for (int count = 0; count < n - 1; count++) {
        // Pick the minimum distance vertex from the set of
        // vertices not yet processed. u is always equal to
        // src in the first iteration.
        int u = minDistance(dist, sptSet);

        // Mark the picked vertex as processed
        sptSet[u] = true;

        // Update dist value of the adjacent vertices of the
        // picked vertex.
        for (int v = 0; v < n; v++)

            // Update dist[v] only if is not in sptSet,
            // there is an edge from u to v, and total
            // weight of path from src to  v through u is
            // smaller than current value of dist[v]
            if (!sptSet[v] && graph[u][v]
                && dist[u] != INT_MAX
                && dist[u] + graph[u][v] < dist[v])
                dist[v] = dist[u] + graph[u][v];
    }

    // print the constructed distance array
    printSolution(dist);
}

// driver's code
int main()
{
    int i, j; 
	int a[V][V];
	char fn[100];
	FILE *f;
	do {
	
	printf("File (*.INP): "); gets(fn);
	if (!strchr(fn,'.')) strcat(fn,".INP");
	f=fopen(fn,"r");
	if (f==NULL) printf("File khong ton tai. Nhap lai!\n");
	}	while (f==NULL);
	fscanf(f,"%d",&n);
	for (i=0; i<n; i++){
	  for (j=0; j<n; j++) fscanf(f,"%d",&a[i][j]);
	 
	}
	fclose(f);
	
	// in ma tran do thi
	printf("\nn = %d\n",n);
	for (i=0; i<n; i++){
	  for (j=0; j<n; j++) printf("%5d",a[i][j]);
	  printf("\n");
	}
    dijkstra(a, 0);

    return 0;
}