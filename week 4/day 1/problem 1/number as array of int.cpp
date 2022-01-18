#include<iostream>
#include<vector>

using namespace std;

bool greater_than( vector<int> x, vector<int> y){
	//returns true if y is greater tahn x
	if ( y.size() > x.size() ) return true;
	for( int i=0; i<x.size() ; i++){
		if( y[i]==x[i] ) continue;
		if( y[i] > x[i] ) return true;
		else return false;
	}
	return false;
}

vector<int> left_to_right( vector<int> num ){
	int s=num.size()/2;
	int n=num.size();
	
	for( int i=0; i<s; i++ ){
		num[i]=num[n-1-i];
	}
	
}

vector<int> next_pali( vector<int> num ){
	
}

vector<int> all_9( vector<int> num ){
	
}

vector<int> solve( vector<int> num ){
	
}

int main(){
	while (1){
	    vector<int> arr;
	    cout<<"Enter the number ( each digit should be space seperated & enter -1 to end the input sequence ) : ";
	    
	    while(1){
	    	int t;
			cin>>t;
			if(t==-1) break;
			arr.push_back(t);
		}	
		
		cout<<"The smallest palindrome greater than n is: ";
		vector<int> res=solve(arr);
		for( int i =0; i<res.size() ;i++ ){
			cout<<res[i]<<" ";
		}
		cout<<endl<<endl;
	}
	
}
