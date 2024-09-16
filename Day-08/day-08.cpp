#include <iostream>
#include <vector>
#include <sstream>
#include<string>
using namespace std;
int main(){
    string text;
    cout<<"Enter any text:";
    getline(cin,text);
    stringstream ss(text);
    string word;
    vector<string> arr;
    while (ss>>word){
        arr.push_back(word);
    }
    cout<<"Reversed String is: ";
    for (int i=arr.size()-1;i>=0;i--){
        cout<<arr[i]<<" ";
    }
    return 0;
}
