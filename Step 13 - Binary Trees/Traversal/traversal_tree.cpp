#include <bits/stdc++.h>
using namespace std;

class TreeNode{
    public:
    
    int data;
    TreeNode* left, *right;

    TreeNode(){
        data = 0;
        left = NULL, right = NULL;
    }

    TreeNode(int data){
        this->data = data;
        left = NULL, right = NULL;
    }

    TreeNode(int data, TreeNode* left, TreeNode* right){
        this->data = data;
        this->left = left;
        this->right = right;
    }

};


//! Create Binary Tree
TreeNode* createTree(vector<int>&arr){
    TreeNode* root = new TreeNode(arr[0]);
    TreeNode* n1 = new TreeNode(arr[1]);
    TreeNode* n2 = new TreeNode(arr[2]);
    TreeNode* n3 = new TreeNode(arr[3]);
    TreeNode* n4 = new TreeNode(arr[4]);
    TreeNode* n5 = new TreeNode(arr[5]);
    TreeNode* n6 = new TreeNode(arr[6]);

    root->left = n1, root->right = n2;
    n1->left = n3, n1->right = n4;
    n2->left = n5, n2->right = n6;

    return root;
}

//! Tree Traversals

//! Pre-Order
void preOrder(TreeNode* root,vector<int>& preOrderVector){
    if(root == NULL)    return;

    preOrderVector.push_back(root->data);
    preOrder(root->left,preOrderVector);
    preOrder(root->right,preOrderVector);
}

//! In-Order
void inOrder(TreeNode* root,vector<int>& inOrderVector){
    if(root == NULL)    return;

    inOrder(root->left,inOrderVector);
    inOrderVector.push_back(root->data);
    inOrder(root->right,inOrderVector);
}

//! Post-Order
void postOrder(TreeNode* root,vector<int>& postOrderVector){
    if(root == NULL)    return;

    postOrder(root->left,postOrderVector);
    postOrder(root->right,postOrderVector);
    postOrderVector.push_back(root->data);
}

//! All Traversals in one Traversal

//* Brute 
vector<vector<int>> getTreeTraversal(TreeNode* root){
    vector<int> preOrderVector;
    vector<int> inOrderVector;
    vector<int> postOrderVector;

    preOrder(root,preOrderVector);
    inOrder(root,inOrderVector);
    postOrder(root,postOrderVector);

    vector<vector<int>> ans;
    ans.push_back(inOrderVector);
    ans.push_back(preOrderVector);
    ans.push_back(postOrderVector);

    return ans;
}


//! Breath First Search (BFS) / Level Order Traversal
//* t,s => O(N)
vector<vector<int>> levelOrder(TreeNode* root){
    vector<vector<int>> ans;
    if(root == NULL)
        return ans;
    
    queue<TreeNode*> q;
    q.push(root);

    while(!q.empty()){
        int size = q.size();
        vector<int> level;

        for(int i=0;i<size;i++){
            TreeNode* node = q.front();
            q.pop();
            if(node->left != NULL)
                q.push(node->left);
            if(node->right != NULL)
                q.push(node->right);
            level.push_back(node->data);
        }
        ans.push_back(level);
    }
    return ans;
}

//* CN question
void levelOrder0(TreeNode * root){
    if(root == nullptr) 
        return;
    vector<int> ans;
    queue<TreeNode*> q;
    q.push(root);

    while(!q.empty()){
        int size = q.size();
        vector<TreeNode*> level;

        for(int i=0;i<size;i++){
            TreeNode* node = q.front();
            ans.push_back(node->data);
            q.pop();
            if(node->left)  
                q.push(node->left);
            if(node->right)
                q.push(node->right);
        }
    }
}


//! Traversal - Iterative

//! Pre-Order
vector<int> preOrderIter(TreeNode* root){
    vector<int> ans;
    if(root == NULL)
        return ans;

    stack<TreeNode*> s;
    s.push(root);

    while(!s.empty()){
        TreeNode* node = s.top();
        s.pop();
        ans.push_back(node->data);

        if(node->right)
            s.push(node->right);
        if(node->left)
            s.push(node->left);
    }

    return ans;
}


//! In-Order
vector<int> inOrderIter(TreeNode* root){
    vector<int> ans;
    if(root == NULL)    return ans;
    stack<TreeNode*> s;
    TreeNode* node = root;

    while(true){
        if(node != NULL){
            s.push(node);
            node = node->left;
        }
        else{
            if(s.empty())   break;
            node = s.top();
            s.pop();
            ans.push_back(node->data);
            node = node->right;
        }
    }

    return ans;
}


//! Post Order using 2 Stacks
vector<int> postorderTraversal(TreeNode* root){
    vector<int>ans; 
    if(root == NULL)
        return ans;
    stack<TreeNode*> s1,s2;
    s1.push(root);

    while(!s1.empty()){
        TreeNode* node = s1.top();
        s1.pop();
        if(node->left)
            s1.push(node->left);
        if(node->right)
            s1.push(node->right);
        s2.push(node);
    }

    while(!s2.empty()){
        ans.push_back((s2.top())->data);
        s2.pop();
    }

    return ans;
}


//! Post Order using 1 stack
vector<int> postOrder1Stack(TreeNode* root){
    vector<int>ans;
    if(root == NULL)
        return ans;
    


    return ans;
}