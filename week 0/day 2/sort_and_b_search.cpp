#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

//sort and binary search approach
//will sort the array using sort fn (uses quick sort) and b.s. for sum-arr[i] element for each i. if one exists return true else false
bool solve( vector<int> arr, int sum){
	sort(arr.begin(), arr.end());
	
	for( int i=0; i<arr.size(); i++){
		
	}
	
	for( int i=0; i<arr.size(); i++){
		if(binary_search( arr.begin(), arr.end(), sum-arr[i]) ){
			if( sum-arr[i]==arr[i] ){
				//we shld have 2 values of arr[i] in arr to have a valid pair
				vector<int>::iterator l1, l2;
				l1=lower_bound(arr.begin(), arr.end(), sum-arr[i]);
				l2=upper_bound(arr.begin(), arr.end(), sum-arr[i]);
				
				if( l1!= l2 ) return true;
			}
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
