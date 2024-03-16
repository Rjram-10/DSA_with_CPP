#include<iostream>
#include<stdlib.h>
using namespace std;
class Queue{
    private:
        int front;
        int rear;
        int arr[5];
    public:
        Queue(){
            front=-1;
            rear=-1;
            for(int i=0;i<sizeof(arr);i++){
                arr[i]=0;
            }
        }
        bool Isempty(){
            if(front==-1 && rear==-1){
                return true;
            }
            else{
                return false;
            }
        }
        bool Isfull(){
            if((rear==front)!=-1 && (rear==front)!=0){
                return true;
            }
            else {
                return true;
            }
        }
        void Enqueue(int value){
            if(Isfull()){
                cout<<"Array is full"<<endl;
            }
            else if(Isempty()){
                    front=0;
                    rear=0;
                    arr[rear]=value;
                }
            
            else{
                rear++;
                arr[rear]=value;
            }
        }
        int Dequeue(){
            if(Isempty()){
                cout<<"Array is empty"<<endl;
                return 0;
            }
            else if((front==rear) && (rear==0)){
                int x=arr[rear];
                front=0;
                rear=0;
                return x;
            }
            else{
                int x=arr[rear];
                rear--;
            }
        }
        int count(){
            if(Isempty()){
                return 0;
            }
            else{
                int x=(rear-front)+1;
                return x;}
        }
        void Display(){
            for(int i=0;i<sizeof(arr);i++){
                cout<<arr[i]<<" ";
            }
            cout<<endl;
        }


};
int main(){
    Queue q1;
    int option,value;
    do{
        cout<<"0.Quit"<<endl;
        cout<<"1.Enqueue()"<<endl;
        cout<<"2.Dequeue()"<<endl;
        cout<<"3.Isempty()"<<endl;
        cout<<"4.Isfull()"<<endl;
        cout<<"5.Count()"<<endl;
        cout<<"6.Display()"<<endl;
        cout<<"7.Clear()"<<endl;
        
        cout<<"Enter your option :- ";
        cin>>option;
        
        switch(option){
            case 1:
                cout<<"Enter number to be enqueued :- ";
                cin>>value;
                q1.Enqueue(value);
                break;
            case 2:
                cout<<"Number dequeued is :- "<<q1.Dequeue();
                break;
            case 3:
                if(q1.Isempty()){
                    cout<<"Array is empty";
                }
                break;
            case 4:
                if(q1.Isfull()){
                    cout<<"Array is full";
                }
                break;
            case 5:
                cout<<"The no. of element in array is :- "<<q1.count()<<endl;
                break;
            case 6:
                cout<<"The elements are :- "<<endl;
                q1.Display();
                break;
            case 7:
                system("CLS");
                break;
            default:
                cout<<"Enter proper option :- "<<endl;
                break;
        }

    }while(option!=0);
    return 0;

}