#include<iostream>
#include<vector>
using namespace std;
struct Node{
    int data;
    Node* left;
    Node* right;
    Node(){
        data=0;
        right=left=NULL;
    }
    Node(int d){
        data=d;
        right=left=NULL;
    }
};
class Binary{
    private:
        Node* root=new Node();
        void insertrecur(Node* &n,int key){
            if(n==NULL) n=new Node(key);
            else if(key>n->data){
                insertrecur(n->right,key);
            }
            else if(key<n->data){
                insertrecur(n->left,key);
            }
        }
        void preorder(Node* &n,vector<int> &v){
            if(!n==NULL){
                v.push_back(n->data);
                preorder(n->left,v);
                preorder(n->right,v);
            }
        }
        int heighting(Node* n){
            Node* temp=n;
            if(temp==NULL) return -1;
            else{
                int rheight=heighting(temp->right);
                int lheight=heighting(temp->left);
                if(rheight>lheight) return rheight+1;
                else return lheight+1;
                }
        }
        void bfs(Node* n){
            int h=heighting(n);
            for(int i=0;i<=h;i++){
                printing(n,i);
            }
        }
        void printing(Node* n,int l){
            if(n==NULL){
                return ;
            }
            else if(l==0){
                cout<<n->data<<" ";
            }
            else{
                printing(n->left,l-1);
                printing(n->right,l-1);
            }
        }
    public:
        Binary(){
            root=NULL;
        }
        void insertkey(int k){
            insertrecur(root,k);
        }
        vector<int> preorder(){
            vector<int> v;
            preorder(root,v);
            return v;
        }
        void height(){
            int h=heighting(root);
            cout<<h<<endl;
        }
        
};
int main(){
    int n;
    Binary bin;
    cin>>n;
    for(int i=0;i<n;i++){
        int key;
        cin>>key;
        bin.insertkey(key);
    }
    vector<int> v=bin.preorder();
    for(auto i:v){
        cout<<i<<" ";
    }}
