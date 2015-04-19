#include <cstdlib>
#include <stdio.h>
#include <iostream>
#include <opencv2/opencv.hpp>
#include <opencv2/highgui/highgui.hpp>

using namespace cv;
//using namespace std;

int main(int argc, char** argv){
	std::cout << "Hellodisplay" << std::endl;
	IplImage* img = cvLoadImage(argv[1]); // allocate the image 	
	std::cout << "allocated image" << std::endl;
	cvNamedWindow("TestCV", CV_WINDOW_AUTOSIZE); // create a window that will display the image
	std::cout << "created window" << std::endl;
	cvShowImage("TestCV", img); // put the image into the window	
	std::cout << "showing image" << std::endl;
	cvWaitKey(0); 				// wait for a keystroke. If not 0, will wait for that many millis
	cvReleaseImage(&img); 		// deallocate the memory for the image	
	cvDestroyWindow("TestCV"); // as it says	

	return 0;
}
