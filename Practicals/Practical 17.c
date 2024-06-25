//16. Write a program for merge sort.
#include<stdio.h>
#define n 6
int a[n];
int temp[n];
void combine( int low,int mid, int high)
{
	int i,j,k,x;
	i=low;
	k=low;
	j=mid+1;
	while( i <= mid && j<=high)
	{
		if(a[i]<=a[j])
		{
			temp[k]=a[i];
			k++;
			i++;
		}
		else
		{
			temp[k]=a[j];
			k++;
			j++;
		}
	}
	while(i<=mid)
	{
			temp[k]=a[i];
			k++;
			i++;
	}
	while(j<=high)
	{
			temp[k]=a[j];
			k++;
			j++;
	}
	for(x=low;x<=high;x++)
	{
		a[x]=temp[x];
	}
}
void mergesort(int low,int high)
{
	int mid;
	if(low<high)
	{
		mid=(low+high)/2;
		mergesort(low,mid);//left sub array
		mergesort(mid+1,high);
		combine(low,mid,high);
	}
}
void  main()
{
	int i,low,high;
	printf("\n ENTER Unsorted Array:\n");
	for(i=0;i<n;i++)
	{
		printf("\na[%d]=",i);
		scanf("%d",&a[i]);
	}
	low=0;
	high=n-1;
	mergesort(low,high);
	printf("\n Sorted Array:\n");
	for(i=0;i<n;i++)
	{
		printf("\na[%d]=%d",i,a[i]);
	}
}
