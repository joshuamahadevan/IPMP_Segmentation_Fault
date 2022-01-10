#include<iostream>

using namespace std;

void solve( int arr[], int s){
	int xr=0;
	for( int i=0; i<s; i++){
		xr=xr^arr[i];
	}
	
	//to get one set bit in xr, we do xr&&(~xr+1)
	
	int bit=xr&(~xr+1);
	
	int x=0,y=0;
	for( int i=0; i<s; i++){
		if(arr[i] & bit){
			x=x^arr[i];
		}else{
			y=y^arr[i];
		}
	}
	
	cout<<"The 2 unique elements are: "<<x<<" "<<y;
}

int main(){
	int s;
	
	cout<<"Enter size: ";
	cin>>s;
	
	int arr[s];
	cout<<"Enter elements of array: ";
	for( int i=0; i<s; i++){
		cin>>arr[i];
	}
	
	solve( arr, s);
}
