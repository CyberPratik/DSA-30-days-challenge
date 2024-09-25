#include <iostream>
#include <vector>
using namespace std;
vector<int> arr(int N) 
{
    vector<int> f1;
    for (int i=2;i*i<=N;i++) 
    {
        if (N%i==0) 
        {
            f1.push_back(i);
            vector<int> subFactors=arr(N/i);
            f1.insert(f1.end(), subFactors.begin(), subFactors.end());
            return f1;
        }
    }
    f1.push_back(N);
    return f1;
}
int main() 
{
    int N;
    cout<<"Enter a number for prime factorization: ";
    cin>>N;
    vector<int> f1=arr(N);
    cout<<"Prime factors of "<<N<< " are: ";
    for (int factor:f1) 
    {
        cout<<factor<<" ";
    }
    return 0;
}
