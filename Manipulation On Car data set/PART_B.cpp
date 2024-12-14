
#include <iostream>
using namespace std;


struct stu{
    int id ;
    stu *next=NULL;
};
void choices();
void InsertEnd(stu *&last,int );
void display(stu *last);
void sort(stu *&last,stu *&last1,stu *&last3);
void deselect(stu *l,stu *& last );


stu *last1 = NULL;
stu *last2 = NULL;
stu *last3 = NULL;

int main(){
    int choice=0;
    do {
        choices();
    
        int choice;
        cout<<endl<<"Choice: ";
        cin>>choice;
        cout<<"-----------------------------------------------------------------------"<<endl;
    
        switch(choice){
            case 1:
                cout<<"Inserting at end of list 1..."<<endl;
                cout<<"Enter id: ";
    			int id;
				cin>>id;
                InsertEnd(last1,id);
                break;
            case 2: 
                cout<<"Inserting at end of list 2..."<<endl;
                cout<<"Enter id: ";
    			
				cin>>id;
				InsertEnd(last2,id);
                break;
            case 3:
                cout<<"Displaying list 1..."<<endl;
                display(last1);
                break;
            case 4:
                cout<<"Displaying list 2..."<<endl;
                display(last2);
                break;
            case 5:
            	sort(last1,last2,last3);
                break;
                
            case 6:
				display(last3);    
        }
        
    }while(choice!=5);
    
}

void choices()
{
    cout<<"-----------------------------------------------------------------------"<<endl;
    cout<<
    "    Press 1  to insert at end of list 1"<<endl<<
    "    Press 2  to insert at end of list 2"<<endl<<
    "    Press 3  to Display list 1"<<endl<<
    "    Press 4  to Display list 2"<<endl<<
    "    Press 5  to sort both "<<endl<<
    "    Press 6  to display Sorted "<<endl<<
	"    Press 7  to exit"<<endl;
    
}

void InsertEnd(stu *&last,int id){
    
    
    stu *curr;
    curr=new stu;
    curr->id=id;
        
    if(last==NULL){
        curr->next=curr;
        last=curr;
    }
    else{
        curr->next=last->next;
        last->next=curr;
        last=curr;
    }

}

void display(stu *last){
	
	if(last == NULL){
		
		cout << "List is empty!" << endl;
		return;
	}
	
	stu *p = last->next;
	
	do {
		
		cout << "Marks: " << p->id << endl;
		p = p->next;
	} while(p != last->next);
}


void sort(stu *&last1, stu *&last2, stu *&last3) {
    
	
    do{
    	
    	stu *p = last1->next;
    	stu *r = last2->next;
    	
    	stu *l = p;
    	if (last1!=NULL){
		
		
		do 
		{
			
			stu *q = p->next;
			if (q->id< p->id){
				l = q;	
			} 
			p=p->next;
			
			
		}while(p != last1->next&& p!=NULL );
   		 }
    	
    	stu *k = r;
    	if (last2!=NULL){
		
		do 
		{
			
			stu *t = r->next;
			if (t->id< r->id){
				k = t;	
			} 
			r = r->next;
			
			
		}while(r != last2->next&&r!=NULL);
		}
    	
		
		if (l->id<k->id){
    		
			InsertEnd(last3,l->id);
    		
    		deselect(l,last1);
    		
		}
		else{
			
			InsertEnd(last3,k->id);
    		deselect(k,last2);
    	
				
		}
		
		if (last1!=NULL&&last2==NULL){
			
			InsertEnd(last3,l->id);
    		deselect(l,last2);
			continue;
		}
    	else if (last2!=NULL&&last1==NULL){
    		InsertEnd(last3,k->id);
    		deselect(k,last2);
    		continue;
    		
		}
    		
	
    	
    }while(last1!=NULL && last2!=NULL);


		




}


void deselect(stu *l,stu *&last){
	
	
	if (l==last){
		
		
		if(l->next==l){
					
			last=NULL;	
				
		}
		else{
			
			stu *z = last->next;
			stu *y = NULL;
			do {
				y= z;
				z = z->next;
			} while(z != last->next);					
					
			y->next=z->next;
			last = y;	
					
			}
				
		}
	else{
		
		stu *z = last->next;
		stu *y = NULL;
		do {
			
			y= z;
			z = z->next;
		}while(z != l);					
					
		y->next=z->next;
				
		}
	
	
	
	
}
