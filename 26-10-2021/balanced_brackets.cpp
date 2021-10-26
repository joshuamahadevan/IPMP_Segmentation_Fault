#include <bits/stdc++.h> 

using namespace std;  

bool sol( string str ){
	
	stack <char> s;
	
	for(int i=0; i<str.length(); i++){
		char ch=str[i];
		
		if( ch=='(' || ch=='{' || ch=='[' ){
			s.push(ch);
		}
		else if( ch==')' || ch=='}' || ch==']' ){
			if(s.empty()){
				cout<<"Stack is empty"<<endl;
				return false;
			}else if( s.top()=='{'&&ch=='}' || s.top()=='['&&ch==']' || s.top()=='('&&ch==')' ){
				s.pop();
				continue;
			}else{
				cout<<"Opening and closing brackets doesn't match";
				return false;
			}
		}
	}
	
	return true;
}

int main() {  
	string str;
	cin>>str;

	cout<< ( (sol(str)) ? "The given sequence is a balanced bracket sequence. " : "The given sequence is not a balanced bracket sequence. " );
	
    
    return 0;  
}  
