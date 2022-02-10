#include<iostream> 

using namespace std;

int max_sum_ (int*a, int n){
	//time o(n^2)
	bool available[n];
	for( int i=0; i<n; i++) available[i]=true;
	
	int res=0;
	while(1){
		int max=INT_MIN, mi=-1;
		for( int i=0; i<n; i++){
			if( !available[i] ) continue;
			if(a[i]==max) {
				int v1=0, v2=0;
				
				if(mi>1 && available[mi-1]) v1+=a[mi-1];
				if(mi<n-1 && available[mi+1]) v1+=a[mi+1];
				
				if(i>1 && available[i-1]) v2+=a[i-1];
				if(i<n-1 && available[i+1]) v2+=a[i+1];
				
				if( v2<v1 ) mi=i;
			}
			if(a[i]>max){ max=a[i]; mi=i; }
		}
		if(max==INT_MIN) break;
		res+=max;
		available[mi]=false;
		if(mi<n-1) available[mi+1]=false;
		if(mi>0) available[mi-1]=false;	
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
		
		int res=max_sum_(a,n);
		cout<<"For the given array, the maximum sum of non-adjacent elements is: "<<res<<endl;
	}
}
