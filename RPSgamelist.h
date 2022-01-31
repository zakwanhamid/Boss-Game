#include <iostream>
using namespace std;

template <typename T>
class list//List class
{
    struct node
    {
        T val;
        int key;
        node* next;
    };

    node* head;
    node* nodeptr;
    node* temp;
    node* newptr;
    
    int length;

    public:
    //Constructor & Distructor
    list(){head = nullptr, nodeptr = nullptr, temp = nullptr, newptr = nullptr, length = 0;}
    ~list();

    //Declaring public functions
    void append(T);
    T get(int);
    void setNodeptrHead();
    T getCurrVal();
    void print();
    int getLength() {return length;}
};

template <typename T>
list<T>::~list()//Delete all node 
{ 
    nodeptr = head;
    temp = head;
    while (nodeptr)
    {
        temp = nodeptr;
        nodeptr = nodeptr->next;
        delete temp;
    }
}

template <typename T>
void list<T>::append(T val)//Add new node to current list 
{
    length++;
    nodeptr = head;
    newptr = new node;
    newptr->next = nullptr;
    newptr->val = val;
    newptr->key  = length;

    
    if (!head)
    {
        head = newptr;    
    }
    
    else
    {
        while (nodeptr->next)
        {
            nodeptr = nodeptr->next;
        }
        
        nodeptr->next = newptr;
           
    }
    
}

template <typename T>
T list<T>::get(int key)//Get id value by searching for the intended value 
{
    nodeptr = head;
    while (nodeptr->next && nodeptr->key != key)
    {
        nodeptr = nodeptr->next;
    }

    return  nodeptr->val;
}

template <typename T>
void list<T>::setNodeptrHead()//Reset back nodeptr to head
{
    nodeptr = head;
}

template <typename T>
T list<T>::getCurrVal()//Return current value, proceed nodeptr to next by doing so
{
    T choice;
    
    choice = nodeptr->val;
    nodeptr = nodeptr->next;
    return choice;
}

template <typename T>
void list<T>::print()//Print list all values in list
{
    nodeptr = head;
    while (nodeptr)
    {
        cout << nodeptr->key << endl;
        nodeptr = nodeptr->next;
    }
}

