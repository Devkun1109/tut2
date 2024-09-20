#include<iostream>
using namespace std;
int main(){
    int i,j,l,q=0,p=1;
    cout<<"lenght of array:";cin>>l;
    int a[l];
    int b[l];
    
    cout<<"enter the element of array :";
    for(int i=0;i<l;i++){
        cin>>a[i];
    }
    b[0]=a[0];
    for(i=0;i<l;i++){
        q=0;
        for(j=0;j<l;j++){
            if (a[i]==b[j]){
                q=1;
                break;
            }
        }
        if (q==0){
            b[p++]=a[i];
        }

    }
    for(i=0;i<p;i++){
        printf("%d ",b[i]);
    }
    cout<<"total number are :"<<p+1;
}