#include<iostream>
using namespace std;
class Node{
    public:
        int key;
        int data;
        Node* prev;
        Node* next;

        Node(){
            key=data=0;
            prev=next=NULL;
        }
        Node(int k, int d){
            key=k;
            data=d;
        }
};
class doublylinkedlist{
    public:
        Node* head;
        doublylinkedlist(){
            head=NULL;
        }
        doublylinkedlist(Node* n){
            head=n;
        }

        Node* isnodeexist(int k){
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

        void appendnode(Node* n){
            if(isnodeexist(n->key)!=NULL){
                cout<<"Data is already existed";
            }
            else{
                if(head==NULL){
                    head=n;
                }
                else{
                    Node* ptr=head;
                    while(ptr!=NULL){
                        ptr=ptr->next;
                    }
                    ptr->next=n;
                    n->prev=ptr;
                }
                cout<<"Inserted"<<endl;
            }
        }

        void insertfront(Node* n){
            if(isnodeexist(n->key)!=NULL){
                cout<<"Data is already existed";
}
            else{
                if(head==NULL){
                    head=n;
                }
                else{
                    head->prev=n;
                    n->next=head;

                    head=n;
                    }
                cout<<"Inserted"<<endl;

            }
        }
        void insertafter(int k,Node* n){
            if(isnodeexist(k)==NULL){
                cout<<"Data is not existed";
            }
            else{
                if(isnodeexist(n->key)!=NULL){
                    cout<<"Already in system"<<endl;
                }
                else{
                    Node* temp=isnodeexist(k);
                    Node* nextnode=temp->next;
                    if(nextnode==NULL){
                        temp->next=n;
                        n->prev=temp;
                    }
                    else{
                        n->next=nextnode;
                        n->prev=temp;
                        temp->next=n;
                        nextnode->prev=n;
                    }
                    cout<<"Inserted"<<endl;
            }
        }
        }

        void deleteforkey(int k){
            if(isnodeexist(k)==NULL){
                cout<<"Node is not existed";
            }
            else{
                if(head->key==k){
                    head=head->next;
                }
                else{
                    Node* ptr=isnodeexist(k);
                    if(ptr->next==NULL){
                        ptr->prev->next=NULL;
                    }
                    else{
                        ptr->prev->next=ptr->next;
                        ptr->next->prev=ptr->prev;
                    }
                }
                cout<<"Deleted"<<endl;
            }
        }

        void updatenode(int k,int d){
            if(isnodeexist(k)==NULL){
                cout<<"Node not existed"<<endl;
            }
            else{
                Node* ptr=isnodeexist(k);
                ptr->data=d;
                cout<<"Updated"<<endl;
            }
        }

        void print(){
            if(head==NULL){
                cout<<"No nodes"<<endl;
            }
            else{
                Node* ptr=head;
                while(ptr!=NULL){
                    cout<<"("<<ptr->key<<","<<ptr->data<<") -->";
                    ptr=ptr->next;
                }
                cout<<endl;
            }
            }
};
int main(){
    doublylinkedlist d;
    int key,data,k1;
    int option;
    do{
        cout<<"0.Quit"<<endl;
        cout<<"1.Insert node in last"<<endl;
        cout<<"2.Insert node in first"<<endl;
        cout<<"3.Insert node after a node"<<endl;
        cout<<"4.Delete node by key"<<endl;
        cout<<"5.Updating"<<endl;
        cout<<"6.Print"<<endl;

        Node* n=new Node();
        cout<<"Enter option :- ";
        cin>>option;
        switch(option){
            case 0:
                break;
            case 1:
                cout<<"Enter key & data :- ";
                cin>>key;
                cin>>data;
                n->data=data;
                n->key=key;
                d.appendnode(n);
                break;
            case 2:
                cout<<"Enter key & data :- ";
                cin>>key;
                cin>>data;
                n->data=data;
                n->key=key;
                d.insertfront(n);
                break;
            case 3:
                cout<<"Enter key after that node is to be inserted :- ";
                cin>>k1;
                cout<<"Enter key & data :- ";
                cin>>key;
                cin>>data;
                n->data=data;
                n->key=key;
                d.insertafter(k1,n);
                break;
            case 4:
                cout<<"Enter key of deleting node :- ";
                cin>>k1;
                d.deleteforkey(k1);
                break;
            case 5:
                cout<<"Enter key & data of updating node :- ";
                cin>>k1;
                cin>>data;
                d.updatenode(k1,data);
                break;
            case 6:
                d.print();
                break;
                

                
        }

    }while(option!=0);
}
