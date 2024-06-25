//15. Write a program for bubble sort.
#include<stdio.h>
#define n 5
void main()
{
	int a[n],i,j,temp;
	printf("\n ENTER Unsorted Array:\n");
	for(i=0;i<n;i++)
	{
		printf("\na[%d]=",i);
		scanf("%d",&a[i]);
	}
	for(i=0;i<n-1;i++)
	{
		for(j=0;j<n-1-i;j++)
		{
			if(a[j]>a[j+1])
			{
				temp=a[j];
				a[j]=a[j+1];
				a[j+1]=temp;
			}
		}
	}
	printf("\n Sorted Array:\n");
	for(i=0;i<n;i++)
	{
		printf("\na[%d]=%d",i,a[i]);
	}
}
