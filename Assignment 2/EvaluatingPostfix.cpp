#include <iostream>
using namespace std;




void Epostfix();

class stack{
	public:
	int top;
	int *arr;
	int size;
	
	stack(){
		top = -1;
		arr = new int[10];
		size = 10;
	}
	
	stack(int b){
		top = -1;
		arr = new int[b];
		size = b;
	}
	
	void push(int a){
		if(isfull()){
			top++;
			arr[top] = a;
		}
		else{
			cout << "Stack is full" << endl;
		}
	}
	
	int pop(){
		if(isEmpty()){
			int temp = top;
			top--;
			return arr[temp];
		}
		else{
			
			return 0 ;
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
	Epostfix();
}

void Epostfix(){
	cout<<"Enter a String "<<endl;
    string Str;
    cin>>Str;
    stack s(Str.length());
    
    
    for (int i=0;i<Str.length();i++){
		
		if (Str[i] =='-'||Str[i] =='+'||Str[i] =='*'||Str[i] =='/'){
		
			int a = s.pop();
			int b = s.pop();
			
			if(Str[i] =='-'){
				s.push((a-b));
				
			}
			else if(Str[i] =='+'){
				s.push((a+b));
			}
			else if(Str[i] =='*'){
				s.push((a*b));
			}
			else{
				s.push((a/b));
			}
			
			
		}
		else{
			
			int num = Str[i] - '0';
			s.push(num);
		}
	
	}
    
    cout<<s.pop();
    
	
}

