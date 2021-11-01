#pragma once

/**
 * Class represents camera setup and its parameters.
 */
class Camera
{
	double horizontalCameraAngleRange;
	double verticalCameraAngleRange;
	double horizontalCameraAngleOffset;
	double verticalCameraAngleOffset;
	int horizontalCameraResolution;
	int verticalCameraResolution;
	float distanceFromGround;
public:
	/**
     * Creates camera with specified parameters.
	 * horizontalCameraAngleRange - camera angle range on the X axis.
	 * verticalCameraRange - camera angle range on the Y axis.
	 * horizontalCameraAngleOffset - if camera is tilted below the horizon, value should be below 0.
	 * verticalCameraAngleOffset - if camera is turned left, value should be below 0.
	 * horizontalCameraResolution - camera resolution on the X axis.
	 * verticalCameraResolution - camera resolution on the Y axis.
	 * distanceFromGround - camera installation height.
     */
	Camera(double horizontalCameraAngleRange,
		double verticalCameraAngleRange, double horizontalCameraAngleOffset, double verticalCameraAngleOffset,
		int horizontalCameraResolution, int verticalCameraResolution, double distanceFromGround);
	/**
	 * Gets horizontal camera angle range.
	 */
	double getHorizontalCameraAngleRange();
	/**
	 * Gets vertical camera angle range.
	 */
	double getVerticalCameraAngleRange();
	/**
	 * Gets horizontal camera angle offset.
	 */
	double getHorizontalCameraAngleOffset();
	/**
	 * Gets vertical camera angle offset.
	 */
	double getVerticalCameraAngleOffset();
	/**
	 * Gets horizontal camera resolution.
	 */
	int getHorizontalCameraResolution();
	/**
	 * Gets vertical camera resolution.
	 */
	int getVerticalCameraResolution();
	/**
	 * Gets distance from ground.
	 */
	double getDistanceFromGround();
};