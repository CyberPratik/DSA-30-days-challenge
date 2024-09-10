#include<iostream>
using namespace std;
int main(){
	int n;
	int expected_sum=0, actual_sum=0;
	cout<<"Enter number of elements:";
	cin>>n;
	int arr[n];
	for(int i=0;i<n;i++)
	{
		cin>>arr[i];
	}
	expected_sum=((n+1)*(n+2))/2;
	for(int i=0;i<n;i++)
	{
		actual_sum=actual_sum+arr[i];
	}
	cout<<"Missing Number:"<<expected_sum-actual_sum;
}