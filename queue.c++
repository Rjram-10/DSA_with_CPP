#include<iostream>
#include<queue>
using namespace std;

queue<int> enqueue(queue<int> s,int k){
    s.push(k);
    return s;
}

queue<int> dequeue(queue<int> s){
    s.pop();
    return s;
}

void peek(queue<int> q){
    if(q.empty()) cout<<"Nothing to peek"<<endl;
    else{
        cout<<"Peeked on queue and found :- "<<q.front()<<endl;
    }
}

void print(queue<int> q){
    queue<int> s=q;
    if(s.empty()) cout<<"No element in queue"<<endl;
    else{
        do{
            cout<<s.front()<<'\t';
            s.pop();
        }while(!s.empty());
        cout<<endl;
    }

}

int main(){
    queue<int> q;
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
                cout<<"Enter number to push :- ";
                cin>>i;
                q=enqueue(q,i);
                break;
            case 2:
                cout<<"Dequeued item is :- "<<q.front()<<endl;
                q=dequeue(q);
                break;
            case 3:
                if(q.empty()) cout<<"It's empty"<<endl;
                else cout<<"It's not empty";
                break;
            case 4:
                peek(q);
                break;
            case 5:
                print(q);
                break;
        }
    }while(option!=0);
}