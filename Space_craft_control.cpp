#include <iostream>
#include <bits/stdc++.h>
using namespace std;
class Spacecraft
{
private:
  int x, y, z;
  string direction;
  int angle;

public:
  Spacecraft(int x, int y, int z, string direction)
  {
    this->x = x;
    this->y = y;
    this->z = z;
    this->direction = direction;
    this->angle = 0;
  }
};
int main()
{
  {
    cout << "h";
    string initial_direction = "N";
    Spacecraft spacecraft(0, 0, 0, initial_direction);
    vector<char> commands;
    while (true)
    {
      char ch;
      cin >> ch;
      if (ch == '0')
        break;
      commands.push_back(ch);
    }

    spacecraft.execute_commands(commands);

    cout << "Final Position: (" << spacecraft.getX() << ", " << spacecraft.getY() << ", " << spacecraft.getZ() << ")\n";
    cout << "Final Direction: " << spacecraft.getDirection() << "\n";
    cout << "Final Angle: " << spacecraft.getAngle() << " degrees\n";

    return 0;
  }