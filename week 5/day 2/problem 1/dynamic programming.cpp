#include<iostream> 

using namespace std;

int max_sum_dp( int*a, int n, int*dp){
	if( n==0 ) return 0;
	if( n==1 ) return a[0];
	if( n==2 ) return (a[0]>a[1]) ? a[0] : a[1];
	
	dp[0]=a[0];
	dp[1]= (a[0]>a[1]) ? a[0] : a[1];
	
	for( int i=2; i<n; i++){
		dp[i] = ( a[i]+dp[i-2] > dp[i-1] ) ? a[i]+dp[i-1] : dp[i-1]; 
	}
	
	return dp[n-1];
}

int max_sum_ (int*a, int n){
	int dp[n];
	return max_sum_dp(a,n,dp);
}

int main(){
	while(1){
		int n;
		cout<<"Enter the number of elements in the list: ";
		cin>>n;
		
		int a[n];
		cout<<"Enter the elements of the array: ";
		for ( int i=0; i<n; i++){cin>>a[i];}
		
		int res=max_sum_(a,n);
		cout<<"For the given array, the maximum sum of non-adjacent elements is: "<<res<<endl;
	}
}
