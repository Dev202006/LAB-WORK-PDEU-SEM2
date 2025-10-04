#include<iostream>
using namespace std; 


template <typename T> class linked_list{

    public: 
    T data; 
    linked_list * link; 
    
    //constructors
    linked_list(){T data = T() ;link = nullptr;}
    linked_list(T n):data(n){}

    //insert function
    void insert_after(linked_list *other)
    {
        link = other; 
    }
    void insert_in_between(linked_list *other, linked_list *after)
    {
        link = other; 
        other->link = after; 
    }
    void insert_before(linked_list *other)
    {
        other->link = this;
    }
    static void traverse(linked_list *start)
    {
        cout<<"Traversing linked list now: "<<endl; 
        linked_list *temp = start; 
        while(temp!=NULL)
        {
            cout<<temp->data<<endl; 
            temp = temp->link; 

        }

    }
    static linked_list * getnode()
    {
    linked_list<T> *p = new linked_list<T>();
    return p; 
    }
    static linked_list * getnode(T n)
    {
    linked_list<T> *p = new linked_list<T>(n);
    return p; 
    }   


    ~linked_list()
    {
        delete link;
    }


};



int main()
{
    linked_list<int> *p1 = linked_list<int>::getnode();
    linked_list<int> *p2 = linked_list<int>::getnode(10);
    linked_list<int> *p3 = linked_list<int>::getnode(20);

    cout<<"P1:"<<p1->data<<endl; 
    cout<<"P2:"<<p2->data<<endl; 
    cout<<"P3:"<<p3->data<<endl; 

    p1->insert_after(p2);
    p2->insert_after(p3);
    
    linked_list<int> *start = p1; 
    linked_list<int>::traverse(start);

}