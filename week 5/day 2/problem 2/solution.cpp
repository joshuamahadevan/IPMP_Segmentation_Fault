#include<iostream> 

using namespace std;

int rain_water( int*a, int n){
	int l[n], r[n];
	
	int max=INT_MIN;
	for( int i=0; i<n; i++){
		if(a[i]>max) max=a[i];
		l[i]=max;
	}
	max=INT_MIN;
	for( int i=n-1; i>=0; i--){
		if(a[i]>max) max=a[i];
		r[i]=max;
	}
	
	int res=0;
	for( int i=0; i<n; i++){
		int wh=(l[i]<r[i])?l[i]:r[i];
		res+=wh-a[i];
	}
	return res;
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
