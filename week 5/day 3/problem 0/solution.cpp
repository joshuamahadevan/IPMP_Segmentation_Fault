#include<iostream>
#include<vector>

using namespace std;

vector<int> find_leaders(int*a, int n){
    vector<int> res;
    int max=INT_MIN;
    for( int i=n-1; i>=0; i--){
        if(a[i] > max){
            max=a[i];
            res.push_back(max);
        }
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

        vector<int> res=find_leaders(a,n);
        cout<<"The leaders of the given array are: ";
        for( int i=0; i<res.size(); i++) cout<<res[i]<<" ";
        cout<<endl;
    }

}