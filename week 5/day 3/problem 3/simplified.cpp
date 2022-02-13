#include<iostream>

using namespace std;

int max_profit(int*a, int n){
    int res=0;
    for( int i=0; i<n-1; i++){
        if(a[i]<a[i+1]) res+=a[i+1]-a[i];
    }
    return res;
}

int main(){
    while(1){
        int n;
        cout<<"Enter the size of the array: ";
        cin>>n;

        int a[n];
        cout<<"Enter the elements of the array: ";
        for( int i=0;i <n; i++) cin>>a[i];

        int res=max_profit(a,n);
        cout<<"The max profit which can be earned from this market data is: "<<res<<endl;
    }
}