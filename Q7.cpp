/*Let A[1 …. n] be an array of n real numbers. A pair (A[i], A[j ]) is said to be an inversion
if these numbers are out of order, i.e., i < j but A[i]>A[j ]. Write a program to count the number 
of inversions in an array.*/
#include<iostream>
using namespace std;
int main(){
    int n, inv = 0;
    cout<<"Enter the number of elements in the array: ";
    cin>>n;
    int A[n];
    cout<<"Enter the elements of the array: ";
    for(int i = 0; i < n; i++)
        cin>>A[i];
    for(int i = 0; i < n; i++){
        for(int j = i + 1; j < n; j++){
            if(A[i] > A[j]){
                inv++;
                }
            }
        }
    cout<<"Number of inversions: "<<inv;
    }

