#include<iostream>
bool InMemory(int *arr,int size,int page)
{
	for(int i=0;i<size;i++)
	{
		if(page==arr[i]) return true;
	}
	return false;
}
bool IsEmpty(int *arr,int size)
{
	for(int i=0;i<size;i++)
	{
		if(arr[i]==-1) return true;
	}
	return false;
}
int main()
{
	int *arr,frame_size,miss=0,count=0,hit=0,counter=0;
	bool *furthest;
	std::string page_reference_string;
	std::cout<<"Enter Page Reference String:";
	std::cin>>page_reference_string;
	std::cout<<"Enter Frame Size:";
	std::cin>>frame_size;
	arr=new int[frame_size];
	furthest=new bool[frame_size];
	for(int i=0;i<frame_size;i++)
	{
		furthest[i]=false;
		arr[i]=-1;
	}
	std::cout<<"Page | Frames"<<std::endl;
	for(int i=0;i<page_reference_string.length();i++)
	{
		if(InMemory(arr,frame_size,page_reference_string[i]-48))
		{
			hit++;
		}
		else if(!InMemory(arr,frame_size,page_reference_string[i]-48))
		{
			if(IsEmpty(arr,frame_size))
			{
				arr[count]=page_reference_string[i]-48;
				count=(count+1)%frame_size;
				miss++;
			}
			else
			{
				for(int j=i+1;j<page_reference_string.length();j++)
				{
					for(int k=0;k<frame_size;k++)
					{
						if(arr[k]==page_reference_string[j]-48 && furthest[k]==false)
						{
							furthest[k]=true;
							counter++;
						}
						if(counter==frame_size-1) break;
					}
					if(counter==frame_size-1) break;
				}
				for(int j=0;j<frame_size;j++)
				{
					if(furthest[j]==false)
					{
						arr[j]=page_reference_string[i]-48;
						miss++;
						break;
					}
				}
			}
			for(int j=0;j<frame_size;j++) furthest[j]=false;
			counter=0;
		}
		std::cout<<page_reference_string[i]<<"\t";
		for(int i=0;i<frame_size;i++)
		{
			std::cout<<arr[i]<<" ";
		}
		std::cout<<std::endl;
	}
	std::cout<<"Hits = "<<hit<<std::endl;
	std::cout<<"Misses = "<<miss<<std::endl;
	delete[] arr;
}
