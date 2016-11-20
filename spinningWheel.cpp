// Author: Chris Meyering
// Class: CS 110C
// Created: Monday October 19th 2014
// Semester: Fall 2014
// Instructor: Steve Abensohn
// Input: Whether or not the user wants to play again
// Output: A virtual wheel represented by a series of 20 numbers printed out
//         on a line. One line is equivalent to one whole wheel-revolution
//         This program will print from 20 to 39 random multiples of
//         5 between 5 and 100. Keeps track of number of times the user
//         spinned the wheel. Keeps track of how many points the user got so 
//         far.
// Last Modified: Thursday October 23rd 2014
// Modified by: Chris Meyering


#include "Node.h"
#include <iostream>
#include <stdlib.h>
#include <time.h>
using namespace std;

void again(bool &playAgain);
void spinWheel(Node *&head, Node *&current);
void playGame(Node *&head);
void initializeNode(Node *&head);

// number of values the wheel will have.
const unsigned int NUM_OF_VALUES = 20;


// Call necessary functions to play the game. Create a Node object and
// instantiate a random seed generator.
int main()
{
  srand (time(NULL));
  Node *head = new Node();
  initializeNode(head);
  playGame(head);
  while (head)
  {
    Node* nextNode = head->getNext();
    delete head;
    head = nextNode;
  } //equivalent to a destructor but cleaner in my opinion
  return 0;
}

  



// Create a list of 20 randomly generated multiples of 5 going from
// 5 to 100. Same number can appear multiple times.
void initializeNode(Node *&head)
{
  Node *wheel;
  wheel = head;
  for (unsigned int i = 0; i < NUM_OF_VALUES; i++)
  {
    int randNum = (rand() % 20 + 1) * 5;
    Node *newNode = new Node;
    newNode->setValue(randNum);
    newNode->setNext(NULL);
    wheel->setNext(newNode);
    wheel = newNode;
  }
}




// Spins the wheel as long as user enters y or Y
void playGame(Node *&head){
  Node *current = head->getNext();
  int spinNum = 1;
  int points = 0;
  bool playAgain = 1;
  do
  {
    cout << "Spin " << spinNum << ":\n";
    spinWheel(head, current);
    points += current->getValue();
    cout << "Points so far: " << points << endl;
    again(playAgain);
    spinNum++;
  } while (playAgain);
}



// Will spin the wheel once (between 20 and 39 positions)
void spinWheel(Node *&head, Node *&current){
  cout << "       ";
  int randNum2 = (rand() % 20 + 20);
  for (int i = 0; i < randNum2; i++)
  {
    if (current == NULL) // if end of list go to beginning
      current = head->getNext();
    if (i == 20)  // print a new line every 20
      cout << endl << "       ";
    cout << current->getValue() << " ";
    if (i != randNum2 - 1) // keep pointer on most recent position.
      current = current->getNext();
  }
  cout << endl;
}



// Determine whether or not the user wants to spin again.
void again(bool &playAgain)
{
  char answer;
  try
  {
    cout << "Spin again (y/n)? ";
    cin >> answer;
    throw answer;
  }
  catch (char e1)
  {
    if (e1 == 'y' || e1 == 'Y') {
      cout << endl;
    } else if (e1 == 'n' || e1 == 'N'){
      cout << "See you soon!\n";
      playAgain = 0;
    } else {
      cout << "Invalid entry: " << e1 << endl;
      cout << "Program will now be terminated.\n";
      playAgain = 0;
    }
  }
}
