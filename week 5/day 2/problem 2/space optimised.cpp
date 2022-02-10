#include<iostream> 

using namespace std;

int rain_water( int*a, int n){
	int left_max=0, right_max=0;
	int lo=0, hi=n-1;
	
	while(lo<hi){
		if(a[lo]<a[hi]){
			
		}else{
			
		}
	}
}

int main(){
	while(1){
		int n;
		cout<<"Enter the number of elements in the list: ";
		cin>>n;
		
		int a[n];
		cout<<"Enter the elements of the array: ";
		for ( int i=0; i<n; i++){cin>>a[i];}
		
		int res=rain_water(a,n);
		cout<<"Volume of water trapped after raining is: "<<res<<endl;
	}
}
