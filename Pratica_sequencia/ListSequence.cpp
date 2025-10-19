
#include "Sequence.h"
#include <string>

Sequence::Sequence()
{
    first = NULL;
    this->quantity = 0;
}

Sequence::~Sequence()
{
    Node<std::string>* curr = first;
    while(curr != NULL)
    {
        Node<std::string>* aux = curr;
        curr = curr->getNext();
        delete aux;
    }
}

std::string Sequence::get(int i)
{
    if (i < 1 || i > quantity) {
        return "";
    }
    
    Node<std::string>* curr = first;
    int counter = 1;
    
    while( curr != NULL && counter < i )
    {
        curr = curr->getNext();
        counter++;
    }
    
    if (curr != NULL) {
        return curr->getValue();
    }
    return "";
}

void Sequence::insert(int i, std::string element)
{
    if (i < 1 || i > quantity + 1) {
        return;
    }
    
    if (i == 1) {
        insertBegin(element);
        return;
    }
    
    if (i == quantity + 1) {
        insertEnd(element);
        return;
    }
    
    Node<std::string>* curr = first;
    for (int count = 1; count < i-1; count++) {
        curr = curr->getNext();
    }
    
    Node<std::string>* newNode = new Node<std::string>(element, curr->getNext());
    curr->setNext(newNode);
    quantity++;
}

void Sequence::insertBegin(std::string element)
{
    Node<std::string>* node = new Node<std::string>(element);
    
    if( first != NULL )
    {
        node->setNext( first );
    }
    
    first = node;
    this->quantity++;
}

void Sequence::insertEnd(std::string element)
{
    Node<std::string>* node = new Node<std::string>(element);
    this->quantity++;
    
    if(first == NULL)
    {
        first = node;
        return;
    }
    
    Node<std::string>* curr = first;
    
    while( curr->getNext() != NULL )
    {
        curr = curr->getNext();
    }
    
    curr->setNext(node);
}

std::string Sequence::remove(int i)
{
    if (i < 1 || i > quantity) {
        return "";
    }
    
    if (i == 1) {
        return removeBegin();
    }
    
    if (i == quantity) {
        return removeEnd();
    }
    
    Node<std::string>* curr = first;
    Node<std::string>* prev = NULL;
    
    for (int count = 1; count < i; count++) {
        prev = curr;
        curr = curr->getNext();
    }
    
    prev->setNext(curr->getNext());
    std::string result = curr->getValue();
    delete curr;
    quantity--;
    return result;
}

std::string Sequence::removeBegin()
{
    if (first == NULL) {
        return "";
    }
    
    Node<std::string>* toDelete = first;
    first = first->getNext();
    
    std::string result = toDelete->getValue();
    delete toDelete;
    this->quantity--;
    return result;
}

std::string Sequence::removeEnd()
{
    if(first == NULL)
    {
        return "";
    }
    
    if (first->getNext() == NULL) {
        return removeBegin();
    }
    
    Node<std::string>* curr = first;
    Node<std::string>* prev = NULL;
    
    while( curr->getNext() != NULL )
    {
        prev = curr;
        curr = curr->getNext();
    }
    
    prev->setNext(NULL);
    std::string result = curr->getValue();
    delete curr;
    this->quantity--;
    return result;
}

Node<std::string>* Sequence::getFirst()
{
    return this->first;
}

void Sequence::print(void)
{
    Node<std::string> *n = this->first;
    while(n != nullptr)
    {
        std::cout << n->getValue() << " ";
        n = n->getNext();
    }
    std::cout << std::endl;
}

bool Sequence::isEmpty()
{
    return this->getQuantity() == 0;
}

int Sequence::getQuantity()
{
    return this->quantity;
}
