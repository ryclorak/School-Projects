/*************
Karol Cyrklaff
Infix To Postfix
02/16/20
*************/

#include <iostream>
#include <fstream>
#include <stack>

using namespace std;

struct Node
{
  int value;
  Node* next;
};

int Prec(char);
void Traverse(Node*);
void Enqueue(Node*&, Node*&, int);
int Dequeue(Node*, Node*);


int main()
{
  stack <char> s;
  Node* f = new Node;
  Node* r = new Node;
  f = nullptr;
  r = nullptr;
  char* infix = nullptr;
  ifstream inF;
  cout << "Opening input.txt..." << endl;
  inF.open("input.txt");
  if (inF.is_open())
  {
    cout << "it worked" << endl;
  }
  while (!inF.eof())
  {
    inF >> infix;
  }

  int i = 0;

  while (infix[i] != '\0')
  {
    if (infix[i] >= '0' && infix[i] <= '9')
      cout << infix[i];
    else
    {
      if (Prec(infix[i]) > Prec(s.top()))
      {
        s.push(infix[i]);
        i++;
      }
      else if (Prec(infix[i]) < Prec(s.top()))
      {
        Enqueue(f, r, infix[i]);
      }
    }
  }

  return 0;
}

int Prec(char a)
{
  int p;
  switch (a)
      {
      case '=' :
        p = 0;
        break;
      case '(' :
        p = 1;
        break;
      case '+' :
      case '-' :
        p = 2;
        break;
      case '*' :
      case '/' :
        p = 3;
        break;
      case '^' :
        p = 4;
        break;
      }
      return p;
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

