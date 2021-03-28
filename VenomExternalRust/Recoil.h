#pragma once
#include "Structs.h"

class Recoil {
public:

#pragma optimize( "", off )
	float fov = 90;
	float sensitivity = 0.3f;

	double getRandomNumber(int max) {
		int randomInt = -(max / 2) + (rand() % max);
		double rand = (randomInt) / 100.0;
		return rand;
	}

	double SmoothPercentage(double animation, double repeat_delay, float percentage)
	{
		percentage += getRandomNumber(10);
		double delta = repeat_delay - animation;

		double new_animation = animation + (delta - (delta * percentage));

		return new_animation;
	}



	double AnimationConversion(Vector angles)
	{
		return (sqrt(pow(angles.x, 2) + pow(angles.y, 2))) / 20.0 * 1000.0;
	}

	bool cjyjngavymsyeuftuygrw() {
		double xjdeysnf = 45158;
		double xgbcnehvubj = 65360;
		if (45158 == 45158) {
			int rdeknjxsgo;
			for (rdeknjxsgo = 62; rdeknjxsgo > 0; rdeknjxsgo--) {
				continue;
			}
		}
		return false;
	}

	Vector AngleConversion(Vector angles)
	{
		Vector pixel_return;
		pixel_return.x = angles.x / (-0.03 * static_cast<double>(sensitivity) * 3.0 * (fov / 100.0));
		pixel_return.y = angles.y / (-0.03 * static_cast<double>(sensitivity) * 3.0 * (fov / 100.0));

		pixel_return.x += getRandomNumber(5);
		pixel_return.y += getRandomNumber(5);


		pixel_return.x = pixel_return.x;
		pixel_return.y = pixel_return.y;
		return pixel_return;
	}
#pragma optimize( "", on )
};