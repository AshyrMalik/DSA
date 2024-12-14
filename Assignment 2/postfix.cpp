#include <iostream>
using namespace std;




void postfix();

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
	postfix();
	
	
	
}


void postfix(){
	
	cout<<"Enter a String "<<endl;
    string Str;
    cin>>Str;
    stack s(Str.length());
    string output="";
	for (int i=0;i<Str.length();i++){
		
		if (Str[i] =='-'||Str[i] =='+'||Str[i] =='*'||Str[i] =='('){
			cout<<"1"<<endl;
			switch(Str[i]){
				cout<<"1"<<endl;
				case '(':
					s.push('(');
					
					break;
				case '-':
					
					if(s.isEmpty()){
						char ch =s.pop1();
						while(s.isEmpty()&&ch!='('){
							output+=s.pop();
							ch =s.pop1();
						}
						s.push('-');
					}
					
					else{
						s.push('-');	
					}
					
					break;
				
				case '+':
					if(s.isEmpty()){
						char ch =s.pop1();
						while(s.isEmpty()&&ch!='('){
							output+=s.pop();
							ch =s.pop1();
						}
						s.push('+');
					}
					
					else{
						s.push('+');	
					}
					
					break;
					
				case '*':
					
					s.push('*');
					
					break;
			}	
		}
		else if(Str[i]==')'){
			
			char ch=s.pop();
			
			while(ch!='('){
				output+=ch;
				ch=s.pop();	
			}
		
		}
			
		else{
		
			output+=Str[i];
			
		}
}
	while(s.isEmpty()){
		output+=s.pop();
		
	}
	cout<<output;
}
