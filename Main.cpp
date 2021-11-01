#include "Main.hpp"
#include <iostream>
#include "Camera.hpp"
#include <vector>
#include "CoordinateConverter.hpp"

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
	std::vector<Point> convertedPoints;
	for (Point p : points) {
		double x = 0;
		double y = 0;
		CoordinateConverter::convertPerspectiveToMetricalCoordinates(&x, &y, p.getX(), p.getY(), camera);
		convertedPoints.push_back(Point(x, y));
		std::cout << '[' << p.getX() << ',' << p.getY() << "] -> " << '[' << x << ',' << y << "]" << std::endl;
	}
	double x = 0;
	double y = 0;
	Camera camera1(60.0 / 180 * PI, 40.0 / 180 * PI, -0 / 180 * PI, -37.0 / 180 * PI, 1920, 1080, 3);
	CoordinateConverter::convertPerspectiveToMetricalCoordinates(&x, &y, 1920, 1080, camera1);
	std::cout << x << ';' << y;
	return 0;
}
