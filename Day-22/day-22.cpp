#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;
int f1(const vector<int>& arr, int k) 
{
    unordered_map<int, int> arr;
    for(int num:arr) 
    {
        arr[num]++;
    }
    for(int num:arr) 
    {
        if(arr[num]==k) 
        {
            return num;
        }
    }
    return -1; 
}
int main() 
{
    int n, k;
    cout<<"Enter the size of the array: ";
    cin>>n;
    vector<int> arr(n);
    cout<<"Enter the elements of the array: ";
    for (int i=0;i<n;i++) 
    {
        cin>>arr[i];
    }
    cout<<"Enter the value of k: ";
    cin>>k;
    int result=f1(arr, k);
    if(result==-1) 
    {
        cout<<"No element appears exactly "<<k<<" times."<<endl;
    } 
    else 
    {
        cout<<"The first element to appear exactly "<<k<<" times is: "<<result<<endl;
    }

    return 0;
}
