#include<iostream>
#include<vector>

using namespace std;

void swap( int &a, int &b){
	int temp=a;
	a=b;
	b=temp;
}

void print(vector<int> v){
	for( int i=0; i<v.size(); i++){
		cout<<v[i]<<" ";
	}
	cout<<endl;
}//function to print the vector

void bubble_sort( vector<int> &v ){
	//getting v by referance as we want to make changes to v directly
	while(1){
		bool flag=true;
		
		for(int i=0; i+1<v.size(); i++){
			if(v[i]>v[i+1]){
				//elements not in order
				swap(v[i], v[i+1]);
				flag=false;
			}
		}
		
		if(flag) break; //if no change is made to the vector in one full pass, the vector is sorted.
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
	
	bubble_sort(v);//sorts the vector using bubble sort algorithm
	
	cout<<"The array after sorting is: ";
	print(v);
		
	return 0;
}
