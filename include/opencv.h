#pragma once
#include <cmath>
#include <iostream>
#include <math.h>
#include <opencv4/opencv2/core.hpp> // Basic OpenCV structures (cv::Mat, Scalar)
#include <opencv4/opencv2/highgui.hpp> // OpenCV window I/O
#include <opencv4/opencv2/imgcodecs.hpp>
#include <opencv4/opencv2/videoio/videoio.hpp>
#include <stdio.h>
#include <string>

void opencv(std::string f);
int process(cv::VideoCapture &capture);
