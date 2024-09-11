#include <iostream>
using namespace std;
int dup_num(int *arr)
{
    int one_step=arr[0];
    int two_step=arr[0];
    do{
        one_step=arr[one_step];
        two_step=arr[arr[two_step]];   
    }while(one_step!=two_step);
    one_step=arr[0];
    while(one_step!=two_step) {
        one_step=arr[one_step]; 
        two_step=arr[two_step];         
    }
    return two_step; 
}
int main()
{
    int n;
    cout<<"Enter number of elements in array: ";
    cin>>n;
    int arr[n];
    cout<<"Enter elements with one duplicate: ";
    for(int i=0;i<n;i++)
	{
        cin>>arr[i];
    }
    int num=dup_num(arr);
    cout<<"Duplicate number: "<<num<<endl;
    return 0;
}
