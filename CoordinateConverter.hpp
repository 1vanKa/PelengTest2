#pragma once
#include "Camera.hpp"

class CoordinateConverter
{
	/**
	 * Calculates angles from the origin of coordinates using point on the image and Camera object.
	 * horizontalAngle, verticalAngle - output parameters.
	 */
	static void calculateAnglesForPoint(double* horizontalAngle, double* verticalAngle,
		int pointX, int pointY, Camera camera);
	/**
	 * Calculates angle in one plane.
	 */
	static double calculateAngleForPoint(double cameraAngleRange, double cameraAngleOffset,
		int cameraResolution, int pointCoordinate);
	/**
	 * Calculates metrical coordinates from points on image.
	 * calculatedX, calculatedY - outputParameters.
	 */
	static void calculateMetricalCoordinates(double* calculatedX, double* calculatedY,
		double verticalAngle, double horizontalAngle, double distanceFromGround);
	/**
	 * Calculates opposite cathet of the right triangle with angle and adjacent cathet.
	 */
	static double calculateOppositeCathet(double angle, double adjacent—athet);
public:
	/**
	 * Converts coordinates of the pixel to metrical coordinates. Camera is installed in the origin of coordinates.
	 * calculatedX, calculatedY - outputParameters.
	 */
	static void convertImagePointToMetricalCoordinates(double* calculatedX, double* calculatedY,
		int pointX, int pointY, Camera camera);
};

