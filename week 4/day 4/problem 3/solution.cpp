#include<bits/stdc++.h>

using namespace std;


int main(){
	while( 1 ){
		int n;
		cout<<"Enter the size of the array: ";
		cin>>n;	
		
		int a[n];
		cout<<"Enter the elements of the array: ";
		for( int i=0; i<n; i++){
			cin>>a[i];
		}
 		
 		//first partition at 1 => 0->0 vs 1->n-1
 		//final partition at n-2 => 0->n-3 vs n-1->n-1
		int r_sum=0;
		for( int i=1; i<n; i++){
			r_sum+=a[i];
		}
		int l_sum=0;
		
		
		for( int i=1; i<=n-2; i++){
			l_sum+=a[i-1];
			r_sum-=a[i];
			
			if(l_sum==r_sum) {
				cout<<"The required partition is: "<<a[i]<<endl;
				break;
			}
		}
 		
	}
}
