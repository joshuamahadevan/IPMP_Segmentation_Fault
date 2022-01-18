#include<bits/stdc++.h>

using namespace std;

struct e{
	int first, 
		second, 
		sum;
};

//custom compare function for sorting sums
bool compare_e( struct e e1, struct e e2 ){
	return e1.sum<e2.sum; 
}

bool noCommon( struct e e1, struct e e2 ){
	return (e1.first!=e2.first) && 
		   (e1.first!=e2.second) && 
		   (e1.second!=e2.first) && 
		   (e1.second!=e2.second) ;
}

pair< bool, int* > find_quad( int* a, int n, int x){
	
	//creating sums array
	vector<struct e> sums;
	for( int i=0; i<n-1; i++){
		for( int j=i+1; j<n; j++){
			struct e temp;
			temp.first=i;
			temp.second=j;
			temp.sum=a[i]+a[j];
			sums.push_back(temp);
		}
	}
	
	//sorting so that we can perform 2-ptr methord
	sort( sums.begin(), sums.end(), compare_e);
	
	int* res;
	res=(int*) malloc(4*sizeof(int)); //gotta malloc because this has to survive even after the function is done executing
	
	//2-ptr methord
	int l=0, r=sums.size()-1;	
	while( l<r ){
		if( sums[l].sum+sums[r].sum == x && noCommon( sums[l], sums[r] ) ){
			res[0]=a[sums[l].first];
			res[1]=a[sums[l].second];
			res[2]=a[sums[r].first];
			res[3]=a[sums[r].second];
			//quad is found, so we return it with true tag
			return make_pair( true, res );
		}else if( sums[l].sum+sums[r].sum > x ) r--;
		else l++;
	}
	
	return make_pair(false,res);
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

		int x;
		cout<<"Enter the value for sum of 4 elements: ";
		cin>>x;
		
		pair<bool,int*> res=find_quad( arr, n, x );
		
		if( res.first ){
			cout<<"The quad that sums to the given key value is: ";
			for( int i=0; i<4; i++){
				cout<< res.second[i] <<" ";
			}
			free(res.second);
			cout<<endl;
		}else{
			cout<<"A quad with sum as "<<x<<" does not exist in the array.\n";
			free(res.second);
		}
		
		cout<<endl;
 		
	}
}
