#include<iostream>
#include<queue>
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
int main()
{
	std::queue<int> q2,q3;
	q2.push(-1),q3.push(-1);
	int processes[10][10],size,sub[10],time=0,counter=0,counter2=0;
	int quantum1=8,quantum2=12;
	bool Queue1[10];
	float AvgTurnaround=0,AvgWaiting=0;;
	std::cout<<"Enter Number of Processes:";
	std::cin>>size;
	if(size==0) return 0;
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
