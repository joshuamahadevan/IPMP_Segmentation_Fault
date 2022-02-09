#include<iostream>
#include<string>
#include<set>

using namespace std;

bool is_all_unique( string s ){
	set<char> h;
	
	for( int i=0; i<s.size(); i++){
		if( h.find(s[i]) != h.end() ) return false;
		else h.insert(s[i]);
	}
	
	return true;
}

int main(){
	while(1){
		string s;
		cout<<"Enter a string: ";
		cin>>s;
		
		if( is_all_unique(s) ){
			cout<<"The entered string has all unique characters. \n";
		}else{
			cout<<"The entered string has some repeating characters. \n";
		}
	}
}
