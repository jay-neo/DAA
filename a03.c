#include<stdio.h>
#define size 20

void swap(int *a,int *b){
	*b=*a+*b-(*a=*b);
}

int partition(int arr[],int left,int right){
	int pivot,i,l,idx;
	pivot=arr[right];
	idx=left;
	for(i=left;i<right;i++)
		if(pivot>arr[i])
			swap(&arr[i],&arr[idx++]);
	swap(&arr[idx],&arr[right]);
	return idx;
}

void quick_sort(int arr[],int left,int right){
	if(left>=right)
		return;
	int p=partition(arr,left,right);
	quick_sort(arr,left,p-1);
	quick_sort(arr,p+1,right);
}


int main(){
	int i,n;
	int arr[size];

	printf("Enter the size of array = ");
	scanf("%d",&n);
	printf("Enter the %d element of array:\n",n);
	for(i=0;i<n;i++)
		scanf("%d",&arr[i]);

	quick_sort(arr,0,n-1);

	printf("After the sorting\n");
	for(i=0;i<n;i++)
		printf("%d ",arr[i]);
}


//code by jay-neo
