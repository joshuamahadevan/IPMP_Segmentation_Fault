#include<iostream>
#include<utility>

using namespace std;
/*
00 01 02 03
10 11 12 13 
20 21 22 23
30 31 32 33 
*/
pair< bool, pair<int,int> > find_2d_sorted( int a[4][4], int n, int key){
    int i=0, j=0;

    //Traverse the array row by row from left to right.
    //if next ele if greater || j=n-1 , shift down. -> C1
        //C1 & i=n-1: return false
    //if current ele is greater, shift left ->C2
        //C2 & we are at j=0, return false
    //if none of these, shift right
    while(1){
        if( a[i][j] == key ) return make_pair(true, make_pair(i,j));

        if( a[i][j] > key ){
            if( j == 0 ) return make_pair(false,make_pair(-1,-1));
            j--;
            continue;
        }
        //now a[i][j]<key 
        if( a[i][j+1] > key || j==n-1) i++;
        else j++;

        if( i==n || j==n ) return make_pair(false,make_pair(-1,-1));
    }
} 

int main(){
	cout<<"Enter the 4x4 array elements row by row: \n";
    int a[4][4];
    for( int i=0; i<4; i++){
    	for( int j=0; j<4; j++ ){
    		cin>>a[i][j];
		}	
	}

   
    while(1){
     cout<<"Enter the key to search for: ";
        int k;
        cin>>k;   

        pair< bool, pair<int,int> > res=find_2d_sorted(a,4,k );

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
