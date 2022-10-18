#include<stdio.h>
void selection(int *,int);
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
	selection(arr,n);
}
void selection(int *arr,int n)
{
	int i,j,temp;
	for(i=0;i<n;i++)
	{
		for(j=i;j<n;j++)
		{
			if(arr[i]>=arr[j])
			{
				temp=arr[i];
				arr[i]=arr[j];
				arr[j]=temp;
			}
		}
	}
	printf("\nAfter the sorting elements are\n");
	for(i=0;i<n;i++)
		printf("%d ",arr[i]);
}

