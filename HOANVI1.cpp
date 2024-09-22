#include <stdio.h>

#define MAX 20
int S[MAX], c=0, n; 

void print();

int main(){
  int i,j,k,tam;
  
  printf("nhap n= "); scanf("%d", &n);
  for (i=1; i<=n; i++) scanf("%d",&S[i]); 
  //print();
  printf("Cau hinh tiep theo:\n");
  while (1){
    i=n-1; while (i>0 && S[i]>S[i+1]) i--;
   if (i==0) break;
    j=n; while (S[j]<S[i]) j--;
    tam=S[i]; S[i]=S[j]; S[j]=tam;
    j=i+1; k=n;
    while (j<k){
      tam=S[j]; S[j]=S[k]; S[k]=tam;
      j++; k--;
	}
    print();
  }  
}

void print()
{
  int i;
  printf("\n ");
  for (i=1; i<=n; i++) printf("%d ", S[i]);
}
