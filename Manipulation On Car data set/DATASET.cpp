#include <iostream>
#include<bits/stdc++.h>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <cstdlib>
#include <stack>



using namespace std;



struct Node1
{
    string make;
    string model;
    int year;
    int price;
    Node1 *right=NULL;
    Node1 *left=NULL;
};

Node1 *root = NULL;
struct Node
{
    string make;
    string model;
    int year;
    int price;
    Node *next=NULL;
    Node *prev=NULL;
};

Node *head = NULL;
Node *tail = NULL;

class Queue
{
public:
	Node *head;
	Node *tail;
	Queue(){
		head = NULL;
		tail = NULL;

		
	}
	
    bool isEmpty()
    {
        return head == NULL;
    }

    void enqueue(Node *temp)
    {
       

        if (head == NULL)
        {
            head = temp;
            tail = temp;
        }
        else
        {
        	
            temp->prev = tail;
            tail->next = temp;
            tail = temp;
        }
    }
    Node* peak()
	{
		if(!isEmpty()){
			return head; 	
		}
    	
	}

    Node *dequeue()
    {
        if (isEmpty())
        {
            cout << "Queue is empty." << endl;
            return NULL;
        }

        Node *temp = head;

        if (head == tail)
        {
            head = NULL;
            tail = NULL;
        }
        else
		{
   			head = head->next;
    		if (head != NULL) {
        		head->prev = NULL;
    		} else {
        		tail = NULL;
    		}
		}	


        return temp;
    }
};

void modelsgreaterthan(Queue q,int val){
	Queue q2 = q;	
	
    if (!q2.isEmpty())
    {
        while (!q2.isEmpty())
        {
            Node* temp = q2.dequeue();
            if (temp->year>=val){
            cout << "Model: " << temp->model << " Make: " << temp->make << " Year: " << temp->year << " Price: " << temp->price << endl;
        	}
        	
        }
    }
    else
    {
        cout << "Queue is empty." << endl;
    }

}

void deletespecificmake(Queue &q,string make){
	Queue q2;
    if (!q.isEmpty())
    {
    	int w=0;
        while (!q.isEmpty())
        {
        	
            Node* temp = q.dequeue();
            if (temp->make==make){
            	
            	q.dequeue();
        	}
        	else{
        		q2.enqueue(temp);
			}
        	w++;	
        }
        if (!q2.isEmpty()){
        	while (!q2.isEmpty()){
        		q.enqueue(q2.dequeue());
			}
        	
		}
        
        
    }
    else
    {
        cout << "Queue is empty." << endl;
    }

	
	
	
}


class STACK{
	public:
		
		void push(string make, string model, int year, int price){
			
			Node *curr = new Node;
    		curr->make = make;
   			curr->price = price;
    		curr->model = model;
    		curr->year = year;
    		
    		
			if(head==NULL){ 
				                   
				head=tail=curr;
			}
			else{
				
				tail->next=curr;
				curr->prev=tail;
				tail=curr;
			}
		}
		
		
		void pop(){
	        if (head == NULL)
	        {
	            cout << "Line is empty!";
	        }
	        else
	        {
	            cout << "\n The record to be deleted: " << tail->make << " , " << tail->model << " , " << tail->year << " , " << tail->price << endl;
	            Node *pop = tail;
	            if (head == tail)
	            {
	                head = tail = NULL;
	            }
	            else
	            {
	                tail->next->prev = NULL;
	                tail = tail->next;
	            }
	            delete pop;
	        }
        }
						
	
		void display_inreverse(){
			if(head==NULL){
				cout<<"\n Empty list";
			}
			
		    Node *current = tail;
	        cout << "The reverse list is: " << endl;
	        while (current != NULL)
	        {
	            cout << current->make << " , " << current->model << " , " << current->year << " , " << current->price << endl;
	            current = current->prev;
	        }
		}

				
		
};

class priorityqueue{
	
	public:
		queue(){
			
		}
		
