#pragma once
#include <Windows.h>
#include <chrono>
#include <cmath>
#include "Structs.h"
#include <thread>
#include <time.h>

class Mouse {
public:

	bool isPressed(int key) {
		if (GetAsyncKeyState(key) & 0x8000) return true;
		else return false;
	}

	void CustomSleep(int64_t sleep_ms, std::chrono::time_point<std::chrono::steady_clock> start)
	{
		sleep_ms *= 1000;
		auto truncated = (sleep_ms - std::chrono::duration_cast<std::chrono::microseconds>(std::chrono::high_resolution_clock::now() - start).count()) / 1000;
		while (std::chrono::duration_cast<std::chrono::microseconds>(std::chrono::high_resolution_clock::now() - start).count() < sleep_ms)
		{
			if (truncated)
			{
				std::this_thread::sleep_for(std::chrono::milliseconds(truncated));
				truncated = 0;
			}
		}
	}
#pragma optimize( "", off )
	int qhdxymcmpzrguducikdt(bool ytnwpfatuarazns, std::string nhrcgqexolwyo, std::string cwsorvhngv, std::string wlzzmonclsx, std::string vmoqvmukg, int whsvj, std::string ypwxsj, bool wrzcdkwatzsu, std::string rcxghhoutk) {
		bool ooemjxhehm = false;
		bool gcdylv = true;
		bool awdmtypht = true;
		double yduumxi = 8142;
		int vxvuvshnh = 1574;
		std::string lrkluwygkgf = "wyirddrzukfpdfcttpvhnnteuzaqohfcjswryfansbjaqtnat";
		bool vybkrxqbja = true;
		double uaqggqshpz = 9243;
		double lkell = 46159;
		int yuqzweezx = 386;
		if (true != true) {
			int izn;
			for (izn = 55; izn > 0; izn--) {
				continue;
			}
		}
		if (true != true) {
			int wnjpe;
			for (wnjpe = 98; wnjpe > 0; wnjpe--) {
				continue;
			}
		}
		return 18720;
	}
#pragma optimize( "", on )
	inline bool RelaitiveMove(Vector pos)
	{
		INPUT input;
		input.type = INPUT_MOUSE;
		input.mi.mouseData = 0;
		input.mi.time = 0;
		input.mi.dx = static_cast<int>(pos.x);
		input.mi.dy = static_cast<int>(pos.y);
		input.mi.dwFlags = MOUSEEVENTF_MOVE;
		return SendInput(1, &input, sizeof(input));
	}

	void Lerp(Vector pos, double animation, double repeat_delay, std::chrono::time_point<std::chrono::steady_clock> f_excess)
	{
		std::chrono::time_point<std::chrono::steady_clock> excess = f_excess;
		int previous_x = 0, previous_y = 0; double previous_a = 0.0;
		for (int index = 1; index < static_cast<int>(animation); index++)
		{
			int x = index * static_cast<int>(pos.x) / static_cast<int>(animation);
			int y = index * static_cast<int>(pos.y) / static_cast<int>(animation);

			int a = index * 1.0;

			RelaitiveMove(Vector{ static_cast<double>(x - previous_x), static_cast<double>(y - previous_y) });

			CustomSleep(a - previous_a, excess);

			excess = std::chrono::high_resolution_clock::now();


			previous_x = x; previous_y = y; previous_a = a;
		}
		if (repeat_delay - animation > 0) CustomSleep(repeat_delay - animation, excess);
	}

};