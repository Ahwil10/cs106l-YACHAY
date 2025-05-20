#include "spellcheck.h"

#include <algorithm>
#include <iostream>
#include <numeric>
#include <ranges>
#include <set>
#include <vector>

template <typename Iterator, typename UnaryPred>
std::vector<Iterator> find_all(Iterator begin, Iterator end, UnaryPred pred);

Corpus tokenize(const std::string& source) {
  Corpus tokens;
  if (source.empty()) return tokens;

  // Find all word boundaries (non-alphanumeric characters)
  auto boundaries = find_all(
      source.begin(), 
      source.end(), 
      [](char c) { return !::isalnum(c); }
  );

  // Create tokens from the segments between boundaries
  for (auto it = boundaries.begin(); it != boundaries.end() - 1; ++it) {
      auto word_begin = *it;
      auto word_end = *(it + 1);
      
      // Skip empty or pure non-alphanumeric segments
      if (std::find_if(word_begin, word_end, ::isalnum) != word_end) {
          tokens.emplace(source, word_begin, word_end);
      }
  }

  return tokens;
}

std::set<Mispelling> spellcheck(const Corpus& source, const Dictionary& dictionary) {
  std::set<Mispelling> misspellings;

  for (const auto& token : source) {
      // Skip empty tokens
      if (token.content.empty()) continue;

      // Check if word is in dictionary
      if (dictionary.find(token.content) == dictionary.end()) {
          Mispelling misspelling{token};
          
          // Find suggestions (words with Levenshtein distance == 1)
          for (const auto& dict_word : dictionary) {
              if (levenshtein(token.content, dict_word) == 1) {
                  misspelling.suggestions.insert(dict_word);
              }
          }
          
          misspellings.insert(misspelling);
      }
  }

  return misspellings;
}

/* Helper methods */

#include "utils.cpp"