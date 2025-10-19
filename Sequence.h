##ifndef __Sequence__Sequence__
#define __Sequence__Sequence__

#include <iostream>
#include "Node.h"
#include <string>

class Sequence
{
private:
    Node<std::string> *first;
    int quantity;
    
public:
    Sequence();
    
    ~Sequence();
    
    std::string get(int i);
    
    Node<std::string>* getFirst();
    
    void insert(int i, std::string element);
    
    void insertBegin(std::string element);
    
    void insertEnd(std::string element);
    
    std::string remove(int i);
    
    std::string removeBegin();
    
    std::string removeEnd();
    
    bool isEmpty();
    
    int getQuantity();
    
    void print(void);
};

#endif