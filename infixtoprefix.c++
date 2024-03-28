#include<iostream>
#include<stack>
#include<algorithm>
using namespace std;
int precedence(char c){
    if(c=='^') return 3;
    else if(c=='*' || c=='/') return 2;
    else if(c=='+' || c=='-') return 1;
    else return -1;
}
string infixtoprefix(stack<char> s,string infix){
    string prefix;
    reverse(infix.begin(),infix.end());
    for(int i=0;i<infix.length();i++){
        if(infix[i]=='(') infix[i]=')';
        else if(infix[i]==')') infix[i]='(';
    }
    for(int i=0;i<infix.length();i++){
        if(infix[i]>='a' && infix[i]<='z' || infix[i]>='A' && infix[i]<='Z'){
            prefix+=infix[i];
        }
        else if(infix[i]=='(') s.push(infix[i]);
        else if(infix[i]==')'){
            while(!s.empty() && s.top()!='('){
                prefix+=s.top();
                s.pop();
            }
            if(s.top()=='(') s.pop();
        }
        else {
            if(s.empty()) s.push(infix[i]);
            else if(precedence(infix[i])>precedence(s.top())){
                s.push(infix[i]);
            }
            else if(precedence(infix[i])==precedence(s.top()) && s.top()=='^'){
                while(!s.empty()&&s.top()=='^'){
                    prefix+=s.top();
                    s.pop();
                }
                s.push(infix[i]);
            }
            else if(precedence(infix[i])==precedence(s.top())){
                s.push(infix[i]);
            }
            else{
                while(!s.empty() && precedence(infix[i])<precedence(s.top())){
                    prefix+=s.top();
                    s.pop();
                }
                s.push(infix[i]);
            }

        }
    }
    while(!s.empty()){
        prefix+=s.top();
        s.pop();
    }
    reverse(prefix.begin(),prefix.end());

    
    return prefix;
}
int main(){
    string infix,prefix;
    cout<<"Enter the expression :- ";
    cin>>infix;
    stack<char> stack;
    prefix=infixtoprefix(stack,infix);
    cout<<"The prefix expression is :- "<<prefix;
}