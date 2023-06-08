#include<stdio.h>
#define MAX 10

const int INF=1e5;
int G[MAX][MAX];
int par[MAX];

void Dijkstra(int n,int src,int dest){
	int i,k,u,v,mini,cost=0;
	int vis[MAX]={};
	int path[MAX]={};
	int dis[n+1];		// called distance array or minimum priority queue where we will store the shortest path estimate

	// intialize minimum priority queue with the shortest path estimate from the source
	for(i=1;i<=n;++i) dis[i]=G[src][i];

	// put the shortest path estimate from the source to the source is 0 in priority queue
	dis[src]=0,vis[src]=1;

	// each node may cover maximum (|V|-1) edges of the graph
	for(k=1;k<n;++k){

		// EXTRACT the next minimum shortest path estimate from minimum priority queue
		mini=INF;
		for(i=1;i<=n;++i)
			if(dis[i]<mini && !vis[i])
				mini=dis[i],u=i;

		// mark visited of the minimum shoratest path estimate node
		vis[u]=1;

		if(k==1) par[u]=src;

		// Relaxes all the adjacents from the node which have the next minimum shortest path estimate
		for(v=1;v<=n;++v)
			if(dis[v]>dis[u]+G[u][v] && !vis[v])
				dis[v]=dis[u]+G[u][v],par[v]=u;

	}

	// Return all types of answer from algorithm
	printf("\nThe final distance table :\n");
	for(i=1;i<=n;++i) printf("%d ",dis[i]);

	printf("\nThe parent nodes of each child nodes :\n");
	for(i=1;i<=n;++i) printf("%d->%d\n",i,par[i]);


	// Path Printing using loop
	printf("The traversing path from %d to %d is:\n",src,dest);
	k=0;
	while(src!=dest){
		path[k++]=dest;
		cost+=dis[dest];
		dest=par[dest];
	}
	path[k]=src;
	for(i=k;i>=0;--i) printf("%d ",path[i]);
	printf("\nThe total cost  = %d\n",cost);

}

// Path Printing using Recursive Backtracking
void printpath(int src,int dest){
	if(dest==src){
		printf("%d ",src);  
		return;
	}
	printpath(src,par[dest]);
	printf("%d ",dest);
}

int main(){
	int i,j,n;
	int src,target,v1,v2,wt;
    
    printf("Enter the number of vertices = ");
    scanf("%d",&n);
    
    printf("Enter the %dx%d adjacency matrix:\n",n,n);
    for(i=1;i<=n;++i)
    	for(j=1;j<=n;++j){
    		scanf("%d",&G[i][j]);
    		if(!G[i][j]) G[i][j]=INF;	// replace 0 with infinity as per our future requirement for the algorithm in shortest path estimation in minimum priority queue
    	}


    printf("Enter the source vetex = ");
    scanf("%d",&src);
    printf("Enter the target vetex = ");
    scanf("%d",&target);

    Dijkstra(n,src,target);
    
    printf("The traversing path from %d to %d is:\n",src,target);
    printpath(src,target);

}
/*
Enter the number of vertices = 5
Enter the 5x5 adjacency matrix:
0 10 0 5 0
0 0 1 2 0
0 0 0 0 4
0 3 9 0 2
7 0 6 0 0
Enter the source vetex = 1
Enter the target vetex = 3

The final distance table :
0 8 9 5 7
The parent nodes of each child nodes :
1->0
2->4
3->2
4->1
5->4
The traversing path from 1 to 3 is:
1 4 2 3
*/

//code by jay-neo

