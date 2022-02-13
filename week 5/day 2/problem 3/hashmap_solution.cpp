#include<iostream>
#include<map>

using namespace std;

int majority( int*a, int n){
	map<int, int> m;
	for( int i=0; i<n; i++){
		m[a[i]]++;
		if(m[a[i]] > n/2 ) return a[i];
	}
	return INT_MIN;
}

int main(){
	while(1){
		int n;
		cout<<"Enter the number of elements of the array: ";
		cin>>n;

		int a[n];
		cout<<"Enter the elements of the array: ";
		for( int i=0; i<n; i++) cin>>a[i];

		int res=majority(a,n);
		if( res==INT_MIN ) cout<<"There is no majority element. \n";
		else cout<<"The majority element in the array is: "<<res<<endl;
	}
}
