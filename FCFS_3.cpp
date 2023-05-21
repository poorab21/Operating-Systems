#include<iostream>
int main()
{
    int processes[10],service[10],waiting[10];
    int burst[10],turnaround[10],completion[10];
    int size,arrival;
    float sum1=0,sum2=0;
    std::cout<<"Enter Number of Processes:";
    std::cin>>size;
    std::cout<<"Enter Arrival Time for all Processes:";
    std::cin>>arrival;
    for(int i=0;i<size;i++)
    {
        processes[i]=i+1;
        std::cout<<"Enter Burst:";
        std::cin>>burst[i];
    }
    service[0]=arrival;
    waiting[0]=0;
    for(int i=1;i<size;i++)
    {
        service[i]=service[i-1]+burst[i-1];
        waiting[i]=service[i]-arrival;
    }
    for(int i=0;i<size;i++)
    {
        turnaround[i]=waiting[i]+burst[i];
    }
    for(int i=0;i<size;i++)
    {
        completion[i]=turnaround[i]+arrival;
    }
    std::cout<<"Process ID"<<"\t"<<"Arrival"<<"\t\t"<<"Burst Time"<<"\t"<<"Waiting Time"<<"\t"<<"Turnaround Time"<<"\t"<<"Completion Time"<<std::endl;
	for(int i=0;i<size;i++)
	{
		sum1+=waiting[i];
		sum2+=turnaround[i];
		std::cout<<i+1<<"\t\t"<<arrival<<"\t\t"<<burst[i]<<"\t\t"<<waiting[i]<<"\t\t"<<turnaround[i]<<"\t\t"<<completion[i]<<std::endl;
	}
	std::cout<<"Average Waiting Time = "<<sum1/size<<std::endl;
	std::cout<<"Average Turnaround Time = "<<sum2/size;
}
