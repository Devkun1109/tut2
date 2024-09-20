#include<iostream>
using namespace std;
int main(){
    int MAX=4;
    int i,j,k=0,size=(MAX*(MAX+1))/2,a[size];
    cout<<"\nEnter elements (row major):\n";
    for(i = 0; i < size; i++){
        cin>>a[i];
        }
    cout<<"\nThe upper triangular matrix is...\n";
    for(i=0;i<MAX;i++){ 
        for(j=0;j<MAX;j++){
            if(i<=j){
                cout<<a[k++]<<" ";
            }
            else
                cout<<"0 ";
            }
    cout<<endl;}
}