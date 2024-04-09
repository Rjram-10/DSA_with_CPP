#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cout<<"Enter size of array :- ";
    cin>>n;
    
    vector<int> v;
    
    cout<<"Enter the value :- ";
    for(int i=0;i<n;i++){
        int j;
        cin>>j;
        v.push_back(j);
    }

    int current_sum=v[0];
    int max_sum=v[0];
    for(int i=0;i<v.size();i++){
        current_sum=max(v[i],current_sum+v[i]);
        max_sum=max(max_sum,current_sum);
    }
    cout<<"Maximum sum of contiguos subarray :- "<<max_sum<<endl;
}