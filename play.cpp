#include <iostream>
using namespace std;
void split(int n, int N[]);
bool nopezero(int n);
bool noperepeat(int n);
void check(int t, int test, int* checkA, int* checkB);
int main()
{
 int a=0;
 int b=0;
 int allnum[3024] = { 0 };

 int num = 1234;
 for (int i = 0; num < 9876; num++)
 {
  if (nopezero(num) && noperepeat(num))
  {
   allnum[i] = num;
   i++;
  }
 }

 int g;
 while (a != 4)
 {
  for (int i = 0; i < 3024; i++)
  {
   if (allnum[i] != -1)
   {
    g = allnum[i];
    cout << "電腦猜測:"<<g << endl;
    allnum[i] = -1;
    break;
   }
  }
  cout << "A:";
  cin >> a;
  cout << "B:";
  cin >> b;

  int checkA;
  int checkB;
  for (int i = 0; i < 3024; i++)
  {
   if (allnum[i] != -1)
   {
    check(g, allnum[i], &checkA, &checkB);
    if (checkA != a || checkB != b)
     allnum[i] = -1;
   }
  }
 }
 return 0;
}
void split(int n, int N[])
{
 N[0] = n / 1000;
 N[1] = (n / 100) % 10;
 N[2] = (n / 10) % 10;
 N[3] = n % 10;
}
bool nopezero(int n)
{
 int N[4];
 split(n, N);
 return (N[0] != 0 && N[1] != 0 && N[2] != 0 && N[3] != 0);
}
bool noperepeat(int n)
{
 int N[4];
 split(n, N);
 int a[10] = { 0,1,2,3,4,5,6,7,8,9 };
 for (int i = 0; i < 4; i++)
 {
  if (a[N[i]] == -1)
   return false;
  else
   a[N[i]] = -1;
 }
 return true;
}
void check(int t, int test, int* checkA, int* checkB)
{
 *checkA = 0;
 *checkB = 0;

 int T[4];
 int TEST[4];
 split(t, T);
 split(test, TEST);
 int a[10] = { 0,1,2,3,4,5,6,7,8,9 };
 for (int i = 0; i < 4; i++)
  a[T[i]] = -1;
 for (int i = 0; i < 4; i++)
 {
  if (a[TEST[i]] == -1)
  {
   if (TEST[i] == T[i])
    *checkA += 1;
   else
    *checkB += 1;
  }
 }
}
