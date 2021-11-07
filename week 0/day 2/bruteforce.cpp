#include<iostream>
#include<vector>

using namespace std;

//brute force approach
//o(n^2) solution
bool solve( vector<int> arr, int sum){
	for( int i=0; i<arr.size(); i++){
		for( int j=i+1; j<arr.size(); j++){
			if( arr[i]+arr[j]==sum) return true;
		}
	}
	return false;
}

int main(){
	while(1){
		int n;			
		cout<<"Enter the size of the array: ";
		cin>>n;
		
		vector<int> arr;
		
		cout<<"Enter the elements of the array: ";
		
		for( int i=0; i<n; i++){
			int temp;
			cin>>temp;
			
			arr.push_back(temp);
		}
		
		cout<<"Enter the sum: ";
		
		int sum; 
		cin>>sum;
		
		if( solve( arr,sum ) ) cout<<"Found a pair"<<endl <<endl;
		else cout<<"No pair found"<<endl <<endl;
	}

	
}
