#include<bits/stdc++.h>

using namespace std;

vector<int> make_squares( int n ){
	vector<int> res;
	
	int i=0, s=0;
	
	do{
		res.push_back(s);
		s=pow( ++i, 2 );
	}while( i<=n );
	
	return res;
}

int count_triplets ( int n ){
	vector<int> squares=make_squares(n);
	int count=0;
	
	for( int a=1; a<n; a++){
		for( int b=a; b<n; b++ ){
			int c=squares[a]+squares[b];
			
		 	if( binary_search( squares.begin(), squares.end(), c ) )  count++;
		}
	}
	
	return count;
}

int main(){
	while(1){
		int n;
	    cout<<"Enter the value of n : ";
	    cin>>n;
	    
	    int c=0;
	    
		for( int i=1; i<=n; i++){
			for( int j=i; j<=n; j++){
				int x = i * i + j * j;
	            // third number
	            int y = sqrt(x);
	            
	            if (y * y == x && y <= n){
	            	cout<<i<<" "<<j<<" "<<y<<endl;
					c++;
				}
			}
		}
		
		cout<<c<<"\n";

	}
	
}
