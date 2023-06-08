#include<stdio.h>
#define MAX 10

const int INF=1e9;
int G[MAX][MAX];
int P[MAX][MAX];

int Floyd_Warshall(int n){
	int  i,j,k;
	for(k=1;k<=n;++k){
		for(i=1;i<=n;++i){
			for(j=1;j<=n;++j){
				if(G[i][j]>G[i][k]+G[k][j]){
					G[i][j]=G[i][k]+G[k][j];
					P[i][j]=k;
				}
			}
			if(G[i][i]<0) return 0;
		}
	}
	return 1;
}
// Time Complexity  = O(N^3)
// Space Complexity = O(N^2)


void printpath(int src,int dest){
	if(P[src][dest]==0){
		printf("%d->%d\n",src,dest);
		return;
	}
	printf("%d->",src);
	printpath(P[src][dest],dest);
}

int main(){
	int i,j,n,src,target;
	
	printf("Enter the number of vertices = ");
	scanf("%d",&n);
	
	printf("Enter the %dx%d adjacency matrix:\n",n,n);
	for(i=1;i<=n;i++){
		for(j=1;j<=n;++j){
			scanf("%d",&G[i][j]);
			if(i!=j && G[i][j]==0) G[i][j]=INF;		
		}
	}
	
	if(!Floyd_Warshall(n)){
		printf("There is an negative wieight cycle.\n");
		return 0;
	}

	printf("Enter the source vertex = ");
	scanf("%d",&src);
	printf("Enter the target vertex = ");
	scanf("%d",&target);
	
	
	printf("The Final Path Matrix:\n");
	for(i=1;i<=n;++i){
		for(j=1;j<=n;++j)
			printf("%d ",P[i][j]);
		printf("\n");
	}
	
	printf("The Traversing Path from %d to %d is:\n",src,target);
	printpath(src,target);
	printf("Total const = %d",G[src][target]);
	
}
/*
0 8 0 1
0 0 1 0
4 0 0 0
0 2 9 0
No Negative


0 0 -2 0
4 0 -3 0
0 0 0 2
0 -1 0 0
Negative 

*/

//code by jay-neo
