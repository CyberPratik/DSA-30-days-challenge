#include <iostream>
#include <stack>
using namespace std;
void f1(stack<int>& st, int elem) 
{
    if(st.empty() || elem>=st.top()) 
    {
        st.push(elem);
        return;
    }
    int topElem=st.top();
    st.pop();                
    f1(st, elem);  
    st.push(topElem);  
}
void recur(stack<int>& st) 
{
    if(st.empty()) 
    {
        return;  
    }
    int topElem=st.top();  
    st.pop();                
    recur(st);       
    f1(st, topElem);  
}
void stack(stack<int> st) 
{
    if(st.empty()) 
    {
        return;
    }
    int topElem=st.top(); 
    st.pop();                
    stack(st);  
    cout<<topElem<< " ";
}
int main() 
{
    stack<int> st;
    int numElements, value;
    cout<<"Enter number of elements: ";
    cin>>numElements;
    cout<<"Enter elements: "<<endl;
    for(int i=0;i<numElements;i++) 
    {
        cin>>value;
        st.push(value);
    }
    recur(st);
    cout<<"Sorted Stack:";
    stack(st);
    cout<<endl;
    return 0;
}
