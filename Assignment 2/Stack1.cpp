#include <iostream>
using namespace std;

void palindrome();

class stack{
	public:
	int top;
	char *arr;
	int size;
	
	stack(){
		top = -1;
		arr = new char[10];
		size = 10;
	}
	
	stack(int b){
		top = -1;
		arr = new char[b];
		size = b;
	}
	
	void push(char a){
		if(isfull()){
			top++;
			arr[top] = a;
		}
		else{
			cout << "Stack is full" << endl;
		}
	}
	
	char pop(){
		if(isEmpty()){
			int temp = top;
			top--;
			return arr[temp];
		}
		else{
			cout << "Stack is empty" << endl;
			return '\0';
		}
	}
	
	bool isfull(){
		
		if (top<size){
			return true;
			
		}
		return false;
		
	} 
	
	bool isEmpty(){
		if(top >= 0){
			return true;
		}
		else{
			return false;
		}
	}
};

int main() {
    palindrome();
    return 0;
}

void palindrome(){
	
    cout<<"Enter a String "<<endl;
    string Str;
    cin>>Str;
    stack s(Str.length());
    
    for(int i=0; i<Str.length(); i++){
        s.push(Str[i]);
    }   
	
    for(int i=0; i<Str.length(); i++){
        char ch = s.pop();
        if(Str[i] != ch){
            cout<<"Not a Palindrome"<<endl;
            return;
        }    	
    }

    cout<<"A palindrome"<<endl;
	
}

