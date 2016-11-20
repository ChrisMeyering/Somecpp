// Author: Chris Meyering
// Date Created: 10/19/2014
// Date Modified 10/24/2014
// Few comments bellow because every function's use is very 
// straightforward

#ifndef NODE_H
#define NODE_H
#include <cstddef>

template <class Type> class Node 
{
  private:
    Node* next;
    Type value;
  public:
    Node();
    Node(const Node& orig);
    bool hasNext();
    Node* getNext();
    void setNext(Node* newNext);
    Type getValue();
    void setValue(Type val);
};

template <class Type>
Node<Type>::Node() 
{
  next = NULL;
}

template <class Type>
Node<Type>::Node(const Node& orig) 
{
  next = orig.next;
  value = orig.value;
}

template <class Type>
bool Node<Type>::hasNext()
{
  if (next != NULL)
    return true;
  else 
    return false;
}

template <class Type>
Node<Type>* Node<Type>::getNext()
{
  return next;
}

template <class Type>
void Node<Type>::setNext(Node* newNext)
{
  if(newNext == NULL)
    next = NULL;
  else 
    next = newNext;
}

template <class Type> 
Type Node<Type>::getValue()
{
  return value;
}


template <class Type>
void Node<Type>::setValue(Type val)
{
  value = val;
}

#endif
