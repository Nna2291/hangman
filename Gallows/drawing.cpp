#include <iostream>
#include "drawing.h"
#include "logic.h"
#include <algorithm>
#include <cctype>
#include <windows.h>
#include <string>

using namespace std;

void draw_visel(int level, int mistakes) {
	clear();
	string drawing[9] = {
						"   ---+\n      |\n      |\n      |\n      |\n      |\n=========",
						"  +---+\n      |\n      |\n      |\n      |\n      |\n=========",
						"  +---+\n  |   |\n      |\n      |\n      |\n      |\n=========",
						"  +---+\n  |   |\n  O   |\n      |\n      |\n      |\n=========",
						"  +---+\n  |   |\n  O   |\n  |   |\n      |\n      |\n=========",
						"  +---+\n  |   |\n  O   |\n /|   |\n      |\n      |\n=========",
						"  +---+\n  |   |\n  O   |\n /|\\  |\n      |\n      |\n=========",
						"  +---+\n  |   |\n  O   |\n /|\\  |\n /    |\n      |\n=========",
						"  +---+\n  |   |\n  O   |\n /|\\  |\n / \\  |\n      |\n=========",
	};
	cout << drawing[level - 1 + mistakes] << endl;
}