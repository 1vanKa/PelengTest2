#pragma once
#include <opencv2/opencv.hpp>
#include <vector>

cv::Mat plotGraph(std::vector<double> x, std::vector<double> y, int imageSizeX, int imageSizeY);
void minMax(std::vector<double> vector, double* max, double* min);