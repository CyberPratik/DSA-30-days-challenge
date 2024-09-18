#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_map>
using namespace std;
vector<vector<string>> f1(const vector<string>& words) 
{
    unordered_map<string, vector<string>> anagramGroups;
    for (const string& word : words) 
    {
        string sortedWord=word;
        sort(sortedWord.begin(), sortedWord.end());
        anagramGroups[sortedWord].push_back(word);
    }
    vector<vector<string>> groupedAnagrams;
    for (const auto& group : anagramGroups) 
    {
        groupedAnagrams.push_back(group.second);
    }
    return groupedAnagrams;
}
int main() 
{
    int n;
    cout<<"Enter number of elements: ";
    cin>>n;

    vector<string> words(n);
    cout<<"Enter the words:\n";
    for (int i=0;i<n;i++)
    {
        cin>>words[i];
    }
    vector<vector<string>> result=f1(words);
    cout<<"\nAnagram Groups:\n";
    for(const auto& group : result) 
    {
        cout<<"[ ";
        for(const string& word : group) 
        {
            cout<<word<<" ";
        }
        cout<<"]\n";
    }
    return 0;
}
