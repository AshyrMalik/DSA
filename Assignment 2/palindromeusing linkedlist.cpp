#include <iostream>
using namespace std;


struct node{
	char ch;
	node*link=NULL;
};

class stack{
	public:
		node* head=NULL;
		
	stack(){
		head=NULL;
	}
	
	void push(char c){
		node* temp = new node;
		temp->ch = c;
		temp->link = head;
		head = temp;
	}
	
	char pop(){
		if(head != NULL){
		
 			node* temp = head;
 			char T = temp->ch;
 			head = temp->link;
			delete temp;
			return T;
		}
		else{
 			cout<<"\nStack is Empty .... Underflow Codition\n";
			return '0';
 		}	
 	} 
	
};



void palindrome(){
	
    cout<<"Enter a String "<<endl;
    string Str;
    cin>>Str;
    stack s;
    
    for(int i=0; i<Str.length(); i++){
    	cout<<"1"<<endl;
        s.push(Str[i]);
    }   
	
    for(int i=0; i<Str.length(); i++){
        char ch = s.pop();
        cout<<ch;
        if(Str[i] != ch){
            cout<<"Not a Palindrome"<<endl;
            return;
        }    	
    }

    cout<<"A palindrome"<<endl;
	
}
int main() {
    palindrome();
    return 0;
}

