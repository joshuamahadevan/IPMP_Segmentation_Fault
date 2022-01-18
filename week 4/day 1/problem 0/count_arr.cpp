#include<iostream>

using namespace std;

void repeating_elements(int* a, int n){
    int count[n];

    for( int i=0; i<n; i++){
        count[i]=0;
    }

    for (int i=0; i<n+2; i++)
    {
        count[a[i]-1]++;
    }
	
    cout<<"The repeated elements are: ";
    for(int i=0; i<n; i++){
        if( count[i] > 1 ) cout<<i+1<<" ";
    }
    
}

int main(){
    int n;
    cout<<"Enter the value of n (array eles. go from 1 to n with 2 repeated values) :";
    cin>>n;

    int a[n+2];
    cout<<"Enter the "<<n+2<<" array elements: ";
    for( int i=0; i<n+2; i++){
        cin>>a[i];
    }

    repeating_elements(a,n);
}
