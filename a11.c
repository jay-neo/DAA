#include<stdio.h>
#define MAX 10

const int INF = 1e9;
int G[MAX][MAX];
int dis[MAX],par[MAX];

int Bellman_Ford(int n,int src){
	int i,u,v;

	for(i=1;i<=n;++i) dis[i]=INF;
	dis[src]=0,par[src]=0;

	for(i=1;i<n;++i){
		for(u=1;u<=n;++u){
			for(v=1;v<=n;++v){
				if(dis[u]!=INF && (dis[v]>dis[u]+G[u][v])){
					dis[v]=dis[u]+G[u][v];
					par[v]=u;
				}
			}
		}
	}
	for(u=1;u<=n;++u){
		for(v=1;v<=n;++v){
			if(dis[u]!=INF && (dis[v]>dis[u]+G[u][v]))
				return 0;
		}
	}

	return 1;
}

void printpath(int src,int dest){
	if(par[dest]==src){
		printf("%d %d ",src,dest);
		return;
	}
	printpath(src,par[dest]);
	printf("%d ",dest);
}


int main(){
	int i,j,n,src,dest;

	printf("Enter the number of vertices = ");
	scanf("%d",&n);

	printf("Enter the graph as %dx%d adjacency matrix:\n",n,n);
	for(i=1;i<=n;++i)
		for(j=1;j<=n;++j){
			scanf("%d",&G[i][j]);
			if(G[i][j]==0) G[i][j]=INF;
		}

	printf("Enter the source vertex = ");
	scanf("%d",&src);
	printf("Enter the target vertex = ");
	scanf("%d",&dest);
	if(Bellman_Ford(n,1)){
			printf("The Final Distance Table:\n");
			for(i=1;i<=n;++i) printf("%d ",dis[i]);
			printf("\nThe Final Parent Table:\n");
			for(i=1;i<=n;++i) printf("%d ",par[i]);
			printf("\nThe Traversing Path from %d to %d is:\n",src,dest);
			printpath(src,dest);
			printf("\nThe Total Cost is = %d",dis[dest]);
	}else{
		printf("Given Graph have Negative Weight Cycle!\n");
	}
}
/*
0 6 0 7 0
0 0 5 8 -4
0 -2 0 0 0
0 0 -3 0 9
2 0 7 0 0

*/
