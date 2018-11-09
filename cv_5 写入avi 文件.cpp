#include <opencv2\opencv.hpp>
#include <iostream>

using namespace std;
using namespace cv;

int main(int argc, char* argv[])
{
	namedWindow("example2_11", WINDOW_AUTOSIZE);
	namedWindow("log_polar", WINDOW_AUTOSIZE);

	VideoCapture capture("C:\\Users\\Administrator\\Desktop\\1.MPG");

	double fps = capture.get(CAP_PROP_FPS);
	Size size((int)capture.get(CAP_PROP_FRAME_WIDTH), (int)capture.get(CAP_PROP_FRAME_HEIGHT));

	VideoWriter writer;
	writer.open("C:\\Users\\Administrator\\Desktop\\2.MPG", CV_FOURCC('M', 'J', 'P', 'G'), fps, size);

	Mat logpolar_frame, bgr_frame;
	for (;;) {
		capture >> bgr_frame;
		if (bgr_frame.empty())
			break;
		imshow("example2_11", bgr_frame);
		logPolar(bgr_frame, logpolar_frame, Point2f(bgr_frame.cols / 2, bgr_frame.rows / 4), 40, WARP_FILL_OUTLIERS	);
		imshow("log_polar", logpolar_frame);
		writer << logpolar_frame;
		char c = waitKey(10);
		if (c == 27)
			break;

	}
	capture.release();
}