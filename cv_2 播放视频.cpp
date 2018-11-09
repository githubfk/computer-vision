#include <opencv2/opencv.hpp>


using namespace cv; 
int main()
{ 


	VideoCapture capture("C:\\Users\\Administrator\\Desktop\\1.MPG");
	Mat frame;
	Mat edge;
	while(true)
	{

		capture >> frame;
		if (frame.empty())
			break;

		cvtColor(frame, edge, COLOR_BGR2GRAY);

		blur(edge, edge, Size(7, 7));
		
		Canny(edge, edge, 10, 30);

		imshow("example", frame);

		imshow("After canny", edge);
		if (waitKey(33) >= 0)
			break;
	}
	return 0; 
}

