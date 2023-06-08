#include<stdio.h>
#define MAX 20

int G[MAX][MAX];
int path[MAX];
int cnt;

int vis[MAX];

void printpath(int n){
	int i;
	for(i=1;i<=n;++i) printf("%d ",path[i]);
	printf("%d\n",path[1]);
}

void Check(int n,int node){
	int i;

	while(1){
		path[node]=(path[node]+1)%(n+1);
		if(!path[node]) return;
		if(G[path[node-1]][path[node]]){
			for(i=1;i<node;++i)
				if(path[i]==path[node]) break;
			if(i==node && (node<n || (node==n && G[path[n]][path[1]]))) return;
		}
	}
}

void HamiltonialCycle2(int n,int node){
	int i;

	while(1){
		Check(n,node);
		if(!path[node]) return;
		if(node==n) printpath(n),cnt++;
		else HamiltonialCycle2(n,node+1);
	}
}




void HamiltonialCycle(int n,int src,int node,int k){
	int i;
	if(k==n){
		if(G[node][src]){
			cnt++;
			printpath(n);
		}
		return;
	}

	for(i=1;i<=n;++i){
		if(G[node][i] && !vis[i]){
			vis[i]=1;
			path[++k]=i;
			HamiltonialCycle(n,src,i,k);
			vis[i]=0;
			--k;
		}
	}
}

int main(){
	int i,j,n,src,nex;

	printf("Enter the number of nodes = ");
	scanf("%d",&n);

	printf("Enter the %dx%d adjacency matrix :\n",n,n);
	for(i=1;i<=n;++i)
		for(j=1;j<=n;++j)
			scanf("%d",&G[i][j]);

	printf("Enter the source node = ");
	scanf("%d",&src);


	// if(src!=n) for(i=1;i<=src;++i) path[i]=i;
	// else src=0;
	// nex=src+1;
	// if(src==n) nex=1;

	// path[1]=src;
	// HamiltonialCycle2(n,src);


	vis[src]=1;
	path[1]=src;
	HamiltonialCycle(n,src,src,1);

	if(cnt) printf("Total Hamiltonial Cycle with respect to %d is = %d\n",src,cnt);
	else printf("No Hamiltonian Cycle is detected!\n");

}

/*

0 1 0 1 0
1 0 1 1 1
0 1 0 0 1
1 1 0 0 1
0 1 1 1 0


0 1 0 1 0
1 0 1 1 1
0 1 0 0 1
1 1 0 0 0
0 1 1 0 0


0 1 1 0 0 0 1 0
1 0 1 0 0 0 0 1
1 1 0 1 0 1 0 0
0 0 1 0 1 0 0 0
0 0 0 1 0 1 0 0
0 0 1 0 1 0 1 0
1 0 0 0 0 1 0 1
0 1 0 0 0 0 1 0

0 1 1 0 0 0 1 1
1 0 1 0 0 0 0 1
1 1 0 1 0 1 0 0
0 0 1 0 1 0 0 0
0 0 0 1 0 1 0 0
0 0 1 0 1 0 1 0
1 0 0 0 0 1 0 1
1 1 0 0 0 0 1 0

*/

/*
// Zeroth Based Graph Indexing

#include<stdio.h>
#define MAX 10

int G[MAX][MAX];
int path[MAX];


int Check(int node,int p){
	int i;

	if(!G[path[p-1]][node]) return 0;

	for(i=0;i<p;++i)
		if(path[i]==node) return 0;

	return 1;
}

int HamiltonialCycle(int n,int p){
	int i;

	if(p==n && G[path[p-1]][path[0]]) return 1;
	if(p==n) return 0;

	for(i=1;i<n;++i){
		if(Check(i,p)){
			path[p]=i;
			if(HamiltonialCycle(n,p+1)) return 1;
			path[p]=0;
		}
	}

	return 0;
}

void printpath(int n){
	int i;
	printf("A Hamiltonial Cycle is detected:\n");
	for(i=0;i<n;++i) printf("%d ",path[i]);
	printf("%d\n",path[0]);
}

int main(){
	int i,j,n;

	printf("Enter the number of nodes = ");
	scanf("%d",&n);

	printf("Enter the %dx%d adjacency matrix :\n",n,n);
	for(i=1;i<=n;++i)
		for(j=1;j<=n;++j)
			scanf("%d",&G[i-1][j-1]);

	if(HamiltonialCycle(n,1)) printpath(n);
	else printf("No Hamiltonial Cycle Found!\n");

}

*/


//code by jay-neo

