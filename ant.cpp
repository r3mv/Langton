#include "ant.hpp"

Ant::Ant(WorldCoord start, int dir, World &grid)
  : coords(start), dir(dir), world(grid)
{}


Ant::~Ant()
{
}


void
Ant::iterate()
{
  unsigned char val = world(coords); 
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
      world(coords) = 255;
      break;
    case 255:
      world(coords) = 0;
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
      coords[1] = (coords[1]+1)%extents[1];
      break;
      case 1:
      	coords[1] = (coords[1]+1)%extents[1];
      	coords[0] = (coords[0]+extents[0]-1)%extents[0];
      	break;
    case 2:
      coords[0] = (coords[0]+extents[0]-1)%extents[0];
      break;
      case 3:
      	coords[0] = (coords[0]+extents[0]-1)%extents[0];
      	coords[1] = (coords[1]+extents[1]-1)%extents[1];
      	break;
    case 4:
      coords[1] = (coords[1]+extents[1]-1)%extents[1];
      break;
      case 5:
      	coords[1] = (coords[1]+extents[1]-1)%extents[1];
      	coords[0] = (coords[0]+1)%extents[0];
      	break;
    case 6:
      coords[0] = (coords[0]+1)%extents[0];
      break;
      case 7:
      	coords[0] = (coords[0]+1)%extents[0];
      	coords[1] = (coords[1]+1)%extents[0];
      	break;
    default:
      assert(false);
    }
}
