#include<iostream> 

using namespace std;

int max_sum_ (int*a, int n){
	int incl=a[0], excl=0;
	
	for( int i=1; i<n; i++){
		int temp=incl;
		incl=excl+a[i];
		excl=(temp>excl)?temp:excl;
	}
	
	return (incl>excl)?incl:excl;
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
