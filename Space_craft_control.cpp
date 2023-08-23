#include <iostream>
#include <bits/stdc++.h>
using namespace std;
class Spacecraft
{
private:
  int x, y, z;
  string faceDirection;
  string moveDirection;

public:
  Spacecraft(int x, int y, int z, string direction)
  {
    this->x = x;
    this->y = y;
    this->z = z;
    this->faceDirection = direction;
    this->moveDirection = direction;
  }

  void move(int distance)
  {
    if (moveDirection == "N")
    {
      y += distance;
    }
    else if (moveDirection == "S")
    {
      y -= distance;
    }
    else if (moveDirection == "E")
    {
      x += distance;
    }
    else if (moveDirection == "W")
    {
      x -= distance;
    }
    else if (moveDirection == "Up")
    {
      z += distance;
    }
    else if (moveDirection == "Down")
    {
      z -= distance;
    }
  }

  void turn_left()
  {
    if (faceDirection == "N")
    {
      faceDirection = "W";
      moveDirection = "W";
    }
    else if (faceDirection == "S")
    {
      faceDirection = "E";
      moveDirection = "E";
    }
    else if (faceDirection == "E")
    {
      faceDirection = "N";
      moveDirection = "N";
    }
    else if (faceDirection == "W")
    {
      faceDirection = "S";
      moveDirection = "S";
    }
  }

  void turn_right()
  {
    if (faceDirection == "N")
    {
      faceDirection = "E";
      moveDirection = "E";
    }
    else if (faceDirection == "S")
    {
      faceDirection = "W";
      moveDirection = "W";
    }
    else if (faceDirection == "E")
    {
      faceDirection = "S";
      moveDirection = "S";
    }
    else if (faceDirection == "W")
    {
      faceDirection = "N";
      moveDirection = "N";
    }
  }

  void turn_up()
  {
    moveDirection = "Up";
  }

  void turn_down()
  {
    moveDirection = "Down";
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

  string getFaceDirection() { return faceDirection; }
};
int main()
{

  string initial_direction;
  cout << "Enter Initial Direction\n N for North\n S for South \n E for East \n W for West" << endl;

  cin >> initial_direction;
  int x, y, z;
  cout << "Enter x coordinate" << endl;
  cin >> x;
  cout << "Enter y coordinate" << endl;
  cin >> y;
  cout << "Enter z coordinate" << endl;
  cin >> z;
  Spacecraft spacecraft(x, y, z, initial_direction);
  vector<char> commands;
  cout << "Enter commands and for ending press \"0\"" << endl;
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
  cout << "Final Direction: " << spacecraft.getFaceDirection() << "\n";

  return 0;
}