#include<iostream>
#include<queue>
int main()
{
	std::queue<int> q1;
	int burst[100],arrival[100],sub[100];
	bool allow[10],once[10];
	float AvgTurnaround=0,AvgWaiting=0;
	int size,quantum,time=0,process_Number=0;
	int waiting[100],last_position[100];
	int turnaround[100],completionTime[100];
	std::cout<<"Enter Number of Processes:";
	std::cin>>size;
	for(int i=0;i<size;i++)
	{
		std::cout<<"Process "<<i+1<<std::endl;
		std::cout<<"Enter Arrival Time:";
		std::cin>>arrival[i];
		std::cout<<"Enter Burst Time:";
		std::cin>>burst[i];
		sub[i]=burst[i];
	}
	std::cout<<"Enter Quantum:";
	std::cin>>quantum;
	for(int i=0;i<size;i++)
	{
		allow[i]=false;
	}
	for(int i=0;i<size;i++)
	{
		once[i]=false;
	}
	for(int i=0;i<size;i++)
	{
		last_position[i]=0;
	}
	for(int i=0;i<size;i++)
	{
		waiting[i]=0;
	}
	if(arrival[0]>0)
	{
		time=arrival[0];
	}
	q1.push(process_Number);
	allow[0]=true;
	once[0]=true;
	while(1)
	{
		if(sub[process_Number]>=quantum)
		{
			sub[process_Number]-=quantum;
			if(last_position[process_Number] != 0)
			{
				waiting[process_Number]+=time-last_position[process_Number];
			}
			time+=quantum;
			last_position[process_Number]=time;
			if(sub[process_Number]==0)
			{
				q1.pop();
				for(int i=0;i<size;i++)
				{
					if(time>=arrival[i] && allow[i]==false)
					{
						q1.push(i);
						allow[i]=true;
					}
				}
				if(q1.empty()) break;
				process_Number=q1.front();
				if(arrival[process_Number]<time && once[process_Number]==false && last_position[process_Number]==0)
				{
					waiting[process_Number]+=time-arrival[process_Number];
					once[process_Number]=true;
				}
			}
			else if(sub[process_Number]>0)
			{
				for(int i=0;i<size;i++)
				{
					if(time>=arrival[i] && allow[i]==false)
					{
						q1.push(i);
						allow[i]=true;
					}
				}
				q1.push(process_Number);
				q1.pop();
				process_Number=q1.front();
				if(arrival[process_Number]<time && once[process_Number]==false && last_position[process_Number]==0)
				{
					waiting[process_Number]+=time-arrival[process_Number];
					once[process_Number]=true;
				}
			}
		}
		else if(sub[process_Number]<quantum)
		{
			q1.pop();
			if(last_position[process_Number] != 0)
			{
				waiting[process_Number]+=time-last_position[process_Number];
			}
			time+=sub[process_Number];
			sub[process_Number]=0;
			for(int i=0;i<size;i++)
			{
				if(arrival[i]<=time && allow[i] && allow[i]==false)
				{
					q1.push(i);
				}
			}
			if(q1.empty()) break;
			process_Number=q1.front();
			if(arrival[process_Number]<time && once[process_Number]==false && last_position[process_Number]==0)
			{
				waiting[process_Number]+=time-arrival[process_Number];
				once[process_Number]=true;
			}
		}
	}
	for(int i=0;i<size;i++)
	{
		turnaround[i]=waiting[i]+burst[i];
	}
	for(int i=0;i<size;i++)
	{
		completionTime[i]=turnaround[i]+arrival[i];
	}
	std::cout<<"Process ID"<<"\t"<<"Arrival Time"<<"\t"<<"Burst Time"<<"\t"<<"Turnaround Time"<<"\t"<<"Waiting Time"<<"\t"<<"Completion Time\n";
	for(int i=0;i<size;i++)
	{
		AvgTurnaround+=turnaround[i];
		AvgWaiting+=waiting[i];
		std::cout<<i+1<<"\t\t"<<arrival[i]<<"\t\t"<<burst[i]<<"\t\t"<<turnaround[i]<<"\t\t"<<waiting[i]<<"\t\t"<<completionTime[i]<<"\n";
	}
	std::cout<<"Average Turnaround time = "<<AvgTurnaround/size<<std::endl;
	std::cout<<"Average Waiting Time = "<<AvgWaiting/size;
}
