#include "ladder.h"

void error(string word1, string word2, string msg) {
    cout << word1 << msg << word2 << endl;
}


bool sameLenDiff(const string& word1, const string& word2) {
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
    int len1 = static_cast<int>(word1.size());
    int len2 = static_cast<int>(word2.size());
    
}