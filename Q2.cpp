#include<iostream>
using namespace std;
int main(){
    int arr[10]={11,13,14,16,15,12,17,18,20,19};
    int i,j,temp;
    for(i=0;i<10;i++){
        for(j=i+1;j<10;j++){
            if(arr[i]>arr[j]){
            temp=arr[i];
            arr[i]=arr[j];
            arr[j]=temp;
        }}
    }
    for(i=0;i<10;i++){
        cout<<arr[i]<<" ";
    }
}