#pragma once
#include <string>
#include <vector>

struct Vector {
	double x, y;
};
struct weaponData
{
	int index;
	std::string name;
	std::vector<Vector> angles;
	double repeat_delay;
};

struct attachmentData
{
	int index;
	std::string name;
	double multiplyer;
};