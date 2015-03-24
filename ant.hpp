#ifndef LANGTON_ANT_HPP
#define LANGTON_ANT_HPP

#include <opencv2/opencv.hpp>
#include "world.hpp"

class Ant
{


public:

  Ant(int x, int y, int dir,  World &grid);
  
  virtual ~Ant();

  void
  iterate();
  
private:
  void
  rotate(unsigned char);

  void 
  swapColors(unsigned char);
  
  void
  move();

private:

  int x;
  int y;
  int dir;
  
  //cv::Mat &grid;

  World& world;
  

};

#endif
