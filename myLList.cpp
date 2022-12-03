/*
 * file: myLList.cpp
 * author: Harvey Villanueva
 * 
 * src file for myLList
 */
#include "../include/myLList.h"
//Default Constructor
myLList::myLList()
{
    setSize(0);
    setHead(NULL);
    setTail(NULL);
}
//Alternate Constructor, converts conventional array to Linked List
//format of arraySize in main method is "sizeof(anArray)/sizeof(*anArray)"
myLList::myLList(int arraySize, int *anArray)
{
    setSize(0);
    setHead(NULL);
    setTail(NULL);
    //For each element in the array, add to the Linked List
    for (int i = 0; i < arraySize; i++)
    {
        add(anArray[i]);
    }
}
//Copy Constructor
myLList::myLList(const myLList &rhs)
{
    setSize(0);
    setHead(NULL);
    setTail(NULL);
    //Initialize datum pointer to head of rhs
    Datum *temp = rhs.head;
    //Loop until datum pointer is null
    while (temp != NULL)
    {
        //Add the data of the value of the datum that temp points to
        add((*temp).getData());
        //Set temp to the next attribute of the datum that temp currently points to
        temp = temp->getNext();
    }
}
//Destructor
myLList::~myLList()
{
    //Deallocating memory for each Datum in LL
    while (head != NULL)
    {
        //Hold the pointer to the next datum in the Linked List
        Datum *next = head->getNext();
        //Delete current pointer
        delete head;
        //Go to next datum
        head = next;
    }
    //List is now empty
    size = 0;
}
//Concatenates rhs to this Linked List
const myLList myLList::operator+(const myLList &rhs) const
{
    //init temp datum to head of rhs
    Datum *temp = rhs.head;
    myLList n(*this);
    //iterate through rhs
    while (temp != NULL)
    {
        //add each datum of rhs to lhs
        n.add((*temp).getData());
        //iterate
        temp = temp->getNext();
    }
    return n;
}
//effectively sets this equal to rhs
const myLList myLList::operator=(const myLList &rhs)
{
    //Effectively the deconstructor for myLList
    //Deallocating memory for each Datum in LL
    while (head != NULL)
    {
        Datum *next = head->getNext();
        delete head;
        head = next;
    }
    //now lhs is an empty LL
    size = 0;
    //To iterate through rhs
    Datum *temp = rhs.head;
    //iterate until temp is NULL
    while (temp != NULL)
    {
        //add new datum with data at temp to LHS
        add((*temp).getData());
        //iterate to next datum in RHS
        temp = temp->getNext();
    }
    return *this;
}
//returns the (index)th element of a linked list
const Datum myLList::operator[](int index) const
{
    if (index < 0 || index >= size)
        exit(1);
    //initialize datum pointer to head
    Datum *temp = head;
    //iterate until temp points to the (index)th datum
    for (int i = 0; i < index; i++)
    {
        temp = temp->getNext();
    }
    //return the datum that temp points to
    return *temp;
}
//check equality of two lists
bool myLList::operator==(const myLList &rhs) const
{
    //If lists aren't same size, no chance they are equal
    if (size != rhs.size)
        return false;
    //check equality index-wise
    Datum *temp = head;
    Datum *temp1 = rhs.head;
    //iterate through both LL which are the same size
    while (temp != NULL)
    {
        //if any index-wise data are not equal between LHS and RHS, we decide these LL are not equal
        if ((*temp).getData() != (*temp1).getData())
            return false;

        temp = temp->getNext();
        temp1 = temp1->getNext();
    }
    //here implies LL are equal
    return true;
}
//in general, adds new datum with data aData to the end of the Linked List
void myLList::add(int aData)
{
    //Allocating memory for new datum (needs to be deleted)
    Datum *n = new Datum(aData);
    if (head == NULL)
    //Head is null (this is first Datum in LL)
    {
        //First datum is head AND tail
        head = n;
        tail = n;
    }
    else
    //Head is not null
    {
        //Current tail points to new datum
        (*tail).setNext(n);
        //Tail points to new datum
        tail = n;
    }
    //one more datum in list
    size++;
}
//insert new datum with data aData at the (index)th position
void myLList::insert(int aData, int index)
{
    if (index < 0 || index >= size)
        exit(1);
    //To iterate through LL
    Datum *temp = head;
    //Iterate to Datum that points to index
    for (int i = 0; i < index-1; i++)
    {
        temp = temp->getNext();
    }
    //Init new datum to insert at index
    Datum *datumToInsert = new Datum(aData);
    //Point datumToInsert to current Datum at index
    (*datumToInsert).setNext(temp->getNext());
    //point index-1 to datumToInsert
    (*temp).setNext(datumToInsert);
    //one more datum in list
    size++;
}
//remove the (index)th datum
void myLList::remove(int index)
{
    if (index < 0 || index >= size)
        exit(1);
    //To iterate through LL
    Datum *temp = head;
    //Iterate to Datum that points to index
    for (int i = 0; i < index - 1; i++)
    {
        //Go to next datum
        temp = temp->getNext();
    }
    //Pointer to Datum to remove
    Datum *del = temp->getNext();
    //Set next attribute of Datum temp to the next attribute of the value of next Datum
    (*temp).setNext(temp->getNext()->getNext());
    //Deallocate Datum that was removed
    delete del;
    //one less datum in list
    size--;
}
//Prints a Linked List
void myLList::print() const
{
    //Initialize datum pointer to head
    Datum *temp = head;
    //Loop until temp points to null
    while (temp != NULL)
    {
        //print the data in datum
        cout << temp->getData();
        //for pretty printing, print a comma if there is a next datum
        if ((*temp).getNext() != NULL)
            cout << ", ";
        //go to next datum
        temp = temp->getNext();
    }
    //for pretty printing, after entire list has printed
    cout << endl;
}
//finds the first Datum with a specific data value and returns (not needed for 240Assignment06)
Datum *myLList::find(int aData)
{
    Datum *temp = head;
    while (temp != NULL)
    {
        if ((*temp).getData() == aData)
            return temp;
        temp = temp->getNext();
    }
    //Didn't find Datum.
    return NULL;
}
//returns private member variable tail
Datum *myLList::getTail() const
{
    return tail;
}
//returns private member variable head
Datum *myLList::getHead() const
{
    return head;
}
//get private member variable size
int myLList::getSize() const
{
    return size;
}
//set private member variable head
void myLList::setHead(Datum *aHead)
{
    head = aHead;
}
//set private member variable tail
void myLList::setTail(Datum *aTail)
{
    tail = aTail;
}
//set private member variable size
void myLList::setSize(int aSize)
{
    size = aSize;
}