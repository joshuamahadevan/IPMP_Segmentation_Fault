#include<bits/stdc++.h>

using namespace std;

pair< bool, int* > find_quad( int* a, int n, int x){
	sort(a,a+n); //2-ptr works only oon sorted lists
	int* res;
	res=(int*) malloc(4*sizeof(int)); //gotta malloc because this has to survive even after the function is done executing

	for( int i=0; i<n-3; i++){
		for ( int j=i+1; j<n-2; j++){
			int k=x-a[i]-a[j];
			
			//now we have to search for a pair with sum k from j+1 to n-1 suing 2-ptr methord
			
			int l=j+1, r=n-1;
			while( l<r ){
				if( a[l]+a[r] == k ) {
					res[0]=a[i];
					res[1]=a[j];
					res[2]=a[l];
					res[3]=a[r];
					return make_pair(true, res);
				}else if ( a[l]+a[r] > k ) r--;
				else l++;
			} 
		}
	}
	
	return make_pair(false, res);
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
			free(res.second);
			cout<<endl;
		}else{
			cout<<"A quad with sum as "<<x<<" does not exist in the array.\n";
			free(res.second);
		}
		
		cout<<endl;
 		
	}
}
