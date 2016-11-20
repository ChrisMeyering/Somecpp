// Author: Chris Meyering
// Date Created: 10/19/2014
// Date Modified 10/24/2014
// Few comments bellow because every function's use is very 
// straightforward

#ifndef NODE_H
#define NODE_H
#include <cstddef>

class Node 
{
  private:
    Node* next;
    int value;
  public:
    Node();
    Node(const Node& orig);
    bool hasNext();
    Node* getNext();
    void setNext(Node* newNext);
    int getValue();
    void setValue(int val);
};

Node::Node() 
{
  next = NULL;
}

Node::Node(const Node& orig) 
{
  next = orig.next;
  value = orig.value;
}

bool Node::hasNext()
{
  if (next != NULL)
    return true;
  else 
    return false;
}

Node* Node::getNext()
{
  return next;
}

void Node::setNext(Node* newNext)
{
  if(newNext == NULL)
    next = NULL;
  else 
    next = newNext;
}

int Node::getValue()
{
  return value;
}



void Node::setValue(int val)
{
  value = val;
}

#endif
