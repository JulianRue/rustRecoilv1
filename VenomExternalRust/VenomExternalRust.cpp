// VenomExternalRust.cpp : Diese Datei enthält die Funktion "main". Hier beginnt und endet die Ausführung des Programms.
//

#include <iostream>
#include <Windows.h>
#include <map>
#include <thread>
#include <random>

#include "Structs.h"
#include "Patterns.h"
#include "Mouse.h"
#include "Recoil.h"

weaponData currentWeapon;
attachmentData currentBarrel;
attachmentData currentScope;

Mouse mouse;
Recoil recoil;
HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
int selected_index = 0;

std::map<int, weaponData> keybinds
{
	{VK_OEM_5, RecoilPatterns::getData("none")},
	{VK_F2, RecoilPatterns::getData("assualt_rifle")},
	{VK_F3, RecoilPatterns::getData("mp5")},
	{VK_F4, RecoilPatterns::getData("thompson")},
	{VK_F5, RecoilPatterns::getData("custom_smg")},
	{VK_F6, RecoilPatterns::getData("lr_assault_rifle")},
	{VK_F7, RecoilPatterns::getData("sar")},
	{VK_F8, RecoilPatterns::getData("m249")}
};


std::map<int, attachmentData> keybinds_scope
{
	{VK_NUMPAD0, RecoilPatterns::scopes::none},
	{VK_NUMPAD1, RecoilPatterns::scopes::holo},
	{VK_NUMPAD2, RecoilPatterns::scopes::simple},
	{VK_NUMPAD3, RecoilPatterns::scopes::scope8}
};


std::map<int, attachmentData> keybinds_barrel{
	{VK_NUMPAD7, RecoilPatterns::barrel::none},
	{VK_NUMPAD8, RecoilPatterns::barrel::suppressor}
};


