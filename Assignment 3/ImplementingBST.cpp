#include <iostream>
#include<bits/stdc++.h>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <cstdlib>

using namespace std;

struct bst{

	bst*right=NULL;
	bst*left=NULL;
	string make;
	string model;
	int price;
	int year;
};

bst*root=NULL;


void insertbst(string make, string model, int year, int price){
	bst*curr=new bst;
	
	curr->make = make;
   	curr->price = price;
    curr->model = model;
    curr->year = year;
	
	if(root==NULL){
		root=curr;
	}
	else{
		
		bst*p=root;
		bst*k;
		
		while(p!=NULL){
			
			k=p;
			
			if( curr->price > p->price){
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

void display(bst*k){
	
	if(k!=NULL){
		
		display(k->left);
		cout<<"\nMake: "<<k->make<<" model: "<<k->model<<" price: "<<k->price<<" Year: "<<k->year;
		display(k->right);
		
	}
}

void minimum(bst*k){
	
	if(k->left==NULL){
		cout<<"\nMake: "<<k->make<<" model: "<<k->model<<" price: "<<k->price<<" Year: "<<k->year;
	
	}
	else {
	  	while (k->left!=NULL){
	  		k=k->left;
	  		
		}
		cout<<"\nMake: "<<k->make<<" model: "<<k->model<<" price: "<<k->price<<" Year: "<<k->year;
	
	  }	
}
void maximum(bst *k){
		
	if(k->right==NULL){
		cout<<"\nMake: "<<k->make<<" model: "<<k->model<<" price: "<<k->price<<" Year: "<<k->year;
	
	}
	else {
	  	while (k->right!=NULL){
	  		k=k->right;
	  		
		}
		cout<<"\nMake: "<<k->make<<" model: "<<k->model<<" price: "<<k->price<<" Year: "<<k->year;
	
	  }	
	
}

bst* search(string make,string model,int price){
	bst* k=root;
	
	while(k!=NULL && k->model!=model&& k->make!=make){
		if(price>k->price){
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

int hight(bst*k){
	if(k==NULL){
		return -1;
	}
	else{
		int left=hight(k->left);
		int right=hight(k->right);
		if(left>right){
			return (left+1);
		}
		else{
			return (right+1);
		}
	}
	
}


int main(){
	
	//reading data from file
    ifstream fin;
    fin.open("car details v4.csv");
    string line, word;
    vector<string> lineData;
    int lines = 0;
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
            insertbst(lineData[0],lineData[1],year,price);
        }
        //clearing vector
        lineData.clear();
        lines++;
    }
    int choice=0;
    do{
    	cout<<"\nPress 1 to display binary Serach tree"<<endl;
	    cout<<"Press 2 to display most expensive car"<<endl;
	    cout<<"Press 3 to dislplay most cheapest car"<<endl;
	    cout<<"Press 4 to find number of leaves"<<endl;
	    cout<<"Press 5 to find hight of tree "<<endl;
    	cin>>choice;
    	
		if (choice==1){
    		
			display(root);
			
    		
		}
		else if(choice==2){
			maximum(root);
			
		}
		else if(choice ==3){
			minimum(root);
		}
		
		else if(choice==4){
			cout<<"No of leaves"<<leaf(root,0);
		}
		else if(choice==5){
			cout<<"Hight: "<<hight(root);
			
		}
		
		
    	
    	
	}while(choice!=6);
    
}


