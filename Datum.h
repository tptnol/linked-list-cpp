/*
 * file: Datum.h
 * author: Harvey Villanueva
 * 
 * header file for Datum
 */
#ifndef DATUM_H
#define DATUM_H

#include <iostream>
#include <cstdlib>

using namespace std;

class Datum
{
public:
    //Default Constructor
    Datum();
    //Alternate Constructor
    Datum(int);
    //Copy Constructor
    Datum(const Datum &);
    //Destructor
    ~Datum();
    //Getters and Setters
    int getData() const;
    void setData(int);
    Datum *getNext() const;
    void setNext(Datum *);

private:
    int data;
    Datum *next;
};

#endif //DATUM_H