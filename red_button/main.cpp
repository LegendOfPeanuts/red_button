//
// Created by DAVID on 6/3/2023.
//

#include <opencv2/opencv.hpp>
#include "main.h"
#include <iostream>

using namespace cv;
using namespace std;

char[] prefix = "[CV_RED_BUTTON]";
char[] error_prefix = "[ERROR]";

// Main function
int main(int argc, char** argv) {

    VideoCapture cap(0);

    if (!cap.isOpened()) {
        std::cout << prefix << error_prefix << "Error opening video stream or file" << std::endl;
        return -1;
    }

    double dWidth = cap.get(CAP_PROP_FRAME_WIDTH); // Get the width of frames of the video
    double dHeight = cap.get(CAP_PROP_FRAME_HEIGHT); // Get the height of frames of the video

    cout << "Frame size : " << dWidth << " x " << dHeight << endl;

    string window_name = "Main camera feed";
    namedWindow(window_name, WINDOW_AUTOSIZE);

    while (true) {

        Mat frame;

        bool bSuccess = cap.read(frame); // Read a new frame from video

        if (!bSuccess) {
            cout << prefix << error_prefix << "Cannot read a frame from video stream" << endl;
            break;
        }

        imshow(window_name, frame);

        if (waitKey(10) == 27) {
            cout << prefix << "Esc pressed, exiting" << endl;
            break;
        }

    }

    return 0;
}
