#include <iostream>
#include <fstream>
#include <queue>
#include <set>
#include <map>
#include <vector>
#include <string>
#include <cmath>
#include <algorithm>


using namespace std;

void error(string word1, string word2, string msg);
bool edit_distance_within(const std::string& str1, const std::string& str2, int d); // edits the different letter number
bool is_adjacent(const string& word1, const string& word2); // checks if the words are different by one letter
bool sameLenDiff(const string& word1, const string& word2);
bool oneLenDiff(const string& word1, const string& word2, int len1, int len2);
vector<string> generate_word_ladder(const string& begin_word, const string& end_word, const set<string>& word_list); // BFS to generate the ladder
void load_words(set<string> & word_list, const string& file_name); // actually get the words
void print_word_ladder(const vector<string>& ladder); // print the word ladder
void verify_word_ladder(const vector<string>& ladder); // verify the word ladder is correct
