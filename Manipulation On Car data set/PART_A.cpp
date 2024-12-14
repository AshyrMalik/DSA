jn#include<iostream>
using namespace std;

struct stu{
	int id ;
	float marks;
	stu *next=NULL;
};

void choices();
void InsertEnd(stu *&,stu *&);
void InsertStart(stu *&,stu *&);
void Display(stu *&,stu *&);
void AfterSpecific(stu *&,stu *&);
stu* search(int a,stu *& first);
void BeforeSpecific(stu *&,stu *&);
void DeleteStart(stu *&,stu *&);
void DeleteEnd(stu *&,stu *&);
void DeleteSpecific(stu *&,stu *&);
void ReverseDisplay(stu *&,stu *&);
void ReverseList(stu *&,stu *&);
void swap(int , int ,stu *&,stu *& );
void sort(stu *&);
void mergeLists(stu *&first1,stu *&last1,stu *&first2,stu *&last2);

stu *first1=NULL;
stu *last1=NULL;
stu *first2=NULL;
stu *last2=NULL;
int select;

int main()
{
    
    bool control=true; 
    
    do{
        choices();
        int choice;
        cout<<endl<<"Choice: ";
        cin>>choice;
        cout<<"-----------------------------------------------------------------------"<<endl;
        
        switch(choice)
        {
            case 1:
                
				cout<<"Inserting at end..."<<endl; 
            	int option;
				cout<<"Press 1 for the first List \nPress 2 for the Second list "<<endl;
				cin>> option;
				if (option==1){
					InsertEnd(first1,last1);
				}
				else{
					InsertEnd(first2,last2);
				}
				
				break;   
        
            case 2:
     			
				cout<<"Inserting at start..."<<endl;
				cout<<"Press 1 for the first List \nPress 2 for the Second list "<<endl;
				cin>> option;
				if (option==1){
					InsertStart(first1,last1);
				}
				else{
					InsertStart(first2,last2);
				}
				    	
				break;    
            
			case 3:
				cout<<"Inserting after Specific value..."<<endl;
				cout<<"Press 1 for the first List \nPress 2 for the Second list "<<endl;
				cin>> option;
				if (option==1){
					AfterSpecific(first1,last1);
				}
				else{
					AfterSpecific(first2,last2);
				}
				
				break;    
				        
            case 4:
            	cout<<"Inserting before specific value..."<<endl;
            	cout<<"Press 1 for the first List \nPress 2 for the Second list "<<endl;
				cin>> option;
				if (option==1){
					BeforeSpecific(first1,last1);
				}
				else{
					BeforeSpecific(first2,last2);
				}
				
				break;   
                
        
            case 5:
            	cout<<"Displaying List..."<<endl;
                cout<<"Press 1 for the first List \nPress 2 for the Second list "<<endl;
				cin>> option;
				if (option==1){
					Display(first1,last1);
				}
				else{
					Display(first2,last2);
				}
				
                break;
		
            case 6:
        		cout<<"Deleting from end..."<<endl;
            	cout<<"Press 1 for the first List \nPress 2 for the Second list "<<endl;
				cin>> option;
				if (option==1){
					DeleteEnd(first1,last1);
				}
				else{
					DeleteEnd(first2,last2);
				}
				
				break;
                
            case 7:
            	cout<<"Deleting from start..."<<endl;
            	cout<<"Press 1 for the first List \nPress 2 for the Second list "<<endl;
				cin>> option;
				if (option==1){
					DeleteStart(first1,last1);
				}
				else{
					DeleteStart(first2,last2);
				}
				
				break;
                
            case 8:
            	cout<<"Deleting specific value..."<<endl;
            	cout<<"Press 1 for the first List \nPress 2 for the Second list "<<endl;
				cin>> option;
				if (option==1){
					DeleteSpecific(first1,last1);
				}
				else{
					DeleteSpecific(first2,last2);
				}
				
				break;
            
			case 9:
				cout<<"Displaying Reverse List..."<<endl;
                cout<<"Press 1 for the first List \nPress 2 for the Second list "<<endl;
				cin>> option;
				if (option==1){
					ReverseDisplay(first1,last1);
				}
				else{
					ReverseDisplay(first2,last2);
				}
				
                break;
			
			case 10:
				cout<<"Reversing List..."<<endl;
                cout<<"Press 1 for the first List \nPress 2 for the Second list "<<endl;
				cin>> option;
				if (option==1){
					ReverseList(first1,last1);
				}
				else{
					ReverseList(first2,last2);
				}
				
                break;
			case 11:
				cout<<"Swaping values..."<<endl;
    			
				int id1,id2;
				cout<<"Press 1 for the first List \nPress 2 for the Second list "<<endl;
				cin>> option;
				if (option==1){
					
					cout<<"Enter the First id: ";
					cin>> id1;
					cout<<"Enter the Second id: ";
					cin>> id2;
					swap(id1,id2,first1,last1);
				}
				else{
					
					cout<<"Enter the First id: ";
					cin>> id1;
					cout<<"Enter the Second id: ";
					cin>> id2;
					swap(id1,id2,first2,last2);
				}

                break;
							    
			case 12:
				cout<<"Press 1 for the first List \nPress 2 for the Second list "<<endl;
				cin>> option;
				if (option==1){
					sort(first1);
				}
				else{
					sort(first2);
				}
				cout<<"Sorting values..."<<endl;
    			 
				break;			
            case 13:    
                
				cout<<"Closing Program..."<<endl;            
                mergeLists(first1,last1,first2,last2);
                break;      
            
            default :
                cout<<"Enter a number between 1 and 13";
                
		}
        
    } while (control==true);
	
	return 0;
}



