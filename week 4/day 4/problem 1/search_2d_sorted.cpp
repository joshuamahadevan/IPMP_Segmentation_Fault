#include<iostream>
#include<pair>

using namespace std;

pair< bool, pair<int,int> > find_2d_sorted( int ** a, int n, int key){

} 

int main(){
    while(1){
        int n;
        cout<<"Enter the value of n : ";
        cin>>n;

        cout<<"Enter the array elements row by row: ";
        int a[n][n];
        for( int i=0; i<n; i++){
            for( int j=0; j<n; j++){
                cin>>a[i][j];
            }
        }

        cout<<"Enter the key to search for: ";
        int k;
        cin>>k;   

        pair< bool, pair<int,int>> res=find_2d_sorted(a,n,k );

        if( res.first ){
            cout<<"Key value found at position "<<
            res.second.first<<" "<<res.second.second;
        }else{
            cout<<"The key was not found.";
        }
        cout<<"\n\n";
    }
    return 0;
}