//
//  main.cpp
//  LinkedListDelete
//
//  Created by Esteban Gomez on 1/10/18.
//  Copyright © 2018 esteban. All rights reserved.
//
#include <cstddef>
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
class Node
{
public:
    int data;
    Node *next;
    Node(int d){
        data=d;
        next=NULL;
    }
};
class Solution{
public:
Node* removeDuplicates(Node *head)
{
    Node* cur = head->next;
    Node* cur1 = head;
    
    while (cur1 != NULL)
    {
        cur = cur1->next;
        while (cur != NULL)
        {
            if (cur1->data == cur->data)
            {
                Node* temp = cur1->next;
                cur1->next = cur->next;
                delete temp;
            }
            if (cur1->data == cur->data && cur->next == NULL)
            {
                delete cur;
            }
            /*if (cur1->data == cur->data)
             {
             Node* temp = cur;
             cur1->next = cur->next;
             delete temp;
             }*/
            
            cur = cur->next;
        }
        cur1 = cur1->next;
    }
    delete cur;
    delete cur1;
    return head;
}
Node* insert(Node *head,int data)
{
    Node* p=new Node(data);
    if(head==NULL){
        head=p;
        
    }
    else if(head->next==NULL){
        head->next=p;
        
    }
    else{
        Node *start=head;
        while(start->next!=NULL){
            start=start->next;
        }
        start->next=p;
        
    }
    return head;
    
    
}
void display(Node *head)
{
    Node *start=head;
    while(start)
    {
        cout<<start->data<<" ";
        start=start->next;
    }
}
};

int main()
{
    Node* head=NULL;
    Solution mylist;
    int T,data;
    cin>>T;
    while(T-->0){
        cin>>data;
        head=mylist.insert(head,data);
    }
    head=mylist.removeDuplicates(head);
    
    mylist.display(head);
    
}
