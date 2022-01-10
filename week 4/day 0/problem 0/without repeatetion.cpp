#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

void print(vector<int>arr ){
	cout<<endl;
	for( int i=0; i<arr.size(); i++){
		cout<<arr[i]<<" ";
	}
}

void solve( vector<int> ar1, vector<int>ar2 ){
	int i1=0, i2=0;
	
	//union
	
	cout<<endl<<endl<<"Union of the 2 lists is: ";
	
	while( i1<ar1.size() && i2<ar2.size() ){
		if(ar1[i1] > ar2[i2] ){
			cout<<ar2[i2++]<<" ";
			while(ar2[i2]==ar2[i2+1]){
				i2++;
			}
		}else if( ar1[i1] == ar2[i2] ){
			cout<<ar1[i1++]<<" ";
			i2++;
			while(ar1[i1]==ar1[i1+1]){
				i1++;
			}
			while(ar2[i2]==ar2[i2+1]){
				i2++;
			}
		}else{
			//ar1[i1] < ar2[i2]
			cout<<ar1[i1++]<<" ";
			while(ar1[i1]==ar1[i1+1]){
				i1++;
			}
		}
	}
	while( i1<ar1.size() ){
		cout<<ar1[i1++]<<" ";
	}
	while( i2<ar2.size() ){
		cout<<ar2[i2++]<<" ";
	}
	
	//intersection
	i1=0,i2=0;
	cout<<endl<<endl<<"Intersection of the 2 lists is: ";
	
	while( i1<ar1.size() && i2<ar2.size() ){
		if(ar1[i1] > ar2[i2] ){
			i2++;
		}else if( ar1[i1] == ar2[i2] ){
			cout<<ar1[i1++]<<" ";
			i2++;
		}else{
			//ar1[i1] < ar2[i2]
			i1++;
		}
	}
	
}

int main(){
	vector<int> arr1, arr2;
	
	int temp;
	cout<<"Enter the values of the first array (Enter -1 at the end to finish the input sequence) : ";
	while(1){
		cin>>temp;
		if(temp==-1) break;
		arr1.push_back(temp);
	}
	cout<<endl<<"Enter the values of the second array (Enter -1 at the end to finish the input sequence) : ";
	while(1){
		cin>>temp;
		if(temp==-1) break;
		arr2.push_back(temp);
	}
	
	sort(arr1.begin(), arr1.end());
	sort(arr2.begin(), arr2.end());
	
	cout<<endl<<"The 2 sorted lsits are: ";
	print(arr1);
	print(arr2);
	
	solve(arr1,arr2);
	
	
}
