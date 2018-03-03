//
//  main.cpp
//  BFS
//
//  Created by Esteban Gomez on 1/3/18.
//  Copyright © 2018 esteban. All rights reserved.
//

#include <iostream>
#include <cstddef>
#include <queue>
#include <string>
#include <cstdlib>
using namespace std;
class Node{
public:
    int data;
    Node *left,*right;
    Node(int d){
        data=d;
        left=right=NULL;
    }
};
class Solution{
public:
    Node* insert(Node* root, int data){
        if(root==NULL){
            return new Node(data);
        }
        else{
            Node* cur;
            if(data<=root->data){
                cur=insert(root->left,data);
                root->left=cur;
            }
            else{
                cur=insert(root->right,data);
                root->right=cur;
            }
            return root;
        }
    }
    void levelOrder(Node * root){
        //Write your code here
        //
        queue <Node*> bfs;
        Node* cur = root;
        while (cur != NULL)
        {
            cout << cur->data << " ";
            
            if (cur-> left != NULL)
            {
                bfs.push(cur->left);
            }
            if (cur->right != NULL)
            {
                bfs.push(cur->right);
            }
            if (!bfs.empty())
            {
                cur = bfs.front();
                bfs.pop();
            }
            else cur = NULL;
        }
        
    }
};//End of Solution
int main(){
    Solution myTree;
    Node* root=NULL;
    int T,data;
    cin>>T;
    while(T-->0){
        cin>>data;
        root= myTree.insert(root,data);
    }
    myTree.levelOrder(root);
    return 0;
}
