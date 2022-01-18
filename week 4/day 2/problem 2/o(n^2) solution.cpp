#include<bits/stdc++.h>

using namespace std;

pair< bool, int* > find_quad( int* a, int n, int x){
	
	unordered_map< int , pair<int,int> > mp;
	//map : sum -> indices
	//I am doing th eone without repetetions. 
	//so we basically add the first occurance of each sum to the map. 
	//if we encounter the same sum again, we donot add it to the map, hence avoiding repeatition
	
	int* res;
	res=(int*) malloc(4*sizeof(int));
	
	for ( int i=0; i<n-1; i++ ){
		for ( int j=i+1; j<n; j++ ){
			if( mp.find( a[i]+a[j] )!= mp.end() ){
				//mp has an entry with a[i]+a[j]
				if( mp.find( x-a[i]-a[j] ) != mp.end() ){
    				pair<int,int> p = mp [x- a[i] - a[j] ];
    				
    				if( p.first!=i && p.second!=i &&
    					p.first!=j && p.second!=j ){
    					    res[0]=a[i];
    					    res[1]=a[j];
    					    res[2]=a[p.first];
    					    res[3]=a[p.second];
    						return { true, res };
    					}				    
				}
			}else mp[a[i]+a[j]]= make_pair(i,j) ;
		}
	}
	
	return { false, 0 };	
}

int main(){
	while( 1 ){
		int n;
		cout<<"\nEnter the size of the array: ";
		cin>>n;
		
		int arr[n];
		cout<<"Enter the elements of the array: ";
		for( int i=0; i<n; i++ ){
			cin>>arr[i];
		}

		int x;
		cout<<"Enter the value for sum of 4 elements: ";
		cin>>x;
		
		pair<bool,int*> res=find_quad( arr, n, x );
		
		if( res.first ){
			cout<<"The quad that sums to the given key value is: ";
			for( int i=0; i<4; i++){
				cout<< res.second[i] <<" ";
			}
			cout<<endl;
		}else{
			cout<<"A quad with sum as "<<x<<" does not exist in the array.\n";
		}
		
		cout<<endl;
 		
	}
}
