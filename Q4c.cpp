#include<iostream>
#include<string>
using namespace std;
bool isvowel(char c){
    c=tolower(c);
    return (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u');

    
}
string removeVowel(string str){
    string result;
    for(int i=0;i<str.length();i++){
        if(!isvowel(str[i])){
            result +=str[i];
        }
    }
    return result;
}
int main(){
    string rst;
    cout<<"Enter a string: ";
    cin>>rst;
    rst=removeVowel(rst);
    cout<<rst;
}
