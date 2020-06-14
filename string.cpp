#include <iostream>
#include <fstream>

using namespace std;

ifstream in("input.txt");
ofstream out("output.txt");


int strLen(char* A)
{
   int len = 0;
	while (A[len] != '\0')
		len++;

	return len;
}

int stringLength(char* A)
{
   char Q[20];
	int len = 0;
	while (A[len] != '\0')
		len++;

   for (int i=0; i < len; ++i)
   {
      Q[i] = A[i];
   }
   //char z = '0' + len;
   A[0] = len; // if this is converted to a char, return value is corrupted
   int j;
   for (j=1; j <= len; ++j)
   {
      A[j] = Q[j-1];
   }
   A[j] = '\0';
	return A[0];
}

void stringCopy(char* A, char* B)
{
   int i;
	for (i=0; i<strLen(B); ++i)
	{
		A[i] = B[i];
	}
	A[i]='\0';
}

bool stringCompare(char* A, char* B)
{
	for (int i=0; i<strLen(A); ++i)
	{
		if (A[i] != B[i])
			return false;
	}
	return true;
}

void stringConcatenation(char* A, char* B)
{
   int i;
   int j=0;
	for (i=strLen(A); i<(strLen(A) + strLen(B)); ++i)
	{
		A[i] = B[j];
		j++;
	}
	A[i] = '\0';
}

int stringPosition(char* A, char B)
{
	for (int i=0; i < strLen(A); ++i)
	{
		if (A[i] == B)
			return i;
	}
	return -1;
}




int main()
{
   char a[6] = "apple";
   char b[7] = "banana";
   char c[6] = "curry";
   char d[10] = "dumplings";
   char e[8] = "eclairs";
   char f[12] = "frenchFries";
   char g[12] = "frenchFries";

   cout << "List of test words: " << "a: " << a << endl << "b: " << b << endl << "c: " << c << endl
        << "d: " << d << endl << "e: " << e << endl << "f: " << f << endl << "g: " << g << endl;

   cout << "Length of apple, strLen: " << strLen(a) << endl;
   cout << "a: " << a << endl;
   cout << "Length of apple, stringLength: " << stringLength(a) << endl;
   cout << "a: " << a << endl;

   cout << "Copying banana to apple..." << endl;
   stringCopy(a, b);
   cout << "a: " << a << "\nb: " << b << endl;

   cout << "Comparing c to d..." << endl << stringCompare(c, d) << endl;
   stringCompare(c, d);
   cout << "c: " << c << "\nd: " << d << endl;
   cout << "Comparing f to g..." << endl << stringCompare(f, g) << endl;
   stringCompare(f, g);
   cout << "f: " << f << "\ng: " << g << endl;

   cout << "Concatenating e and f..." << endl;
   stringConcatenation(e, f);
   cout << "e: " << e << "\nf: " << f << endl;

   cout << "Finding string position of 'F' in f..." << endl << stringPosition(f, 'F') << endl;
   cout << "f: " << f << endl;

    in.close();
    out.close();

    return 0;
}

