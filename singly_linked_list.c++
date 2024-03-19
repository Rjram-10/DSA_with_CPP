#include<iostream>
using namespace std;
class Node{
    public:
        int key;
        int data;
        Node* next;

        Node(){
            key=0;
            data=0;
            next=NULL;
        }
        Node(int k,int d){
            key=k;
            data=d;
        }
};
class SinglyLinkedList{
    public:
        Node* head;
        
        SinglyLinkedList(){
            head=NULL;
        }  
       
        SinglyLinkedList(Node* n){
            head=n;
        }
       
        Node* nodeExist(int k){
            
            Node* temp=NULL;
           
            Node* ptr=head;
           
            while(ptr!=NULL){
                if(ptr->key==k){
                    temp=ptr;
                }
                ptr=ptr->next;
            }
            return temp;
        }
        //Inserting node in last
        void appendNode(Node *n){
            
            if(nodeExist(n->key)!=NULL){
                cout<<"Node Already existed with same key";
            }

            else if(head==NULL){
                head=n;
            }
            else{
                Node* ptr=head;
                while(ptr->next!=NULL){
                    ptr=ptr->next;
            }
            ptr->next=n;
            cout<<"Inserted in last"<<endl;

        }
    }

        //Inserting node in front
        void frontinsert(Node *n){
            
            if(nodeExist(n->key)!=NULL){
                cout<<"Node Already existed";
            }
            
            else{
                n->next=head;
                head=n;
            }
            cout<<"Inserted in front"<<endl;
        }

        //Inserting node after a node
        void insertnodeafter(int k,Node* n){
            if(nodeExist(n->key)!=NULL){
                cout<<"Node Already existed with same key";
            }
            else{
                Node* ptr=nodeExist(k);
                if(ptr==NULL){
                    cout<<"Node Already existed with same key";
                }
                else{
                n->next=ptr->next;
                ptr->next=n;
            }
            }
            cout<<"Inserted"<<endl;
        }

        //Deleting node by unique key
        void deletewithkey(int k){
            if(nodeExist(k)==NULL){
                cout<<"Node Already deleted";
            }
            else{
                if(head->key==k){
                    head=head->next;
                    cout <<"Deleted"<<endl;
                }
                else{
                    Node* temp=NULL;
                    Node* prevptr=head;
                    Node* currptr=head->next;
                    while(currptr!=NULL){
                        if(currptr->key==k){
                            temp=currptr;
                            currptr=NULL;
                        }
                        else{
                            prevptr=prevptr->next;
                            currptr=currptr->next;
                        }
                    }
                    if(temp!=NULL){
                        prevptr->next=temp->next;
                    }
                    else{
                        cout<<"No such element";
                    }
            }
        }}

        //Updating node by Unique key
        void updating(int k,int d){
            if(nodeExist(k)==NULL){
                cout<<"No such type of node";
            }
            else{
                Node* ptr=nodeExist(k);
                ptr->data=d;
                cout<<"Data updated";
            }
            cout<<"Updated"<<endl;
        }

        //Printing 
        void print(){
            if(head==NULL){
                cout<<"No nodes in Singly Linked List";
            }
            else{
                Node* ptr=head;
                while(ptr!=NULL){
                    cout<<"("<<ptr->key<<","<<ptr->data<<") -->";
                    ptr=ptr->next;
            }
        }
}
};
int main(){
    SinglyLinkedList s;
    int option,key,data,k1;
    do{
        cout<<"0.Quit"<<endl;
        cout<<"1.Insert node in last"<<endl;
        cout<<"2.Insert node in first"<<endl;
        cout<<"3.Insert node after a node"<<endl;
        cout<<"4.Delete node by key"<<endl;
        cout<<"5.Updating"<<endl;
        cout<<"6.Print"<<endl;

        cout<<"Enter option";
        cin>>option;
        Node* n=new Node();

        switch (option)
        {
            case 0:
                break;
            case 1:
                cout<<"Enter key & data :- ";
                cin>>key;
                cin>>data;
                n->data=data;
                n->key=key;
                s.appendNode(n);
                break;
            case 2:
                cout<<"Enter key & data :- ";
                cin>>key;
                cin>>data;
                n->data=data;
                n->key=key;
                s.frontinsert(n);
                break;
            case 3:
                cout<<"Enter key after insertion is have to occured :- ";
                cin>>k1;
                cout<<"Enter key & data :- ";
                cin>>key;
                cin>>data;
                n->data=data;
                n->key=key;
                s.insertnodeafter(k1,n);
                break;
            case 4:
                cout<<"Enter key for deletion :- ";
                cin>>k1;
                s.deletewithkey(k1);
                break;
            case 5:
                cout<<"Enter key where updation is to be occured :- ";
                cin>>k1;
                cout<<"Enter data for updation is to be occured :- ";
                cin>>data;
                s.updating(k1,data);
                break;
            case 6:
                s.print();
                break;

        }

    }while(option!=0);
}