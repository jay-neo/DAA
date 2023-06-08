#include<stdio.h>
#define MAX 20

int min(int a,int b){ return a>b?b:a; }

int MCM(int n,int d[]){
    int i,j,k;
    int m[n][n];

    for(i=1;i<n;++i) m[i][i]=0;

    for(i=n-1;i>=1;--i)
        for(j=i+1;j<n;++j){
            m[i][j]=1e9;
            for(k=i;k<j;++k)
                m[i][j]=min(m[i][j],(m[i][k]+m[k+1][j]+d[i-1]*d[k]*d[j]));
        }

    return m[1][n-1];
}

int mcm2(int n,int p[]){
    int i,j,k,L;
	int m[n][n];

    for(i=0;i<n;i++) m[i][i]=0;

    for(L=2;L<n;L++){
        for(i=1;i<n-L+1;i++){
            j=i+L-1;
            m[i][j]=1e9;
            for(k=i;k<j;k++){
               m[i][j]=min(m[i][j],(m[i][k]+m[k+1][j]+p[i-1]*p[k]*p[j]));
            }
        }
    }

    return m[1][n - 1];
}

int main() {
    int i,n,arr[MAX];

    printf("Enter the size of dimension array = ");
    scanf("%d",&n);
    printf("Enter the %d array elements:\n",n);
    for(i=0;i<n;++i) scanf("%d",&arr[i]);

    printf("Minimum number of multiplications is %d\n", MCM(n,arr));
	printf("Minimum number of multiplications is %d", mcm2(n,arr));

    return 0;
}

// code by jay-neo
