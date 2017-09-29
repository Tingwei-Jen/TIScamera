#include "ImageSource.h"

ImageSource::ImageSource(Camera_Config _config){

    ImageSize.width = _config.width;
    ImageSize.height = _config.height;
    pOpenCVImage = cvCreateImage(ImageSize , IPL_DEPTH_8U, 1 ); // Grayscale
    pColorCVImage = cvCreateImage(ImageSize , IPL_DEPTH_8U, 3 ); // Color image

    _device_name = std::to_string(_config.device_num);
    _device_name =  "/dev/video" + _device_name;
    char *cstr = new char[_device_name.length() + 1];
    strcpy(cstr, _device_name.c_str());

    device.open_device((char*)cstr);
    device.init_device(ImageSize.width, ImageSize.height);
    printf("Device Open\n");
    device.start_capturing();
    printf("Start capturing\n");

}
ImageSource::~ImageSource(){

    device.stop_capturing();
    device.uninit_device();
    device.close_device();
    printf("Device Close\n");

}

cv::Mat ImageSource::SnapFrame(){

    ImageBuffer = device.snapFrame();
    if( ImageBuffer != NULL ){

        memcpy( pOpenCVImage->imageData, ImageBuffer, pOpenCVImage->imageSize);
        cvCvtColor(pOpenCVImage,pColorCVImage,CV_BayerGB2RGB); // Create a color image from the raw data
        m = cv::cvarrToMat(pColorCVImage); 

    } else {

        printf("No image buffer retrieved.\n");
    }
    return m;
}