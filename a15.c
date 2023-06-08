#include<stdio.h>
#define MAX 10

int G[MAX][MAX];	// 1th based graph
int ans[MAX];

int Check(int n,int node,int c){
	int i;
	for(i=1;i<=n;++i)
		if(i!=node && G[i][node] && ans[i]==c)
			return 0;
	return 1;
}

int graphColoring(int n,int node,int m){
	int i;
	if(node==n) return 1;
	for(i=1;i<=m;++i){
		if(Check(n,node,i)){
			ans[node]=i;
			if(graphColoring(n,node+1,m)) return 1;
			ans[node]=0;
		}
	}
	return 0;
}


int main(){
	int i,j,n,m;
	printf("Enter the size of array = ");
	scanf("%d",&n);

	printf("Enter the %dx%d adjacency matrix of the graph:\n",n,n);
	for(i=1;i<=n;++i)
		for(j=0;j<=n;++j)
			scanf("%d",&G[i][j]);

	printf("Enter the number of colours = ");
	scanf("%d",&m);

	printf("The graph coloring ");
	graphColoring(n,0,m)?printf("possible!\n"):printf("not possible!\n");


}
