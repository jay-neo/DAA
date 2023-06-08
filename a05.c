#include<stdio.h>
#include<stdlib.h>
#define MAX 20

float arr[MAX][4];
// |   0  |  1   |  2   |  3  |
// |Sl no.|weight|profit|ratio|


int cmp(const void *a,const void *b){
	const int (*aa)[4]=(const int (*)[4])a;
    const int (*bb)[4]=(const int (*)[4])b;
    return (*aa)[3]<(*bb)[3];
}


void Knapsack(int n,float size){
	int i,j,k;
	float profit=0;
	float sol[MAX]={};

	// sorting according to the ratio in decresing order
	// for(i=0;i<n-1;i++) for(j=0;j<n-i-1;j++) for(k=0;k<4;k++) if(arr[j][3]<arr[j+1][3])
	// arr[j+1][k] = arr[j][k] + arr[j+1][k] - ( arr[j][k] = arr[j+1][k] );

	qsort(arr,n,sizeof(arr[0]),cmp);

	// for(i=0;i<n;++i) printf("%0.2f %0.2f %0.2f %0.2f\n",arr[i][0],arr[i][1],arr[i][2],arr[i][3]);
	
	//calculate total profit
	for(i=0;i<n;i++){
		if(arr[i][1]>size){
			profit+=arr[i][3]*size;
			sol[(int)arr[i][0]]=size/arr[i][1];
			break;
		}
		profit+=arr[i][2];
		sol[(int)arr[i][0]]=1;
		size-=arr[i][1];
	}

	// Print all the required solution
	printf("The final solution vector according input table:\n");
	for(i=0;i<n;++i) printf("%0.2f ",sol[i]);
	printf("\nTotal Profit = %0.2f",profit);
	
}

 int main(){
 	int n,i;
 	float cap;
 	printf("Enter the nuber of objects = ");
 	scanf("%d",&n);

 	for(i=0;i<n;i++){
 		arr[i][0]=i;
 		// printf("Enter the %d object's weight = ",i+1);
 		scanf("%f",&arr[i][1]);
 		// printf("Enter the %d object's profit = ",i+1);
 		scanf("%f",&arr[i][2]);
 		arr[i][3]=arr[i][2]/arr[i][1];
 	}

 	printf("Enter the capacity of Knapshak = ");
 	scanf("%f",&cap);

 	Knapsack(n,cap);

 }

/*
 Enter the nuber of objects = 5
10 40
15 45
5 30
25 90
22 77
Enter the capacity of Knapshak = 60
The final solution vector according input table:
1.00 0.00 1.00 1.00 0.91
Total Profit = 230.00
*/

 // code by jay-neo
