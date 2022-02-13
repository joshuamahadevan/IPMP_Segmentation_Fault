#include<iostream>

using namespace std;

int find_min_ind(int*a, int n){
    int min=INT_MAX, ind=-1;
    for( int i=0; i<n; i++){
        if (a[i]<min){
            min=a[i];
            ind=i;
        } 
    }
    return ind;
}

void k_max_elements(int*a, int n, int k, int* res){
    for( int i=0; i<k; i++) res[i]=a[i];

    int min_i=find_min_ind(res,k);
    for( int i=k; i<n; i++){
        if(a[i]>res[min_i]) {
            res[min_i]=a[i];
            min_i=find_min_ind(res,k);
        }
    }

    //if result should be sorted...
    //sort(res,res+k, greater<int>)
}

int main(){
    while(1){
        int n;
        cout<<"Enter the size of the array: ";
        cin>>n;

        int a[n];
        cout<<"Enter the elements of the array: ";
        for( int i=0;i <n; i++) cin>>a[i];

        int k;
        cout<<"Enter the k max elements you want to be displayed: ";
        cin>>k;

        int res[k];
        k_max_elements(a,n,k,res);
        cout<<"The k max elements of the array are: ";
        for(int i=0; i<k; i++) cout<<res[i]<<" ";
        cout<<endl;
    }

}