void choices()
{
	cout<<"-----------------------------------------------------------------------"<<endl;
    cout<<
    "	Press 1  to insert at end "<<endl<<
    "	press 2  to Insert at start"<<endl<<
    "	Press 3  to Insert the value after specific value"<<endl<<
    "	Press 4  to Insert the value before specific value"<<endl<<
    "	Press 5  to Display the array list"<<endl<<
    "	Press 6  to Delete the value from end of the list"<<endl<<
    "	Press 7  to Delete the value from start of the list"<<endl<<
    "	Press 8  to Delete specific value"<<endl<<
    "	Press 9  to Display the list in reverse manner"<<endl<<
    "	Press 10 to Reverse the list"<<endl<<
    "	Press 11 to Swap the values"<<endl<<
	"	Press 12 to sort the values"<<endl<<
	"	Press 13 to exit the program"<<endl;
	
}


void InsertEnd(stu *& first,stu *&last)
{
	stu *curr;
	curr=new stu;
	
	cout<<"Enter id: ";
	cin>>curr ->id;
	
	cout<<"Enter marks: ";
	cin>> curr->marks;
	
	if(last==NULL){
		first=last=curr;
	}
	else{
		last->next=curr;
		last=curr;
	}
	
}

void InsertStart(stu *& first,stu *&last){
	
	stu *curr;
	curr=new stu;
	
	cout<<"Enter id: ";
	cin>>curr ->id;
	
	cout<<"Enter marks: ";
	cin>> curr->marks;
	
	if (last==NULL){
		first=last=curr;
	}
	else{
		curr->next=first;
		first=curr;
		
	}
	
	
}

void AfterSpecific(stu *& first,stu *&last){
    select=0;
	cout<<"Enter the id after which you want to enter: ";
    int find;
    cin >>find;

    stu *p = search(find,first);
    
	if (p==NULL){
        cout<<"Value not found";
    }
    else{
        stu *curr;
        curr=new stu;

        cout<<"Enter id: ";
        cin>>curr ->id;

        cout<<"Enter marks: ";
        cin>> curr->marks;
	
        if(p==last)
		{
			last->next=curr;	
			last=curr;
		}
		else{
		
        	curr->next=p->next;
        	p->next=curr;
		}
    }
}

