#include <iostream>
#include <vector>
#include <queue>
#include <sstream>
using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x):val(x), left(NULL), right(NULL) {}
};
bool valid(TreeNode* root, long long minVal, long long maxVal) {
    if(!root) return true;
    if(root->val<=minVal || root->val>=maxVal) return false;
    return valid(root->left, minVal, root->val) && valid(root->right, root->val, maxVal);
}
bool valid(TreeNode* root) 
{
    return valid(root, LLONG_MIN, LLONG_MAX);
}
TreeNode* buildTree(const vector<string>& nodes) {
    if(nodes.empty() || nodes[0]=="null") return nullptr;
    TreeNode* root=new TreeNode(stoi(nodes[0]));
    queue<TreeNode*>q;
    q.push(root);
    int i = 1;
    while (!q.empty() && i < nodes.size()) 
    {
        TreeNode* current = q.front();
        q.pop();
        if (nodes[i] != "null") 
        {
            current->left = new TreeNode(stoi(nodes[i]));
            q.push(current->left);
        }
        i++;
        if (i < nodes.size() && nodes[i] != "null") 
        {
            current->right = new TreeNode(stoi(nodes[i]));
            q.push(current->right);
        }
        i++;
    }
    return root;
}
vector<string> splitInput(const string& input) 
{
    vector<string> result;
    string cleanedInput= input.substr(input.find('[')+ 1,input.find(']')-input.find('[')-1);
    stringstream ss(cleanedInput);
    string node;
    while (getline(ss, node, ',')) {
        if (node == "null") 
        {
            result.push_back("null");
        } 
        else 
        {
            result.push_back(node);
        }
    }

    return result;
}

int main() 
{
    string input;
    cout<<"Enter tree as array (e.g., root = [5,1,4,null,null,3,6]): ";
    getline(cin, input);

    vector<string> nodes=splitInput(input);
    TreeNode* root=buildTree(nodes);
    if (valid(root)) {
        cout<< "Output: true" << endl;
    } else {
        cout<< "Output: false" << endl;
    }
    return 0;
}