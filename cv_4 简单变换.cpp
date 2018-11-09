#include <opencv2/opencv.hpp>

using namespace cv;

void example2_5(const Mat &image) {
	namedWindow("example_in", WINDOW_AUTOSIZE);
	namedWindow("example_out", WINDOW_AUTOSIZE);

	imshow("example_in", image);
	Mat out;
	GaussianBlur(image, out, Size(5, 5), 3, 3);
	GaussianBlur(out, out, Size(5, 5), 3, 3);
	imshow("example_out", out);
	waitKey(0);
}