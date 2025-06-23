/* Canny edge detection on live USB camera feed using OpenCV libs */

#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"

#include <iostream>
#include <stdio.h>
#include <stdlib.h>

using namespace std;
using namespace cv;

int main(int argc, char** argv){

	namedWindow("Canny edge detection", WINDOW_NORMAL);
	namedWindow("Live USB Camera", WINDOW_NORMAL);

	/* Here the USB camera is /dev/video0 --> is device '0'.
	   Adjust the camera device ID according to he /dev/video* device it is connected to. */
	cv::VideoCapture cap(0);
    cv::Mat in_video;
    cv::Mat out_video;

	if(!cap.isOpened()){
		std::cout << "ERROR: Could not open Camera" << std::endl;
		return -1;
	}
    
	while(true) {
    	cap >> in_video;
		cvtColor(in_video, out_video, COLOR_BGR2GRAY);
		
    	Canny(out_video, out_video, 100, 200, 3);
		cv::imshow("Live USB Camera", in_video);
		cv::imshow( "Canny edge detection", out_video);
			
		/* Press 'c' to break */
		char c = cv::waitKey(33);
    	if( c == 'c' ) break;
    }
   	return 0;
}








