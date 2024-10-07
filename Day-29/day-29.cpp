#include <iostream>
#include <vector>
using namespace std;
long long fibonacci(int n) 
{
    if (n==0) return 0;
    if (n==1) return 1;
    vector<long long> fib(n+1);
    fib[0]=0; 
    fib[1]=1; 
    for(int i=2;i<=n;++i) 
    {
        fib[i]=fib[i-1]+fib[i-2];
    }
    return fib[n]; 
}
int main() 
{
    int n;
    cout<<"Enter number of elements: ";
    cin>>n;
    long long result=fibonacci(n);   
    cout<<"Fibonacci Number is:"<<result<<endl;
    return 0;
}