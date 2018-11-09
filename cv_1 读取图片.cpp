#include <opencv2\opencv.hpp>
#include <iostream>
int main(int argc, char** argv)
{
	cv::Mat My_img = cv::imread("C:\\Users\\Administrator\\Desktop\\1.jpg");
	
	if (My_img.empty())
		return -1;
	cv::namedWindow("example", cv::WINDOW_AUTOSIZE);
	cv::imshow("example", My_img);
	cv::waitKey(11110);
	cv::destroyWindow("example");
	return 0;
}
