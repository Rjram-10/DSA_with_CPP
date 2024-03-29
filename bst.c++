#include<bits/stdc++.h>
using namespace std;
class Node{
    public:
        int data;
        Node* left;
        Node* right;

        Node(int v){
            data=v;
            left=NULL;
            right=NULL;
             }
};

Node* createbst(vector<int> v,int start, int end){
    sort(v.begin(),v.end());
    if(start>end){
        return NULL;
    }

    int mid=(start+end)/2;
    Node* root= new Node(v[mid]);

    root->left=createbst(v,start,mid-1);
    root->right=createbst(v,mid+1,end);

    return root;
}

vector<int> prenode,innode,postnode,vec;
vector<int> preorder(Node* node){
    if(node==NULL){
        return vec;
    }
    prenode.push_back(node->data);
    preorder(node->left);
    preorder(node->right);
    return prenode;
}

vector<int> inorder(Node* node){
    if(node==NULL){
        return vec;
    }
    inorder(node->left);
    innode.push_back(node->data);
    inorder(node->right);
    return innode;
}

vector<int> postorder(Node* node){
    if(node==NULL){
        return vec;
    }
    postorder(node->left);
    postorder(node->right);
    postnode.push_back(node->data);
    return postnode;
}

int main(){
    vector<int> v;
    int n,j;
    cout<<"Enter no. of data";
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>j;
        v.push_back(j);
    }

    Node* root=createbst(v,0,v.size()-1);
    vector<int> pre=preorder(root);
    vector<int> ins=inorder(root);
    vector<int> post=postorder(root);

    for(auto i:pre){
        cout<<i<<" ";
    }
    cout<<endl;
    for(auto i:ins){
        cout<<i<<" ";
    }
    cout<<endl;
    for(auto i:post){
        cout<<i<<" ";
    }
    cout<<endl;


}