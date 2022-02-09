#include<iostream>

using namespace std;

bool is_good( int* a, int i, int j ){
	int c=0;
	for ( int k=i; k<=j; k++){
		if(a[k]==0) c++;
		if(a[k]==1) c--;
	}
	return c==0;
}

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
		
		int max=INT_MIN, l_i, r_i;
		for( int i=0; i<n-1; i++){
			for( int j=i+1; j<n; j++){
				if(is_good(a,i,j)) {
					if(j-i > max){
						max=j-i;
						l_i=i;
						r_i=j;						
					}

				}
			}
		}
		
		if(max==INT_MIN) cout<<"No such subarray exists. \n";
		else cout<<"The largest subarray with equal number of 0's and 1's is from index "<<l_i<<" to "<<r_i<<"\n";
			
	}
	
}
