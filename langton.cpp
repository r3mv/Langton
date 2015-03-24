#include <opencv2/opencv.hpp>

#include "ant.hpp"



int
main()
{

  const int size = 1200;

  World w(boost::extents[100][100]);

  World::size_type numDim = w.num_dimensions();
  std::vector<int> dims(numDim);
  for (int i = 0; i < numDim; ++i) {
    dims[i] = w.shape()[i];
  }
  cv::Mat m(w.num_dimensions(), &dims[0], CV_8U, w.origin());

  cv::namedWindow("Langton", 0);
  cv::imshow("Langton", m);

  Ant a(m.rows/2, m.cols/2, 0, w);

  Ant b(rand()%m.rows, rand()%m.cols, 4, w);

  char c = 'a';
  long iter = 0;
  // while ((c = cv::waitKey(0)) != 'q') {
  for (; c != 'q'; iter++) {
    a.iterate();
        b.iterate();
    if (iter%10 == 0) {
      std::cout << "Iter " << iter << std::endl;
      cv::imshow("Langton", m);
      c = cv::waitKey(2);
    }
  }

}
