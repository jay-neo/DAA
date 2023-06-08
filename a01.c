#include<stdio.h>
#include<stdlib.h>
#define size 20

int cmp(const void *a,const void *b){
	//For Accending Order
	return (*(int*)a)>(*(int*)b);
}
void print_arr(int arr[],int n){
	int i;
	printf("In sorted array:\n");
	for(i=0;i<n;i++) printf("%d ",arr[i]);
	printf("\n");
}

void binary_search(int arr[],int left,int right,int key){
	int mid=left+(right-left)/2;
	//Base Case:
	if(left>right){
		printf("The searching value not found in given array.\n");
		return;
	}
	if(key==arr[mid]){
		printf("The searching value found at %d position.\n",mid+1);
		return;
	}
	//Recursive Case:
	if(key<arr[mid]) binary_search(arr,left,mid-1,key);
	else if(key>arr[mid]) binary_search(arr,mid+1,right,key);
}


int main(){
	int i,n,key;
	int arr[size];

	printf("Enter the size of array = ");
	scanf("%d",&n);
	printf("Enter the %d element of array:\n",n);
	for(i=0;i<n;i++)
		scanf("%d",&arr[i]);

	printf("Enter the searching value = ");
	scanf("%d",&key);

	qsort(arr,n,sizeof(int),cmp);
	print_arr(arr,n);

	binary_search(arr,0,n-1,key);

}

//code by jay-neo
