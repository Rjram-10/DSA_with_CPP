#include <iostream>
#include <stdlib.h>
using namespace std;
// In normal queue , when dequeue operation is applied , the used spaces can't reused as when it comes to last element front=row 
// which condition for isFull() hence can't be filled even the past spaces are clear
class Queue{
    private:
        int front,rear;
        int len; 
        int arr[0];
        int count=0;
        
    public:
        Queue(int l){
            len=l;
            arr[l];
            front=-1;
            rear=-1;
            for(int i=0;i<l;i++){
                arr[i]=0;
            }
        }
        bool isEmpty(){
            if(front==-1 & rear==-1){
                return true;
            }
            else{
                return false;
            }
        }
        bool isFull(){
            if((rear+1)%len==front){
                return true;
            }
            else {
                return false;
            }
        }
        void Enqueue(int value){
            if(isFull()){
                cout<<"Array is full"<<endl;
                return;
            }
            else if(isEmpty()){
                front=rear=0;
                count++;
            }
            else{
                rear=(rear+1)%len;
                count++;
            }
                arr[rear]=value;
        }
        int Dequeue(){
            int x=0;
            if(isEmpty()){
                return x;
            }
            else if(front==rear){
                x=arr[front];
                arr[front]=0;
                front=rear=-1;
                count--;
                return x;
            }
            else{
                x=arr[front];
                arr[front]=0;
                front=(front+1)%len;
                count--;
                return x;
            }
        }

        int element(){
            return count;
        }

        void Display(){
            for(int i=0;i<len;i++){
                cout<<arr[i]<<" ";
            }
            cout<<endl;
        }};
int main(){
    int number;
    cout<<"Enter no. of element";
    cin>>number;
    Queue q1(number);
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
                cout<<endl;
                break;
            case 3:
                if(q1.isEmpty()){
                    cout<<"Array is empty";
                }
                break;
            case 4:
                if(q1.isFull()){
                    cout<<"Array is full";
                }
                break;
            case 5:
                cout<<"The no. of element in array is :- "<<q1.element()<<endl;
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

};