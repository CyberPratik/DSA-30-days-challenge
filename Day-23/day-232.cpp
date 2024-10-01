#include <iostream>
#include <vector>
#include <queue>
using namespace std;
vector<int> arr(vector<int>& arr, int k) 
{
    priority_queue<pair<int, int>> maxHeap;
    vector<int> result;
    for(int i=0;i<k;i++) 
    {
        maxHeap.push({arr[i],i});
    }
    result.push_back(maxHeap.top().first);
    for(int i=k;i<arr.size();i++) 
    {
        maxHeap.push({arr[i], i});
        while(maxHeap.top().second<=i-k) 
        {
            maxHeap.pop();
        }
        result.push_back(maxHeap.top().first);
    }

    return result;
}
int main() 
{
    int n, k;
    cout<<"Enter the size of the array: ";
    cin>>n;
    vector<int> arr(n);
    cout<<"Enter the elements of the array: ";
    for(int i=0;i<n;i++) 
    {
        cin>>arr[i];
    }
    cout<<"Enter the window size (k): ";
    cin>>k;
    vector<int> result=arr(arr, k);
    cout<<"Sliding window maximums: ";
    for(int num:result) 
    {
        cout<<num<<" ";
    }
    cout<<endl;
    return 0;
}