		void enque(string make, string model, int year, int price,int b1,int b2){
			Node *curr = new Node;
    		curr->make = make;
   			curr->price = price;
    		curr->model = model;
    		curr->year = year;
    		
			if(isEmpty()){ 
				                         //for empty
				head=tail=curr;
			}
			else{
				if(head==tail){
					
					if(b1==1){												                    //when only when element is present
						if((curr->year>head->year&&b2==2)||(curr->year<head->year&&b2==1)){
							head=curr;
							head->next=tail;
							tail->prev=head;
						}
						else if((curr->year<head->year&&b2==2)||(curr->year>head->year&&b2==1)){
							tail=curr;
							head->next=tail;
							tail->prev=head;
						}
					}
					else{
						if((curr->price>head->price&&b2==2)||((curr->price<head->price&&b2==1))){
							head=curr;
							head->next=tail;
							tail->prev=head;
						}
						else if((curr->price<head->price&&b2==2)||((curr->price>head->price&&b2==1))){
							tail=curr;
							head->next=tail;
							tail->prev=head;
						}
					}
				}
				
				else{                                //more than 1 element
					Node*s=tail;
					
					if(b1==1){
						if(b2==1){
							while(s!=NULL && curr->year<s->year){
								s=s->prev;	
							}
						}
						else{
						
							while(s!=NULL && curr->year>s->year){
								s=s->prev;	
							}
						}
					}
					else{
						if(b2==1){
							while(s!=NULL && curr->price<s->price){
								s=s->prev;	
							}	
						}
						else{
						
							while(s!=NULL && curr->price>s->price){
								s=s->prev;	
							}
						}
					}
					
					if(s==tail){
						tail->next=curr;
						curr->prev=tail;
						tail=curr;
					}
					else if(s==NULL){
						curr->next=head;
						head->prev=curr;
						head=curr;
					}
					else{
					
						curr->next=s->next;
						curr->prev=s;
						s->next->prev=curr;
						s->next=curr;
					}
				}
				
			}
		}
		int deque(){
			if(isEmpty()){
				cout<<"\nList is Empty ";
			}
			else{ 
		    	cout <<"\n Output = "<< head->make << " , " << head->model << " , " << head->year << " , " << head->price << endl;
		     	Node*p=head;
				head->next->prev=NULL;
				head=head->next;
		     	delete p;
			}
		}
		
		bool isEmpty(){
			if(head==NULL){
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
				Node* ptr=head;
				while(ptr!=NULL){
					cout <<"\n Output = "<< ptr->make << " , " << ptr->model << " , " << ptr->year << " , " << ptr->price << endl;
					ptr=ptr->next;
				}
			}
		}
		void displaynth(int n){
			if(isEmpty()){
				cout<<"\nList is empty\n";
			}
			else{
				int count=0;
				Node* ptr=head;
				while(ptr!=NULL&& count!=n){
					cout <<"\n Output = "<< ptr->make << " , " << ptr->model << " , " << ptr->year << " , " << ptr->price << endl;
					ptr=ptr->next;
					count++;
				}
			}
		}
};




void insertbst(string make, string model, int year, int price){
	Node1*curr=new Node1;
	curr->make = make;
   	curr->price = price;
    curr->model = model;
    curr->year = year;
	
	if(root==NULL){
		root=curr;
	}
	else{
		
		Node1*p=root;
		Node1*k;
		
		while(p!=NULL){
			k=p;
			if(curr->price>p->price){
				p=p->right;
			}
			else{
				p=p->left;
			}
			
		}
		if(curr->price>k->price){
			k->right=curr;
		}
		else{
			k->left=curr;
		}
	}
}




void addNode(string make, string model, int year, int price)
{
    Node *new_node = new Node;
    
    new_node->make = make;
    new_node->price = price;
    new_node->model = model;
    new_node->year = year;
    
    new_node->next = NULL;
    new_node->prev = NULL;
    
    if(head == NULL)
    {
        head = new_node;
        tail = new_node;
        return;
    }
    //non empty
    new_node->prev = tail;
    tail->next = new_node;
    tail = new_node;
}

