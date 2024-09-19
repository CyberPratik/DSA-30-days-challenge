#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;
vector<string> f1(string s) 
{
    sort(s.begin(), s.end());
    set<string> result;
    result.insert(s);
    while(next_permutation(s.begin(), s.end())) 
    {
        result.insert(s);
    }
    return vector<string>(result.begin(), result.end());
}
int main() 
{
    string s;
    cout<<"Enter your string:";
    cin>>s;
    vector<string> permutations=f1(s);
    for (const string &perm : permutations) 
    {
        cout<<perm<<" ";
    }
    cout<<endl;
    return 0;
}