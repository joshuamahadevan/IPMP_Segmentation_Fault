#include<iostream>

using namespace std;

void display( bool** a , int n, int m ){
	for( int i=0; i<n; i++){
		for( int j=0; j<m; j++){
			cout<<a[i][j]<<" ";
		}
		cout<<endl;
	}
}

void modify( bool** a, int n, int m){
	bool row_0=false, col_0=false;
	
	for( int i=0; i<n; i++){
		for( int j=0; j<m; j++){
			bool e=a[i][j];
			if( i==0 ) row_0 = row_0 || e;
			if( j==0 ) col_0= col_0 || e;
			
			if( i!=0 && j!=0 ){
				//element is not in the root column/row
				a[i][0] = a[i][0] || e;
				a[0][j] = a[0][j] || e;
			}
		}
	}
	
	for( int i=1; i<n; i++){
		for( int j=1; j<m; j++){
			if( a[i][0]  || a[0][j] ) a[i][j]=1;
		}
	}
	
	if(row_0){
		for( int j=0; j<m; j++){
			a[0][j]=1;
		}
	}
	if(col_0){
		for( int i=0; i<n; i++){
			a[i][0]=1;
		}
	}
}

int main(){
	while(1){
		int n,m;
		
		cout<<"Enter the dimensions of the  2d bool matrix: ";
		cin>>n>>m;
		
		bool *a[n];
		for( int i=0; i<n; i++){
			a[i]=new bool[m];
		}
		cout<<"Enter the elements of the "<<n<<" x "<<m<<" matrix row by row: \n";
		
		for( int i=0; i<n; i++){
			for( int j=0; j<n; j++){
				cin>>a[i][j];
			}
		}
		
		cout<<"The entered matrix is: \n";
		modify( a, n, m );
		display( a, n, m);
			
	}
	
}
