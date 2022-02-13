#include<iostream>

using namespace std;

int best_buy(int*a, int l, int n){
    int i=l;
    while(a[i+1]<=a[i] && i<n) i++;
    cout<<"Buy at "<<i<<" "<<a[i]<<endl;
    return i;
}

int best_sell(int*a, int l, int n, int &ac){
    int i=l;
    while( a[i+1] > a[i] && i<n) i++;
    ac+=(a[i]-a[l]);
    cout<<"Sell at "<<i<<" "<<a[i]<<endl;
    return i;
}

void simulate(int*a, int n, int &ac){
    int i=0;
    while(i<n){
        int buy=best_buy(a,i,n);
        if(buy>=n-1) return;
        i=best_sell(a,buy,n,ac);
    }
}

int max_profit(int*a, int n){
    int res=0;
    simulate(a,n,res);
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