#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <cmath>
#include <algorithm>

std::vector<double> angles;

std::vector<double> numsToTry = {1,2,3,4,5,6};

std::vector<double> SC = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30};
std::vector<double> BCC = {2,4,6,8,10,12,14,16,18,20,22,24,26,28,30};
std::vector<double> FCC = {3,4,8,11,12,16,19,20,24,27,32};

std::vector<double> SCDiffs;
std::vector<double> BCCDiffs;
std::vector<double> FCCDiffs;

void GetAngles(std::string _filepath) {
	std::ifstream file (_filepath);
	std::string angle;
	while (std::getline(file, angle)) {
		angles.push_back(std::stod(angle));
	}
}

double Closest(double _n, std::vector<double> _arr) {
	if (_n > 30)
		return 0;
	double best = 0;
	double lowestDiff = 100000;
	for (double i : _arr) {
		double diff = std::abs(_n-i);
		if (diff < lowestDiff) {
			lowestDiff = diff;
			best = i;
		}
	}
	return best;
}

int main (int argc, char* argv[]) {
	// Retreive angles from file
	if (argc >= 2)
		GetAngles((std::string)argv[1]);
	else {
		std::cout << "Please provide input data.\n";
		return 0;
	}

	// Get sin^2 of angles
	for (double i = 0; i < angles.size(); i++) {
		angles[i] = pow(sin(angles[i]*0.0174533), 2);
	}

	// sort the list
	std::sort(angles.begin(), angles.end());

	// divide by smallest
	double smallest = angles[0];
	for (double i = 0; i < angles.size(); i++) {
		angles[i] /= smallest;
	}

	// Generate numbers multiplied by a multiple. Calculate diff from closest in a set and use total diff
	for (double k : numsToTry) {
		double totalDiffSC = 0;
		double totalDiffBCC = 0;
		double totalDiffFCC = 0;
		for (double a : angles) {
			double c = Closest(a*k, SC);
			if (c == 0)
				continue;
			totalDiffSC += std::abs(a*k-c);
		}
		for (double a : angles) {
			double c = Closest(a*k, BCC);
			if (c == 0)
				continue;
			totalDiffBCC += std::abs(a*k-c);
		}
		for (double a : angles) {
			double c = Closest(a*k, FCC);
			if (c == 0)
				continue;
			totalDiffFCC += std::abs(a*k-c);
		}
		SCDiffs.push_back(totalDiffSC);
		BCCDiffs.push_back(totalDiffBCC);
		FCCDiffs.push_back(totalDiffFCC);
	}
	
	double smallestSCDiff = 10000;
	for (double d : SCDiffs)
		if (d < smallestSCDiff)
			smallestSCDiff = d;
	double smallestBCCDiff = 10000;
	for (double d : BCCDiffs)
		if (d < smallestBCCDiff)
			smallestBCCDiff = d;
	double smallestFCCDiff = 10000;
	for (double d : FCCDiffs)
		if (d < smallestFCCDiff)
			smallestFCCDiff = d;
	
	std::cout << "SC Diffs:\n";
	for (int i = 0; i < numsToTry.size(); i++) {
		if (SCDiffs[i] == smallestSCDiff)
			std::cout << "\033[31m";
		std::cout << i+1 << ": " << SCDiffs[i] << "\033[0m\n";
	}
	std::cout << "\nBCC Diffs:\n";
	for (int i = 0; i < numsToTry.size(); i++) {
		if (BCCDiffs[i] == smallestBCCDiff)
			std::cout << "\033[31m";
		std::cout << i+1 << ": " << BCCDiffs[i] << "\033[0m\n";
	}
	std::cout << "\nFCC Diffs:\n";
	for (int i = 0; i < numsToTry.size(); i++) {
		if (FCCDiffs[i] == smallestFCCDiff)
			std::cout << "\033[31m";
		std::cout << i+1 << ": " << FCCDiffs[i] << "\033[0m\n";
	}
}
