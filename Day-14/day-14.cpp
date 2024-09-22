#include <iostream>
#include <unordered_map>
using namespace std;
int f1(string &s, int k) {
    int n=s.length();
    unordered_map<char, int> arr;
    int left=0, right=0;
    int count=0;
    while (right<n) 
	{
        arr[s[right]]++;
        while (arr.size()>k) 
		{
            arr[s[left]]--;
            if (arr[s[left]]==0) 
			{
                arr.erase(s[left]);
            }
            left++;
        }
        count+=(right-left+1);
        right++;
    }
    return count;
}
int f2(string s, int k) 
{
    return f1(s, k)-f1(s, k - 1);
}
int main() 
{
    string s;
    int k;
    cout<<"Enter string: ";
    cin>>s;
    cout<<"Enter value of k: ";
    cin>>k;
    int result=f2(s, k);
    cout<<"Result: "<<result<<endl;
    return 0;
}
