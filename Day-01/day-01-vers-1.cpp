#include<iostream>
using namespace std;
int main(){
	int n,count0=0,count1=0;
	cout<<"Enter no. of elements:";
	cin>>n;
	int arr[n];
	for(int i=0;i<n;i++)
	{
	    cin>>arr[i];
	}
	for(int i=0;i<n;i++)
	{
	    if(arr[i]==0)
	    {
	        count0++;
	    }
	    else if(arr[i]==1)
	    {
	        count1++;
	    }
	}
	for(int i=0;i<n;i++)
	{
		arr[i]=2;
	}	
   	for(int i=0;i<count1+count0;i++)
    	{
        	arr[i]=1;
    	}
    	for(int i=0;i<count0;i++)
    	{
        	arr[i]=0;
    	}
    	for(int i=0;i<n;i++)
    	{
        	cout<<arr[i]<<"\t";
    	}
}
