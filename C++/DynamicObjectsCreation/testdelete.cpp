#include<iostream>
using namespace std;
int main()
{
   int a = 10, *b;
   b = &a;
   delete b;
   return 0;
}
