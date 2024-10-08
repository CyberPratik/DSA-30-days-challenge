#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int change(vector<int>& coins, int amount) 
{
    vector<int> dp(amount+1,amount+1); 
    dp[0]=0;
    for(int i=1;i<=amount;++i) 
    {
        for(int coin:coins) 
        {
            if(coin<=i) 
            {
                dp[i]=min(dp[i],dp[i-coin]+1); 
            }
        }
    }
    return dp[amount]>amount?-1:dp[amount]; 
}
int main() 
{
    int n,amount;
    cout<<"Enter number of coin denominations: ";
    cin>>n;
    vector<int> coins(n);
    cout<<"Enter the coin denominations: ";
    for(int i=0;i<n;i++) 
    {
        cin>>coins[i];
    }
    cout<<"Enter the amount: ";
    cin>>amount;
    int result=change(coins,amount);
    if (result!=-1)
        cout<<"Coins required: "<<result<<endl;
    else
        cout<<"Not possible to make the amount with given coins"<<endl;
    return 0;
}
