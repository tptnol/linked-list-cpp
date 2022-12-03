/*
 * file: main.cpp
 * author: Harvey Villanueva
 * 
 * main method for linked list program
 */
#include <iostream>
#include "../include/myLList.h"

using namespace std;

int main(int argc, char const *argv[])
{   
    cout << "----------MAIN" << endl;
    cout << "----------Creating Default LL called a" << endl;
    myLList a;
    cout << "----------ADDING 3.14 to a" << endl;
    a.add(3.14);
    cout << "----------ADDING 1-5 to a" << endl;
    for(int i=1;i<6;i++)
        a.add(i);
    cout << "----------Printing a" << endl;
    a.print();
    cout << "----------Making array with values 7-1 called b" << endl;
    int b[] = {7,6,5,4,3,2,1};
    cout << "----------Printing b" << endl;
    for(int i=0;i<7;i++)
        cout << b[i] << " ";
    cout << endl;
    cout << "----------Creating LL from array b called c" << endl;
    cout << "---------------Note: must include size of array in constructor" << endl;
    myLList c(sizeof(b)/sizeof(*b),b);
    cout << "----------Printing c" << endl;
    c.print();
    cout << "----------Creating LL from copy constructor with c called d" << endl;
    myLList d(c);
    cout << "----------Printing d" << endl;
    d.print();
    cout << "----------Concatenating a and c with + operator, only printing the result" << endl;
    (a+c).print();
    cout << "----------Concatenating a and c and d with + operator, only printing the result" << endl;
    (a+c+d).print();
    cout << "----------Setting c=a, then printing c" << endl;
    c=a;
    c.print();
    cout << "----------Setting a=c=d" << endl;
    a=c=d;
    cout << "----------Printing a" << endl;
    a.print();
    cout << "----------Printing c" << endl;
    c.print();
    cout << "----------Printing d" << endl;
    d.print();
    cout << "----------Printing the 3rd element of c with c[2]" << endl;
    cout << c[2].getData() << endl;
    cout << "----------Checking equivalence of a and c with == operator" << endl;
    cout << (a==c) << endl;
    cout << "----------Inserting 5.5 at index 3 of c" << endl;
    cout << "---------------Note: indexing begins with 0, so index 3 is the 4th element" << endl;
    c.insert(5.5,3);
    cout << "----------Printing c" << endl;
    c.print();
    cout << "----------Inserting 5.7 at index 3 of d" << endl;
    d.insert(5.7,3);
    cout << "----------Printing d" << endl;
    d.print();
    cout << "----------Checking equivalence of c and d with == operator" << endl;
    cout << (c==d) << endl;
    cout << "----------Removing value at index 3 in a" << endl;
    a.remove(3);
    cout << "----------Printing a" << endl;
    a.print();

    return 0;
}
