#include "CoordinateConverter.hpp"
#include "Camera.hpp"
#include <cmath>

void CoordinateConverter::convertImagePointToMetricalCoordinates(double* calculatedX, double* calculatedY,
	int pointX, int pointY, Camera camera) {
	double horizontalAngle = 0;
	double verticalAngle = 0;
	calculateAnglesForPoint(&horizontalAngle, &verticalAngle, pointX, pointY, camera);
	calculateMetricalCoordinates(calculatedX, calculatedY, verticalAngle, horizontalAngle, camera.getDistanceFromGround());
}

void CoordinateConverter::calculateAnglesForPoint(double* horizontalAngle, double* verticalAngle, int pointX, int pointY, Camera camera) {
	*horizontalAngle = calculateAngleForPoint(camera.getHorizontalCameraAngleRange(),
		camera.getHorizontalCameraAngleOffset(), camera.getHorizontalCameraResolution(), pointX);
	*verticalAngle = calculateAngleForPoint(camera.getVerticalCameraAngleRange(),
		camera.getVerticalCameraAngleOffset(), camera.getVerticalCameraResolution(), camera.getVerticalCameraResolution() - pointY);
	*verticalAngle > 0 ? *verticalAngle = atan(1.0) * 2 - *verticalAngle : *verticalAngle = -atan(1.0) * 2 + *verticalAngle;
}

double CoordinateConverter::calculateAngleForPoint(double cameraAngleRange, double cameraAngleOffset,
	int cameraResolution, int pointCoordinate) {
	return cameraAngleRange * (double)pointCoordinate / (double)cameraResolution - cameraAngleRange / 2 + cameraAngleOffset;
}

void CoordinateConverter::calculateMetricalCoordinates(double* calculatedX, double* calculatedY,
	double verticalAngle, double horizontalAngle, double distanceFromGround) {
	*calculatedY = calculateOppositeCathet(verticalAngle, distanceFromGround);
	*calculatedX = calculateOppositeCathet(horizontalAngle, *calculatedY);
}

double CoordinateConverter::calculateOppositeCathet(double angle, double adjacent—athet) {
	return adjacent—athet * tan(angle);
}
