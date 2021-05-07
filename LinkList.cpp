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


int main()
{
    Single_LinkList a ;
    a.add(30);
    a.add(20);
    a.add(50);
    a.add(10);
    a.add(10);
    a.add(2);
    a.add(10);
    a.add(15);
    a.add(40);
    a.add(100);
    
    a.del(2);
    a.del(10);
    a.del(15);
    a.del(50);
    a.del(100);

    a.add(1000);
    a.add(1);
    a.add(25);    
    
    
    a.display();
}
