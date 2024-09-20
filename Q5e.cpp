#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "Enter the size of the matrix (n x n): ";
    cin >> n;
    int size=n*(n + 1)/2;
    int arr[size];
    int matrix[n][n];
    cout << "Enter the elements of the symmetric matrix:\n";
    for(int i=0;i<n;++i) {
        for(int j=i;j<n;++j) {
            cin>>arr[i*n-(i-1)*i/2+(j-i)];
        }
    }
    cout<<"The symmetric matrix is:\n";
    for(int i=0;i<n;++i) {
        for(int j= 0;j<n;++j) {
            if(j>=i) {
                int idx=i*n-(i-1)*i/2+(j-i);
                cout<<arr[idx]<<" ";
            } 
            else {
                int idx=j*n-(j-1)*j/2+(i-j);
                cout<<arr[idx]<< " ";
            }
        }
        cout<<endl;
    }
    return 0;
}
