#include <iostream>
using namespace std;

#ifndef STACK
#define STACK
class stack//Class stack
{
    struct node
    {
        bool stat;
        node* next;
    };

    node* head;
    node* nodeptr;
    node* temp;
    node* newptr;
    int length;

    public:
    stack(){head = nullptr, nodeptr = nullptr, temp = nullptr, newptr = nullptr, length = 0;}
    //stack(const stack&);
    ~stack();
    void push(bool);
    bool peek();
    void pop();
    int getLength();
};


stack::~stack()//Deletes all nodes
{
    node* delptr;

    while (head)
     {
        delptr = head;
        head = head->next;
        delete delptr;
        length--;      
     }
        
}

void stack::push(bool stat)//Add new node to current stack
{
    newptr = new node;
    newptr->stat = stat;
    newptr->next = nullptr;

    if (!head)
    head = newptr;
    else
    {
        newptr->next = head;
        head = newptr;
    } 

    length++;  
}

bool stack::peek()
{
    return head->stat;
}

void stack::pop()//Delete top node
{
    nodeptr = head;
    head = head->next;
    delete nodeptr;

    length --;
}

int stack::getLength()//Get stack length
{
    return length;
}


#endif


