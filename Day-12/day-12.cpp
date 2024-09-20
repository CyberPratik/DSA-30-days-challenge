#include <iostream>
#include <vector>
using namespace std;
bool check(string s) {
    vector<char> stack;
    for(char c : s)
	{
        if(c == '(' || c == '{' || c == '[')
		{
            stack.push_back(c);
        } 
		else 
		{
            if (stack.empty()) return false;
            if ((c == ')' && stack.back() == '(') ||
                (c == '}' && stack.back() == '{') ||
                (c == ']' && stack.back() == '[')) {
                stack.pop_back();
            } else {
                return false; 
            }
        }
    }
    return stack.empty(); 
}
int main() 
{
    string s;
    cout << "Enter a string of parentheses: ";
    cin >> s;
    if (check(s)) 
	{
        cout << "True" << endl;
    } 
	else 
	{
        cout << "False" << endl;
    }
    return 0;
}