void BeforeSpecific(stu *& first,stu *&last){
	
	select=1;
	cout<<"Enter the id after which you want to enter: ";
    int find;
    cin >>find;

    stu *p = search(find,first);
    if (p==NULL){
        cout<<"Value not found";
    }
    
    else{
        stu *curr;
        curr=new stu;

        cout<<"Enter id: ";
        cin>>curr ->id;

        cout<<"Enter marks: ";
        cin>> curr->marks;
        
        if(p==first)
		{
			curr->next=first;	
			first=curr;
		}
		else{
		
        	curr->next=p->next;
        	p->next=curr;
		}
    }
	
	
}
void Display(stu *& first,stu *&last){
	stu *display;
	display=first;
	
	if (display==NULL){
		cout<<"List is empty "<<endl;
	}
	
	else{
	
		while(display!=NULL){
		
			cout<<"id: "<<display->id<<endl;
			cout<<"Marks: "<<display->marks<<endl;		
			display=display->next;
		}
	
	}
	
}

void DeleteEnd(stu *& first,stu *&last) {
    stu *p=NULL;
	if (first == NULL) {
        cout << "List is empty";
       
    }

    else if (first == last) {
        p= first;
        first = last = NULL;
        delete p;
    }
	else{
	
    	stu *p = first;
    	while (p->next != last) {
        	p = p->next;
    	}

    	delete last;
    	last = p;
    	last->next = NULL;
}	

}
void DeleteStart(stu *& first,stu *&last){
	
	stu *p=NULL;
	if (first==NULL){
		cout<<"List is empty";
		
	}
	else if(first==last){
		p=first;
		first=last=NULL;
		delete p;
	}
	
	else{
		p=first;
		first=p->next;
		delete p;
	}
	
		
}

void DeleteSpecific(stu *& first,stu *&last){
	
	cout<<"Enter the id you want to delete: ";
	int id;
	cin>>id;
	
	stu *p=first;
	stu *k=first;
	
	
	while(p->id!=id && p->next!=NULL){
		k=p;
		p=p->next;
	}
	
	if (p==NULL){
		cout<<"ID NOT FOUND";
	}
	else if (p==first){
		p=first;
		first=p->next;
		delete p;
		
	}
	else if(p==last){
		stu *l = first;
    	while (l->next != last) {
        	l = l->next;
    	}

    	delete last;
    	last = l;
    	last->next = NULL;
	}	
	else{
		k->next=p->next;	
		delete p;
		
	}
	
		
}
	
void ReverseDisplay(stu *& first,stu *&last){
	select = 1;
	stu *k=last;
	
	while(k!=first){
		stu *p=search(k->id,first);
		cout<<"id : "<< k->id <<endl;
		cout<<"Marks : "<< k->marks <<endl;
		k=p;		
		
	}
	cout<<"id : "<< first->id <<endl;
	cout<<"Marks : "<< first->marks <<endl;
	
	
	
	
}

void ReverseList(stu *& first,stu *&last){
	select=1;
	stu *k=last;
	stu *r=last;
	if (k==NULL){
		cout<<"List is empty"<<endl;
	}
	else{
	
		while(k!=first){
			stu *p=search(k->id,first);
			k->next=p;		
			k=p;
		
		}
		first->next=NULL;
		last=first;
		first=r;
	}
	
}



