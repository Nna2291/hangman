#include <iostream>
#include "logic.h"
#include <vector>
#include "drawing.h"
#include <algorithm>
#include <cctype>
#include <windows.h>
#include <string>

using namespace std;



bool game() {
	bool answer = false;
	int correct = 0;
	int diff;
	int mistakes = 0;

	vector<char> letters;
	string a;
	string word;

	while (!answer) {
		clear();
		greetings();
		diff = rules();
		word = make_a_word();
		answer = check_start_info(diff, word);
	}
	game_started();

	char y = word[rand() % word.length()];
	char x = word[rand() % word.length()];
	while (x == y) {
		x = word[rand() % word.length()];
	}
	letters.push_back(x);
	letters.push_back(y);
	
	while (mistakes != 9 - diff) {
		draw_visel(diff, mistakes);

		if (draw_word(word, letters)) {
			return true;
		}

		a = ask_letter();
		
		transform(a.begin(), a.end(), a.begin(), [](unsigned char c) { return tolower(c); });
		if (find(letters.begin(), letters.end(), a[0]) != letters.end()) {
			cout << "You already tried this letter! (press any key to continue)" << endl;
			cin.clear();
			cin.ignore((numeric_limits<streamsize>::max)(), '\n');
			cin.get();
		}
		else if (word.find(a) != string::npos) {
			letters.push_back(a[0]);
			correct++;
		} 
		else {
			mistakes++;
			letters.push_back(a[0]);
		}
		
	}
	draw_visel(diff, mistakes);
	cout << word << endl;
	return false;
}

int main() {
	bool again = true;
	while (again) {
		bool status = game();
		if (status) {
			again = get_y_n_answer("You win! Congrats! Wanna play one more time? Y(es)/N(o): ");
		}
		else {
			again = get_y_n_answer("You Lose:( Don't worry Wanna try one more time? Y(es)/N(o): ");
		}
	}
	return 0;
}