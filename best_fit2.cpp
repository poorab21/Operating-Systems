#include<iostream>
int Largest_Block(int partitions[],int size)
{
	int largest=-1;
	for(int i=0;i<size;i++)
	{
		if(largest<partitions[i])
		{
			largest=partitions[i];
		}
	}
	return largest+1;
}
int main()
{
	int partitions[100],partition_size,largest=-1;
	int processes[100],process_size,position=-1;
	int blocks[100][100],count=0;
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
		std::cout<<"Enter Process Size:";
		std::cin>>processes[i];
	}
	for(int i=0;i<process_size;i++)
	{
		largest=Largest_Block(partitions,partition_size);
		position=-1;
		for(int j=0;j<partition_size;j++)
		{
			if(processes[i]<=partitions[j] && partitions[j]<largest)
			{
				position=j;
				largest=partitions[j];
			}
		}
		if(position==-1)
		{
			blocks[count][0]=i+1;
			blocks[count][1]=processes[i];
			blocks[count][2]=position;
		}
		else if(position != -1)
		{
			blocks[count][0]=i+1;
			blocks[count][1]=processes[i];
			blocks[count][2]=position+1;
			partitions[position]-=processes[i];
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
