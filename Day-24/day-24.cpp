#include <iostream>
#include <vector>
using namespace std;
struct TreeNode 
{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
TreeNode* lowest(TreeNode* root, TreeNode* p, TreeNode* q) 
{
    if(root==nullptr||root==p || root==q)
    {
        return root;
    }

    TreeNode* left=lowest(root->left, p, q);
    TreeNode* right=lowest(root->right, p, q);

    if(left!=nullptr && right!=nullptr) 
    {
        return root;
    }

    return left!=nullptr?left:right;
}
TreeNode* order(const vector<int>& arr, int i) 
{
    if(i>=arr.size() || arr[i]==-1) 
    {
        return nullptr;
    }
    
    TreeNode* root=new TreeNode(arr[i]);
    root->left=order(arr, 2 * i + 1);
    root->right=order(arr, 2 * i + 2);
    return root;
}
TreeNode* findNode(TreeNode* root, int val) 
{
    if(root==nullptr || root->val==val) 
    {
        return root;
    }
    
    TreeNode* left=findNode(root->left, val);
    if(left!=nullptr) 
    {
        return left;
    }
    return findNode(root->right, val);
}
int main() 
{
    int n,p_val,q_val;
    cout<<"Enter the number of elements: ";
    cin>>n;
    vector<int> tree(n);
    cout<<"Enter the elements of the tree (use -1 for null nodes): ";
    for(int i=0;i<n;++i) 
    {
        cin>>tree[i];
    }
    cout<<"Enter value of p: ";
    cin>>p_val;
    cout<<"Enter value of q: ";
    cin>>q_val;
    TreeNode* root=order(tree, 0);
    TreeNode* p=findNode(root, p_val);
    TreeNode* q=findNode(root, q_val);
    
    if(p==nullptr || q==nullptr) 
    {
        cout<<"One or both nodes not found in the tree."<<endl;
        return 1;
    }
    TreeNode* lca = lowest(root, p, q);
    if(lca!=nullptr) 
    {
        cout<<"Lowest Common Ancestor of "<<p_val<<" and "<<q_val<<" is: "<<lca->val<<endl;
    } 
    else 
    {
        cout<<"LCA not found."<<endl;
    }
    return 0;
}