void print()
{
    Node *ptr = head;
    cout << " MAKE , MODEL , YEAR , PRICE" << endl;
    if (head!=NULL)
    {
       while (ptr)
       {
           cout<<ptr->make<<" , "<<ptr->model<<" , "<<ptr->year<<" , "<<ptr->price<< endl;
           ptr=ptr->next;
       }
    }
   else
    {
       cout << "List is empty"<<endl;
    }
}
void print(string make)
{
    Node *ptr = head;
    cout << "Make , Model , Year , Price" << endl;
    if (head!=NULL)
    {
        while (ptr)
        {
            if(ptr->make==make)
            {
                cout << ptr->make << " , " << ptr->model << " , " << ptr->year << " , " << ptr->price << endl;
            }
            ptr=ptr->next;
        }
    }
    else
    {
       cout << "List is empty"<<endl;
    }
}

void print(int year)
{
    Node *ptr = head;

    if (head != NULL)
    {
        cout << "Make , Model , Year , Price" << endl;
        while (ptr)
        {
            if (ptr->year >= year)
            {
                cout << ptr->make << " , " << ptr->model << " , " << ptr->year << " , " << ptr->price << endl;
            }
            ptr = ptr->next;
        }
    }
    else
    {
        cout << "List is empty" << endl;
    }
}






void deleteLess(int price)
{
    Node *ptr = head;
    while (ptr)
    {
        if(ptr->price > price)
        {
            
            if((ptr==head||ptr==tail) && head==tail)
            {
                head=NULL;
                tail=NULL;
            }
            else if(ptr==head)
            {
                head=head->next;
                head->prev=NULL;
            }
            else if(ptr==tail)
            {
                tail=tail->prev;
                tail->next=NULL;
            }
            else
            {
                ptr->prev->next=ptr->next;
                ptr->next->prev=ptr->prev;
            }
        }
        ptr=ptr->next;
    }
}
void displayinorder(Node1*k){
	if(k!=NULL){
		
		displayinorder(k->left);
		cout << k->make << " , " << k->model << " , " << k->year << " , " << k->price << endl;
		displayinorder(k->right);
	}
}

Node1* searchp(int key){
	Node1* k=root;
	Node1*l;
	while(k!=NULL && k->price!=key){
		l=k;
		if(key>k->price){
			k=k->right;
		
		}
		else{
			k=k->left;
			
		}
		
	}
	return l;
}
Node1* search(int key){
	Node1* k=root;
	
	while(k!=NULL && k->price!=key){
		if(key>k->price){
			k=k->right;
		
		}
		else{
			k=k->left;
			
		}
		
	}
	
	return k;
}
Node1* successor(Node1* p){
	if(p->right->left==NULL){
		return p->right;
	}
	else{
		Node1*k=p->right;
		while(k->left!=NULL){
			k=k->left;
		}
		return k;
	}
}
Node1* predessor(Node1* p){
	if(p->left->right==NULL){
		return p->right;
	}
	else{
		Node1*k=p->left;
		while(k->right!=NULL){
			k=k->right;
		}
		return k;
	}
}

Node1* successorp(Node1* p){
	if(p->right->left==NULL){
		return p;
	}
	else{
		Node1*k=p->right;
		Node1*j;
		while(k->left!=NULL){
			j=k;
			k=k->left;
		}
		return j;
	}
}

Node1* findingMaximum(Node1 *r){
   	  Node1 *p=r;
   	  if(p->right==NULL || p->left==NULL){
   	  	 return p;
   	  	
	  }
	  else {
	  	while (p->right!=NULL){
	  		p=p->right;
	  		
		}
		return p;
	  }
   }
   
   
Node1* findingMinimum(Node1 *r){
   	  Node1 *p=r;
   	  if(p->right==NULL || p->left==NULL){
   	  	 return p;
   	  	
	  }
	  else {
	  	while (p->left!=NULL){
	  		p=p->left;
	  		
		}
		return p;
	  }
}



