#include <Windows.h>
#include <iostream>
#include <list>
#include <stdio.h>

int main(void) {
	SetConsoleOutputCP(65001);

	std::list<const char*> yamanoteStationName = {
	    "Tokyo",   "Kanda",        "Akihabara",  "Okachimachi", "Ueno",   "Uguisudani",
	    "Nippori", "Tabata",       "Komagome",   "Sugamo",      "Otsuka", "Ikebukuro",
	    "Mejiro",  "Takadanobaba", "Shin-Okubo", "Shinjuku",    "Yoyogi", "Harajuku",
	    "Shibuya", "Ebisu",        "Meguro",     "Gotanda",     "Osaki",  "Shinagawa",
	    "Tamachi", "Hamamatsucho", "Shimbashi",  "Yurakucho",
	};

	std::cout << "1970”N‚ÌŽRŽèü‰wˆê——" << std::endl;

	for (auto& name : yamanoteStationName) {
		std::cout << name << std::endl;
	}

	std::cout << "\n" << std::endl;

	auto findStationNameIterator =
	    std::find(yamanoteStationName.begin(), yamanoteStationName.end(), "Nippori");
	findStationNameIterator++;
	yamanoteStationName.insert(findStationNameIterator, "Nishi-Nippori");

	std::cout << "2019”N‚ÌŽRŽèü‰wˆê——" << std::endl;

	for (auto& name : yamanoteStationName) {
		std::cout << name << std::endl;
	}

	std::cout << "\n" << std::endl;

	findStationNameIterator =
	    std::find(yamanoteStationName.begin(), yamanoteStationName.end(), "Shinagawa");
	findStationNameIterator++;
	findStationNameIterator =
	    yamanoteStationName.insert(findStationNameIterator, "Takanawa Gateway");

	std::cout << "2022”N‚ÌŽRŽèü‰wˆê——" << std::endl;

	for (auto& name : yamanoteStationName) {
		std::cout << name << std::endl;
	}

	return 0;
}