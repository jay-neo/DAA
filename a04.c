#include<stdio.h>
#include <limits.h>
#define size 20
int arr[size];
int mx=INT_MIN;
int mn=INT_MIN;

void max_min(int left,int right){
	int mid,mxx,mnn;
	if(left==right){
		mn=mx=arr[left];
	}
	else if(left==right-1){
		if(arr[left]<arr[right]){
			mx=arr[right];
			mn=arr[left];
		}
		else{
			mx=arr[left];
			mn=arr[right];
		}
	}
	else{
		mid=left+(right-left)/2;
		max_min(left,mid);
		mxx=mx;
		mnn=mn;
		max_min(mid+1,right);
		if(mxx>mx) mx=mxx;
		if(mnn<mn) mn=mnn;
	}
}

int main(){
	int i,n;

	printf("Enter the size of array = ");
	scanf("%d",&n);
	printf("Enter the %d element of array:\n",n);
	for(i=0;i<n;i++)
		scanf("%d",&arr[i]);

	max_min(0,n-1);

	printf("Maximum Element = %d\n",mx);
	printf("Minimum Element = %d",mn);

}

//code by jay-neo
