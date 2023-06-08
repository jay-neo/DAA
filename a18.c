#include<stdio.h>
#define MAX 20

int G[MAX][MAX];
int vis[MAX];

void DFS(int n,int node){
	int i;
	printf("%d ",node);
	vis[node]=1;
	for(i=1;i<=n;++i)
		if(!vis[i] && G[node][i])
			DFS(n,i);
}

int Q[MAX];
int rear=-1,front=-1;

void BFS(int n,int node){
	int i;
	for(i=1;i<=n;i++){
		if(vis[i]!=1 && G[node][i]){
			Q[++rear]=i;
			vis[i]=1;
			printf("%d ",i);
		}
	}
	if(front<=rear)
		BFS(n,Q[front++]);
}


int main(){
	int i,j,n,src;

	printf("Enter the number of vertices = ");
	scanf("%d",&n);

	printf("Enter %dx%d matrix :\n",n,n);
	for(i=1;i<=n;i++){
		for(j=1;j<=n;j++){
			scanf("%d",&G[i][j]);
		}
	}

	printf("Enter the source vertex : ");
	scanf("%d",&src);
	printf("The DFS Traversal is:\n");
	DFS(n,src);
	printf("\n");
	
	for(i=0;i<=n;i++) vis[i]=0;

	printf("The BFS Traversal is:\n");
	printf("%d ",src);
	vis[src]=1;
	BFS(n,src);
	printf("\n");

}
/*

0 1 0 1 1 0 0
1 0 1 0 0 1 1
0 1 0 0 0 0 0
1 0 0 0 0 0 0
1 0 0 0 0 0 0
0 1 0 0 0 0 0
0 1 0 0 0 0 0

DFS = > 1 2 3 6 7 4 5
BFS = > 1 2 4 5 3 6 7
*/
