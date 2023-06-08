#include<stdio.h>
#define MAX 20

const int INF=1e5;
int G[MAX][MAX];
int vis[MAX];
int path[MAX],k;
int ans;

// Greedy Approach
int TSP(int n,int src,int node){
	int i,mini,nex;
	mini=nex=INF;

	vis[node]=1;
	path[++k]=node;
	for(i=1;i<=n;++i){
		if(G[node][i]<mini && !vis[i]){
			nex=i;
			mini=G[node][i];
		}
	}

	if(nex==INF){
		if(G[node][src]==INF) return 0;
		for(i=1;i<=n;++i) if(!vis[i]) return 0;
		ans+=G[node][src];
		path[++k]=src;
		return 1;
	}

	ans+=G[node][nex];
	return TSP(n,src,nex);
}


// Dynamic Prgramming Approach using Bit Masking
// int n=4;
static int All(int x){ return (1<<x)-1; }
// #define All(x) ((1<<x)-1)
int dp[MAX][MAX];
int min(int a,int b){ return a<b?a:b; }

int TSP2(int n,int src,int node,int mask){
	int i;
	int res=INF;

	if(mask==All(n)) return G[node][src];
	if(dp[mask][node]!=0) return dp[mask][node];

	for(i=1;i<=n;++i)
		if((mask&(1<<i))==0){
			res=min(res,G[node][i]+TSP2(n,src,i,mask)|(1<<i));
		}

	return dp[mask][node]=res;

}

// This problem is all so be solved using Backtracking, Branch&Bound and also genetic algorithm

int main(){
	int i,j,n,src;

	printf("Enter the number of nodes = ");
	scanf("%d",&n);

	printf("Enter the %dx%d adjacency matrix :\n",n,n);
	for(i=1;i<=n;++i)
		for(j=1;j<=n;++j){
			scanf("%d",&G[i][j]);
			if(i==j || !G[i][j]) G[i][j]=INF;
		}

	printf("Enter the source node = ");
	scanf("%d",&src);

	if(TSP(n,src,src)){
		printf("The Traversing Path is :\n");
		for(i=1;i<=k;++i) printf("%d ",path[i]);
		printf("\nTotal cost is = %d\n",ans);
	}
	else printf("There is no Traversing Path!!");

	// printf("Answer = %d\n",TSP2(n,src,src,1));		// not working

}
/*
0 4 1 3
4 0 2 1
1 2 0 5
3 1 5 0
1—>3—>2—>4—>1
=7


1 2 3 4
5 6 7 8
3 4 5 6
9 8 4 3
The Traversing Path is :
1 2 3 4 1
Total cost is = 24



0 10 15 20
10 0 35 25
15 35 0 30
20 25 30 0
The Traversing Path is :
1 2 4 3 1
Total cost is = 80


12 30 33 10 45
56 22 9 15 18
29 13 8 5 12
33 28 16 10 3
1 4 30 24 20
The Traversing Path is :
1 5 4 3 2 1
=99



0 7 3
4 0 2
9 1 0
The Traversing Path is :
1 3 2 1
Total cost is = 8


0 5 9 12 4 8
5 0 4 7 9 7
9 4 0 5 5 11
12 7 5 0 10 14
4 9 5 10 0 12
8 7 11 14 12 0
=46
The Traversing Path is :
1 5 3 2 4 6 1
Total cost is = 42


0 5 0 0 1
5 0 1 3 7
0 1 0 2 0
0 3 2 0 0
7 1 0 0 0
There is no Traversing Path!!


0 20 42 25
20 0 30 34
42 30 0 10
25 34 10 0
>>85

*/

// code by jay-neo

