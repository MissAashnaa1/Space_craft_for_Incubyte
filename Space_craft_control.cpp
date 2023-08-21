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

  void execute_commands(const std::vector<char> &commands)
  {
    for (char cmd : commands)
    {
      if (cmd == 'f')
      {
        move(1);
      }
      else if (cmd == 'b')
      {
        move(-1);
      }
      else if (cmd == 'l')
      {
        turn_left();
      }
      else if (cmd == 'r')
      {
        turn_right();
      }
      else if (cmd == 'u')
      {
        turn_up();
      }
      else if (cmd == 'd')
      {
        turn_down();
      }
    }
  }
};
int main()
{

  string initial_direction = "";
  cin >> initial_direction;
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