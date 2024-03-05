#include <iostream>
#include <string>
#include <cmath>
#include <cstdlib> // For rand and srand
#include <ctime>   // For time function
using namespace std;
int ReadNumberOfIteration(int &Counter1)
{
  do
  {
    cout << "How many the rounds the game will be? ";
    cin >> Counter1;
  } while (Counter1 <= 0);
  return Counter1;
}
int ReadNumber(int &Number)
{
  do
  {
    cout << "Choose the choice Number (1 = paper , 2 = a rock , 3 = scissors) :";
    cin >> Number;
  } while (Number > 3 || Number < 1);
  return Number;
}
int RandomNumber(int to, int from)
{
  return rand() % (to - from + 1) + from;
}
void CheckChoice(int Number, int Counter1)
{
  int CounterWin = 0, CounterFail = 0, CounterTie = 0;
  for (int i = 0; i < Counter1; i++)
  {
    ReadNumber(Number);

    if ((Number == 1 && RandomNumber(1, 3) == 2) ||
        (Number == 2 && RandomNumber(1, 3) == 3) ||
        (Number == 3 && RandomNumber(1, 3) == 1))
    {
      cout << "You win" << endl;
      system("color 2f");
      CounterWin++;
    }
    else if ((Number == 2 && RandomNumber(1, 3) == 1) ||
             (Number == 3 && RandomNumber(1, 3) == 2) ||
             (Number == 1 && RandomNumber(1, 3) == 3))
    {
      cout << "You fail" << endl;
      system("color 4f");
      CounterFail++;
    }
    else
    {
      cout << "It's a tie" << endl; 
      system("color 1f ");
      CounterTie++;
    }
  }
  cout << "You win " << CounterWin << " rounds." << endl;
  cout << "You fail " << CounterFail << " rounds." << endl;
  cout << "You Tie   " << CounterTie << " rounds." << endl;
}
int main()
{
  srand((unsigned)time(NULL));

  int Number = 0, Counter1 = 0;

  ReadNumberOfIteration(Counter1);
  CheckChoice(Number, Counter1);

  return 0;
}