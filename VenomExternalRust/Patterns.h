#pragma once
#include "Structs.h"
#include <iostream>
#include <fstream>
#include <string>
#include <stdlib.h>

namespace RecoilPatterns {
	std::string readFile(std::string name);
	std::vector<Vector> getAngles(std::string data);
	double getDelay(std::string data);
	int index = 1;
	weaponData getData(std::string name) {
		weaponData data;
		//std::vector<Vector> angles = std::vector<Vector>();

		try {
			std::string raw = readFile("patterns/" + name + ".txt");
			std::size_t startPos = raw.find("[[") + 1;
			std::size_t endPos = raw.find("]]") + 1;
			std::string angles = raw.substr(startPos, endPos-1);
			std::string delay = raw.substr(endPos + 2, raw.size());
			
			data.name = name;
			data.repeat_delay = getDelay(delay);
			data.angles = getAngles(angles);
			data.index = index;
			index++;
			std::cout << "Successfully loaded Pattern for " << name << "\n";
		}
		catch (...) {
			std::cout << "ERROR\n";
			system("pause");
			exit(0);
		}
		return data;
	}


	double getRandomNumber(int max) {
		int randomInt = rand() % max;
		double rand = (randomInt) / 1000000.0;
		return rand;
	}

	double getDelay(std::string data) {
		double val = std::atof(data.substr(1, data.size() - 2).c_str());
		
		if(val != 0){
			return val-getRandomNumber(30);
		}
		else {
			return val;
		}
	}

	std::vector<Vector> getAngles(std::string data) {
		std::vector<Vector> val = std::vector<Vector>();
		try {
			while (true) {
				std::size_t startPos = data.find("[");
				std::size_t endPos = data.find("]");
				std::size_t delimiter = data.find(",");
				double x = std::atof(data.substr(startPos + 1, delimiter).c_str()) - getRandomNumber(10);
				double y = std::atof(data.substr(delimiter + 1, endPos).c_str()) - getRandomNumber(10);
				for (Vector v : val) {
					x = x - v.x;
					y = y - v.y;
				}
				val.push_back({ x,y });
				if (data.size() > endPos + 3) {
					data = data.erase(0, endPos + 3);
				}
				else {
					break;
				}
				
			}
		}
		catch(...){}

		return val;
	}

	std::string readFile(std::string name) {
		std::ifstream myfile;
		std::string line, data;
		myfile.open(name);
		if (myfile.is_open()){
			while (std::getline(myfile, line))
			{
				data += line;
			}
			myfile.close();
		}
		else {
			std::cout << "Unable to open file " + name + "\n";
		}
		return data;
	}

	namespace scopes {
		attachmentData none{
			0, "none", 1.0
		};

		attachmentData scope8{
			4, "8-Times", 3.83781
		};

		attachmentData holo{
			2, "Holo", 1.18506
		};

		attachmentData simple{
			3, "Simple", 0.8201
		};
	}

	namespace barrel {
		attachmentData none{
			0, "none", 1.0
		};

		attachmentData suppressor{
			2, "Suppressor ", 0.8101
		};

	}
}