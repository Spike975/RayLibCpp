#include <iostream>
#include <string>
#include <random>
#include <time.h>
#include "stringsExercise.h"

void everyOther() {
	std::string input;
	std::cout << "Please enter charecters:\n";
	std::getline(std::cin, input, '\n');

	for (int i = 0; i < input.length(); i++) {
		if (i % 2 != 0) {
			std::cout << input[i];
		}
	}
	std::cout << '\n';
}
void titleBestow() {
	srand(time(NULL));
	std::string input;
	std::cout << "Please enter your name:\n";
	std::getline(std::cin, input, '\n');
	
	int random = rand() % 5;

	if (random == 0) {
		input += ", The Great!";
	}
	else if (random == 1) {
		input += ", The Abominable";
	}
	else if (random == 2) {
		input += ", The Invincible";
	}
	else if (random == 3) {
		input += ", The Forgetable";
	}
	else if (random == 4) {
		input += ", The Monstrosity";
	}

	std::cout << input << '\n';
}
void charOccurances() {
	std::string input;
	char varible;
	std::cout << "Please enter your sentence:\n";
	std::getline(std::cin, input, '\n');
	std::cout << "Please enter the charecter you would like to look for:\n";

}