#include <iostream>
#include <vector>
#include <string>
using namespace std;
string str(vector<string>& strs) {
    if (strs.empty()) 
        return "";
    string prefix = strs[0];
    for(int i=1;i<strs.size();i++)
    {
        while(strs[i].find(prefix)!=0) 
        {
            prefix=prefix.substr(0,prefix.size()-1);
            if (prefix.empty()) 
                return "";
        }
    }
    return prefix;
}
int main() {
    int n;
    cout<<"Enter the number of strings: ";
    cin>>n;
    vector<string> str1(n);
    cout<<"Enter the strings:\n";
    for(int i=0;i<n;i++) 
    {
        cin>>str1[i];
    }
    string result=str(str1);
    if(result.empty())
    {
        cout<<"No common prefix found.\n";
    }
    else
    {
        cout<<"Longest common prefix: "<<result<<endl;
    }
    return 0;
}
