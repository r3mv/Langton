#include "ant.hpp"

Ant::Ant(int x, int y, int dir, World &grid)
  : x(x), y(y), dir(dir), world(grid)
{}


Ant::~Ant()
{
}


void
Ant::iterate()
{
  unsigned char val = world[x][y]; 
  rotate(val);
  swapColors(val);
  move();
}

void
Ant::rotate(unsigned char val)
{
  switch(val)
    {
    case 0:
      dir = (dir+2)%8;
      break;
    case 255:
      dir = (dir+6)%8;
      break;
    default:
      assert(false);
    }
}

void 
Ant::swapColors(unsigned char val)
{
  switch(val)
    {
    case 0:
      world[x][y] = 255;
      break;
    case 255:
      world[x][y] = 0;
      break;
    default:
      assert(false);
    }
}

void 
Ant::move() 
{
  /**
   * Freeman code
   3  2  1 
   4  *  0 
   5  6  7
  */
  const World::size_type* extents = world.shape();

  switch(dir)
    {
    case 0:
      y = (y+1)%extents[1];
      break;
      // case 1:
      // 	y = (y+1)%extents[1];
      // 	x = (x+extents[0]-1)%extents[0];
      // 	break;
    case 2:
      x = (x+extents[0]-1)%extents[0];
      break;
      // case 3:
      // 	x = (x+extents[0]-1)%extents[0];
      // 	y = (y+extents[1]-1)%extents[1];
      // 	break;
    case 4:
      y = (y+extents[1]-1)%extents[1];
      break;
      // case 5:
      // 	y = (y+extents[1]-1)%extents[1];
      // 	x = (x+1)%extents[0];
      // 	break;
    case 6:
      x = (x+1)%extents[0];
      break;
      // case 7:
      // 	x = (x+1)%extents[0];
      // 	y = (y+1)%extents[0];
      // 	break;
    default:
      assert(false);
    }
}
