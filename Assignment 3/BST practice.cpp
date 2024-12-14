#include <iostream>
using namespace std;
void insertbst();
void deletion();


struct bst{
	int id;
	bst*right=NULL;
	bst*left=NULL;
};
void display(bst*k);
int level(bst*k);
int leaf(bst*k,int count);
bst* successor(bst* p);
bst* successorp(bst* p);
bst* search(int key);
bst*root=NULL;

int main(){
	int choice=0;
	do{
		cout<<"\n Enter choice \n1) Insert on bst\n2) Sccessor\n3) predessecor\n4) Search\n5) Delete node\n6)Display inorder\n7)Leaves in bst\n8)Height\nEnter choice: ";
		cin>>choice;
		if(choice==1){
			insertbst();
		}
		if(choice==5){
			deletion();	
		}
		if(choice==6){
			display(root);	
		}
		if(choice==2){
			int key;
			cout<<"\nEnter key of which successor is to be found: ";
			cin>>key;
			bst*o=successor(search(key));
			cout<<"\nThe Successor is "<<o->id;	
		}
		if(choice==4){
			int key;
			cout<<"\nenter key : ";
			cin>>key;
			bst*a=search(key);		
		}
		if(choice==7){
			int count=leaf(root,0);	
			cout<<"\nLeaves= "<<count;
		}
		if(choice==8){
			int count=level(root);	
			cout<<"\nHeight= "<<count;
		}
	}while(choice!=0);
	
	
	return 0;
}

void insertbst(){
	bst*curr=new bst;
	cout<<"\nEnter ID: ";
	cin>>curr->id;
	
	if(root==NULL){
		root=curr;
	}
	else{
		
		bst*p=root;
		bst*k;
		
		while(p!=NULL){
			k=p;
			if(curr->id>p->id){
				p=p->right;
			}
			else{
				p=p->left;
			}
			
		}
		if(curr->id>k->id){
			k->right=curr;
		}
		else{
			k->left=curr;
		}
	}
}

void display(bst*k){
	if(k!=NULL){
		
		display(k->left);
		cout<<"\nTHe value is : "<<k->id;
		display(k->right);
	}
}


int leaf(bst*k,int count){
	if(k!=NULL){
		
		if(k->left==NULL&&k->right==NULL){
			count++;
		}
		count=leaf(k->left,count);
		count=leaf(k->right,count);
	}

	return count;
	
}

int level(bst*k){
	if(k==NULL){
		return -1;
	}
	else{
		int lh=level(k->left);
		int rh=level(k->right);
		if(lh>rh){
			return (lh+1);
		}
		else{
			return (rh+1);
		}
	}
	
}


bst* search(int key){
	bst* k=root;
	
	while(k!=NULL && k->id!=key){
		if(key>k->id){
			k=k->right;
		
		}
		else{
			k=k->left;
			
		}
		
	}
	
	if(k!=NULL){
		cout<<"\nValue Found\n";
	}
	else{	
		cout<<"\nValue not found\n";
	}
	return k;
}

bst* searchparent(int key){
	bst* k=root;
	bst* p;
	while(k!=NULL && k->id!=key){
		p=k;
		if(key>k->id){
			k=k->right;
		
		}
		else{
			k=k->left;
			
		}
		
	}
	
	return p;
}

bst* successor(bst* p){
	if(p->right->left==NULL){
		return p->right;
	}
	else{
		bst*k=p->right;
		while(k->left!=NULL){
			k=k->left;
		}
		return k;
	}
}


bst* successorp(bst* p){
	if(p->right->left==NULL){
		return p;
	}
	else{
		bst*k=p->right;
		bst*j;
		while(k->left!=NULL){
			j=k;
			k=k->left;
		}
		return j;
	}
}
void deletion(){
	int key;
	cout<<"\nEnter key: ";
	cin>>key;
	bst*k=search(key); 
	
	
	if(k==root){             //if the node to be deleted is the root
		if(k->left==NULL&&k->right==NULL){
			root=NULL;
		}
		else if(k->left==NULL||k->right==NULL){
			if(k->left==NULL){
				bst*u=root;
				root=k->right;
				delete u;
			}
			else{
				bst*u=root;
				root=k->left;
				delete u;
			}
		}
		else{
			bst* suc=successor(k);
			bst* sucp=successorp(k);
			if(k==sucp){
				root=suc;
				suc->left=k->left;
				delete k;
			}
			else{
				root=suc;
				bst*temp=suc->right;
				suc->left=k->left;
				suc->right=k->right;
				sucp->left=temp;
			}
		}
	}
	
	
	else{                            //if the node to be deleted is not the root
	
		bst*p=searchparent(key);
		cout<<"\np "<<p->id<<" k "<<k->id;
		
		if(k->left==NULL&&k->right==NULL){                  //if the node to be deleted is leaf/has no branch
			if(p->right==k){
				p->right=NULL;
			}
			else{
				p->left=NULL;
			}
		}
		
		else if(k->left==NULL|| k->right==NULL){                //if the node to be deleted has one branch
			if(p->right==k){
				if(k->right==NULL){
					p->right=k->left;
				}
				else{
					p->right=k->right;
				}
			}
			else{
				if(k->right==NULL){
					p->left=k->left;
				}
				else{
					p->left=k->right;
				}
			}
		}
		
		else{                                          //if the node to be deleted has 2 branches
			bst* suc=successor(k);
			bst* sucp=successorp(k);
			if(p->right==k){
				if(k==sucp){
					p->right=suc;
					suc->left=k->left;
					delete k;
				}
				else{
					p->right=suc;
					bst*temp=suc->right;
					suc->left=k->left;
					suc->right=k->right;
					sucp->left=temp;
				}
			}
			else{
				if(k==sucp){
					p->left=suc;
					suc->left=k->left;
					delete k;
				}
				else{
					p->left=suc;
					bst*temp=suc->right;
					suc->left=k->left;
					suc->right=k->right;
					sucp->left=temp;
				
				
			}
			
		}
	}
}
}










