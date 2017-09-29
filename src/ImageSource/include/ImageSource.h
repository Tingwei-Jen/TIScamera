/*
 * ImageSource.h
 *
 *  Created on: Sep 20, 2017
 *      Author: tingwei
 */

#include <iostream>
#include <string>
#include <opencv2/opencv.hpp>

#include "v4ldevice.h"

#ifndef IMAGESOURCE_H_
#define IMAGESOURCE_H_

struct Camera_Config{

    int width;
    int height;
    int device_num;

};

class ImageSource{
public:
    ImageSource(Camera_Config _config);
    ~ImageSource();
    cv::Mat SnapFrame();

private:
    v4ldevice device;
    IplImage* pOpenCVImage;
    IplImage* pColorCVImage;
    CvSize ImageSize;
    unsigned char* ImageBuffer = NULL;

    std::string _device_name;
    cv::Mat m;
};

#endif /* IMAGESOURCE_H_ */