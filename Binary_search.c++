#include<iostream>
using namespace std;
int binarysearch(int arr[],int left,int right,int x){
    
    while(left<=right){
    
        int mid=left+(right-left)/2;
    
        if(arr[mid]==x){
            return mid;
        }
    
        else if (x<arr[mid])
        {
            right=mid-1;
        }
        else{
            left=mid+1;
        }
        }
    return -1;
};
int main(){
    int num;
    int arr[10]={0,1,2,3,4,5,6,7,8,9};
    int output;
    cout<<"Enter the number to search :- ";
    cin>>num;

    output=binarysearch(arr,0,9,num);
    if(output==-1){
        cout<<"Not found in array"<<endl;
    }
    else{
        cout<<"Found at "<<output<<"index"<<endl;
    }

};