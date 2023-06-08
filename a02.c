#include<stdio.h>
#define size 20


void merge(int arr[],int left,int mid,int right){

	int i,temp_arr[size];
	int l=left;
	int r=mid+1;
	int t=left;

	while(l<=mid && r<=right){
		if(arr[l]<=arr[r])
			temp_arr[t++]=arr[l++];
		else
			temp_arr[t++]=arr[r++];
	}
	while(l<=mid)
		temp_arr[t++]=arr[l++];
	while(r<=right)
		temp_arr[t++]=arr[r++];
	for(i=left;i<=right;i++)
		arr[i]=temp_arr[i];
}

void merge_sort(int arr[],int left,int right){
	int mid;
	if(left>=right) return;
	mid=(right+left)/2;
	merge_sort(arr,left,mid);
	merge_sort(arr,mid+1,right);
	merge(arr,left,mid,right);
}

int main(){
	int i,n;
	int arr[size];

	printf("Enter the size of array = ");
	scanf("%d",&n);
	printf("Enter the %d element of array:\n",n);
	for(i=0;i<n;i++)
		scanf("%d",&arr[i]);

	merge_sort(arr,0,n-1);

	printf("After the sorting\n");
	for(i=0;i<n;i++)
		printf("%d ",arr[i]);
}


//code by jay-neo
