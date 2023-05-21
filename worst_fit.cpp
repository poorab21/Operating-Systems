#include<iostream>
int main()
{
	int partitions[100],partition_size,blocks[100][100],count=0;
	int processes[100],process_size,largest_block=-1,largest=-1;
	bool full[100];
	std::cout<<"Enter Number of Partitions:";
	std::cin>>partition_size;
	for(int i=0;i<partition_size;i++)
	{
		std::cout<<"Partition "<<i+1<<std::endl;
		std::cout<<"Enter Partition Size:";
		std::cin>>partitions[i];
		full[i]=false;
	}
	std::cout<<"Enter Number of Processes:";
	std::cin>>process_size;
	for(int i=0;i<process_size;i++)
	{
		std::cout<<"Process "<<i+1<<std::endl;
		std::cout<<"Enter Process size:";
		std::cin>>processes[i];
	}
	for(int i=0;i<process_size;i++)
	{
		largest_block=-1;
		largest=-1;
		for(int j=0;j<partition_size;j++)
		{
			if(largest<partitions[j] && processes[i]<=partitions[j] && full[j]==false)
			{
				largest_block=j;
				largest=partitions[j];
			}
		}
		if(largest_block==-1)
		{
			blocks[count][0]=i+1;
			blocks[count][1]=processes[i];
			blocks[count][2]=largest_block;
		}
		else
		{
			blocks[count][0]=i+1;
			blocks[count][1]=processes[i];
			blocks[count][2]=largest_block+1;
			full[largest_block]=true;
		}
		count++;
	}
	std::cout<<"Process Number | Process Size | Block Number"<<std::endl;
	for(int i=0;i<count;i++)
	{
		if(blocks[i][2] != -1)
		{
			std::cout<<blocks[i][0]<<"\t\t"<<blocks[i][1]<<"\t\t"<<blocks[i][2]<<std::endl;
		}
		else if(blocks[i][2]==-1)
		{
			std::cout<<blocks[i][0]<<"\t\t"<<blocks[i][1]<<"\t\t"<<"waiting"<<std::endl;
		}
	}
}
