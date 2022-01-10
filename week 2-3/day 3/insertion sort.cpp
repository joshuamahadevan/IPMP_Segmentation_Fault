#include<iostream>
#include<vector>

using namespace std;

void print( vector<int> ar){
    for( int i=0; i<ar.size(); i++ ){
        cout<<ar[i]<<" ";
    }
    cout<<endl;
}

void swap( int&a, int&b){
    int temp=a;
    a=b;
    b=temp; 
}

void insertion_sort( vector<int> &arr){
    for( int i=1; i<arr.size(); i++){
    	//arr[0:i] will be the sorted list. we have to find where the i+1 th element should be inserted and do the same.
    	int t=i;
    	
    	while( arr[t-1] > arr[t] ){
    		//swapping the element each time vs finding index and then inserting: 
    		//	each swap takes (3 instructions * n) but while inserting the system has to shift all stuff to the right and then only insert the element.
    		//	so both are equally tedious ig.. i may be wrong. idk
    		//  this kinda looks like a bubble sort implementation so i am lil confused if this is still insertion sort or not. lol ;-;
    		swap(arr[t-1],arr[t]);
    		t--;
    		if(t==0) break;
		}
    }
}

int main(){
    vector<int> arr;

    cout<<"Enter the elements of the array (Enter -1 after the last element) : ";
    while(1){
        int temp;

        cin>>temp;
        if(temp==-1) break;
        else arr.push_back(temp);
    }

    cout<<"The array before sorting is: ";
    print(arr);

    insertion_sort( arr );

    cout<<"The array after sorting is: ";
    print(arr);    
    
}