void print() {
	system("cls");
	SetConsoleTextAttribute(hConsole, 12);
	std::cout << "Your logo\n";

	SetConsoleTextAttribute(hConsole, 4);
	std::cout << "by (your paste name lul)\n";

	SetConsoleTextAttribute(hConsole, 15);
	std::cout << "\n------------------------------------------------------------------\n\n";
	std::cout << "Sensitivity:\t";

	SetConsoleTextAttribute(hConsole, 10);
	std::cout << std::to_string(recoil.sensitivity);
	SetConsoleTextAttribute(hConsole, 15);
	std::cout << "\t~> [NUM*] / [NUM/]\n";
	std::cout << "FOV:\t\t";

	SetConsoleTextAttribute(hConsole, 10);
	std::cout << std::to_string(recoil.fov);
	SetConsoleTextAttribute(hConsole, 15);
	std::cout << "\t~> [NUM+] / [NUM-]\n\n";

	
	
	SetConsoleTextAttribute(hConsole, 13);
	std::cout << " ~~~~~~{ WEAPONS }~~~~~~\t\t~~~~~~{ SCOPES }~~~~~~\t\t~~~~~~{ ATTACHMENTS }~~~~~~\n";
	SetConsoleTextAttribute(hConsole, 15);



	if (currentWeapon.index == 1) {
		SetConsoleTextAttribute(hConsole, 10);
		std::cout << "[^" << "]\t" << keybinds[VK_OEM_5].name;
		SetConsoleTextAttribute(hConsole, 15);
	}
	else {
		std::cout << "[^" << "]\t" << keybinds[VK_OEM_5].name;
	}

	if (currentScope.index == 0) {
		SetConsoleTextAttribute(hConsole, 10);
		std::cout << "\t\t\t\t[NUM0]\t" << keybinds_scope[VK_NUMPAD0].name;
		SetConsoleTextAttribute(hConsole, 15);
	}
	else {
		std::cout << "\t\t\t\t[NUM0]\t" << keybinds_scope[VK_NUMPAD0].name;
	}


	if (currentBarrel.index == 0) {
		SetConsoleTextAttribute(hConsole, 10);
		std::cout << "\t\t\t[NUM7]\t" << keybinds_barrel[VK_NUMPAD7].name << "\n";
		SetConsoleTextAttribute(hConsole, 15);
	}
	else {
		std::cout << "\t\t\t[NUM7]\t" << keybinds_barrel[VK_NUMPAD7].name << "\n";
	}








	if (currentWeapon.index == 2) {
		SetConsoleTextAttribute(hConsole, 10);
		std::cout << "[F2]\t" << keybinds[VK_F2].name;
		SetConsoleTextAttribute(hConsole, 15);
	}
	else {
		std::cout << "[F2]\t" << keybinds[VK_F2].name;
	}

	if (currentScope.index == 2) {
		SetConsoleTextAttribute(hConsole, 10);
		std::cout << "\t\t\t[NUM1]\t" << keybinds_scope[VK_NUMPAD1].name;
		SetConsoleTextAttribute(hConsole, 15);
	}
	else {
		std::cout << "\t\t\t[NUM1]\t" << keybinds_scope[VK_NUMPAD1].name;
	}

	if (currentBarrel.index == 2) {
		SetConsoleTextAttribute(hConsole, 10);
		std::cout << "\t\t\t[NUM8]\t" << keybinds_barrel[VK_NUMPAD8].name << "\n";
		SetConsoleTextAttribute(hConsole, 15);
	}
	else {
		std::cout << "\t\t\t[NUM8]\t" << keybinds_barrel[VK_NUMPAD8].name << "\n";
	}







	if (currentWeapon.index == 3) {
		SetConsoleTextAttribute(hConsole, 10);
		std::cout << "[F3]\t" << keybinds[VK_F3].name;
		SetConsoleTextAttribute(hConsole, 15);
	}
	else {
		std::cout << "[F3]\t" << keybinds[VK_F3].name;
	}

	if (currentScope.index == 3) {
		SetConsoleTextAttribute(hConsole, 10);
		std::cout << "\t\t\t\t[NUM2]\t" << keybinds_scope[VK_NUMPAD2].name << "\n";
		SetConsoleTextAttribute(hConsole, 15);
	}
	else {
		std::cout << "\t\t\t\t[NUM2]\t" << keybinds_scope[VK_NUMPAD2].name << "\n";
	}





	if (currentWeapon.index == 4) {
		SetConsoleTextAttribute(hConsole, 10);
		std::cout << "[F4]\t" << keybinds[VK_F4].name;
		SetConsoleTextAttribute(hConsole, 15);
	}
	else {
		std::cout << "[F4]\t" << keybinds[VK_F4].name;
	}

	if (currentScope.index == 4) {
		SetConsoleTextAttribute(hConsole, 10);
		std::cout << "\t\t\t[NUM3]\t" << keybinds_scope[VK_NUMPAD3].name << "\n";
		SetConsoleTextAttribute(hConsole, 15);
	}
	else {
		std::cout << "\t\t\t[NUM3]\t" << keybinds_scope[VK_NUMPAD3].name << "\n";
	}



	if (currentWeapon.index == 5) {
		SetConsoleTextAttribute(hConsole, 10);
		std::cout << "[F5]\t" << keybinds[VK_F5].name << "\n";
		SetConsoleTextAttribute(hConsole, 15);
	}
	else {
		std::cout << "[F5]\t" << keybinds[VK_F5].name << "\n";
	}

	if (currentWeapon.index == 6) {
		SetConsoleTextAttribute(hConsole, 10);
		std::cout << "[F6]\t" << keybinds[VK_F6].name << "\n";
		SetConsoleTextAttribute(hConsole, 15);
	}
	else {
		std::cout << "[F6]\t" << keybinds[VK_F6].name << "\n";
	}

	if (currentWeapon.index == 7) {
		SetConsoleTextAttribute(hConsole, 10);
		std::cout << "[F7]\t" << keybinds[VK_F7].name << "\n";
		SetConsoleTextAttribute(hConsole, 15);
	}
	else {
		std::cout << "[F7]\t" << keybinds[VK_F7].name << "\n";
	}

	if (currentWeapon.index == 8) {
		SetConsoleTextAttribute(hConsole, 10);
		std::cout << "[F8]\t" << keybinds[VK_F8].name << "\n";
		SetConsoleTextAttribute(hConsole, 15);
	}
	else {
		std::cout << "[F8]\t" << keybinds[VK_F8].name << "\n";
	}


}

