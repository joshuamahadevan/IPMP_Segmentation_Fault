#include<bits/stdc++.h>

using namespace std;

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
