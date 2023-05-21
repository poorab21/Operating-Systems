#include<iostream>
#include<math.h>
struct list{
	int ProcessNumber=0;
	int Arrival_Time=0;
	int burst_Time=0;
	int Turnaround_Time=0;
	int Completion_Time=0;
	int Waiting_Time=0;
	int priority=0;
	list *next=NULL;
	bool completed=false;
	int sub;
	bool In_Process=false;
	int dormant_time=0;
	bool repeat=false;
}*start=NULL,*last=NULL;
int n=0;
int Total_Processes()
{
	list *temp=start;
	int count=0;
	while(temp != NULL)
	{
		count++;
		temp=temp->next;
	}
	return count;
}
void Input(list *l)
{
	n++;
	l->ProcessNumber=n;
	std::cout<<"Enter Arrival Time:";
	std::cin>>l->Arrival_Time;
	std::cout<<"Enter Burst Time:";
	std::cin>>l->burst_Time;
	std::cout<<"Enter Priority:";
	std::cin>>l->priority;
	l->sub=l->burst_Time;
}
void Delete(list *l)
{
	std::cout<<"Process Deleted"<<std::endl;
	std::cout<<"Process ID = "<<l->ProcessNumber<<std::endl;
	std::cout<<"Arrival Time = "<<l->Arrival_Time<<std::endl;
	std::cout<<"Burst Time = "<<l->burst_Time<<std::endl;
	std::cout<<"Priority = "<<l->priority<<std::endl;
	std::cout<<"Completion Time = "<<l->Completion_Time<<std::endl;
	std::cout<<"Turnaround Time = "<<l->Turnaround_Time<<std::endl;
	std::cout<<"Waiting Time = "<<l->Waiting_Time<<std::endl;
	if(l==start && l != last)
	{
		start=start->next;
		l->next=NULL;
		delete l;
	}
	else if(l==last && last==start)
	{
		start=NULL;
		last=NULL;
	}
	else if(l==last && last != start)
	{
		list *temp=start;
		while(temp->next != last)
		{
			temp=temp->next;
		}
		list *temp2=last;
		last=temp;
		temp->next=NULL;
		delete temp2;
	}
	else
	{
		list *temp=start;
		while(temp->next != l)
		{
			temp=temp->next;
		}
		temp->next=l->next;
		l->next=NULL;
		delete l;
	}
}
void Table()
{
	std::cout<<"Process ID"<<"\t"<<"Arrival Time"<<"\t"<<"Burst Time"<<"\t"<<"Priority"<<"\t"<<"Completion Time"<<"\t"<<"Turnaround Time"<<"\t"<<"Waiting Time\n";
	for(list *z=start;z != NULL;z=z->next)
	{
		std::cout<<z->ProcessNumber<<"\t\t"<<z->Arrival_Time<<"\t\t"<<z->burst_Time<<"\t\t"<<z->priority<<"\t\t"<<z->Completion_Time<<"\t\t"<<z->Turnaround_Time<<"\t\t"<<z->Waiting_Time<<std::endl;
	}
}
list* Previous(list *l)
{
	list *temp=start;
	while(temp->next != l)
	{
		temp=temp->next;
	}
	return temp;
}
void Discard(list *l)
{
	list *temp=start;
	if(l==start)
	{
		start=start->next;
		l->next=NULL;
	}
	else
	{
		list *x=Previous(l);
		if(l==last)
		{
			x->next=NULL;
			last=x;
		}
		else
		{
			x->next=l->next;
			l->next=NULL;
		}
	}
}
int Priority()
{
	int i=0;
	for(list *l=start;l != NULL;l=l->next)
	{
		if(l->priority>i)
		{
			i=l->priority;
		}
	}
	return i+1;
}
void Display(list *z)
{
	std::cout<<"Process ID"<<"\t"<<"Arrival Time"<<"\t"<<"Burst Time"<<"\t"<<"Priority"<<"\t"<<"Completion Time"<<"\t"<<"Turnaround Time"<<"\t"<<"Waiting Time\n";
	std::cout<<z->ProcessNumber<<"\t\t"<<z->Arrival_Time<<"\t\t"<<z->burst_Time<<"\t\t"<<z->priority<<"\t\t"<<z->Completion_Time<<"\t\t"<<z->Turnaround_Time<<"\t\t"<<z->Waiting_Time<<std::endl;
}
void swap(int &x,int &y)
{
	int temp=x;
	x=y;
	y=temp;
}
void Priority_Insertion()
{
	list *l=new list;
	Input(l);
	if(start==NULL)
	{
		start=l;
		last=l;
	}
	else if(l->priority < start->priority)
	{
		l->next=start;
		start=l;
	}
	else if(l->priority >last->priority)
	{
		last->next=l;
		last=l;
	}
	else if(l->priority==start->priority && start->Arrival_Time>l->Arrival_Time)
	{
		l->next=start;
		start=l;
	}
	else if(l->priority==start->priority && start->Arrival_Time<l->Arrival_Time)
	{
		l->next=start->next;
		start->next=l;
	}
	else if(l->priority==last->priority && last->Arrival_Time<l->Arrival_Time)
	{
		last->next=l;
		last=l;
	}
	else
	{
		list *temp=start,*z=last;
		while(1)
		{
		if(z->priority > l->priority && z != start)
		{
			z=Previous(z);
		}
		else if(z->priority > l->priority && z==start)
		{
			l->next=start;
			start=l;
			break;
		}
		else if(z->priority < l->priority && z==last)
		{
			last->next=l;
			last=l;
			break;
		}
		else if(z->priority==l->priority)
		{
			if(z->Arrival_Time > l->Arrival_Time)
			{
				list *x=Previous(z);
				x->next=l;
				l->next=z;
				break;
			}
			else if(z->Arrival_Time < l->Arrival_Time)
			{
				l->next=z->next;
				z->next=l;
				break;
			}
		}
		else if(z->priority < l->priority)
		{
			l->next=z->next;
			z->next=l;
			break;
		}
		}
	}
}
void Aging(list *l)
{
	l->priority-=1;
	list *z=last;
	while(1)
	{
		if(z->priority > l->priority && z != start)
		{
			z=Previous(z);
		}
		else if(z->priority > l->priority && z==start)
		{
			l->next=start;
			start=l;
			break;
		}
		else if(z->priority < l->priority && z==last)
		{
			last->next=l;
			last=l;
			break;
		}
		else if(z->priority==l->priority)
		{
			if(z->Arrival_Time > l->Arrival_Time && z==start)
			{
				l->next=start;
				start=l;
			}
			else if(z->Arrival_Time > l->Arrival_Time)
			{
				list *x=Previous(z);
				x->next=l;
				l->next=z;
				break;
			}
			else if(z->Arrival_Time < l->Arrival_Time)
			{
				l->next=z->next;
				z->next=l;
				break;
			}
		}
		else if(z->priority < l->priority)
		{
			l->next=z->next;
			z->next=l;
			break;
		}
	}
}
int main()
{
	int size,time=0;
	list *temp=NULL;
	std::cout<<"Enter Initial Number of Processes:";
	std::cin>>size;
	for(int i=0;i<size;i++)
	{
		Priority_Insertion();
	}
	while(start != NULL && last != NULL)
	{
		int largest_Priority=Priority();
		for(list *l=start;l != NULL;l=l->next)
		{
			if(l->Arrival_Time<=time && l->sub>0 && l->priority<largest_Priority)
			{
				largest_Priority=l->priority;
				temp=l;
				l->In_Process=true;
			}
		}
		temp->sub--;
		time++;
		for(list *l=start;l != NULL;l=l->next)
		{
			if(l->Arrival_Time < time && l->In_Process==false)
			{
				l->dormant_time+=1;
			}
		}
		if(temp->sub==0)
		{
			temp->completed=true;
			temp->Completion_Time=time;
			temp->Turnaround_Time=(temp->Completion_Time)-(temp->Arrival_Time);
			temp->Waiting_Time=(temp->Turnaround_Time)-(temp->burst_Time);
			if(temp->Waiting_Time<0)
			{
				temp->Waiting_Time=0;
			}
			Table();
			Delete(temp);
			if(size%2==0 && Total_Processes()==(size/2) || size%2 != 0 && Total_Processes()==floor(size/2))
			{
				int n;
				std::cout<<"50% Processes have been Executed\n";
				std::cout<<"Enter Number of New Processes to insert:";
				std::cin>>n;
				size=n+Total_Processes();
				for(int i=0;i<n;i++)
				{
					Priority_Insertion();
				}
				Table();
			}
		}
		for(list *l=start;l != NULL;l=l->next)
		{
			for(list *z=start;z != NULL;z=z->next)
			{
				if(z->dormant_time==10)
				{
					z->dormant_time=0;
					Discard(z);
					Aging(z);
					break;
				}
			}
		}
	}
}
