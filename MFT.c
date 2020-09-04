#include<stdio.h>
int main()
{
	int process[50], size[50], nba[50], ifm[50];
	int memory,blocks,block_size,n,i,j,count=0;

	printf("Enter total memory size: ");
	scanf("%d",&memory);
	printf("Enter number of blocks: ");
	scanf("%d",&blocks);
	block_size = memory/blocks;
	printf("Block Size is : %d",block_size);
	printf("\nEnter number of processes: ");
	scanf("%d",&n);

	for(i=0; i<n; i++)
	{
		process[i] = i+1;
		printf("Enter process %d size : ",i+1);
		scanf("%d",&size[i]);
		if(size[i]>memory)
		{
			count = 1;
			break;
		}
		nba[i] = size[i]/block_size;
		if((size[i]%block_size)!=0)
		{
			nba[i] = nba[i]+1;
		}
		ifm[i] = (nba[i]*block_size)-size[i];
		memory = memory - size[i];
	}
	printf("\n Process\tSize\tNo.Blocks\tInternal Fragmentation\n\n");
	for(j=0;j<n;j++)
	{
		printf(" P-%d\t\t%d\t%d\t\t%d\n",process[j],size[j],nba[j],ifm[j]);
	}
	if(count==1)
	{
		printf("insufficient memory for remaining process");
	}
}
