#ifndef LOGIC_H    
#define LOGIC_H
#include <vector>

void greetings();
int rules();
std::string make_a_word();
bool check_start_info(int level, std::string word);
void game_started();
void clear();
void draw_word(std::string word, std::vector<char> letters);
std::string ask_letter();
bool get_y_n_answer(std::string question);
#endif