/*
 * CS106L Assignment 2: Marriage Pact
 * Created by Haven Whitney with modifications by Fabio Ibanez & Jacob Roberts-Baca.
 *
 * Welcome to Assignment 2 of CS106L! Please complete each STUDENT TODO
 * in this file. You do not need to modify any other files.
 *
 */

 #include <iostream>
 #include <fstream>
 #include <set>
 #include <queue>
 #include <string>
 #include <sstream>
 #include <cstdlib>
 #include <ctime>

//std::string kYourName = "Jefferson_Valencia"; // Don't forget to change this!

/**
 * Takes in a file name and returns a set containing all of the applicant names as a set.
 *
 * @param filename  The name of the file to read.
 *                  Each line of the file will be a single applicant's name.
 * @returns         A set of all applicant names read from the file.
 *
 * @remark Feel free to change the return type of this function (and the function
 * below it) to use a `std::unordered_set` instead. If you do so, make sure
 * to also change the corresponding functions in `utils.h`.
 */
// Function to read names from file into a set (ordered)
std::set<std::string> get_applicants(const std::string& filename) {
  std::set<std::string> applicants;
  std::ifstream file(filename);
  std::string name;

  if (!file) {
      std::cerr << "Error opening file: " << filename << std::endl;
      return applicants;
  }

  while (std::getline(file, name)) {
      applicants.insert(name);
  }

  file.close();
  return applicants;
}

// Helper function to extract initials from a full name
std::string get_initials(const std::string& name) {
  std::stringstream ss(name);
  std::string word, initials;

  while (ss >> word) { // Read each word (first name, last name, etc.)
      initials += word[0]; // Take the first letter
  }

  return initials;
}

// Function to find matches based on initials
std::queue<std::string*> find_matches(const std::set<std::string>& students, const std::string& name) {
  std::queue<std::string*> matches;
  std::string target_initials = get_initials(name);

  for (const std::string& student : students) {
      if (get_initials(student) == target_initials) {
          matches.push(const_cast<std::string*>(&student)); // Store pointer to matched name
      }
  }

  return matches;
}

// Function to get the "one true match" from the queue
std::string get_match(std::queue<std::string*>& matches) {
  if (matches.empty()) {
      return "NO MATCHES FOUND. Better luck next year 😢";
  }

  // Seed random number generator
  std::srand(std::time(0));

  int match_count = matches.size();
  int random_index = std::rand() % match_count; // Pick a random index

  std::string* selected_match = nullptr;
  for (int i = 0; i <= random_index; ++i) {
      selected_match = matches.front();
      matches.pop();
      if (i < random_index) {
          matches.push(selected_match); // Re-add non-selected names back to queue
      }
  }

  return *selected_match;
}

int main() {
  std::string filename = "applicants.txt";
  std::set<std::string> applicants = get_applicants(filename);

  std::cout << "Applicants list:\n";
  for (const auto& name : applicants) {
      std::cout << name << std::endl;
  }

  std::string search_name;
  std::cout << "\nEnter a name to find matches by initials: ";
  std::getline(std::cin, search_name);

  std::queue<std::string*> matches = find_matches(applicants, search_name);

  std::cout << "\nMatching applicants with same initials:\n";
  std::queue<std::string*> temp_matches = matches;
  if (temp_matches.empty()) {
      std::cout << "NO MATCHES FOUND.\n";
  } else {
      while (!temp_matches.empty()) {
          std::cout << *temp_matches.front() << std::endl;
          temp_matches.pop();
      }
  }

  std::cout << "\nYour one true match is: " << get_match(matches) << std::endl;

  return 0;
}

/* #### Please don't remove this line! #### */
#include "autograder/utils.hpp"
