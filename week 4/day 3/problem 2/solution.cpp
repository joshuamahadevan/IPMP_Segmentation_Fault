#include<bits/stdc++.h>

using namespace std;

pair< int, int > find_the_pair( int* a, int n ){
	//first am going to seperate the +va and -ve numbers, 
	//then do something similar to the 2 ptr approach for finding sum.
	
	set<int> pos, neg;
	
	for( int i=0; i<n; i++){
		if( a[i] > 0 ) pos.insert(a[i]);
		else neg.insert(-a[i]);
	}
	
	set<int> :: iterator p_it=pos.begin(), n_it=neg.begin();
	int p=0,n_=0;
	int min_mod=INT_MAX;
	while ( p_it != pos.end() && n_it !=neg.end() ){
		if( abs(*(p_it)-*(n_it)) < min_mod ) {
			p=*p_it;
			n_=*n_it;
			min_mod=abs(*(p_it)-*(n_it));
		}
		
		if( *(p_it) - *(n_it) > 0 ) n_it++;
		else p_it++;
	}
	
	return make_pair(p,-n_);
	
}

int main(){
	while( 1 ){
		int n;
		cout<<"\nEnter the size of the array: ";
		cin>>n;
		
		int arr[n];
		cout<<"Enter the elements of the array: ";
		for( int i=0; i<n; i++ ){
			cin>>arr[i];
		}

		pair<int,int> res=find_the_pair( arr, n );
		
		cout<<"The pair of numbers which have sum closest to 0 is: "
			<<res.first<<" "<<res.second<<"\n\n";
 		
	}
}
