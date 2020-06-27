/*************
Karol Cyrklaff
02/09/20
Convert Binary to Hexadecimal
*************/

#include <iostream>
#include <stack>

using namespace std;


int main()
{
  stack <int> s;
  int x;
  int divRes;
  int modRes;

  cout << ">>";
  cin >> x;
  divRes = x;
  while (divRes != 0)
  {
    modRes = divRes % 2;
    s.push(modRes);
    divRes /= 2;
  }

  cout << "Binary representation of " << x << " is: ";
  while (! s.empty())
  {
    cout << s.top();
    s.pop();
  }

  divRes = x;
  while (divRes != 0)
  {
    modRes = divRes % 16;
    s.push(modRes);
    divRes /= 16;
  }

  cout << "\n\nHexadecimal representation of " << x << " is: ";
  while (! s.empty())
  {
    if (s.top() > 9)
    {
      switch(s.top())
      {
        case 10: cout << 'a';
        break;
        case 11: cout << 'b';
        break;
        case 12: cout << 'c';
        break;
        case 13: cout << 'd';
        break;
        case 14: cout << 'e';
        break;
        case 15: cout << 'f';
        break;
      }
    }
      else
      {
        cout << s.top();
      }
      s.pop();
    }

  return 0;
}


