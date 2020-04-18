#include <iostream>
#include <opencv2/opencv.hpp>

int main(int argc, char**argv) {
  std::cout<< "Hello world" <<std::endl;
  cv::Mat img(500, 500, CV_8UC3, cv::Scalar(50,150,250));
  cv::imshow("img", img);
  cv::waitKey(0);
  return 0;
}
