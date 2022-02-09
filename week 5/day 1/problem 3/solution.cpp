#include<iostream> 
#include<utility>

using namespace std;

pair<int,int> find_given_sum_sub_array( int*a, int n, int sum){
	int l=0, r=0, curr=0;
	
	while( l<n && r<n ){
		if( curr == sum ) return make_pair(l,r);
		if( curr < sum ) curr += a[r++];
		else curr -= a[l++];
	}
	
	return make_pair(-1,-1);
}

int main(){
	while(1){
		int n;
		cout<<"Enter the number of elements in the list: ";
		cin>>n;
		
		int a[n];
		cout<<"Enter the elements of the array: ";
		for ( int i=0; i<n; i++){cin>>a[i];}
		
		int s;
		cout<<"Enter the sum to be searched: ";
		cin>>s;
		
		pair<int,int> res = find_given_sum_sub_array(a,n,s);
		
		if( res.first == -1) cout<<"No such sub-array exists. \n";
		else {
			cout<<"The sub-array with the given sum is: ";
			for( int i=res.first; i<res.second; i++){
				cout<<a[i]<<" ";
			}
			cout<<endl;
		}
	}
}
