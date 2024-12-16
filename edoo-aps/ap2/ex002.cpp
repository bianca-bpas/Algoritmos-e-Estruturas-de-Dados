#include <iostream>
using namespace std;

int main() {
  char ch;
  string word;
  cin >> "Let's go! Press the return key: " >> ch;
  cout << "Enter a word containing three characters at most: ";
  cin >> word;
  cout << "Your input: " << ch << endl;

  return 0;
}
