#include<bits/stdc++.h>

using namespace std;

int b_search_( vector<bool> a, int l, int r ){

	if( l==r ) return l;
	
	int mid=(l+r)/2;
//	cout<<"b_search "<<l<<" "<<r<<" mid= "<<mid<<endl;	
	if(a[mid]){
		//a[mid]=1 -> shld move r to mid
		return b_search_(a,l,mid);
	}else{
		//a[mid]=0 -> shld move l to mid
		return b_search_ (a,mid+1,r);
	}
}

int lower_bound_1( vector<bool> a){
//	cout<<"lb\n";
	return b_search_ (a,0,a.size()-1);
} 

int main(){
	while( 1 ){
		cout<<"Enter the number of rows and columns: ";
		
		int n,m;
		cin>>n>>m;
		vector< vector<bool> > arr;
	
		
		cout<<"Enter the rows one by one: ";
		for( int i=0; i<n; i++ ){
			vector< bool > t;
			for( int j=0; j<m; j++ ){
				bool x;
				cin>>x;
				t.push_back(x);
			}
			arr.push_back(t);
		}
		
		int min=INT_MAX, ind=-1;
		
		for( int i=0; i<arr.size(); i++){
			int t=lower_bound_1(arr[i]);
//			cout<<"Lower bound for "<<i+1<<" th row is: "<<t<<endl;
			if( t<min ) {
				min=t;
				ind=i;
			}
		}
		
		cout<<ind<<endl<<endl;
		
		
	}
}
