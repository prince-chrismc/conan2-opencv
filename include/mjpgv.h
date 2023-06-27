#pragma once
#include "opencv.h"
#include <cmath>
#include <iostream>
#include <string>

#ifdef _WIN32
#define MJPGV_EXPORT __declspec(dllexport)
#else
#define MJPGV_EXPORT
#endif

MJPGV_EXPORT void mjpgv(std::string f);