void swap(int id1, int id2,stu *& first,stu *&last){
	

	 
	stu *p=first;
	
    while( p->id != id1 && p != NULL ) {
		
		p=p->next;
    
	}
		
	stu *q=first;
	
	while( q->id != id2 && q != NULL ) {
		
		q=q->next;
		
    }
	
	if (p==NULL){
		
		cout<<"Id 1 not found"<<endl;
	}
	else if(q==NULL){
		cout<<"Id 2 not found"<<endl;
	}	
	
	else if(p==q){
		cout<<"Swapping not possible: SAME NODE";
	}
	
	else if ((p==first && q==last)||(p==last && q==first)){
		
		
		if (p==first){
		
		select=1;
		stu *r = search(last->id,first);
		
		r->next=first;
		q->next=p->next;
		p->next=NULL;
		
		last=p;
		first=q; 
		}
		
		else{
			select=1;
		
			stu *r = search(last->id,first);
			
			r->next=first;
			p->next=q->next;
			q->next=NULL;
		
			last=q;
			first=p;	
		}
	}
	else if(p==first||q==first){
				
		if (p==first){
			if(p->next==q){
	
				stu *r=q->next;	
				q->next=p;
				p->next=r;
				
				first=q;
			}
			
			else{
			
				stu *s=q->next;
			
			
				select=1;
				stu *r=search(q->id,first);
		
				q->next=p->next;
				r->next=p;
				p->next=s;
			
				first=q;
			}
		}
		else{
			if(q->next==p){
	
				stu *r=p->next;	
				p->next=q;
				q->next=r;
				
				first=p;
			}
			
			else{
			
				stu *s=p->next;
			
			
				select=1;
				stu *r=search(p->id,first);
		
				p->next=q->next;
				r->next=q;
				q->next=s;
			
				first=p;
			}
		}	
	}
	
		
	else if (p==last||q==last){
		
		if (p==last){
			
			if(q->next==p){
				select=1;
				
				stu *r=search(q->id,first);	
				p->next=q;
				r->next=p;
				q->next=NULL;
				last=q;
				
			}
			
			else{
			
				stu *s=q->next;
		
				select=1;
				stu *r=search(q->id,first);
				stu	*t=search(p->id,first);
			
				r->next=p;
				p->next=s;
				
				
				t->next=q;
				q->next=NULL;
				
				last=q;
			}
		}
		
		else{
			if(p->next==q){
				select=1;
				
				stu *r=search(p->id,first);	
				q->next=p;
				r->next=q;
				p->next=NULL;
				last=p;
				
			}
			
			else{
			
				stu *s=p->next;
		
				select=1;
				stu *r=search(p->id,first);
				stu	*t=search(q->id,first);
			
				r->next=q;
				q->next=s;
				
				
				t->next=p;
				p->next=NULL;
				
				last=p;
			}
			
		}
		
		
	}
	else{
		
		select=1;
		stu *r=search(p->id,first);
		stu *s=search(q->id,first);
		
		r->next=q;
		s->next=p;
	
		stu *l=p->next;
		stu *j=q->next;
		
		p->next=j;
		q->next=l;
		
	 
		
	}
		
	
	
	


}

void sort(stu *& first){
	
	stu*p = first;
	stu *q = NULL;
	stu *r = NULL;
	while (p!=NULL){
		
		q = p-> next;	
		r = p-> next;
		while(q!=NULL){
	
			if (q->id < p->id  ){
				swap( p->id , q->id);
				
			}
			q = q->next;
			
		}
	
		p = r ;
		
		
		
	
	}
		
	
}


stu* search(int a,stu *& first){
	
	stu *p=first;
    stu *k=first;
    
    while( p->id != a && p != NULL ) {
        k=p;
		p=p->next;
		
    }
    
    if (select==0){
    
		return p;
	}
	else{
		
		return k;
	}
	
	
	
}


void mergeLists(stu *&first1,stu *&last1,stu *&first2,stu *&last2) {
    
	sort(first1);    
    
    stu *q=first2;
    do{
    	stu *r = q;
		stu *p= first1 ;
		
		
		while(p->id&&p!=NULL){
			
			p=p->next;
		}
		
		if (p==first1){
			r->next=p;
			first1 = r;
			
		}
		else if(p==NULL){
			last1->next=r;
			last1=r;
			
		}
		else{
			stu *r=first1;
			stu *k = first1;
			while( r->id != p->id && r != NULL ) {
       			k=r;
				r=r->next;
		
    		}
			k->next=r->next;
			r->next=k;
			
					
		} 	
		
		q=q->next;
    }while (q != NULL);
    first2=NULL;
	last2=NULL;				
    
}


		



