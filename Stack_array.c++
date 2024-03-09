/* Application of Stack
1.Used  for Undo-Redo function in program by storing the progess in stack like structure
2.Balancing of symbols in programming language
3.Forward-backward function in browser
4.Multiple algorithm like Tower of Hanoi 
Program down is given showing the operation 
using namespace std; 

    class stack{  
        private:
            int top; 
            int arr[5];
        public:
            stack(){
                top=-1;
                for(int i=0;i<=4;i++){
                    arr[i]=0;
                }
            }
             bool isempty(){
                if(top==-1){
                    return true;
                }
                else{
                    return false;
                }
            }
            bool isfull(){
                if(top==4){
                    return true;
                }
                else{
                    return false;
                }
            }
            void push(int value){
                if (isfull()){
                    cout<<" Stack overflow"<<endl;
                }
                else{
                    top++;
                    arr[top]=value;
                    cout<<"Value is pushed";}
                }
            int pop(){
                if (isempty()){
                    cout<<"Stack underflow";
                }
                else{
                int poped=arr[top];
                arr[top]=0;
                top--;
                cout<<"The number "<<poped<<" is removed from stack.";
            }}
            int peek(int pos){
                cout<<"Number at "<<pos<<" is "<<arr[pos];
            }
            int count(){
                int count=0;
                for(int i=0;i<=top;i++){
                    count++;
                }
            }
            int change(int pos,int value){
                arr[pos-1]=value;
                cout<<"Value is changed";
            }
            void display(){
                if (isempty()){
                    cout<<"Stack Underflow";
                }
                else{
                    cout<<top;
                    for(int i=top;i<=0;i--){
                        cout<<arr[i]<<endl;
                    }
            }}
            // void clear(){
            //     system(cls);
            // }

    };
int main(){
    stack s1;
    int value,pos,choice;
    do{
        cout<<"1.Push"<<endl;
        cout<<"2.Pop"<<endl;
        cout<<"3.Peek"<<endl;
        cout<<"4.Change"<<endl;
        cout<<"5.Display"<<endl;
        cout<<"6.Is_empty"<<endl;
        cout<<"7.Is_Full"<<endl;
        cout<<"8.Clear"<<endl;
        cin>>choice;
        switch(choice){
            case 1:
                cout<<"Enter value";
                cin>>value;
                s1.push(value);
                break;
            case 2:
                s1.pop();
                break;
            case 3:
                cout<<"Enter number position to enter :";
                cin>>pos;
                s1.peek(pos);
                break;
            case 4:
            cout<<"Enter number position to enter :";
            cin>>pos;
            cout<<"Enter number to replace";
            cin>>value;
            s1.change(pos,value);
                break;
            case 5:
            s1.display();
                break;
            case 6:
            if(s1.isempty()){
                cout<<"Stack underflow";
            }
                break;
            case 7:
            if(s1.isfull()){
                cout<<"Stackk overflow";
            }
                break;
            // case 8:
            // s1.clear();
            default:
                cout<<"Enter another option";
                break;
    }}
}