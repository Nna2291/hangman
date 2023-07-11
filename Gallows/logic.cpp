#include <iostream>
#include "logic.h"
#include <algorithm>
#include <cctype>
#include <windows.h>
#include <string>


using namespace std;

void greetings() {
	cout <<
		"#     #                      #     #               \n"
		"#     #   ##   #    #  ####  ##   ##   ##   #    # \n"
		"#     #  #  #  ##   # #    # # # # #  #  #  ##   # \n"
		"####### #    # # #  # #      #  #  # #    # # #  # \n"
		"#     # ###### #  # # #  ### #     # ###### #  # # \n"
		"#     # #    # #   ## #    # #     # #    # #   ## \n"
		"#     # #    # #    #  ####  #     # #    # #    # \n"
		"by: @Nna2291\n"<< endl;
}



int rules() {
	cout <<
		"Welcome to HangMan!\n"
		"There are different levels:\n"
		"1) 8 mistakes\n"
		"2) 7 mistakes\n"
		"3) 6 mistakes\n" << endl;
	int diff{};
	while (true) 
	{
		cout << "Enter level 1-3 ";
		cin >> diff;

		if (cin.fail()) {
			cin.clear();
			cin.ignore((numeric_limits<streamsize>::max)(), '\n');
			cout << "It's not a number!" << endl;
		}
		else if (diff > 3 || diff < 1) {
			cout << "Level must be in [1;3]" << endl;
		}
		else {
			cout << "\nYour level is ";
			cout << diff;
			cout << "\n\n";
			return diff;
		}
	}
}

string make_a_word() {
	string word;
	while (true) 
	{
		cout << "Enter word: ";
		cin >> word;
		if (word.find_first_not_of("abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ") != string::npos)
		{
			cout << "You can't use special symbols or digits in the word!" << endl;
		}
		else if (word.length() < 4) {
			cin.clear();
			cin.ignore((numeric_limits<streamsize>::max)(), '\n');
			cout << "Minimum value is 4!" << endl;
		}
		else {
			transform(word.begin(), word.end(), word.begin(), [](unsigned char c) { return tolower(c); });
			return word;
		}
	}
}

bool get_y_n_answer(string question) {
	string answer;
	while (true) {
		cout << question;
		cin >> answer;
		transform(answer.begin(), answer.end(), answer.begin(), [](unsigned char c) { return tolower(c); });
		if ((answer != "n") && (answer != "y")) {
			cout << "Type N or Y!" << endl;
		}
		else {
			return answer != "n";
		}
	}
}

bool check_start_info(int level, string word) {
	cout << "\nYour level is ";
	cout << level << endl;
	cout << "Your word is ";
	cout << word << endl;
	return get_y_n_answer("Is everything correct? Y(es)/N(o): ");
}

void clear()
{
	HANDLE                     hStdOut;
	CONSOLE_SCREEN_BUFFER_INFO csbi;
	DWORD                      count;
	DWORD                      cellCount;
	COORD                      homeCoords = { 0, 0 };

	hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
	if (hStdOut == INVALID_HANDLE_VALUE) return;

	/* Get the number of cells in the current buffer */
	if (!GetConsoleScreenBufferInfo(hStdOut, &csbi)) return;
	cellCount = csbi.dwSize.X * csbi.dwSize.Y;

	/* Fill the entire buffer with spaces */
	if (!FillConsoleOutputCharacter(
		hStdOut,
		(TCHAR)' ',
		cellCount,
		homeCoords,
		&count
	)) return;

	/* Fill the entire buffer with the current colors and attributes */
	if (!FillConsoleOutputAttribute(
		hStdOut,
		csbi.wAttributes,
		cellCount,
		homeCoords,
		&count
	)) return;

	/* Move the cursor home */
	SetConsoleCursorPosition(hStdOut, homeCoords);
}

void game_started() {
	clear();
	cout <<
		" #####                                                                         ###\n"
		"#     #   ##   #    # ######     ####  #####   ##   #####  ##### ###### #####  ###\n"
		"#        #  #  ##  ## #         #        #    #  #  #    #   #   #      #    # ###\n"
		"#  #### #    # # ## # #####      ####    #   #    # #    #   #   #####  #    #  # \n"
		"#     # ###### #    # #              #   #   ###### #####    #   #      #    #    \n"
		"#     # #    # #    # #         #    #   #   #    # #   #    #   #      #    # ###\n"
		" #####  #    # #    # ######     ####    #   #    # #    #   #   ###### #####  ###\n\n";
}

bool draw_word(string word, vector<char> letters) {
	bool word_guessed = true;
	cout << "Guessed word: ";
	for (int i = 0; i < word.length(); i++)
	{
		if (find(letters.begin(), letters.end(), word[i]) != letters.end()) {
			cout << word[i];
		}
		else {
			cout << "_";
			word_guessed = false;
		}
	}
	cout << endl;
	return word_guessed;
}

string ask_letter() {
	string letter;
	while (letter.length() != 1) {
		cout << "Enter a letter: ";
		cin >> letter;
		if (letter.length() != 1) {
			cout << "Enter just one letter!" << endl;
		} 
		else {
			return letter;
		}
	}
}