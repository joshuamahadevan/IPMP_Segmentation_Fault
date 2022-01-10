#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

//2 pointer methord described in gfg
bool solve( vector<int> arr, int sum){
	sort(arr.begin(), arr.end());

    //now that the array is sorted, we can start with the 2 point methord
    int l=0, r=arr.size()-1;

    while( l<r ){
        if( arr[l]+arr[r] > sum){
            r--;
        }else if( arr[l]+arr[r] < sum){
            l++;
        }else{
            return true;
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
