#include <stdio.h>
#include <string.h>

#define MAX 20
#define INF 1e9
int Dijkstra(int u, int v, int p[], int a[][MAX], int n)//Duong di tra ve trong mang p, voi moi i: a[i][i]=0
{
  int i,j;
  int D[MAX], T[MAX];
       
  for (i = 0; i < n; i++) D[i]=INF; D[u]=0; //Khoi tao cac dinh vo cung
  for (i = 0; i < n; i++) T[i]=1; 
  while (T[v]){ //Chung nao T(v) rong thi dung.
  	i=0; while (!T[i]) i++; // Danh dau dinh i da xet
  	for (j=i+1; j<n; j++) 
	  if (T[j] && D[j]<D[i]) i=j; // Lay diem nho nhat khi xet dinh hien tai
  	T[i]=0;
  	for (j=0; j<n; j++) if (T[j]&&a[i][j]) // moi dinh j ke dinh i
  	  if (D[i]+a[i][j]<D[j]){
  	  	D[j]=D[i]+a[i][j]; //++duong di
  	  	p[j]=i; //Luu path
	  }
  }
  return D[v];
}

int main(){
	int i, j, n, s, e,  Distance; 
	int a[MAX][MAX], p[MAX];
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
	
	printf("Dinh dau  (1...%d): ",n); scanf("%d",&s); s--;
	printf("Dinh cuoi (1...%d): ",n); scanf("%d",&e); e--;
	Distance=Dijkstra(s,e,p,a,n);
	printf("\nDo dai ngan nhat la: %d\n",Distance);	
	i=e; printf("\n%d<--",1+i);

	while (p[i]!=s){
		i=p[i];printf("%d<--",1+i);
	}
	printf("%d\n",1+s);
	
	return 0;
}
