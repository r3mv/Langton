#ifndef LANGTON_WORLD_HPP
#define LANGTON_WORLD_HPP

#include <boost/multi_array.hpp>

/**
 * Defines the world known by the ants
 */

typedef unsigned char langton_t;
const size_t LANGTON_WORLD_DIMENSION = 2;

typedef boost::multi_array<langton_t, LANGTON_WORLD_DIMENSION> World;

// class World
// {
// public:
//   World(boost::extents extents);

//   ~World();

// private:
//   WorldType array;

// };

#endif // LANGTON_WORLD_HPP
