#include <iostream>
#include <opencv2/opencv.hpp>

#include <gst/gst.h>
#include "tcamprop.h" 

using namespace cv;
using namespace std;

int main(){











    cv::Mat frame;
    cv::VideoCapture cap(0);
    if(!cap.isOpened()){
        
        cout<<"Cannot open camera"<<endl;
        return -1;
    }

    while(true){   
        if(!cap.read(frame))
            break;
        cv::Mat src = cv::Mat(frame);
        cv::imshow( "window",  src );
        cv::waitKey(30);
    }

	return 0;
}
