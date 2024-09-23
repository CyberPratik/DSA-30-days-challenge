#include <iostream>
#include <unordered_map>
using namespace std;
int sort(string s) 
{
    unordered_map<char, int> a1;
    int maxi=0, start=0;
    for (int i=0;i<s.size();i++) 
	{
        if (a1.find(s[i])!=a1.end()) 
		{
            start=max(start, a1[s[i]]+1);
        }
        a1[s[i]]=i;
        maxi=max(maxi,i-start+1);
    }
    return maxi;
}
int main() 
{
    string s;
    cout<<"Enter your string:";
	cin>>s;
    cout<<sort(s)<<endl;
    return 0;
}
