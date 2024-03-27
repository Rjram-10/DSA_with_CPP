#include<iostream>
#include<stack>
using namespace std;

bool isoperator(char c){
    if(c=='+'||c=='-'||c=='/'||c=='-'||c=='^'){
        return true;
    }

    else return false;
};

int precedence(char c){
    if(c=='^') return 3;
    else if(c=='*'||c=='/') return 2;
    else if(c=='+'||c=='-') return 1;
    else return -1;
}

string InfinixtoPostfix(stack<char> s,string inix){
    string postfix;
    for(int i=0;i<inix.length();i++){
        if(inix[i]>='a' && inix[i]<='z' || 
        inix[i]>='A' && inix[i]<='Z'){
            postfix+=inix[i];
        }
        else if(inix[i]=='('){
            s.push(inix[i]);
        }
        else if(inix[i]==')'){
            while(s.top()!='(' && (!s.empty())){
                postfix+=s.top();
                s.pop();
            }
            if(s.top()=='('){
                s.pop();
            }
        }
        else if(isoperator(inix[i])){
            if(s.empty()) s.push(inix[i]);
            else{
                if(precedence(inix[i])>precedence(s.top())){
                    s.push(inix[i]);
                }
                else if(precedence(inix[i])==precedence(s.top()) && inix[i]=='^'){
                    s.push(inix[i]);
                }
                else{
                    while(!s.empty() && (precedence(inix[i])<=precedence(s.top()))){
                        postfix+=s.top();
                        s.pop();
                    }
                    s.push(inix[i]);

                }
            }
        }
        
    }
    while(!s.empty()){
        postfix+=s.top();
        s.pop();
    }
    return postfix;
};
int main(){
    string infix,postfix;
    cout<<"Enter a infix expression :- ";
    cin>>infix;
    stack<char> s;
    postfix=InfinixtoPostfix(s,infix);
    cout<<postfix;
}