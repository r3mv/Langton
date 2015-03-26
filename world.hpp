#ifndef LANGTON_WORLD_HPP
#define LANGTON_WORLD_HPP

#include <array>
#include <boost/multi_array.hpp>

/**
 * Defines the world known by the ants
 */

typedef unsigned char langton_t;
const size_t LANGTON_WORLD_DIMENSION = 2;

typedef boost::multi_array<langton_t, LANGTON_WORLD_DIMENSION> World;

typedef std::array<World::index, LANGTON_WORLD_DIMENSION> WorldCoord;

#endif // LANGTON_WORLD_HPP
