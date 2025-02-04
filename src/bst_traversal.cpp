#include <bits/stdc++.h>

using namespace std;

struct bstNode
{
    int val;
    bstNode* left;
    bstNode* right;
};
bstNode* newNode(int data)
{
    bstNode* newNode = new bstNode();
    newNode->val = data;
    newNode->left = newNode->right = nullptr;
    return newNode;
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
/*
level order traversal
time complexity - O(n)
space complexity - O(n)
*/ 
void bfs(bstNode*& root)
{
    queue<bstNode*> q;
    q.push(root);
    while(!q.empty())
    {
        bstNode* first = q.front();
        q.pop();
        cout << first->val << " ";
        if(first->left!=nullptr)
            q.push(first->left);
        if(first->right!=nullptr)
            q.push(first->right);
    }
}
/*
Inorder, preorder and postorder traversal
inorder - Left, root, right
preorder - root, left, right
*/
void preorder(bstNode*& root)
{
    if(root == nullptr) cout << ":(";
    stack<bstNode*> st;
    st.push(root);
    while(!st.empty())
    {
        bstNode* top = st.top();
        st.pop();
        cout << top->val << ",";
        // first push the right elements. Its LIFO - so left should come out first, only happens if it enters last
        if(top->right!=nullptr)
            st.push(top->right);
        if(top->left!=nullptr)
            st.push(top->left);
    }
}
void inorder(bstNode*& root)
{
    if(root == nullptr) cout << ":(";
    stack<bstNode*> st;
    bstNode* curr = root;
    while(!st.empty() || curr!=nullptr) // if both happen together - then we have travrsed the tree.
    {
        while(curr!=nullptr)
        {
            st.push(curr);
            curr = curr->left;
        }
        curr = st.top();
        st.pop();
        cout << curr->val << ",";
        curr = curr->right;
    }
}
bool isBalanced(bstNode* root)
{
    if(root == nullptr) return false;
    stack<bstNode*> st;
    bstNode* curr = root;
    int prev = INT_MAX;
    bool firstNode = true;
    while(!st.empty() || curr!=nullptr) // if both happen together - then we have travrsed the tree.
    {
        while(curr!=nullptr)
        {
            st.push(curr);
            curr = curr->left;
        }
        curr = st.top();
        // Additional check to be done!
        if(firstNode)
        {
            prev = curr->val;
            firstNode = false;
        }
        else
        {
            if(curr->val<prev) // <=
                return false;
            prev = curr->val;
        }
        st.pop();
        // cout << curr->val << ",";
        curr = curr->right;
    }
    return true;
}
bstNode* findMax(bstNode*& root)
{
    if(root == nullptr) return root;
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
    return right;

}
bstNode* DeleteNode(bstNode*& root, int data)
{
    /*
    There are three cases
    leaf nodes - directly delete them.
    nodes with one child - treat it like linkedlist.
    nodes with two child - find the highest value in the left subtree of the node to be deleted - replace the value of the node
    with the highest value and delete the duplicate node in left subtree. The deleted node will have no right child, might have a 
    left child. (worst case -  we go to the 2nd condition.)
    */
    if (root==nullptr) return root;
    else if (data > root->val) root->right = DeleteNode(root->right,data);
    else if(data < root->val) root->left = DeleteNode(root->left,data);
    else
    {
        if(root->right == nullptr && root->left == nullptr)
        {
            delete root;
            root = NULL; // otherwise it will be a dangling pointer.
        }
        else if(root->left == nullptr)
        {
            bstNode* temp = root;
            root = root->right;
            delete temp;
        }
        else if(root->right == nullptr)
        {
            bstNode* temp = root;
            root = root->left;
            delete temp;
        }
        else
        {
            bstNode* max = findMax(root->left);
            root->val = max->val;
            root->left = DeleteNode(root->left,max->val);
        }
        return root;
    }
}
/*
Inorder Successor of a given node - do inorder traversal, do binary search, return the next index. - O(n)
O(log n) - O(Height of the tree)
Node has right subtree - go to the leftmost node of the right subtree
Node has no right subtree - start from root and end at the node. Return the deepest ancestor which is > node.val
OR go to the nearest ancestor for which the node is in the left subtree.
*/
bstNode* findSuccessor(bstNode* root, int data)
{
    if (root == nullptr) return nullptr;
    bstNode* current = root;
    // searching.
    while(current->val!=data)
    {
        if(data > current->val) current = current->right;
        else current = current->left;
    }
    if (current == nullptr) return nullptr;

    // if right subtree.
    if(current->right!=nullptr)
    {
        current = current->right;
        // find min in the right subtree
        while(current->left!=nullptr)
        {
            current = current->left;
        }
        return current;
    }
    else
    {
        bstNode* successor = nullptr;
        bstNode* ancestor = root;
        while(ancestor!=current)
        {
            // only store successor in if block because to be an inorder successor.val > curr.val
            if(current->val < ancestor->val)
            {
                successor = ancestor;
                ancestor = ancestor->left;
            }
            else
                ancestor = ancestor->right;
        }
        return successor;
    }
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
    bfs(root); // level order
    cout << endl;
    preorder(root);
    cout << endl;
    inorder(root);
    cout << endl;
    // return;
}