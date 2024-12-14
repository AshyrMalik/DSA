#include <iostream>
using namespace std;


struct rides{
	
	string name;
	float rating;
	float fare;
	
	
	rides *next = NULL;
	
	
};


struct dri{
	int id ;
	string name;
	
	dri *next=NULL;
	dri *prev=NULL;
	rides *first = NULL;
	rides *last = NULL;
	int ride = 0;
};


dri *first = NULL;
dri *last = NULL;



void AddRides(int a);
void choices();
void Display();
void InsertDrivers();
void DeleteSpecific(int a);
void SpecificDriver(int a);
void ratings();
void choices1();
void SpecificAmount(int a);
void DeleteDrivers(float a);
void stars_5();
void mostTrips();
void Highest();
int main(){

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
                
				cout<<"Inserting New Driver..."<<endl; 
				InsertDrivers();
            	
				break;   
        
            case 2:
     			
				cout<<"Displaying All Drivers..."<<endl;
				
				Display();
				    	
				break;    
            
			case 3:
				cout<<"Deleting Specific Driver..."<<endl;
				
				cout<<"Enter id: ";
				int id;
				cin>>id;
				
				DeleteSpecific(id);
				
				break;    
				        
            case 4:
            	cout<<"Adding Rides..."<<endl;
            	cout<<"Enter id of the driver whose ride you want to enter: ";
				cin>>id;
				AddRides(id);
				
				break;   
            case 5:
            	cout<<"Information about Specific Driver..."<<endl;
				cout<<"Enter id of the driver whose ride you want to enter: ";
				cin>>id;
				
				SpecificDriver(id);                
                break;
		
        
            case 6:
            	cout<<"Performance Menue..."<<endl;
                
				do{
                	choices1();
                	cout<<endl<<"Choice: ";
        			cin>>choice;
        			cout<<"-----------------------------------------------------------------------"<<endl;
        			
        			switch(choice){
        				case 1:
 						    
							ratings();   					
        					break;
        				case 2:
        					cout<<"Enter the specific amount: ";
							int a;
							cin>>a;
							SpecificAmount(a);
							break;
        					
        				case 3:
        					cout<<"Enter the ratings: ";
							float b;
							cin>>b;
							DeleteDrivers(b);
							
							break;
        					
        				case 4 :
        					stars_5();
        					break;
        					
        				case 5:
        					void mostTrips();
        					break;
						case 6:
							Highest();
							break;
        				case 7: 
        					
							cout<<"Closing program"<<endl;
        					break;
					}
        			
        	
        
        
				}while(choice!=6);
                
				break;
		
            case 7:
        		cout<<"Closing Program..."<<endl;
            	control=false;
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
    "	Press 1  to insert new Driver "<<endl<<
    "	press 2  to Display all Drivers"<<endl<<
    "	Press 3  to Delete specific Drivers"<<endl<<
    "	Press 4  to add rides "<<endl<<
    "	Press 5  to get information about specific Driver"<<endl<<
    "	Press 6  to open performance menue " <<endl<<
	"	Press 7  to Exit the program " <<endl;
	
}
void choices1(){
	
	cout<<"-----------------------------------------------------------------------"<<endl;    		
    cout<<
    "	Press 1  to see the driver with the highest average ratings"<<endl<<
    "	Press 2  to see the drivers earning less than a specific amount"<<endl<<
    "	Press 3  to delete the driver with ratings less than a certain rating"<<endl<<
    "	Press 4  to see how many 5 stars each driver has"<<endl<<
    "	Press 5  to see the driver who have completed the most trips"<<endl<<
    "	Press 6  to see the driver with the highest average earnings per trip"<<endl<<
    "	Press 7  to get back to the main menu"<<endl;
	
}



void InsertDrivers(){
	
	dri *curr;
	curr=new dri;
	
	cout<<"Enter id of the driver: ";
	cin>>curr ->id;
	
	cout<<"Enter Name of the driver: ";
	cin>> curr->name;
	
	if(first==NULL){
		
		
		
		first=last=curr;
		
	}
	else{
		last->next=curr;
		curr->prev=last;
		last=curr;
	}
	
}

void Display(){
    dri *p;
    p = first;
    
    if(p == NULL){
        cout << "NO RECORD..." << endl;
    }
    
    while(p != NULL){
        cout << "ID: " << p->id << endl;
        cout << "Name: " << p->name << endl;
        cout << "Rides completed: " << p->ride << endl;
		cout << "-------------------------------------" << endl;
        
        
        
        p = p->next;
    }
}


void DeleteSpecific(int a){
	
	dri *p;
	p = first;
	while (p!=NULL){
		
		if(p->id==a){
			cout<<"Id "<<a<<" is deleted"<<endl;
			if(p==first && p==last){
				first=NULL;
				last=NULL;
				
			}
			
			else if (p==first){
				(p->next)->prev=NULL;
				first=p->next;
				
			}
			else if (p==last){
				p->prev->next=NULL;
				last=p->prev;
				
			}
			else{
				(p->prev)->next=p->next;
				(p->next)->prev=p->prev;
			
			}
			return ;
			
		}
		p=p->next;
	}
	cout<<"DRIVER NOT FOUND"<<endl;

}

