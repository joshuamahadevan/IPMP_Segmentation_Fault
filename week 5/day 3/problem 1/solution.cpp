#include<iostream>

using namespace std;

int find_max_repeating(int*a, int n){
    //using array as hash 
    for(int i=0; i<n; i++){
        a[a[i]%n]+=n;
    }
    //which ever i has max value of a[i]/n is max repeated element
    int res=-1, max=-1;
    for( int i=0; i<n; i++){
        int temp=a[i]/n;
        if( temp>max ) { max=temp; res=i;}
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

        int res=find_max_repeating(a,n);
        cout<<"The max repeating element of the array is: "<<res<<endl;
    }

}