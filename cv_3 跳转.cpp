#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <iostream>
#include <fstream>

using namespace std;
using namespace cv;

int g_slider_pisition = 0;
int g_run = 1, g_dontset = 0;
VideoCapture g_cap;

void onTrackbarSlider(int pos, void*) {
	g_cap.set(CAP_PROP_POS_FRAMES, pos);

	if (!g_dontset)
		g_run = 1;
	g_dontset = 0;
	cout << "huidiaohanshu " << endl;
}

int main(int argc, char** argv) {
	namedWindow("example", WINDOW_AUTOSIZE);
	g_cap.open("C:\\Users\\Administrator\\Desktop\\1.MPG");
	int frames = (int)g_cap.get(CAP_PROP_FRAME_COUNT);
	int tmpw = (int)g_cap.get(CAP_PROP_FRAME_WIDTH);
	int tmph = (int)g_cap.get(CAP_PROP_FRAME_HEIGHT);

	cout << "video has " << frames << "frames of dimensions£¨" << tmpw << "," << tmph << ")." << endl;

	createTrackbar("position", "example", &g_slider_pisition, frames, onTrackbarSlider);

	Mat frame;
	for (;;) {
		if (g_run != 0) {
			g_cap >> frame;
			if (frame.empty())
				break;
			int current_pos = (int)g_cap.get(CAP_PROP_POS_FRAMES);
			cout << "****" <<  "g_dontset = " << g_dontset << endl;
			g_dontset = 1;
			cout << "g_dontset = " << g_dontset << endl;
			setTrackbarPos("position", "example", current_pos);
			imshow("example", frame);
			g_run  -= 1;
			cout << "g_run = " <<  g_run << endl;
		}
		char c = (char)waitKey(10);
		if (c == 's') //single step
		{
			g_run = 1;
			cout << "single step, run = " << g_run << endl;
		}
		if (c == 'r')// run mode
		{
			g_run = -1;
			cout << "run mode , run = " << g_run << endl;
		}
		if (c == 27)
			break;
	}
	return 0;
}
