#include <iostream>
using namespace std;

class Human{
public:
  Human();
  Human(int theID, string theName, string theLevel);
  ~Human();
  int getID();
  string getName();
  string getLevel();
  void setID(int id);
  void setName(string theName);
  void setLevel(string theLevel);
private:
  int id;
  string name;
  string level;
};