void AddRides(int a){
	dri *p;
	p = first;
	
	if(p == NULL){
        cout << "NO RECORD..." << endl;
    }
	while (p!=NULL){
		
		if(p->id==a){
				
			rides *curr;
			curr=new rides;
	
			cout<<"Enter the name of passenger: ";
			cin>>curr ->name;
		
			cout<<"Enter the fare : ";
			cin>> curr->fare;
					
			cout<<"Enter the rating : ";
			cin>> curr->rating;
			
			if(p->last==NULL){
				p->first=p->last=curr;
			}
			else{
				p->last->next = curr;
				p->last=curr;
			}
			p->ride= p->ride + 1;
			
			cout <<"press 1 to enter another ride \nPress any other button to go back: ";
			int b;
			cin>>b;
			if(b==1){
				continue;
			}

			return  ;
			
				
		}
		p =p->next;
	
		}
		
	
}

	
void SpecificDriver(int a){
	dri *p;
	p = first;
	if(p == NULL){
        cout << "NO RECORD..." << endl;
    }
	while (p!=NULL){
		
		if(p->id==a){
			
			cout<<"Information about Driver: "<<endl;
			cout << "ID: " << p->id << endl;
        	cout << "Name: " << p->name << endl;
        	cout << "Rides completed: " << p->ride << endl;
			cout << "-------------------------------------" << endl;
        	cout<<"Information about Rides: "<<endl;
			
			rides *r=p->first;
			while(r != NULL){
            	
            	cout << "Passenger Name: " << r->name << endl;
            	cout << "Rating: " << r->rating << endl;
            	cout << "Fare: " << r->fare << endl;
            	
            	cout << "-------------------------------------" << endl;
            	r = r->next;
        	}
			
			return ;
		}
		p=p->next;
	}
}


void ratings(){
	dri *p;
	p=new dri;
	p=first;
	if(p == NULL){
        cout << "NO RECORD..." << endl;
    	return ;
	}
	float average=0.0;
	dri *k = NULL;
	while(p!=NULL){
		rides *r;
		r = p->first;
		float temp=0.0;
		while(r!=NULL){
			
			temp += r->rating;
			r=r->next;
			
		}
		temp = temp/(float)p->ride;  
		
		if(temp>average){
			average = temp;
			k = p;
		}
		 
		p=p->next;
		
		
	}
	
	cout<<"The Highest average is "<<k->name<< " and the ratings is "<< average<<endl ;
	
}

void SpecificAmount(int a){
	dri *p;
	p = new dri;
	p = first;
	if(p == NULL){
        cout << "NO RECORD..." << endl;
    	return ;
	}
	while(p!=NULL){
		rides *r=p->first;
		int sum=0;
		while(r!=NULL){
			sum+=r->fare;
			r=r->next;
			
		}
		if(sum<a){
			cout<<"Id: "<<p->id<<endl;
			cout<<"Name: "<<p->name<<endl;
			cout<<"Rides completed: "<<p->ride<<endl;
		}
		p = p->next;
		
		
		
		
		
	}
	
	
}


void DeleteDrivers(float a){
	dri *p;
	p=new dri;
	p=first;
	
	if(p==NULL){
		cout << "NO RECORD..." << endl;
		return;
	}	
	
	while(p!=NULL){
		
		rides *r;
		r= p->first;
		float aver=0.0;
		while(r!=NULL){
			
			aver += r->rating;
			r=r->next;
			
		}
		aver = aver/(float)p->ride;  
		
		if (aver<a){
			DeleteSpecific(p->id);
		}	
			
			
		p=p->next;	
	}
	
}

void stars_5(){
	dri *p;
	p=new dri;
	p=first;
	if (p==NULL){
		
		return ;
	}
	
	while (p!=NULL){
		rides *r=new rides;
		r=p->first;
		int count = 0;
		while(r!=NULL){
			
			if(r->rating==5.0){
				count+=1;
			}
			
			
			r=r->next;
		}
		
		cout<<"ID: "<<p->id<<endl;
		cout<<"Name: "<<p->name<<endl;
		cout<<"Rides completed: "<<p->ride<<endl;
		cout<<"Five Stars: "<<count<<endl;
	
		p=p->next;
	
	}
		
		
		
		
		
}
	
	
void Highest(){
    dri *p;
	p=new dri;
	p=first;
	if (p==NULL){
		return ;
	}
	dri*k=NULL;
	float average=0;
	while(p!=NULL){
		rides *r=p->first;
		float temp=0;
		while(r!=NULL){
			
			temp+=r->fare;	
			r=r->next;
		}
		temp=temp/(float)p->ride;
		
		if(temp>average){
			average=temp;
			k=p;
			
		}
		p=p->next;
		
	}
	cout<<"The highest average earner per trip is "<<k->name<< " and the pay is "<< average<<endl ;
	
	
	
}