int main()
{
	int type=0;
	do{
	
	STACK s1;
	priorityqueue q1;
    //reading data from file
    ifstream fin;
    fin.open("car details v4.csv");
    string line, word;
    vector<string> lineData;
    int lines = 0;
    
    int basis1;
    int basis2;
    
		
	    cout<<"\n 1.Implement a priority queue"<<endl;
	    cout<<"2.implement Bst"<<endl;
	    cout<<"3.implement Stack"<<endl;
	    cout<<"4.Implement simple Queue"<<endl;
	    cout<<"5.implement normal"<<endl;
	    cout<< "Select an option:";
		cin>>type;
		if(type==1){
			cout<<"\nOn what bases do you wanna arrange your data \n1)Year\n2)Price";
			cin>>basis1;
			cout<<"\nDo you want the data to be in increasing order or decreasing order \n1)Increasing\n2)Decreasing";
			cin>>basis2;
		}
	    while(!fin.eof()){
	        //reading data and adding to vector
	        getline(fin,line);
	        stringstream s(line);
	        while(getline(s,word,',')){
	            lineData.push_back(word);
	        }
	        //type casting duration from string to int
	        stringstream s2(lineData[3]);
	        int year;
	        s2>>year;
	        stringstream s3(lineData[2]);
	        int price;
	        s3>>price;
	        //adding data to linked list
	        if(lines!=0)
	        {
	        	
	            if(type==1){
	            	
	            	q1.enque(lineData[0],lineData[1],year,price,basis1,basis2);
				}
				else if(type==2){
					insertbst(lineData[0],lineData[1],year,price);
					
				}
				else if(type==3){
					s1.push(lineData[0],lineData[1],year,price);
				}
				else{
					addNode(lineData[0],lineData[1],year,price);
				}
	        }
	        //clearing vector
	        lineData.clear();
	        lines++;
	    }
	    if(type==2){
	    	int c=0;
	    	do{
				
		    	cout<<"\n 1.Print information about all cars in a sorted way "<<endl;
			    cout<<"2.Get the Car closest to the value of one of the car"<<endl;
			    cout<<"3.Compare the features of the Most expensive Car and the Most affordable car "<<endl;
			    cout<< "Select an option and 0 to exit:";
			    cin>>c;
			    switch(c){
			    	case 1:{
						displayinorder(root);
			    		break;
					}
					case 2:{
						int key;
						cout<<"\nEnter value of the one of the car ";
						cin>>key;
						Node1*p1=search(key);
						cout<<"\nLESSER THAN EQUAL TO THAT VALUE";
						Node1 *k=predessor(p1);
						cout << "\n"<<k->make << " , " << k->model << " , " << k->year << " , " << k->price << endl;
						Node1*p=k;
						for(int i=0;i<2&&p1!=p;i++){
							p=searchp(p->price);
							cout << p->make << " , " << k->model << " , " << k->year << " , " << k->price << endl;
						}
						cout<<"\nGREATER THAN EQUAL TO THAT VALUE"<<endl;
						
						k=successor(p1);
						cout << k->make << " , " << k->model << " , " << k->year << " , " << k->price << endl;
						p=k;
						for(int i=0;i<2&&p!=p1;i++){
							p=searchp(p->price);
							cout << p->make << " , " << p->model << " , " << p->year << " , " << p->price << endl;
						}
						break;
					}
					case 3:{
						
						cout<<"\nFOR THE MOST EXPENSIVE ONE"<<endl;
						Node1*p=findingMaximum(root);
						cout << p->make << " , " << p->model << " , " << p->year << " , " << p->price << endl;
						cout<<"\nFOR THE AFFORDABLE ONE"<<endl;
						p=findingMinimum(root);
						cout << p->make << " , " << p->model << " , " << p->year << " , " << p->price << endl;

						break;
					}
			    		
			    	
				}
			}while(c==0);
		}
	    else if(type==1){
	    	int c=0;
			do{
			
				cout<<"\nWhat do you wanna do";
				cout<<"\n1)Deque";
				cout<<"\n2)Display All in the arranged manner";
				if(basis1==1&&basis2==1){
					cout<<"\n3)Display n number of the top oldest cars  ";
				}
				else if(basis1==1&&basis2==2){
					cout<<"\n3)Display n number of the top Latest cars  ";
				}
				else if(basis1==2&&basis2==1){
					cout<<"\n3)Display n number of the top Affordable cars  ";
				}
				else{
					cout<<"3)Display n number of the top Expensive cars";
				}
				cout<<"\nchoose : ";
				cin>>c;
			
				if(c==1){
					q1.deque();
				}
				else if(c==2){
					q1.display();
				}
				else if(c==3){
					int n;
					cout<<"\nEnter no of entries you wanna see: ";
					cin>>n;
					q1.displaynth(n);
				}
			
			}while(c!=0);
		}
		
		
		else if(type==3){
	    	int c=0;
			do{
			
				cout<<"\nWhat do you wanna do";
				cout<<"\nDelete the top car record";
				cout<<"\nDisplay The car records in reverse";
				cout<<"\nchoose : ";
				cin>>c;
			
				if(c==1){
					s1.pop();
				}
				else if(c==2){
					s1.display_inreverse();
				}
			
			}while(c!=0);
		}
	    
	    
	    
	    
	    
	    else if(type==4){
			Queue q;
		    Node *ptr = head;
		
		    if (head != NULL)
		    {
		    	int i=1;
		        while (ptr!=NULL&&i!=2060)
		        {
		        	
		            q.enqueue(ptr);
		            
					ptr = ptr->next;
					
					i++;
		        }
		    }
		    else
		    {
		        cout << "List is empty" << endl;
		    }
			
		    
		    int choice = 0;
		    do
		    {
		        cout<<"\n 1.To Find Newer or equal Model Than a certain Year"<<endl;
		        cout<<"2. Delete cars of specific make"<<endl;
		        cout<< "Select an option and 0 to exit:";
		        
		        cin>>choice;
		        switch(choice)
		        {
		            case 1 :
		            {
		            	cout<<"Enter Year";
		            	int year;
		            	cin>>year;
		               	modelsgreaterthan( q,year);
		                break;
		            }
		            case 2 :
		            	{
		            	cout<<"Enter make";
		            	string make;
		            	cin>>make;
		            	deletespecificmake(q,make);
		            	
		                break;
		            	
						}
						
					case 3:
					{
						if (!q.isEmpty())
		    			{
		        			while (!q.isEmpty())
		        			{
		            			Node* temp = q.dequeue();
		            			cout << "Model: " << temp->model << " Make: " << temp->make << " Year: " << temp->year << " Price: " << temp->price << endl;
		        				}
		        	
		        			}
		    			else
		    			{
		        			cout << "Queue is empty." << endl;
		   				}
						
						break;
					}	
		            default :
		            {
		                cout<<"Invalid choice!"<<endl;
		            }
		        }
		    }
		    while(choice!=0);
	    	
		}
		
		
		
		
		
	    else if(type==5) {
		
		    int choice = 0;
		    do
		    {
		        cout<<"\n 1.Print information about all cars"<<endl;
		        cout<<"2.Print information about cars from specific make"<<endl;
		        cout<<"3.Print information about cars newer than a specific year"<<endl;
		        cout<<"4.Delete cars having a price greater than a specific amount"<<endl;
		        cout<< "Select an option and 0 to exit:";
		        
		        cin>>choice;
		        switch(choice)
		        {
		            case 1 :
		            {
		                print();
		                break;
		            }
		            case 2 :
		            {
		                cout<<"Enter the Make: ";
		                string make;
		                cin>>make;
		                print(make);
		                break;
		            }
		            case 3 :
		            {
		 				cout<<"Enter the Year: ";
		                int year;
		                cin>>year;
		                print(year);
		                
		                break;
		            }
		            case 4 :
		            {
		                cout<<"Enter the amount: ";
		                int price;
		                cin>>price;
		                deleteLess(price);
		                break;
		            }
		            
		            
		            default :
		            {
		                cout<<"Invalid choice!"<<endl;
		            }
		        }
		    }
		    while(choice!=0);
		}
	head=NULL;
	tail=NULL;
	
	root=NULL;
	
		
	}while(type!=0);
    return 0;

}