void InputThread()
{
	while (true)
	{
		for (auto& weapon : keybinds)
		{
			if (mouse.isPressed(weapon.first))
			{
				currentWeapon = weapon.second;
				print();
				Beep(400, 100);
				SleepEx(50, false);
			}
		}

		for (auto& barrel : keybinds_barrel)
		{
			if (mouse.isPressed(barrel.first))
			{
				currentBarrel = barrel.second;
				print();
				Beep(400, 100);
				SleepEx(50, false);
			}
		}

		for (auto& scope : keybinds_scope)
		{
			if (mouse.isPressed(scope.first))
			{
				currentScope = scope.second;
				print();
				Beep(400, 100);
				SleepEx(50, false);
			}
		}

		if (mouse.isPressed(VK_MULTIPLY)) {
			recoil.sensitivity += 0.01;
			print();
			Beep(200, 100);
			SleepEx(50, false);
		}
		if (mouse.isPressed(VK_DIVIDE)) {
			recoil.sensitivity -= 0.01;
			print();
			Beep(200, 100);
			SleepEx(50, false);
		}
		if (mouse.isPressed(VK_ADD)) {
			recoil.fov += 1;
			print();
			Beep(200, 100);
			SleepEx(50, false);
		}
		if (mouse.isPressed(VK_SUBTRACT)) {
			recoil.fov -= 1;
			print();
			Beep(200, 100);
			SleepEx(50, false);
		}

		/* Keep that CPU on the down low */
		SleepEx(2, false);
	}
}

std::string gen_random(const int len) {

	std::string tmp_s;
	static const char alphanum[] = "abcdefghijklmnopqrstuvwxyz";


	tmp_s.reserve(len);

	for (int i = 0; i < len; ++i)
		tmp_s += alphanum[rand() % (sizeof(alphanum) - 1)];


	return tmp_s;

}

void animate() {


	while (true) {
		std::string name = gen_random(64);
		SetConsoleTitleA(name.c_str());
		std::this_thread::sleep_for(std::chrono::milliseconds(500));
	}
}

int main()
{
	
	mouse = Mouse();
	recoil = Recoil();

	recoil.sensitivity = 0.3f; 
	recoil.fov = 90.0f;
	
	currentWeapon = keybinds[VK_OEM_5];
	currentScope = keybinds_scope[VK_NUMPAD0];
	currentBarrel = keybinds_barrel[VK_NUMPAD7];

	print();

	std::thread key_binding(InputThread); 
	key_binding.detach();

	std::thread animation(animate);
	animation.detach();
	
	auto f_excess = std::chrono::high_resolution_clock::now();

	while (true)
	{
		while (!(mouse.isPressed(VK_LBUTTON) && mouse.isPressed(VK_RBUTTON)))
		{
			SleepEx(1, false);
			f_excess = std::chrono::high_resolution_clock::now();
		}

		for (int bullet = 1; bullet < currentWeapon.angles.size(); ++bullet)
		{
			if (!mouse.isPressed(VK_LBUTTON)) break;

			Vector pos = recoil.AngleConversion(currentWeapon.angles[bullet]);

			pos.x *= currentBarrel.multiplyer;
			pos.y *= currentBarrel.multiplyer;

			pos.x *= currentScope.multiplyer;
			pos.y *= currentScope.multiplyer;

			double animation = recoil.AnimationConversion(currentWeapon.angles[bullet]);

			mouse.Lerp(pos, recoil.SmoothPercentage(animation, currentWeapon.repeat_delay, 0.1f), currentWeapon.repeat_delay, f_excess);

			f_excess = std::chrono::high_resolution_clock::now();

		}

		while (mouse.isPressed(VK_LBUTTON))
		{
			std::this_thread::sleep_for(std::chrono::microseconds(1));
		}
	}
}
