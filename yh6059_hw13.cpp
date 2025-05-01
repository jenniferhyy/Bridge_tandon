#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
#include <vector>
using namespace std; 

const int GRID = 20; 
const int ANTSNUM = 100; 
const int DBUGNUM = 5;
const int ANTBRRED = 3;
const int DBUGBREED = 8;
const int DBUGDIE = 3;
class World;

class Organism {
  int breed;
  int die; 
  char symbol; 
  bool hasMoved;
  public: 
    Organism (int newBreed, int newDie, char newSymbol) : newBreed(breed), newDie(die), newSymbol(symbol), hasMoved(false) {} 
    Organism() : Organism(0, 0, '-') {}
    virtual ~Organism();
    virtual void move(World *world, int prevPosX, int prevPosY, int newPosX, int newPosY) {}; // after moving, 
    virtual void die(World *world, int prevPosX, int prevPosY) {};

};

class Doodlebug : public Organism {
  public: 
    virtual void move() {};
};

class Ant : public Organism {
  public: 
    virtual void move() {};
};

void Doodlebug::move() {
  srand (time(0));
  if (
  
  Move: Every time step, if there is an adjacent ant (up, down, left, or right), then the doodlebug
will move to that cell and eat the ant. Otherwise, the doodlebug moves according to the same
rules as the ant. Note that a doodlebug cannot eat other doodlebugs.
}
/*
Organism class
- virtual move
- breed
- die
- next step
*/



int main(){  
  char grid[20][20];
  for (int i = 0; i < 20; i++){
    for (int j = 0; j < 20; j++){
      grid[i][j] = '-';
    }
  }
  srand (time(0));

  for (int i = 0; i < 100; i++){
    do {
      row = rand() % 20; 
      col = rand() % 20; 
    } while (grid[row][col] != '-';
    grid[row][col] = 'X';
  }

  for (int i = 0; i < 5; i++){
    do {
      row = rand() % 20;
      col = rand() % 20; 
    } while (grid[row][col] != '-';
    grid[row][col] = 'o';
  }

  for (int i = 0; i < 20; i++){
    for (int j = 0; j < 20; j++){
      cout << grid[i][j] << ' ';
    }
    cout << endl;
  }  return 0; 

// critter moves

}
