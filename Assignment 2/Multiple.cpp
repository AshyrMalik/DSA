#include <iostream>
using namespace std;
void multiplebrackets();
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
			cout<<"Stack is empty"<<endl
			;return '0';
		}
	}
	char pop1(){
		
		return arr[top];
		
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
	multiplebrackets();
}

void multiplebrackets(){
	string Str;
	cin>>Str;
	char ch;
	stack s (Str.length());
	
	for(int i = 0; i<Str.length();i++){
		
		if(Str[i]=='('||Str[i]=='[' ||Str[i]=='{'){
			ch = Str[i];
			if(s.isEmpty()){
				if (ch=='['){
					char ch1=s.pop1();
					if (ch1=='('||ch1=='{'){
						cout<<"Not balanced";
						cout<<"1";
						return;		
					}						
					
				}
				else if(ch=='{'){
					char ch1=s.pop1();
					if (ch1=='('){
						cout<<"Not balanced";
						cout<<"12";
						return;		
					}						
					
				}
			}
			cout<<ch;			
			s.push(ch);
			continue;
		}
		
		if(Str[i]==')'){
			ch =s.pop();
			
			if ((ch=='{')||(ch=='[')){
				cout<<"Not balanced";
				cout<<"1";
				return;
			}
			
		}
		
		if(Str[i]=='}'){
			ch =s.pop();
			if (ch=='('||ch=='['){
				cout<<s.pop();
				cout<<"Not balanced";
				cout<<"2";
				return;
			}
			
		}
	
		
		if(Str[i]==']'){
			ch =s.pop();
			if (ch=='{'||ch=='('){
				cout<<"Not balanced";
				cout<<"4";
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
