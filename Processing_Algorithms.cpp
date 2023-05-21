#include<iostream>
#include<queue>
float RR(int i,int processes[][100],int time)
{
	float y=float(processes[i][1]);
	float z=float(processes[i][2]);
	float x=(((time-y)+z)/z);
	return x;
}
bool All_Complete(bool *Complete,int size)
{
	for(int i=0;i<size;i++)
	{
		if(Complete[i]==true && i==size-1)
		{
			return true;
		}
		else if(Complete[i]==false) return false; 
	}
}
void HRRN()
{
	int processes[100][100],size,time=0,position=-1;
	float ResponseTime=-9999,AvgTurnaround=0,AvgWaiting=0;
	bool Complete[100];
	std::cout<<"Enter Number of Processes:";
	std::cin>>size;
	for(int i=0;i<size;i++)
	{
		processes[i][0]=i+1;
		std::cout<<"Enter Arrival Time:";
		std::cin>>processes[i][1];
		std::cout<<"Enter Burst Time:";
		std::cin>>processes[i][2];
		Complete[i]=false;
	}
	int i=0;
	while(!All_Complete(Complete,size))
	{
		ResponseTime=-9999;
		position=-1;
		for(int i=0;i<size;i++)
		{
			if(processes[i][1]<=time && Complete[i]==false && ResponseTime<RR(i,processes,time))
			{
				ResponseTime=RR(i,processes,time);
				position=i;
			}
			else if(ResponseTime==RR(i,processes,time) && processes[i][1]<=time && Complete[i]==false)
			{
				if(processes[position][1]>processes[i][1])
				{
					ResponseTime=RR(i,processes,time);
					position=i;
				}
				else if(processes[position][1]==processes[i][1])
				{
					if(processes[position][0]>processes[i][0])
					{
						ResponseTime=RR(i,processes,time);
						position=i;
					}
				}
			}
		}
		if(position==-1)
		{
			time++;
		}
		else
		{
			time+=processes[position][2];
			Complete[position]=true;
			processes[position][3]=time;
			processes[position][4]=processes[position][3]-processes[position][1];
			processes[position][5]=processes[position][4]-processes[position][2];
			if(processes[position][5]<0)
			{
				processes[position][5]=0;
			}
		}
	}
	std::cout<<"Process ID"<<"\t"<<"Arrival Time"<<"\t"<<"Burst Time"<<"\t"<<"Turnaround Time"<<"\t"<<"Waiting Time"<<"\t"<<"Completion Time\n";
	for(int i=0;i<size;i++)
	{
		AvgTurnaround+=processes[i][4];
		AvgWaiting+=processes[i][5];
		std::cout<<processes[i][0]<<"\t\t"<<processes[i][1]<<"\t\t"<<processes[i][2]<<"\t\t"<<processes[i][4]<<"\t\t"<<processes[i][5]<<"\t\t"<<processes[i][3]<<"\n";
	}
	std::cout<<"Average Turnaround time = "<<AvgTurnaround/size<<std::endl;
	std::cout<<"Average Waiting Time = "<<AvgWaiting/size;
}
void LJF()
{
	int processes[100][100],size,largest=-1,position=-1,sub[100],time=0,breaker=0;
	float AvgTurnaround=0,AvgWaiting=0;
	bool Complete[100];
	std::cout<<"Enter Number of Processes:";
	std::cin>>size;
	if(size==0) return;
	for(int i=0;i<size;i++)
	{
		processes[i][0]=i+1;
		std::cout<<"Enter Arrival Time:";
		std::cin>>processes[i][1];
		std::cout<<"Enter Burst Time:";
		std::cin>>processes[i][2];
		sub[i]=processes[i][2];
	}
	while(1)
	{
		int largest=-1;
		position=-1;
		for(int i=0;i<size;i++)
		{
			if(processes[i][1] <= time && sub[i] != -1 && largest<processes[i][2])
			{
				largest=processes[i][2];
				position=i;
			}
			else if(processes[i][2]==processes[position][2] && processes[position][1]<=time && processes[i][1]<=time && sub[i] != -1 && sub[position] != -1)
			{
				if(processes[i][1]<processes[position][1])
				{
					largest=processes[i][2];
					position=i;
				}
				else if(processes[i][1]==processes[position][1])
				{
					if(processes[i][0]<processes[position][0])
					{
						largest=processes[i][2];
						position=i;
					}
				}
			}
		}
		if(position==-1)
		{
			time++;
		}
		else
		{
			time+=processes[position][2];
			processes[position][3]=time;
			processes[position][4]=processes[position][3]-processes[position][1];
			processes[position][5]=processes[position][4]-processes[position][2];
			if(processes[position][5]<0)
			{
				processes[position][5]=0;
			}
			Complete[position]=true;
			std::cout<<processes[position][0]<<"->"<<processes[position][2]<<"->"<<time<<"\n";
			sub[position]=-1;
		}
		for(int i=0;i<size;i++)
		{
			if(Complete[i]==true && i==size-1)
			{
				breaker=1;
			}
			else if(Complete[i]==false) break;
		}
		if(breaker==1) break;
	}
	std::cout<<"Process ID"<<"\t"<<"Arrival Time"<<"\t"<<"Burst Time"<<"\t"<<"Turnaround Time"<<"\t"<<"Waiting Time"<<"\t"<<"Completion Time\n";
	for(int i=0;i<size;i++)
	{
		AvgTurnaround+=processes[i][4];
		AvgWaiting+=processes[i][5];
		std::cout<<processes[i][0]<<"\t\t"<<processes[i][1]<<"\t\t"<<processes[i][2]<<"\t\t"<<processes[i][4]<<"\t\t"<<processes[i][5]<<"\t\t\t"<<processes[i][3]<<"\n";
	}
	std::cout<<"Average Turnaround time = "<<AvgTurnaround/size<<std::endl;
	std::cout<<"Average Waiting Time = "<<AvgWaiting/size;
}
void LRTF()
{
	int processes[100][100],size,sub[100],position,time=0,breaker=0;
	float AvgTurnaround=0,AvgWaiting=0;
	std::cout<<"Enter Number of Processes:";
	std::cin>>size;
	if(size==0) return;
	for(int i=0;i<size;i++)
	{
		processes[i][0]=i+1;
		std::cout<<"Enter Arrival Time:";
		std::cin>>processes[i][1];
		std::cout<<"Enter Burst Time:";
		std::cin>>processes[i][2];
		sub[i]=processes[i][2];
	}
	while(1)
	{
		int largest=-1;
		position=-1;
		for(int i=0;i<size;i++)
		{
			if(processes[i][1]<=time && sub[i]>0 && sub[i]>largest)
			{
				largest=sub[i];
				position=i;
			}
			else if(sub[i]==largest && processes[i][1]<=time)
			{
				if(processes[position][1]>processes[i][1])
				{
					largest=sub[i];
					position=i;
				}
				else if(processes[position][1]==processes[i][1])
				{
					if(processes[position][0]>processes[i][0])
					{
						largest=sub[i];
						position=i;
					}
				}
			}
		}
		if(position==-1)
		{
			time++;
		}
		else
		{
			time+=1;
			sub[position]-=1;
			if(sub[position]==0)
			{
				processes[position][3]=time;
				processes[position][4]=processes[position][3]-processes[position][1];
				processes[position][5]=processes[position][4]-processes[position][2];
				if(processes[position][5]<0)
				{
					processes[position][5]=0;
				}
			}
		}
		for(int i=0;i<size;i++)
		{
			if(sub[i]==0 && i==size-1)
			{
				breaker=1;
			}
			else if(sub[i]>0)
			{
				break;
			}
		}
		if(breaker==1) break;
	}
	std::cout<<"Process ID"<<"\t"<<"Arrival Time"<<"\t"<<"Burst Time"<<"\t"<<"Turnaround Time"<<"\t"<<"Waiting Time"<<"\t"<<"Completion Time\n";
	for(int i=0;i<size;i++)
	{
		AvgTurnaround+=processes[i][4];
		AvgWaiting+=processes[i][5];
		std::cout<<processes[i][0]<<"\t\t"<<processes[i][1]<<"\t\t"<<processes[i][2]<<"\t\t"<<processes[i][4]<<"\t\t"<<processes[i][5]<<"\t\t"<<processes[i][3]<<"\n";
	}
	std::cout<<"Average Turnaround time = "<<AvgTurnaround/size<<std::endl;
	std::cout<<"Average Waiting Time = "<<AvgWaiting/size;
}
bool Queue1_Completed(bool *Queue1,int size)
{
	for(int i=0;i<size;i++)
	{
		if(Queue1[i]==true && i==size-1) return true;
		else if(Queue1[i]==false) return false;
	}
}
int LargestArrival(int processes[][10],int size)
{
	int n=0;
	for(int i=0;i<size;i++)
	{
		if(n<processes[i][1])
		{
			n=processes[i][1];
		}
	}
	return n+1;
}
void MLFQ()
{
	std::queue<int> q2,q3;
	q2.push(-1),q3.push(-1);
	int processes[10][10],size,sub[10],time=0,counter=0,counter2=0;
	int quantum1=8,quantum2=12;
	bool Queue1[10];
	float AvgTurnaround=0,AvgWaiting=0;;
	std::cout<<"Enter Number of Processes:";
	std::cin>>size;
	if(size==0) return;
	for(int i=0;i<size;i++)
	{
		processes[i][0]=i;
		std::cout<<"Enter Arrival time:";
		std::cin>>processes[i][1];
		std::cout<<"Enter Burst Time:";
		std::cin>>processes[i][2];
		Queue1[i]=false;
		sub[i]=processes[i][2];
	}
	while(1)
	{
		int position=-1,AT=LargestArrival(processes,size);
		for(int i=0;i<size;i++)
		{
			if(processes[i][1]<=time && Queue1[i]==false && AT>processes[i][1])
			{
				AT=processes[i][1];
				position=i;
			}
			else if(processes[i][1]<=time && Queue1[i]==false && AT==processes[i][1])
			{
				if(processes[i][0]<processes[position][0])
				{
					position=i;
				}
			}
		}
		if(position != -1)
		{
			if(sub[position]<=quantum1)
			{
				time+=sub[position];
				sub[position]=0;
				Queue1[position]=true;
				processes[position][3]=time;
				processes[position][4]=processes[position][3]-processes[position][1];
				processes[position][5]=processes[position][4]-processes[position][2];
			}
			else if(sub[position]>quantum1)
			{
				time+=quantum1;
				sub[position]-=quantum1;
				q2.push(processes[position][0]);
				Queue1[position]=true;
				if(counter==0)
				{
					q2.pop();
					counter=1;
				}
			}
		}
		else if(position==-1)
		{
			if(!q2.empty())
			{
				int n=q2.front();
				position=n;
				if(sub[n]<=quantum2)
				{
					time+=sub[n];
					sub[n]=0;
					processes[n][3]=time;
					processes[n][4]=processes[n][3]-processes[n][1];
					processes[n][5]=processes[n][4]-processes[n][2];
					if(processes[n][5]<0)
					{
						processes[n][5]=0;
					}
				}
				else if(sub[n]>quantum2)
				{
					time+=quantum2;
					sub[n]-=quantum2;
					q3.push(q2.front());
					if(counter2==0)
					{
						q3.pop();
						counter2=1;
					}
				}
				q2.pop();
			}
			else if(!q3.empty())
			{
				int n=q3.front();
				position=n;
				time+=sub[n];
				processes[n][3]=time;
				processes[n][4]=processes[n][3]-processes[n][1];
				processes[n][5]=processes[n][4]-processes[n][2];
				q3.pop();
			}
			else
			{
				time++;
			}
		}
		if(Queue1_Completed(Queue1,size) && q2.empty() && q3.empty()) break;
		else if(Queue1_Completed(Queue1,size) && q2.front()==-1 && q3.front()==-1) break;
	}
	std::cout<<"Process ID"<<"\t"<<"Arrival Time"<<"\t"<<"Burst Time"<<"\t"<<"Completion Time"<<"\t"<<"Turnaround Time"<<"\t"<<"Waiting Time\n";
	for(int i=0;i<size;i++)
	{
		AvgTurnaround+=processes[i][4];
		AvgWaiting+=processes[i][5];
		std::cout<<processes[i][0]+1<<"\t\t"<<processes[i][1]<<"\t\t"<<processes[i][2]<<"\t\t"<<processes[i][3]<<"\t\t"<<processes[i][4]<<"\t\t"<<processes[i][5]<<"\n";
	}
	std::cout<<"Average Turnaround Time = "<<AvgTurnaround/size<<"\n";
	std::cout<<"Average Waiting Time = "<<AvgWaiting/size;
}
bool All_Completed(bool *Complete,int size)
{
	for(int i=0;i<size;i++)
	{
		if(Complete[i]==true && i==size-1) return true;
		else if(Complete[i]==false) return false;
	}
}
void MLQ()
{
	int processes[100][100],size,sub[100],queue=0,position=-1,time=0;
	bool Complete[100];
	float AvgTurnaround=0,AvgWaiting=0;
	std::cout<<"\t\t|Queue 1 Processing Schedule = FCFS|"<<std::endl;
	std::cout<<"\t\t|Queue 2 Processing Schedule = SJF |"<<std::endl;
	std::cout<<"\t\t|__________________________________|"<<std::endl;
	std::cout<<"Enter Number of Processes:";
	std::cin>>size;
	if(size==0) return;
	for(int i=0;i<size;i++)
	{
		processes[i][0]=i+1;
		std::cout<<"Enter Arrival Time:";
		std::cin>>processes[i][1];
		std::cout<<"Enter Burst Time:";
		std::cin>>processes[i][2];
		std::cout<<"Enter Queue Number:";
		std::cin>>processes[i][3];
		sub[i]=processes[i][2];
		Complete[i]=false;
	}
	while(!All_Completed(Complete,size))
	{
		queue=3,position=-1;
		for(int i=0;i<size;i++)
		{
			if(processes[i][1]<=time && Complete[i]==false && processes[i][3]<queue)
			{
				queue=processes[i][3];
				position=i;
			}
			else if(processes[i][1]<=time && Complete[i]==false && processes[i][3]==queue)
			{
				if(queue==1)
				{
					if(processes[i][1]<processes[position][1])
					{
						position=i;
					}
					else if(processes[i][1]==processes[position][1])
					{
						if(processes[i][0]<processes[position][0])
						{
							position=i;
						}
					}
				}
				else if(queue==2)
				{
					if(sub[i]<sub[position])
					{
						position=i;
					}
					else if(sub[i]==sub[position])
					{
						if(processes[i][1]<processes[position][1])
						{
							position=i;
						}
						else if(processes[i][1]==processes[position][1])
						{
							if(processes[i][0]<processes[position][0])
							{
								position=i;
							}
						}
					}
				}
			}
		}
		if(position==-1) 
		{
			time++;
		}
		else
		{
			time++;
			sub[position]-=1;
			std::cout<<processes[position][0]<<"->"<<processes[position][1]<<"->"<<processes[position][2]<<"->"<<time<<"\n";
			if(sub[position]==0)
			{
				Complete[position]=true;
				processes[position][4]=time;
				processes[position][5]=processes[position][4]-processes[position][1];
				processes[position][6]=processes[position][5]-processes[position][2];
				if(processes[position][6]<0)
				{
					processes[position][6]=0;
				}
			}
		}
	}
	std::cout<<"Process ID"<<"\t"<<"Arrival Time"<<"\t"<<"Burst Time"<<"\t"<<"Completion Time"<<"\t"<<"Turnaround Time"<<"\t"<<"Waiting Time\n";
	for(int i=0;i<size;i++)
	{
		AvgTurnaround+=processes[i][5];
		AvgWaiting+=processes[i][6];
		std::cout<<processes[i][0]<<"\t\t"<<processes[i][1]<<"\t\t"<<processes[i][2]<<"\t\t"<<processes[i][4]<<"\t\t"<<processes[i][5]<<"\t\t"<<processes[i][6]<<"\n";
	}
	std::cout<<"Average Turnaround Time = "<<AvgTurnaround/size<<"\n";
	std::cout<<"Average Waiting Time = "<<AvgWaiting/size;
}
int LargestPriority(int processes[][100],int size)
{
	int j=0;
	for(int i=0;i<size;i++)
	{
		if(processes[i][3]>j)
		{
			j=processes[i][3];
		}
	}
	return j+1;
}
void Priority()
{
	int processes[100][100],size,count=0,largest_priority,position=0;
	float AvgTurnaround=0,AvgWaiting=0;
	int time=0,burst[100],smallest;
	std::cout<<"Enter Number of Processes:";
	std::cin>>size;
	for(int i=0;i<size;i++)
	{
		processes[i][0]=i+1;
		std::cout<<"Enter Arrival Time:";
		std::cin>>processes[i][1];
		std::cout<<"Enter Burst Time:";
		std::cin>>processes[i][2];
		std::cout<<"Enter Priority:";
		std::cin>>processes[i][3];
		burst[i]=processes[i][2];
	}
	smallest=processes[0][1];
	for(int i=1;i<size;i++)
	{
		if(smallest>processes[i][1])
		{
			smallest=processes[i][1];
		}
	}
	time=smallest;
	while(count != size)
	{
		int largest_priority=LargestPriority(processes,size);
		for(int i=0;i<size;i++)
		{
			if(processes[i][1]<=time && processes[i][2]>0 && processes[i][3]<largest_priority)
			{
				largest_priority=processes[i][3];
				position=i;
			}
		}
		time++;
		processes[position][2]--;
		if(processes[position][2]==0)
		{
			processes[position][4]=time;
			processes[position][5]=processes[position][4]-processes[position][1];
			processes[position][6]=processes[position][5]-burst[position];
			if(processes[position][6]<0)
			{
				processes[position][6]=0;
			}
			count++;
		}
	}
	std::cout<<"Process ID"<<"\t"<<"Arrival Time"<<"\t"<<"Burst Time"<<"\t"<<"Priority"<<"\t"<<"Completion Time"<<"\t"<<"Turnaround Time"<<"\t"<<"Waiting Time\n";
	for(int i=0;i<size;i++)
	{
		AvgTurnaround+=processes[i][5];
		AvgWaiting+=processes[i][6];
		std::cout<<processes[i][0]<<"\t\t"<<processes[i][1]<<"\t\t"<<burst[i]<<"\t\t"<<processes[i][3]<<"\t\t"<<processes[i][4]<<"\t\t"<<processes[i][5]<<"\t\t"<<processes[i][6]<<"\n";
	}
	std::cout<<"Average Turnaround Time = "<<AvgTurnaround<<std::endl;
	std::cout<<"Average Waiting Time = "<<AvgWaiting<<std::endl;
}
int Largest_Burst(int processes[][100],int size)
{
	int j=0;
	for(int i=0;i<size;i++)
	{
		if(j<processes[i][2])
		{
			j=processes[i][2];
		}
	}
	return j+1;
}
void SRTF()
{
	int processes[100][100],size,position=-1,sub[100],largest,time=0;
	bool Complete[100];
	float AvgTurnaround=0,AvgWaiting=0;
	std::cout<<"Enter Number of Processes:";
	std::cin>>size;
	if(size==0) return;
	for(int i=0;i<size;i++)
	{
		processes[i][0]=i+1;
		std::cout<<"Enter Arrival Time:";
		std::cin>>processes[i][1];
		std::cout<<"Enter Burst Time:";
		std::cin>>processes[i][2];
		Complete[i]=false;
		sub[i]=processes[i][2];
	}
	int n=Largest_Burst(processes,size);
	while(!All_Completed(Complete,size))
	{
		position=-1,largest=n;
		for(int i=0;i<size;i++)
		{
			if(processes[i][1]<=time && Complete[i]==false && sub[i]<largest)
			{
				largest=sub[i];
				position=i;
			}
			else if(processes[i][1]<=time && Complete[i]==false && sub[i]==largest)
			{
				if(processes[i][1]<processes[position][1])
				{
					largest=sub[i];
					position=i;
				}
				else if(processes[i][1]==processes[position][1])
				{
					if(processes[i][0]<processes[position][0])
					{
						largest=sub[i];
						position=i;
					}
				}
			}
		}
		if(position==-1)
		{
			time++;
		}
		else
		{
			time++;
			sub[position]-=1;
			if(sub[position]==0)
			{
				Complete[position]=true;
				processes[position][3]=time;
				processes[position][4]=processes[position][3]-processes[position][1];
				processes[position][5]=processes[position][4]-processes[position][2];
				if(processes[position][5]<0)
				{
					processes[position][5]=0;
				}
			}
		}
	}
	std::cout<<"Process ID"<<"\t"<<"Arrival Time"<<"\t"<<"Burst Time"<<"\t"<<"Turnaround Time"<<"\t"<<"Waiting Time"<<"\t"<<"Completion Time\n";
	for(int i=0;i<size;i++)
	{
		AvgTurnaround+=processes[i][4];
		AvgWaiting+=processes[i][5];
		std::cout<<processes[i][0]<<"\t\t"<<processes[i][1]<<"\t\t"<<processes[i][2]<<"\t\t"<<processes[i][4]<<"\t\t"<<processes[i][5]<<"\t\t"<<processes[i][3]<<"\n";
	}
	std::cout<<"Average Turnaround time = "<<AvgTurnaround/size<<std::endl;
	std::cout<<"Average Waiting Time = "<<AvgWaiting/size;
}
