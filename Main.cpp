#include "Main.hpp"
#include <iostream>
#include "Camera.hpp"
#include <vector>
#include <algorithm>
#include "CoordinateConverter.hpp"
#include <opencv2/opencv.hpp>
#include <opencv2/highgui.hpp>

class Point {
	int x, y;
public:
	Point(int x, int y) {
		this->x = x;
		this->y = y;
	}

	bool operator >(Point p) {
		return this->y > p.y;
	}

	bool operator <(Point p) {
		return this->y < p.y;
	}

	int getX() {
		return x;
	}

	int getY() {
		return y;
	}
};

int main(int argc, char** argv) {
	std::vector<Point> points{ Point(1117,1080), Point(1161,523),
		Point(1015,303), Point(991,174), Point(1161,523), Point(1161,523),
		Point(1054,98), Point(1167,70), Point(1189,32), Point(1160,0) };
	double PI = atan(1.0) * 4;
	Camera camera(60.0 / 180 * PI, 40.0 / 180 * PI, -10.0 / 180 * PI, -37.0 / 180 * PI, 1920, 1080, 3);
	std::vector<double> xValues;
	std::vector<double> yValues;
	std::sort(points.begin(), points.end());
	for (Point p : points) {
		double x = 0;
		double y = 0;
		CoordinateConverter::convertImagePointToMetricalCoordinates(&x, &y, p.getX(), p.getY(), camera);
		std::cout << '[' << p.getX() << ',' << p.getY() << "] -> " << '[' << x << ',' << y << "]" << std::endl;
		xValues.push_back(x);
		yValues.push_back(y);
	}
	cv::imwrite("plot.jpg", plotGraph(xValues, yValues, 500, 500));
	return 0;
}

cv::Mat plotGraph(std::vector<double> x, std::vector<double> y, int imageSizeX, int imageSizeY)
{
	double minX;
	double maxX;
	double minY;
	double maxY;
	minMax(x, &maxX, &minX);
	minMax(y, &maxY, &minY);
	cv::Mat image = cv::Mat::zeros(imageSizeX, imageSizeY, CV_8UC3);
	image.setTo(255);
	double divider = maxX - minX > maxY - minY ? maxX - minX : maxY - minY;
	for (int i = 0; i < (int)x.size() - 1; i++)
	{
		cv::Point p1(imageSizeX / 2 + (x[i] - maxX) / divider * imageSizeX, imageSizeY - (y[i] - minY) / divider * imageSizeY);
		cv::Point p2(imageSizeX / 2 + (x[i + 1] - maxX) / divider * imageSizeX, imageSizeY - (y[i + 1] - minY) / divider * imageSizeY);
		cv::line(image,p1, p2, cv::Scalar(0, 0, 0), 2);
		cv::circle(image, p1, 3, cv::Scalar(255, 0, 0), 3);
		cv::circle(image, p2, 3, cv::Scalar(255, 0, 0), 3);
	}
	return image;
}

void minMax(std::vector<double> vector, double* max, double* min) {
	*min = DBL_MAX;
	*max = -DBL_MAX;
	for (int i = 0; i < vector.size(); i++) {
		if (vector[i] > *max) *max = vector[i];
		if (vector[i] < *min) *min = vector[i];
	}
}
