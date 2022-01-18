#include<iostream>
#include<cmath>

using namespace std;

int no_dig(int n){
	int c=0;
	while(n){
		c++;
		n/=10;
	}
	
	return c;
}

int next_pali(int num){
	int n=num;
	int s=no_dig(n);
	if( s%2 ){
		//no. of dig is odd
		s/=2;
		n/=pow(10,s);
		
		int n1,n2;
		
		n1=n;
		int t=n/10;
		while(t){
			n1=n1*10+t%10;
			t/=10;
		}
		
		n2=n+1;
		if( no_dig(n2)==no_dig(n) ){
			int t=(n+1)/10;
			while(t){
				n2=n2*10+t%10;
				t/=10;
			}			
		}else{
			return num+2;
		}
		
		cout<<"n1= "<<n1<<" n2= "<<n2<<endl;
		if( n1>num ) return n1;
		return n2;
	}else{
		//no. of dig is even
		s/=2;
		n/=pow(10,s);
		
		int n1,n2;
		
		n1=n;
		int t=n;
		while(t){
			n1=n1*10+t%10;
			t/=10;
		}
		
		n2=n+1;
		if( no_dig(n2)==no_dig(n) ){
			int t=n+1;
			while(t){
				n2=n2*10+t%10;
				t/=10;
			}			
		}else{
			return num+2;
		}
		
		cout<<"n1= "<<n1<<" n2= "<<n2<<endl;
		if( n1>num ) return n1;
		return n2;
	}
}

int main(){
	while (1){
	    int n;
	    cout<<"Enter a number :";
	    cin>>n;
	
		cout<<"The smallest palindrome greater than n is: "<<next_pali(n)<<endl<<endl;
	}
	
}
