#include <iostream>
using namespace std;

class queue{
	int *array;
	int front;
	int rear;
	int queue_size;
	public:
		queue(){
			front=-1;
			rear=-1;
			queue_size=20;
			array=new int[queue_size];
		}
		queue(int num){
			front=-1;
			rear=-1;
			queue_size=num;
			array=new int[queue_size];
		}
		void enque(int a){
			if(isFull()){
				cout<<"\nList is Full";
			}
			if(isEmpty()){
				front=rear=0;
				array[rear]=a;
			}
			else{
				
				array[++rear]=a;
				int i=rear;
				int p=(i-1)/2;
				while(array[i]<array[p]&&i!=front){
					int temp= array[p];
					array[p]=array[i];
					array[i]=temp;
					i=p;
					p=(i-1)/2;
				}
				
			}
		}
		int deque(){
			if(isEmpty()){
				cout<<"\nList is Empty ";
			}
			else{ 
		    	int ReturnValue=array[front];
		     	if (front==rear){    
			  		front=rear=-1;
				}
		     	else if((front*2)+2>rear){
			  		array[front]=array[(2*front)+1];
			  		rear--;
				}
				else{
					array[front]=array[rear];
					rear--;
					
					int i=front;
					int lc=(front*2)+1;
					int rc=(front*2)+2;
					while(array[i]>array[lc]||array[i]>array[rc]){
						int lowest;
						if(rc>rear){
							lowest=lc;
						}
						else{
						
							if(array[lc]>array[rc]){
								lowest=rc;
							}
							else{
								lowest =lc;
							}
						}
						int temp=array[i];
						array[i]=array[lowest];
						array[lowest]=temp;
						i=lowest;
						lc=(i*2)+1;
						rc=(i*2)+2;	
					}
				}
				return ReturnValue;

			}
		}
		bool isFull(){
			if((rear+1)%queue_size==front){
				return true;
			}
			else{
				return false;
			}
		}
		bool isEmpty(){
			if(front==-1){
				return true;
			}
			else{
				return false;
			}
		}
		void display(){
			if(isEmpty()){
				cout<<"\nList is empty\n";
			}
			else{
				for(int p=front;p!=rear;p=(p+1)%queue_size){
					cout<<"\n"<<array[p];
				}
				cout<<"\n"<<array[rear];
			}
		}
};



int main(){
	int c;
	queue q1;
	
	
	do{
		cout<<"\nWhatdo you wanna do \n1) Insert 2) DElete 3) Display 0) Exit: ";
		cin>>c;
		switch(c){
			case 1:{
				int v;
				cout<<"\nEnter value: ";
				cin>>v;
				q1.enque(v);
				break;
			}
			case 2:{
				q1.deque();
				break;
			}
			case 3:{
				q1.display();
				break;
			}
		}
	}while(c!=0);
}
