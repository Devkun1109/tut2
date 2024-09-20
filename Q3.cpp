#include<iostream>
using namespace std;
int main(){
    int i;
    int arr[10]={11,12,13,14,16,17,18,19,20,21};
    for(i=0;i<9;i++){
        if(arr[i+1]-arr[i]==2){
            cout<<"missing number is "<<arr[i]+1;
            break;
        }
    }
}