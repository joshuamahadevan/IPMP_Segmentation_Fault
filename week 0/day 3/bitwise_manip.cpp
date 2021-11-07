#include<iostream>

using namespace std;

//my innitial naive solution was to maintain some sort of frequency map of each element and then traverse it again which is'nt the best wway to do it

int main(){
	int n=0;
	
	cout<<"Enter size of array: ";
	int s;
	cin>>s;
	
	cout<<"Enter the elements of the array: ";
	for( int i=0; i<s; i++ ){
		//i am not storing the values in an array.. guess this is called an in-place solution.. idk
		
		int temp;
		cin>>temp;
		
		n=n^temp; 
		
	}
	
	cout<<"The number entered odd number of times is : "<< n;
	
	return 0;	
	
}//this works because 1^1=0 and 0^0=0. so if any number is repeated even number of times, the xor becomes 0
