#include "trie.h"

#include <gtest/gtest.h>

using bess::utils::Trie;

namespace {

// Whether Lookup function matches the prefix correctly
TEST(TrieTest, Lookup) {
  Trie trie;

  trie.Insert("Hello world!");
  trie.Insert("123456");

  EXPECT_FALSE(trie.Lookup("234"));
  EXPECT_FALSE(trie.Lookup("ello"));

  EXPECT_TRUE(trie.Lookup("Hello"));
  EXPECT_TRUE(trie.Lookup("H"));
  EXPECT_TRUE(trie.Lookup(""));
  EXPECT_TRUE(trie.Lookup("1"));
  EXPECT_TRUE(trie.Lookup("123456"));
}

// Whether LookupKey function matches the key against prefixes correctly
TEST(TrieTest, LookupKey) {
  Trie trie;

  trie.Insert("Hel");
  trie.Insert("12");

  EXPECT_FALSE(trie.LookupKey("He1"));
  EXPECT_FALSE(trie.LookupKey("1"));

  EXPECT_TRUE(trie.LookupKey("Hel"));
  EXPECT_TRUE(trie.LookupKey("Hello"));
  EXPECT_TRUE(trie.LookupKey("12"));
  EXPECT_TRUE(trie.LookupKey("123"));
  EXPECT_TRUE(trie.LookupKey("123456"));
}

// Whether an empty Trie behaves correctly with LookupKey and Lookup
TEST(TrieTest, Empty) {
  Trie trie;

  EXPECT_FALSE(trie.Lookup("234"));
  EXPECT_FALSE(trie.Lookup("ello"));
  EXPECT_FALSE(trie.Lookup("Hello"));
  EXPECT_FALSE(trie.Lookup("H"));

  EXPECT_TRUE(trie.Lookup(""));

  EXPECT_FALSE(trie.LookupKey("234"));
  EXPECT_FALSE(trie.LookupKey("ello"));
  EXPECT_FALSE(trie.LookupKey("Hello"));
  EXPECT_FALSE(trie.LookupKey("H"));
  EXPECT_FALSE(trie.LookupKey(""));
}

}  // namespace (unnamed)
