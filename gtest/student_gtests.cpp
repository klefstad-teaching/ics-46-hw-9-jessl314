#include <gtest/gtest.h>

#include "../src/dijkstras.h"
#include "../src/ladder.h"

TEST(Replace, Me) {
  EXPECT_TRUE(true);
}

TEST(Ladder, isAdjacentdiffWord) {
  EXPECT_TRUE(is_adjacent("cat", "hat"));
}

TEST(Ladder, isAdjacentsameWord) {
  EXPECT_TRUE(is_adjacent("hat", "hat"));
}

TEST(Ladder, editDistanceWithin) {
  EXPECT_TRUE(edit_distance_within("appl", "apple", 1));
}

TEST(Ladder, genDiffLen) {
  set<string> word_list;
  vector<string> expected = {"car", "cat", "chat", "cheat"};
  load_words(word_list, "src/words.txt");
  EXPECT_EQ(generate_word_ladder("car", "cheat", word_list), expected);
}

TEST(Ladder, genSameLen) {
  set<string> word_list;
  vector<string> expected = {"marty", "marry", "carry", "curry", "curly", "curls"};
  load_words(word_list, "src/words.txt");
  EXPECT_EQ(generate_word_ladder("marty", "curls", word_list), expected);
  print_word_ladder(generate_word_ladder("marty", "curls", word_list));
}