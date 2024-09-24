#include <iostream>
#include <numeric>
using namespace std;
long long f1(long long N, long long M) 
{
    return (N*M)/gcd(N, M);
}
int main() 
{
    long long N, M;
    cin>>N>>M;
    cout<<f1(N, M)<<endl;
    return 0;
}
