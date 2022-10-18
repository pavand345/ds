#include<stdio.h>
int main()
{
	int n,i,j,temp;
	printf("enter the size of the array : ");
	scanf("%d",&n);
	int arr[n];
	printf("ente the array elements\n");
	for(i=0;i<n;i++)
		scanf("%d",&arr[i]);
	printf("The array elements you entered\n");
	for(i=0;i<n;i++)
		printf("%d ",arr[i]);
	for(i=0;i<n;i++)
	{
		for(j=0;j<n-1-i;j++)
		{
			if(arr[j]>arr[j+1])
			{
				temp=arr[j+1];
				arr[j+1]=arr[j];
				arr[j]=temp;
			}
		}
	}
	printf("\nAfter the Sorting elements are\n");
	for(i=0;i<n;i++)
		printf("%d ",arr[i]);
}
