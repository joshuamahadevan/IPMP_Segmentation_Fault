#include<iostream>
#include<vector>
#include<climits>

using namespace std;

void print(vector<int> v){
	for( int i=0; i<v.size(); i++){
		cout<<v[i]<<" ";
	}
	cout<<endl;
}//function to print the vector

void swap( int &a, int &b){
	int temp=a;
	a=b;
	b=temp;
}

void selection_sort( vector<int> &v ){
	//getting v by referance as we want to make changes to v directly
	for( int p=0; p<v.size(); p++){
		int min_p=p;
		for(int i=p; i<v.size(); i++){
			if(v[i]<v[min_p]) min_p=i;
		}
		
		swap(v[min_p],v[p]);
	}
}

int main(){
	vector<int> v;
	
	//getting input for the array
	cout<<"Enter the elements of the array one by one (Enter -1 after the last element): ";
	while(1){
		int c;
		cin>>c;
		if(c==-1) break;
		v.push_back(c);
	}
	
	//printing arrray before and after sorting
	cout<<"The array before sorting is: ";
	print(v);
	
	selection_sort(v);//sorts the vector using selection sort algorithm
	
	cout<<"The array after sorting is: ";
	print(v);
		
	return 0;
}
