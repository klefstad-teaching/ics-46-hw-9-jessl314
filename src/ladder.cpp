#include "ladder.h"

void error(string word1, string word2, string msg) {
    cout << word1 << msg << word2 << endl;
}


bool sameLenDiff(const string& word1, const string& word2) {
    if (word1 == word2) {
        return true;
    }
    int numDiff = 0;
    for (int i=0; i < static_cast<int>(word1.size()); ++i) {
        if (word1[i] != word2[i]) {
            numDiff++;
        }
    }
    return numDiff == 1;
}

bool oneLenDiff(const string& word1, const string& word2, int len1, int len2) {
    const string& longer = len1 > len2 ? word1 : word2;
    const string& shorter = len1 < len2 ? word1 : word2;

    int i = 0;
    int j = 0;
    while (i < static_cast<int>(longer.size()) && j < static_cast<int>(shorter.size())) {
        if (longer[i] == shorter[j]) {
            ++i;
            ++j;
        }
        else {
            ++i;
        }
    }
    return j == static_cast<int>(shorter.size());
}
bool is_adjacent(const string& word1, const string& word2) {
    int len1 = static_cast<int>(word1.size());
    int len2 = static_cast<int>(word2.size());

    if (abs(len1 - len2) > 1)
       return false;
    if (len1 == len2) {
        return sameLenDiff(word1, word2);
    }

    if (abs(len1 - len2) == 1) {
        return oneLenDiff(word1, word2, len1, len2);
    }
    return false;
}

bool edit_distance_within(const std::string& str1, const std::string& str2, int d) {
    int len1 = static_cast<int>(str1.size());
    int len2 = static_cast<int>(str2.size());
    vector<vector<int>> dp(len1 + 1, vector<int>(len2 + 1));
    
    // column edit initialization
    for (int i = 0; i <= len1; ++i) {
        dp[i][0] = i;
    }
    // row edit initialization
    for (int j = 0; j <= len2; ++j) {
        dp[0][j] = j;  
    }

    // Fill the matrix
    for (int i = 1; i <= len1; ++i) {
        for (int j = 1; j <= len2; ++j) {
            if (str1[i - 1] == str2[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1]; 
            } 
            else {
                dp[i][j] = min({
                    dp[i - 1][j] + 1,
                    dp[i][j - 1] + 1,
                    dp[i - 1][j - 1] + 1
                });
            }
        }
    }

    return dp[len1][len2] <= d;  // Return true if the distance is within the limit
}

vector<string> generate_word_ladder(const string& begin_word, const string& end_word, const set<string>& word_list) {
    queue<vector<string>> ladder_queue;
    ladder_queue.push({begin_word});
    set<string> visited;
    visited.insert(begin_word);
    while (!ladder_queue.empty()) {
        vector<string> ladder = ladder_queue.front();
        ladder_queue.pop();
        string last_word = ladder.back();
        for (const string& word : word_list) {
            if (is_adjacent(last_word, word)) {
                // word not in visited
                if (visited.find(word) == visited.end()) {
                    visited.insert(word);
                    vector<string> new_ladder = ladder;
                    new_ladder.push_back(word);
                    if (word == end_word) {
                        return new_ladder;
                    }
                    ladder_queue.push(new_ladder);
                }
            }

        }


    }
    return {};
}

void load_words(set<string> & word_list, const string& file_name) {
    ifstream inFile(file_name);
    if (!inFile) {
        error("", file_name, "Error opening file: ");
        return;
    }
    string line;
    while (getline(inFile, line)) {
        word_list.insert(line);
    }
    inFile.close();
}

void print_word_ladder(const vector<string>& ladder) {
    if (ladder.empty()) {
        cout << "No word ladder found." << endl;
        return;
    }
    cout << "Word ladder found: ";
    for (const string& word : ladder) {
        cout << word << " ";
    }
    cout << "\n";
}

void verify_word_ladder(const vector<string>& ladder) {
    if (ladder.empty()) {
        cout << "No word ladder found." << endl;
        return;
    }

    for (size_t i = 1; i < ladder.size(); ++i) {
        if (!is_adjacent(ladder[i - 1], ladder[i])) {
            error(ladder[i - 1], ladder[i], "words are not adjacent");
            return;
        }
    }

    cout << "The word ladder is valid!" << endl;
    
}


