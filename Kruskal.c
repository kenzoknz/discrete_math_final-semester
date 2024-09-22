#include <stdio.h>
#include <string.h>
#define MAX 30

typedef struct edge {
  int u, v, w;
} edge;

typedef struct edge_list {
  edge data[MAX];
  int n;
} edge_list;

edge_list elist;

int Graph[MAX][MAX], n;
edge_list spanlist;

// Tra ve cac dinh thuoc ve (kiem tra chung co thuoc chu trinh khong)
int find(int belongs[], int vertexno) {
  return (belongs[vertexno]);
}
//Noi 2 dinh lai voi nhau
void applyUnion(int belongs[], int c1, int c2) {
  int i;

  for (i = 0; i < n; i++)
    if (belongs[i] == c2)
      belongs[i] = c1;
}

// Xep cac canh theo trong so tang dan
void sort() {
  int i, j;
  edge temp;

  for (i = 0; i < elist.n; i++)
    for (j = 0; j < elist.n - 1; j++)
      if (elist.data[j].w > elist.data[j + 1].w) {
        temp = elist.data[j];
        elist.data[j] = elist.data[j + 1];
        elist.data[j + 1] = temp;
      }
}
// Thuat toan Kruskal
void kruskalAlgo() {
 //Khoi tao cac canh
  int belongs[MAX], i, j, cno1, cno2;
  elist.n = 0;
 //tim cac canh cua cac cap dinh 
  for (i = 0; i < n; i++)
    for (j = 0; j < i; j++) {
      if (Graph[i][j] != 0) {
        elist.data[elist.n].u = i;
        elist.data[elist.n].v = j;
        elist.data[elist.n].w = Graph[i][j];
        elist.n++;
      }
    }
 //Xep theo trong so tang dan
  sort();

  for (i = 0; i < n; i++)
    belongs[i] = i;

  spanlist.n = 0;
 //Tim nhom cua cac cap dinh
  for (i = 0; i < elist.n; i++) {
    cno1 = find(belongs, elist.data[i].u);
    cno2 = find(belongs, elist.data[i].v);

    if (cno1 != cno2) { //Neu 2 dinh khong cung 1 nhom (k tao chu trinh) thi noi chung lai voi nhau
      spanlist.data[spanlist.n] = elist.data[i];
      spanlist.n += 1;
      applyUnion(belongs, cno1, cno2);
    }
  }
}


// Printing the result
void print() {
  int i, cost = 0;

  for (i = 0; i < spanlist.n; i++) {
    printf("\n%d - %d : %d", spanlist.data[i].v+1, spanlist.data[i].u+1, spanlist.data[i].w+1);
    cost = cost + spanlist.data[i].w;
  }

  printf("\nCay khung nho nhat: %d", cost);
}

int main() {
  int i, j, total_cost;

	char fn[101];  
  printf("Enter the file name (*.INP): ");
	gets(fn);
	if (!strchr(fn,'.')) strcat(fn,".INP");
	freopen(fn,"r",stdin);
	scanf("%d",&n);
  	for (i = 0; i < n; i++) 
		for (j = 0; j < n; j++)
			scanf("%d",&Graph[i][j]);
	
  printf("n = %d\n", n);
	
	for (i = 0; i < n; i++) {
		for (j = 0; j < n; j++)
			printf("%d\t",Graph[i][j]);
		printf("\n");
	}
  kruskalAlgo();
  print();

}