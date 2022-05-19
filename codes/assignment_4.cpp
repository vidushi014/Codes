#include <bits/stdc++.h>
using namespace std;
struct node{
    int value;
    node *left=NULL,*right=NULL;
    bool left_isthread=false,right_isthread=false;
    node *left_thread=NULL,*right_thread=NULL;
};
vector<node*>lst;
unordered_map<node*,pair<node*,node*>>mp;
node *insert(node *root , int value){
    // cout<<"p";
    node *ptr=root;
    node *parent=NULL;
    while(ptr!=NULL){
        // cout<<ptr->value<<" ";
        if(ptr->value==value){
            cout<<"Duplicate entry";
            return root;
        }
        parent=ptr;
        if(value<ptr->value){
            ptr=ptr->left;
        }
        else{
            ptr=ptr->right;
        }
    }
    node *temp= new node;
    temp->value=value;

    if(parent==NULL){
        root=temp;
        return root;
    }
    else if(value<parent->value){
        parent->left=temp;
    }
    else{
        parent->right=temp;
    }

    return root;
}
void inorder(node *root){
    if(root==NULL){
        return ;
    }
    inorder(root->left);
    lst.push_back(root);
    cout<<root->value<<" ";
    inorder(root->right);
}
void TBST(node *root){
    if(root==NULL){
        return ;
    }
    if(root->left==NULL && mp[root].first!=NULL){
        root->left_thread=mp[root].first;
        root->left_isthread=true;
    }
    if(root->right==NULL && mp[root].second!=NULL){
        root->right_thread=mp[root].second;
        root->right_isthread=true;
    }
    TBST(root->left);
    TBST(root->right);
}
void display(node *root){
    if(root==NULL) return ;
    cout<<root->value<<" ";
    if(root->left_isthread){
        cout<<root->left_thread->value<<" ";
    }
    if(root->right_isthread){
        cout<<root->right_thread->value<<" ";
    }
    cout<<"\n";
    display(root->left);
    display(root->right);
}
int main(){
    // cout<<"*";
    node *root=NULL;
    root = insert(root,11);
    root = insert(root,9);
    root = insert(root,17);
    root = insert(root,12);
    root = insert(root,19);
    root = insert(root,14);
    root = insert(root,15);
    root = insert(root,20);
    inorder(root);
    cout<<"\n";
    for(int i=0;i<lst.size();i++){
        if(i==0){
            mp[lst[i]]={NULL,lst[i+1]};
            continue;
        }
        if(i==lst.size()-1){
            mp[lst[i]]={lst[i-1],NULL};
            continue;
        }
        mp[lst[i]]={lst[i-1],lst[i+1]};
    }
    TBST(root);
    display(root);
}
