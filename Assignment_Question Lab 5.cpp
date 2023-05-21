#include<iostream>
void swap(int &x,int &y)
{
	int temp=x;
	x=y;
	y=temp;
}
int main()
{
	int processes[100][100],size;
	std::cout<<"Enter Number of Processes:";
	std::cin>>size;
	for(int i=0;i<size;i++)
	{
		std::cout<<"Enter Process ID:";
		std::cin>>processes[i][0];
		std::cout<<"Enter Burst Limit(Process "<<i+1<<"):";
		std::cin>>processes[i][1];
	}
	for(int i=0;i<size;i++)
	{
		for(int j=i+1;j<size;j++)
		{
			if(processes[i][1]>processes[j][1])
			{
				swap(processes[i][0],processes[j][0]);
				swap(processes[i][1],processes[j][1]);
			}
			else if(processes[i][1]==processes[j][1] && processes[i][0]>processes[j][0])
			{
				swap(processes[i][0],processes[j][0]);
				swap(processes[i][1],processes[j][1]);
			}
		}
	}
	int completion=0;
	float Average_TurnAround=0,Average_WaitingTime=0;
	for(int i=0;i<size;i++)
	{
		completion+=processes[i][1];
		processes[i][2]=completion;
		processes[i][4]=processes[i][2];
		processes[i][3]=processes[i][4]-processes[i][1];
	}
	std::cout<<"Process ID | Burst | Completion Time | Waiting Time | Turnaround Time"<<std::endl;
	for(int i=0;i<size;i++)
	{
		for(int j=0;j<size;j++)
		{
			if(processes[j][0]==i+1)
			{
				Average_TurnAround+=processes[j][4];
				Average_WaitingTime+=processes[j][3];
				std::cout<<processes[j][0]<<"\t\t"<<processes[j][1]<<"\t"<<processes[j][2]<<"\t\t"<<processes[j][3]<<"\t\t"<<processes[j][4]<<std::endl;
			}
		}
	}
	std::cout<<"Average Turn-around Time = "<<Average_TurnAround/size<<std::endl;
	std::cout<<"Average Waiting Time = "<<Average_WaitingTime/size<<std::endl;
}
