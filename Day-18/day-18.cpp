#include <iostream>
using namespace std;
int def(int N)
{
    int count=0;
    for(int i=1;i<=n;i++) 
    {
        if(n%i==0) 
        {
            count++;
        }
    }
    return count;
}
int main() 
{
    int n;
    cin>>n;
    cout<<def(n)<<endl;
    return 0;
}
