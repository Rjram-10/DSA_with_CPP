#include<iostream>
#include<stack>
using namespace std;
stack<int> push(stack<int> s,int i){
    s.push(i);
    return s;
}

stack<int> pop(stack<int> s){
    s.pop();
    return s;
}

void display(stack<int> s){
    stack<int> j=s;
    while(!j.empty()){
        cout<<j.top()<<'\t';
        j.pop();
    }
    cout<<endl;
}


int main(){
    stack<int> s;
    int i,option;
    do{
        cout<<"0.Exit"<<endl;
        cout<<"1.Enqueue"<<endl;
        cout<<"2.Dequeue"<<endl;
        cout<<"3.Isempty"<<endl;
        cout<<"4.Peek"<<endl;
        cout<<"5.Display"<<endl;
        cout<<"Enter option :- ";
        cin>>option;
        switch(option){
            case 0:
                break;
            case 1:
                cout<<"Enter item to push";
                cin>>i;
                s=push(s,i);
                break;
            case 2:
                if(s.empty()) cout<<"Stack is empty";
                else{
                    int j=s.top();
                    cout<<"Dequeued item is :- "<<j<<endl;
                    s=pop(s);}
                break;
            case 3:
                if(s.empty()) cout<<"Stack is empty";
                else cout<<"Stack is not empty";
                break;
            case 4:
                if(s.empty()) cout<<"Stack is empty";
                else{
                    cout<<"Peeked item is :- "<<s.top()<<endl;
                }
                break;
            case 5:
                if(s.empty()) cout<<"Stack is empty";
                else{
                    display(s);
                }
                    break;}
    }while(option!=0);
}