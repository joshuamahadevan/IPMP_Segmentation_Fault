#include<bits/stdc++.h>

using namespace std;

bool find_sum_0 ( int* a, int n ){
	long long int sums[n];
	sums[0]=a[0];
	for( int i=1; i<n; i++){
		sums[i]=a[i]+sums[i-1];
	}
	
	//if there is a sub array with sum 0, there will be a repeatetion in sums array.
	//as there is no limitation for the range of values in sums, we have to use auxilary memory to recognise repetetion.
	
	unordered_set<long long int> t;
	
	for( int i=0; i<n; i++){
		if( t.size() != 0 && t.find(sums[i]) != t.end() ){
			//repetetion is present
			return true;
		}else{
			t.insert( sums[i] );
		}
	}
	
	//no repetetion found
	return false;
}

int main(){
	while(1){
		int n;
	    cout<<"Enter the size of the array :";
	    cin>>n;
	
	    int a[n];
	    cout<<"Enter the elements of the array: ";
	    for( int i=0; i<n-1; i++){
	        cin>>a[i];
	    }
	
	    bool res = find_sum_0 (a,n);
	    
	    if(find_sum_0 (a,n)) cout<<"There EXISTS a subarray with sum 0 in the given arary.\n";
	    else cout<<"There is NO subarray with sum 0 in the given array. \n";
	}
	
}
