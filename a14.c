#include<stdio.h>
#define MAX 10

int sol[MAX];
int cnt;

int abs(int n){return n>0?n:(n*(-1));}

void printChess(int n){
  int i,j;
  for(i=1;i<=n;++i){
    for(j=1;j<=n;++j){
      if(sol[i]==j) printf(" Q ");
      else printf(" _ ");
    }
    printf("\n");
  }
}

void printSol(int n){
  int i;
  printf("The soultion vector: ");
  for(i=1;i<=n;++i) printf("%d ",sol[i]);
  printf("\n");
  
}

int Place(int q,int p){    // q = q'th queen and p = column position of q
    int i;
    for(i=1;i<=q-1;i++){
      if(sol[i]==p|| abs(sol[i]-p) == abs(i-q) )
          return 0;
    }
    return 1;
}
void Nqueens(int q,int n){
    int i,j;
    for(i=1;i<=n;i++){
        if(Place(q,i)){
            sol[q]=i;
            if(q==n){
              cnt++;
              printSol(n);
              printChess(n);
            }
            else Nqueens(q+1,n);
        }
    }
}

int main(){
  int i,n;
  printf("Enter the number of Queens = ");
  scanf("%d",&n);

  Nqueens(1,n);
  printf("The Total number of soultion = %d\n",cnt);
  
}
//code by jay-neo
