#include "ImageSource.h"
#include "CameraParameters.h"

using namespace std;

int main(){

    osvr::vbtracker::CameraParameters camParams 
        = osvr::vbtracker::getHDKCameraParameters();

    Camera_Config config;
    config.width = 744;
    config.height = 480;
    config.device_num = 1;

    ImageSource DMK(config);

    int wKey = -1;
    while(wKey == -1 ){

        cv::Mat m = DMK.SnapFrame(); 
        cv::imshow("video demo", m);
        wKey = cvWaitKey(10);   
    }

    return 0;
}
