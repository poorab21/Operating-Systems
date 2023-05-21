#include<iostream>
#include<stdlib.h>
bool Exists(int num,int *arr,int size)
{
	for(int i=0;i<size;i++)
	{
		if(num==arr[i]) return true;
	}
	return false;
}
int main()
{
	std::string page_reference_string;
	int frame_size,*arr,j=0,page_faults=0;
	std::cout<<"Enter Page Reference String:";
	std::cin>>page_reference_string;
	std::cout<<"Enter frame size:";
	std::cin>>frame_size;
	arr=new int[frame_size];
	for(int i=0;i<frame_size;i++)
	{
		arr[i]=-1;
	}
	std::cout<<"Page-Reference | Frames"<<std::endl;
	for(int i=0;i<page_reference_string.length();i++)
	{
		if(!Exists((page_reference_string[i]-48),arr,frame_size))
		{
			arr[j]=page_reference_string[i]-48;
			j=((j+1)%frame_size);
			std::cout<<page_reference_string[i]<<"\t\t";
			for(int k=0;k<frame_size;k++)
			{
				std::cout<<arr[k]<<" ";
			}
			std::cout<<std::endl;
			page_faults++;
		}
	}
	std::cout<<"Total Page faults = "<<page_faults<<std::endl;
}
