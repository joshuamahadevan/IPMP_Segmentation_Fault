#include<iostream>
#include<vector>

using namespace std;

//template
bool solve( vector<int> arr, int sum){
	//solution here
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
