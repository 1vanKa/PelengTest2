#include "Camera.hpp"

Camera::Camera(double horizontalCameraAngleRange,
	double verticalCameraAngleRange, double horizontalCameraAngleOffset, double verticalCameraAngleOffset,
	int horizontalCameraResolution, int verticalCameraResolution, double distanceFromGround) {
	this->horizontalCameraAngleRange = horizontalCameraAngleRange;
	this->verticalCameraAngleRange = verticalCameraAngleRange;
	this->horizontalCameraAngleOffset = horizontalCameraAngleOffset;
	this->verticalCameraAngleOffset = verticalCameraAngleOffset;
	this->horizontalCameraResolution = horizontalCameraResolution;
	this->verticalCameraResolution = verticalCameraResolution;
	this->distanceFromGround = distanceFromGround;
}

double Camera::getHorizontalCameraAngleRange() {
	return horizontalCameraAngleRange;
}

double Camera::getVerticalCameraAngleRange() {
	return verticalCameraAngleRange;
}

double Camera::getHorizontalCameraAngleOffset() {
	return horizontalCameraAngleOffset;
}

double Camera::getVerticalCameraAngleOffset() {
	return verticalCameraAngleOffset;
}

int Camera::getHorizontalCameraResolution() {
	return horizontalCameraResolution;
}

int Camera::getVerticalCameraResolution() {
	return verticalCameraResolution;
}

double Camera::getDistanceFromGround() {
	return distanceFromGround;
}