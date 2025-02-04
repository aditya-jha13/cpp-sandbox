#include <bits/stdc++.h>

using namespace std;

struct bstNode
{
    int val;
    bstNode* left;
    bstNode* right;
};

// malloc and new operator return the pointer to the class.
// we keep the address of the root node to keep track of the trees.
bstNode* newNode(int data)
{
    bstNode* newNode = new bstNode();
    newNode->val = data;
    newNode->left = newNode->right = nullptr;
    return newNode;
}

void Insert(bstNode*& root, int data) // because we are passing by reference, we dont need to return anything. it updates the root in the main scope.
{
    if(root == nullptr)
        root = newNode(data);
    else if(data>= root->val)
        Insert(root->right,data);
    else
        Insert(root->left,data);
    // return root;
}

void IterativeInsert(bstNode*& root, int data)
{
    if(root == nullptr)
    {
        root = newNode(data);
        return;
    }
    bstNode* curr = root;
    bstNode* parent = nullptr;
    while(curr!=nullptr)
    {
        parent = curr;
        if(data >= curr->val)
            curr = curr->right;
        else
            curr = curr->left;
    }
    if(data>=parent->val)
        parent->right = newNode(data);
    else
        parent->left = newNode(data);
}
bool Search(bstNode*& root,int data)
{
    if(root == nullptr)
        return false;
    if(root->val == data) return true;
    if(data > root->val) return Search(root->right,data);
    else return Search(root->left,data);
}
vector<int> findMinMax(bstNode*& root)
{
    if(root == nullptr) return vector<int>({-1,-1});
    bstNode* left = root;
    bstNode* right = root;
    while(left->left!=nullptr)
    {
        left = left->left;
    }
    int min = left->val;
    while(right->right!=nullptr)
    {
        right = right->right;
    }
    int max = right->val;
    return vector<int>({min,max});

}
int Height(bstNode*& root)
{
    if(root == nullptr)
        return -1; // acc to def. height of an empty tree is -1
    return 1+max(Height(root->left),Height(root->right));
}
int main()
{
    bstNode* root;
    root = nullptr; // init an empty tree.
    // each bstNode object can be accessed through pointers as they are stored in the heap memory
    IterativeInsert(root,10);
    IterativeInsert(root,7);
    IterativeInsert(root,14);
    IterativeInsert(root,89);
    IterativeInsert(root,6);
    IterativeInsert(root,5);
    IterativeInsert(root,3);
    bool ans = Search(root,89);
    vector<int> mm = findMinMax(root);
    cout << mm[0]<<" ,"<<mm[1]<<endl;
    cout << "Height:" << Height(root)<<endl;
    cout<<ans;

}