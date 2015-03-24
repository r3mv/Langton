#include "world.hpp"
#include <iostream>



/**
 * Just a small test executable to get to know how to use boost::multiarray
 */
void
print(const World &w)
{

  World::size_type numDim = w.num_dimensions();
  assert(numDim == LANGTON_WORLD_DIMENSION);
  const World::size_type* extents = w.shape();
  const World::index* strides = w.strides();

  std::cout << "World is a " << numDim << " dimensional array with the following extents" << std::endl;
  for(World::size_type i = 0; i < numDim; ++i) {
    std::cout << extents[i] << " (" << strides[i] << ")" << std::endl;
  }

}

int
main(int argc, char **)
{

  World w(boost::extents[10][10]);

  print(w);

  World w2(boost::extents[25][10]);
  print(w2);
  
  return 0;
}
