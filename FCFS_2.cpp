#include<iostream>
int main()
{
	int size,burst[100],waiting[100],turnaround[100],completion=0;
	float sum1=0,sum2=0;
	std::cout<<"Enter Number of Processes:";
	std::cin>>size;
	for(int i=0;i<size;i++)
	{
		std::cout<<"Process "<<i+1<<std::endl;
		std::cout<<"Enter Burst Time:";
		std::cin>>burst[i];
	}
	waiting[0]=0;
	for(int i=1;i<size;i++)
	{
		completion+=burst[i-1];
		waiting[i]=completion;
	}
	for(int i=0;i<size;i++)
	{
		turnaround[i]=waiting[i]+burst[i];
	}
	std::cout<<"Process ID"<<"\t"<<"Burst Time"<<"\t"<<"Waiting Time"<<"\t"<<"Turnaround Time"<<std::endl;
	for(int i=0;i<size;i++)
	{
		sum1+=waiting[i];
		sum2+=turnaround[i];
		std::cout<<i+1<<"\t\t"<<burst[i]<<"\t\t"<<waiting[i]<<"\t\t"<<turnaround[i]<<std::endl;
	}
	std::cout<<"Average Waiting Time = "<<sum1/size<<std::endl;
	std::cout<<"Average Turnaround Time = "<<sum2/size;
}
