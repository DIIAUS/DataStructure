#include<iostream>

using namespace std; 

struct node{
    int val; 
    node* next; 
    
};



class Single_LinkList{
    private: 
        node*head; 

    public:
    Single_LinkList(){
        head = NULL;
    };

    void add(int data){

        node*tmp=new node;
        tmp->val = data;

        if(head==NULL){
            tmp->next = NULL;
            head=tmp;
        }
        
        else if(head!=NULL){
            if(data<head->val){
                tmp->next=head;
                head=tmp;
            }
            else if(data>=head->val){
                node* p = new node;
                p=head;
                while(data>=p->val){
                    
                
                    if(p->next==NULL){
                        p->next=tmp;
                        tmp->next=NULL;
                        break;
                    }
                    
                    else if(data==p-> val){
                        tmp->next=p->next;
                        p->next=tmp;
                        break;
                    }
                    else if(data<p->next->val){
                        tmp->next=p->next;
                        p->next=tmp;
                        break;
                    }
                    else{
                        p=p->next;
                    }
                }
            }
        }
        
    }

    void display(){
        node*p =new node;
        p = head;  
        while(p !=NULL){
            cout<< p ->val << "\t";
            p = p ->next;
        }
    }
    void del(int data){
        node*p = new node;
        p=head;
        while(true){
            if(head->val == data){
                head = head-> next;
                delete p;
                break; 
            }
            else if(p->next->val == data){
                node *p2; 
                p2=p->next;
                p->next= p2->next; 
                delete p2; 
                break;  
            }
            else{
                if(p->next==NULL){
                    cout<< "IsEmpty\t"; 
                    break;
                }
                p=p->next;
            }
        } 
    }

};


struct db_node{
    int val;
    db_node* next; 
    db_node* prev;
};

class Double_LinkList{
    
    private: 
        db_node*head;
        db_node*tail; 
    public:
        Double_LinkList(){
            head=NULL;
            tail=NULL;
        }
        void add(int data){
            db_node*tmp = new db_node;
            tmp->val=data;
            if(head == NULL){
                tmp->next=NULL;
                tmp->prev=NULL;
                head=tmp;
                tail=tmp;
            }
            else{
                if(data<=head->val){
                    tmp->next = head;
                    tmp->prev = NULL; 
                    head->prev=tmp;
                    head=tmp;
                } 
                else if(data>=tail->val){
                    tmp->next=NULL;
                    tmp->prev=tail->next;
                    tail->next=tmp;
                    tail=tmp;

                }
                else if(data>head->val){ // seeIt case double number is Error is 25 and 25 

                    db_node* p ;
                    p=head->next;
                    while(true){
                        if(data<=p->val){
                            if(p->next==NULL){
                                tmp->next=tail;
                                tmp->prev=p->prev->next;
                                p->prev->next=tmp;
                                p->prev=tmp;
                                break;
                            }
                            else{
                                tmp->next=p;
                                tmp->prev=p->prev;

                                p->prev->next=tmp;
                                p->prev=tmp;
                                break; 
                            }
                        }
                        else{
                            if(p==NULL){
                                cout<<"ISEMPTY\t"; 
                                break;
                            }
                            p=p->next;
                        }
                    }
                }

            }
        }

        void del(){
            //
        }

        void display(){
            db_node*p =new db_node;
            p = head;  
            while(p !=NULL){
            cout<< p ->val << "\t";
            p = p ->next;
        }
    }


};


int main()
{
    // Single_LinkList a ;
    // a.add(30);
    // a.add(20);
    // a.add(50);
    // a.add(10);
    // a.add(10);
    // a.add(2);
    // a.add(10);
    // a.add(15);
    // a.add(40);
    // a.add(100);
    
    Double_LinkList b ;
    b.add(50);
    b.add(20);
    b.add(20);
    b.add(10);
    
    b.add(25); // Bug
   
    // b.add(20);
    b.add(26);
    //b.add(25);  Bug
    
    

    
    
  
    
    
   

    
    
    //a.display();
    b.display();
    
}
