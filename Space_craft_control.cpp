#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main()
{
  cout << "h";
  string initial_direction = "N";

  vector<char> commands;
  while (true)
  {
    char ch;
    cin >> ch;
    if (ch == '0')
      break;
    commands.push_back(ch);
  }

  return 0;
}