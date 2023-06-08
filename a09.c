#include<stdio.h>
#include<stdlib.h>				// for in-built qsort() function
#define MAX 10

const int INF=1e9+7;
int G[MAX][MAX];



int par[MAX],size[MAX];

void DSU(int n){
    int i;
    for(i=0;i<=n;++i) par[i]=i,size[i]=1;
}
int Find(int node){
    if(node==par[node]) return node;
    return par[node]=Find(par[node]);
}
void Union(int a,int b){
    a=Find(a);
    b=Find(b);
    if(a!=b){
        if(size[a]<size[b]) b=a+b-(a=b);
        par[b]=a;
        size[a]+=size[b];
    }
    
}

void DSU2(int n){
	int i;
	for(i=0;i<=n;++i) par[i]=size[i]=0;
}
int Union2(int a,int b){
	while(par[a]) a=par[a];
	while(par[b]) b=par[b];
	if(a!=b){
		par[b]=a;
		return 1;
	}
	return 0;
}


int Kruskal(int n){										// Using direct Adjacency Matrix
	int i,j,k=1,mini,a=0,b=0,ans=0;

	// DSU(n);										// Method 1
	DSU2(n);										// Method 2

	printf("The Minimum Spanning Tree is:\n");
	while(k<n){
		mini=INF;
		for(i=0;i<n;++i){
			for(j=0;j<n;++j)
				if(G[i][j] && G[i][j]<mini){
					mini=G[i][j];
					a=i;
					b=j;
				}
		}

		// if(Find(a)!=Find(b)){							// Method 1
		// 	Union(a,b);
		// 	printf("(%d %d) = %d\n",a+1,b+1,mini);
		// 	ans+=mini;
		// 	k++;
		// }

		if(Union2(a,b)){								// Method 2
			printf("(%d %d) = %d\n",a+1,b+1,mini);
			ans+=mini;
			k++;
		}

		G[a][b]=G[b][a]=0;
	}

	return ans;
}



int GG[MAX][MAX];

int cmp(const void *a,const void *b){
    // const int *aa=a;
    // const int *bb=b;
    // return aa[2]>bb[2];

    const int (*aa)[3]=a;
    const int (*bb)[3]=b;
    return (*aa)[2]>(*bb)[2];
}
void sort(int e){
    int i,j,k;
    for(i=0;i<e-1;++i) for(j=0;j<e-i-1;++j) if(GG[j][2]>GG[j+1][2]) for(k=0;k<3;++k){
            GG[j][k]=GG[j+1][k]+GG[j][k]-(GG[j+1][k]=GG[j][k]);
    }
}
int convert(int n){
    int i,j;
    int e=0;

    for(i=0;i<n;++i){
        for(j=i;j<n;++j){
            if(G[i][j]){
                GG[e][0]=i+1;
                GG[e][1]=j+1;
                GG[e++][2]=G[i][j];
            }
        }
    }
    return e;
}
void printll(int e){
    int i;
    for(i=0;i<e;++i){
        printf("%d %d %d\n",GG[i][0],GG[i][1],GG[i][2]);
    }
}
int Kruskal2(int n){										// by converting adjacency list
    int i,a,b,wt,e,ans=0;

    DSU(n);

    e=convert(n);

    // printll(e); printf("\n");

    // qsort(GG,e,sizeof(GG[0]),cmp);			// cmp Not Working
    sort(e);

    // printll(e);

    printf("The Minimum Spanning Tree is:\n");
    for(i=0;i<n;++i){
        a=GG[i][0];
        b=GG[i][1];
        wt=GG[i][2];
        if(Find(a)!=Find(b)){
            Union(a,b);
            ans+=wt;
            printf("(%d)-----{%d}-----(%d)\n",a,wt,b);
        }
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

    printf("The minimum cost of MST = %d\n",Kruskal2(n));					// for adjacency list
    printf("The minimum cost of MST = %d\n",Kruskal(n));					// for adjacency matrix

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

