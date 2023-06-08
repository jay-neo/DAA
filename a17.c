#include<stdio.h>
#define N 4

int G[N][N];

int InversionCount(int arr[]){
	int i,j,inv=0;

	for(i=0;i<N*N-1;++i)
		for(j=i+1;j<N*N;++j)
			if(arr[i] && arr[j] && arr[i]>arr[j])
				inv++;

	return inv;
}

int emptyPosition(){
	int i,j;

	for(i=N-1;i>=0;--i)
		for(j=N-1;j>=0;--j)
			if(!G[i][j])
				return N-i;
}

int PuzzelSolve(){
	if(N&1) return !(InversionCount((int*)G)&1);
	else if(emptyPosition()&1) return !(InversionCount((int*)G)&1);
	else return (InversionCount((int*)G)&1);
}


int main(){
	int i,j;

	printf("Enter the %dx%d puzzel grid:\n",N,N);
	for(i=0;i<N;++i)
		for(j=0;j<N;++j)
			scanf("%d",&G[i][j]);

	if(PuzzelSolve()) printf("Solvable!\n");
	else printf("Not Solvable!\n");

}
// Time Complexity	= O(N^2)
// Space Complexity	= O(N)



/*

12 1 10 2
7 11 4 14
5 0 9 15
8 13 6 3
Solvable
*/


//code by jay-neo