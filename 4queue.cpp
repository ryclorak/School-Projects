/*************
Karol Cyrklaff
Queue Functions
02/09/20
*************/

#include <iostream>
#include <queue>
#include <fstream>

using namespace std;

struct Node
{
  int value;
  Node* next;
};

void Traverse(Node*);
void Enqueue(Node*&, Node*&, int);
int Dequeue(Node*, Node*);

int main()
{
  Node* f = new Node;
  Node* r = new Node;
  f = nullptr;
  r = nullptr;
  int n = 666;
  ifstream inF;
  cout << "Opening input.txt..." << endl;
  inF.open("input.txt");
  if (inF.is_open())
  {
    cout << "Populating queue..." << endl;
  }
  while (!inF.eof())
  {
    inF >> n;
    Enqueue(f, r, n);
  }
  cout << "Traversing queue..." << endl;
  Traverse(f);

  cout << "Dequeue once..." << endl;
  Dequeue(f, r);
  Traverse(f);

  cout << "Dequeue again..." << endl;
  Dequeue(f, r);
  Traverse(f);



  cout << "Getting rid of negatives..." << endl;
/*
  while (f)
  {
    if (f->value > 0)
    {
      Enqueue(f, r, f->value);
    }
    else
    {
      Dequeue(f, r);
    }
  }
*/
  Traverse(f);



  return 0;
}

void Traverse(Node* q)
{
  while (q)
  {
    cout << q->value << endl;
    q = q->next;
  }
}

void Enqueue(Node*& fron, Node*& rear, int value)
{
  Node* nn = new Node;
  nn->value = value;
  nn->next = nullptr;
  if (!fron)
  {
    rear = fron = nn;
  }
  else
  {
    rear->next = nn;
    rear = nn;
  }
}

int Dequeue(Node* fron, Node* rear)
{
  Node* temp = new Node;
  int val;
  if (fron)
  {
    temp = fron;
    fron = fron->next;
    val = temp->value;
    delete temp;
    if (!fron)
    {
      rear = fron;
    }
  }
  return val;
}
