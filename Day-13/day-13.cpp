#include <iostream>
using namespace std;
bool check(const string &s, int start, int end) 
{
    while (start < end) 
    {
        if(s[start] != s[end])
            return false;
        start++;
        end--;
    }
    return true;
}
string lPalindrome(string s) 
{
    int n=s.length();
    string longest="";
    for (int i=0;i<n;i++) 
    {
        for (int j=i;j<n;j++) 
        {
            if (check(s, i, j) && (j - i + 1)>longest.length()) 
            {
                longest = s.substr(i, j - i + 1);
            }
        }
    }
    return longest;
}
int main() 
{
    string s;
    cout<<"Enter a string: ";
    cin>>s;
    cout<<"Longest Palindromic Substring: "<<lPalindrome(s)<<endl;
    return 0;
}
