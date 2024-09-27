#include <iostream>
#include <stack>
#include <sstream>
#include <cmath>
using namespace std;
int evaluate(const string& expr) 
{
    stack<int> s;
    stringstream ss(expr);
    string part;
    while(ss>>part) 
    {
        if((part[0]=='-' && part.length()>1 && isdigit(part[1])) || isdigit(part[0])) 
        {
            s.push(stoi(part));  
        } 
        else {
            int val2=s.top(); s.pop();
            int val1=s.top(); s.pop();
            if (part=="+") 
            {
                s.push(val1+val2);
            } 
            else if (part=="-") 
            {
                s.push(val1-val2);
            } 
            else if (part=="*") 
            {
                s.push(val1*val2);
            } 
            else if (part=="/") 
            {
                s.push(val1/val2);
            } 
            else if (part=="^") 
            {
                s.push(pow(val1, val2));  
            }
        }
    }
    return s.top();
}
int main() 
{
    string expr;
    cout<<"Enter your expression: ";
    getline(cin, expr);  
    cout<<"Result: "<<evaluate(expr)<<endl;
    return 0;
}
