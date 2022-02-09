#include<iostream>
#include<vector>

using namespace std;


int main(){
	while(1){
		int n;
		cout<<"Enter the size of the array: ";
		cin>>n;
		
		int a[n];
		cout<<"Enter the elements of the array: ";
		for( int i=0; i<n; i++){
			cin>>a[i];
		}
		
		int c_0=0, c_1=0;
		int hash[n+1];
		hash[0]=0;
		int min=0, max=0;
		//loop to create hash which has pre-sum of elements to that index
		for( int i=0; i<n; i++){
			if(a[i]==1) c_1++;
			else c_0++;
			hash[i+1]=c_0-c_1;
			if( hash[i+1] > max ) max=hash[i+1];
			if( hash[i+1] < min ) min=hash[i+1];
		}
		
		int index[max-min+1];
		//loop to find repeated elements in hash using index as hash
		for( int i=0; i<max-min+1; i++){
			index[i]=INT_MIN;
		}
		int size=-1, l_i=-1, r_i=-1;
		for( int i=0; i<n+1; i++){
			if( index[hash[i]-min] == INT_MIN ){ index[hash[i]-min]=i; continue; }
			//now the value already exists in hash
			int j=index[hash[i]-min];
				
			if( i-j > size ){
				l_i=j; r_i=i;
				size=i-j;
			}
		}
		
		if( l_i==-1 && r_i==-1 ){ cout<<"No such subarray. \n"; continue;}
		cout<<"sub-arary from index "<<l_i<<" to  "<<r_i-1<<" is the largest one with equal 0's and 1's\n";
	}
}
