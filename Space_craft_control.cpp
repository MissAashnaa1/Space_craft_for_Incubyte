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

  void move(int distance)
  {
    if (direction == "N")
    {
      y += distance;
    }
    else if (direction == "S")
    {
      y -= distance;
    }
    else if (direction == "E")
    {
      x += distance;
    }
    else if (direction == "W")
    {
      x -= distance;
    }
    else if (direction == "Up")
    {
      z += distance;
    }
    else if (direction == "Down")
    {
      z -= distance;
    }
  }

  void turn_left()
  {
    if (direction == "N")
    {
      direction = "W";
    }
    else if (direction == "S")
    {
      direction = "E";
    }
    else if (direction == "E")
    {
      direction = "N";
    }
    else if (direction == "W")
    {
      direction = "S";
    }
  }

  void turn_right()
  {
    if (direction == "N")
    {
      direction = "E";
    }
    else if (direction == "S")
    {
      direction = "W";
    }
    else if (direction == "E")
    {
      direction = "S";
    }
    else if (direction == "W")
    {
      direction = "N";
    }
  }

  void execute_commands(vector<char> &commands)
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
  int getX()
  {
    return x;
  }

  int getY()
  {
    return y;
  }
  int getZ()
  {
    return z;
  }
  string getDirection()
  {
    return direction;
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

  return 0;
}