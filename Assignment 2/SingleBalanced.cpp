#include<iostream>
using namespace std;
void checkingbrackets();

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
		
			return '0';
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

int main(){
	checkingbrackets();

}



void checkingbrackets(){
	string Str;
	
	cin>>Str;
	stack s (Str.length());
	
	for(int i = 0; i<Str.length();i++){
		
		if(Str[i]=='('){
			s.push('(');
			continue;
		}
		
		if(Str[i]==')'){
			if (s.pop()!='('){

				cout<<"Not balanced";	
				return;
			}
		}
	}
	
	if (s.top!=-1){
		cout<<"Not balanced";
		return ; 
			
	}
	cout<<"balanced";
	
	
}
