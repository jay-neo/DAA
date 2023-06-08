#include<stdio.h>
#include<stdlib.h>
#define MAX 10

//	WARNING : not checked for directed disconnected graph which have not any negative weight cycle

const int INF = 1e5;
int G[MAX][MAX];

int Bellman_Ford(int s,int n,int src,int dis[],int par[]){
	int i,u,v;

	for(i=s;i<=n;++i) dis[i]=INF;
	dis[src]=0;

	for(i=s;i<n;++i)
		for(u=s;u<=n;++u)
			for(v=s;v<=n;++v)
				if(dis[u]!=INF && dis[v]>dis[u]+G[u][v]){
					dis[v]=dis[u]+G[u][v];
					par[v]=u;
				}

	for(u=s;u<=n;++u)
		for(v=s;v<=n;++v)
			if(dis[u]!=INF && (dis[v]>dis[u]+G[u][v]))
				return v;

	return 0;
}


void printpath(int node,int par[]){
	if(!par[node]){
		printf("%d",node);
		return;
	}
	printpath(par[node],par);
	printf(" -> %d",node);
}

void print_cycle(int s,int n,int node,int par[]){
	int i,curr;

	// for(i=s;i<=n;++i) node=par[node];
	curr=par[node];
	
	printf("%d ",node);
	while(curr!=node) printf("%d ",curr),curr=par[curr];
	printf("%d\n",node);
}

void DFS(int s,int n,int node,int vis[]){
	int i;
	vis[node]=1;
	for(i=1;i<=n;++i) if(!vis[i] && G[node][i]!=INF && G[node][i]) DFS(s,n,i,vis);

}

int solve(int s,int n,int src,int maxi,int dis[],int par[]){
	int i,j,u,v,cnt=0,f=-1;
	
	int vis[n+s];
	for(i=s;i<=n;++i) vis[i]=0;
	for(i=s;i<=n;++i){
		if(!vis[i]) f++,DFS(s,n,i,vis);
	}

	if(f) printf("\n\nThe Graph is Disconnected!!\n\n");

	for(i=s;i<=n;++i) vis[i]=0;
	
	for(i=s;i<=n;++i){
		if(!vis[i]){
			if(!f) v=Bellman_Ford(i,n,src,dis,par);
			else v=Bellman_Ford(i,n,i,dis,par);
			if(v){
				cnt++;
				if(cnt==1) printf("Given Graph have Negative Weight Cycle!!\n");
				printf("Cycle %d: ",cnt);
				print_cycle(i,n,v,par);
			}
			for(j=i;j<=n;++j) if(dis[j]<=maxi) vis[j]=1;
		}
	}

	return cnt;
}



int main(){
	int i,j,n,src,dest;
	int cy,maxi=-INF,f;
	int *vis,*dis,*par;

	printf("Enter the number of vertices = ");
	scanf("%d",&n);

	printf("Enter the graph as %dx%d adjacency matrix:\n",n,n);
	for(i=1;i<=n;++i)
		for(j=1;j<=n;++j){
			scanf("%d",&G[i][j]);
			if(maxi<G[i][j] && i!=j) maxi=G[i][j];
			if(G[i][j]==0) G[i][j]=INF;
		}


	par=(int*)calloc(n+1,sizeof(int));
	dis=(int*)malloc((n+1)*sizeof(int));


	printf("Enter the source vertex = ");
	scanf("%d",&src);


	cy=solve(1,n,src,maxi,dis,par);

	if(cy) printf("The total number of negative cycle = %d\n",cy);
	else{	
			while(1){
				// printf("Enter the target vertex = ");
				// scanf("%d",&dest);

				printf("The Final Distance Table:\n");
				for(i=1;i<=n;++i) printf("%d ",dis[i]);
				printf("\nThe Final Parent Table:\n");
				for(i=1;i<=n;++i) printf("%d ",par[i]);

				printf("\nShortest distances from %d: ",src); 
				for(i=1; i<=n; i++) 
	            	if(i!=src){ 
	                	printf("\n\nVertex %d :   Cost = %d \n",i,dis[i]); 
	                	printf("Path: "); 
	                	printpath(i,par); 
	            	} 
				// printf("\nThe Traversing Path from %d to %d is:\n",src,dest);
				// printpath(dest,par);
				// printf("\nThe Total Cost is = %d",dis[dest]);

	            printf("\n\n\nPress 0 to Exit\nPress 1 to Continue\nEnter : ");
	            scanf("%d",&j);
	            if(j==0) break;

	            for(i=1;i<=n;++i) par[i]=0;

				printf("Enter the source vertex = ");
				scanf("%d",&src);

				Bellman_Ford(1,n,src,dis,par);
	       	}
	}

	free(par);
	free(dis);
}

/*
Enter the number of vertices = 8
Enter the graph as 8x8 adjacency matrix:
0 0 0 0 0 0 0 0
1 0 2 0 0 0 0 0
0 0 0 3 0 0 0 0
0 0 0 0 -3 0 0 0
0 -3 0 0 0 0 0 0
0 0 0 0 0 0 -1 0
0 0 0 0 0 0 0 -1
0 0 0 0 0 -1 0 0
Given Graph have Negative Weight Cycle!!
Cycle 1: 4 3 2 5 4
Cycle 2: 7 6 8 7
The total number of negative cycle = 2
*/



/*
Enter the number of vertices = 5
Enter the graph as 5x5 adjacency matrix:
0 6 0 7 0
0 0 5 8 -4
0 -2 0 0 0
0 0 -3 0 9
2 0 7 0 0
Enter the source vertex = 1
The Final Distance Table:
0 2 4 7 -2
The Final Parent Table:
0 3 4 1 2
Shortest distances from 1:

Vertex 2 :   Cost = 2
Path: 1 -> 4 -> 3 -> 2

Vertex 3 :   Cost = 4
Path: 1 -> 4 -> 3

Vertex 4 :   Cost = 7
Path: 1 -> 4

Vertex 5 :   Cost = -2
Path: 1 -> 4 -> 3 -> 2 -> 5
*/



/*
Enter the number of vertices = 5
Enter the graph as 5x5 adjacency matrix:
0 6 0 7 0
0 0 5 8 -4
0 -2 0 0 0
0 0 -3 0 9
2 0 7 0 0
Enter the source vertex = 5
The Final Distance Table:
2 4 6 9 0
The Final Parent Table:
5 3 4 1 0
Shortest distances from 5:

Vertex 1 :   Cost = 2
Path: 5 -> 1

Vertex 2 :   Cost = 4
Path: 5 -> 1 -> 4 -> 3 -> 2

Vertex 3 :   Cost = 6
Path: 5 -> 1 -> 4 -> 3

Vertex 4 :   Cost = 9
Path: 5 -> 1 -> 4
*/

// code by jay-neo
