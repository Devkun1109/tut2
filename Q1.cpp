#include<iostream>
using namespace std;
int main(){
    int arr[10]={11,12,13,14,15,16,17,18,19,20};
    int min,max,mid;
    int num;
    cout<<"enter the number :";cin>>num;
    min=0;
    max=9;
    while(max>=min){
        mid=(min+max)/2;
        if(num==arr[mid]){
            cout<<"Number "<<num<<" is found at index "<<mid<<endl;
            return 0;
        }
        else if(num>arr[mid]){
            min=mid+1;
        }
        else{
            max=mid-1;
        }
    }
    cout<<"number not found in given array";
    return 0;
}
