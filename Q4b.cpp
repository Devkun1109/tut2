#include<iostream>
#include<string>
using namespace std;
int main(){
    string s="Hello";
    string rs;
    for(int i=s.length()-1;i>=0;i--){
        rs+=s[i];
    }
    cout<<rs<<endl;
}