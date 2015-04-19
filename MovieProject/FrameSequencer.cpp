#include <cstdlib>
#include <iostream>
#include <stdio.h>
#include <opencv2/opencv.hpp>
#include <opencv2/highgui/highgui.hpp>

using namespace cv;
using namespace std;

int main(int argc, char** argv){
	cvNamedWindow( "Frame Sequence", CV_WINDOW_AUTOSIZE);
	CvCapture* movie = cvCreateFileCapture(argv[1]);
	IplImage* frame;
	int counter = 0;
	while(true){
		frame = cvQueryFrame(movie);
		if(!frame){
			cout << "No more frames." << endl;
			break;
		}
		counter++;
		cout << "Frame # " << counter << endl;
		if(counter%3 == 0){
		// show every 3 frames
			cvShowImage("Frame Sequence", frame);
			char c = cvWaitKey(10);		
		}
		//cvShowImage("Frame Sequence", frame);
		//char c = cvWaitKey(30);
		//if(c == 27){
		//	cout << "Chose to exit..." << endl;
		//	break;
		//}
	}
	cvReleaseCapture(&movie);
 	cvDestroyWindow("Frame Sequence");
	return 0;
}
