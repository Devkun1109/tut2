#include<iostream>
using namespace std;
int main(){ 
    int MAX=5;
    int i,j, a[MAX];
   cout<<"enter the elements(row major):"<<endl;
    for(i = 0;i < MAX;i++){
        cin>>a[i];
        }
    cout<<"the Matrix is "<<endl;
    for(i = 0; i < MAX; i++){
        for(j = 0; j < MAX; j++){
            if(i==j)
                cout<<a[i]<<" ";
            else
            cout<<"0 ";
        }
        cout<<endl;
    }
    return 0;
}