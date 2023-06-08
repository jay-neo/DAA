#include<stdio.h>
#define MAX 20

const int INF=1e5;
int G[MAX][MAX];
int T[MAX][3];
int adj[MAX];

int Prim(int n){                        // Time Complexity = O(n^2)
    int i,u,v;
    int mini=INF,ans=0;
    
    // start with node u
    u=0;

    // EXTRACT edge with minimum cost
    for(i=0;i<n;++i)
        if(G[u][i]<mini) mini=G[u][i],v=i;

    // Add in MST
    T[u][0]=u;
    T[u][1]=v;
    T[u][2]=G[u][v];

    // Initialize adjacent nodes
    for(i=0;i<n;++i){
        if(G[i][u]<G[i][v]) adj[i]=u;
        else adj[i]=v;
    }

    adj[u]=adj[v]=0;

    for(u=1;u<n-1;++u){
        // EXTRACT edge with minimum cost
        mini=INF;
        for(i=0;i<n;++i)
            if(adj[i] && G[i][adj[i]]<mini)
                mini=G[i][adj[i]],v=i;

        // Add in MST
        T[u][0]=v;
        T[u][1]=adj[v];
        T[u][2]=G[v][adj[v]];

        adj[v]=0;

        // Update the adj[]
        for(i=0;i<n;++i)
            if(adj[i] && G[i][adj[i]]>G[i][v]) adj[i]=v;

        // adj[v]=adj[adj[v]]=0;

    }

    printf("The Minimum Spanning Tree is:\n");
    for(i=0;i<n-1;++i) printf("(%d %d)-->%d\n",T[i][0]+1,T[i][1]+1,T[i][2]),ans+=T[i][2];

    return ans;
}


int  Prim1(int n){                      //  Time Complexity = O(n^3)
    int i,j,k,a,b,mini,ans=0;
    int vis[n];
    int src=0;

    for(i=0;i<=n;i++) vis[i]=0;
    vis[src]=1;
     
    printf("The Minimum Spanning Tree is:\n");
    for(k=1;k<n;k++){
        mini=INF;
        for(i=0;i<n;i++){
            if(vis[i])
                for(j=0;j<n;j++)
                   if(!vis[j] && mini>G[i][j]){
                        mini=G[i][j];
                        a=i,b=j;
                        }
        }
        
        printf("(%d)----%d----(%d)\n",a+1,mini,b+1);

        vis[a]=vis[b]=1;
        ans+=mini;
    }
    
    return ans;
}

int main(){
    int i,j,n;

    printf("Enter the number of vertices = ");
    scanf("%d",&n);

    printf("Enter the %dx%d adjacency matrix :\n",n,n);
    for(i=0;i<n;++i)
        for(j=0;j<n;++j){
            scanf("%d",&G[i][j]);
            if(!G[i][j]) G[i][j]=INF;
        }

    printf("The minimum cost of MST = %d\n",Prim(n));
    printf("The minimum cost of MST = %d",Prim1(n));
}
/*
0 8 1 5 0 0
8 0 5 0 3 0
1 5 0 5 6 4
5 0 5 0 0 2
0 3 6 0 0 6
0 0 4 2 6 0
*/

// code by jay-neo