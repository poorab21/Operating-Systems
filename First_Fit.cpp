#include<iostream>
int main()
{
	int size_partitions,partitions[100];
	int size_processes,processes[100];
	int block_number[100][100],count=0;
	bool full[100];
	std::cout<<"Enter Number of Partitions:";
	std::cin>>size_partitions;
	for(int i=0;i<size_partitions;i++)
	{
		std::cout<<"Partiton "<<i+1<<std::endl;
		std::cout<<"Enter Partition Size:";
		std::cin>>partitions[i];
		full[i]=false;
	}
	std::cout<<"Enter Number of Processes:";
	std::cin>>size_processes;
	for(int i=0;i<size_processes;i++)
	{
		std::cout<<"Process "<<i+1<<std::endl;
		std::cout<<"Enter Process Size:";
		std::cin>>processes[i];
	}
	for(int i=0;i<size_processes;i++)
	{
		for(int j=0;j<size_partitions;j++)
		{
			if(processes[i]<=partitions[j] && full[j]==false)
			{
				block_number[count][0]=i+1;
				block_number[count][1]=j+1;
				full[j]=true;
				count++;
				break;
			}
			else if(processes[i]>partitions[j] && j==size_partitions-1 || processes[i]<=partitions[j] && j==size_partitions-1 && full[j]==true)
			{
				block_number[count][0]=i+1;
				block_number[count][1]=-1;
				count++;
			}
		}
	}
	std::cout<<"Process Number | Process Size | Block Number"<<std::endl;
	for(int i=0;i<count;i++)
	{
		if(block_number[i][1] != -1)
		{
			std::cout<<block_number[i][0]<<"  |  "<<processes[i]<<"  |  "<<block_number[i][1]<<std::endl;
		}
		else if(block_number[i][1]==-1)
		{
			std::cout<<block_number[i][0]<<"  |  "<<processes[i]<<"  |  "<<"Waiting"<<std::endl;
		}
	}
}
