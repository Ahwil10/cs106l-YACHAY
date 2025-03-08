/*
 * CS106L Assignment 1: SimpleEnroll
 * Created by Fabio Ibanez with modifications by Jacob Roberts-Baca.
 *
 * Welcome to Assignment 1 of CS106L! Please complete each STUDENT TODO
 * in this file. You do not need to modify any other files.
 *
 * Students must implement: parse_csv, write_courses_offered,
 * write_courses_not_offered
 */

 #include <algorithm>
 #include <fstream>
 #include <iostream>
 #include <sstream>
 #include <string>
 #include <vector>
 
 const std::string COURSES_OFFERED_PATH = "student_output/courses_offered.csv";
 const std::string COURSES_NOT_OFFERED_PATH = "student_output/courses_not_offered.csv";
 
 /**
  * Represents a course a student can take in ExploreCourses.
  */
 struct Course {
   std::string title;
   int number_of_units;
   std::string quarter;
   bool is_offered;
 };
 
 #include "utils.cpp"
 
 /**
  * Parses the CSV file and populates the `courses` vector with Course structs.
  */
 void parse_csv(const std::string &filename, std::vector<Course> &courses) {
   std::ifstream file(filename);
   if (!file.is_open()) {
     std::cerr << "Error opening file: " << filename << std::endl;
     return;
   }
   
   std::string line;
   getline(file, line); // Skip the header line
 
   while (getline(file, line)) {
     std::vector<std::string> fields = split(line, ',');
     if (fields.size() < 4) continue; // Ensure valid data
 
     Course course;
     course.title = fields[0];
     course.number_of_units = std::stoi(fields[1]);
     course.quarter = fields[2];
     course.is_offered = (fields[3] == "Yes");
 
     courses.push_back(course);
   }
 }
 
 /**
  * Writes offered courses to a file and removes them from the `all_courses` vector.
  */
 void write_courses_offered(std::vector<Course> &all_courses) {
   std::ofstream file(COURSES_OFFERED_PATH);
   if (!file.is_open()) {
     std::cerr << "Error opening file: " << COURSES_OFFERED_PATH << std::endl;
     return;
   }
 
   file << "Title,Units,Quarter\n";
   all_courses.erase(std::remove_if(all_courses.begin(), all_courses.end(), [&file](const Course &course) {
     if (course.is_offered) {
       file << course.title << "," << course.number_of_units << "," << course.quarter << "\n";
       return true; // Remove the course
     }
     return false;
   }), all_courses.end());
 }
 
 /**
  * Writes courses that are not offered to a separate file.
  */
 void write_courses_not_offered(const std::vector<Course> &unlisted_courses) {
   std::ofstream file(COURSES_NOT_OFFERED_PATH);
   if (!file.is_open()) {
     std::cerr << "Error opening file: " << COURSES_NOT_OFFERED_PATH << std::endl;
     return;
   }
 
   file << "Title,Units,Quarter\n";
   for (const auto &course : unlisted_courses) {
     file << course.title << "," << course.number_of_units << "," << course.quarter << "\n";
   }
 }
 
 int main() {
   static_assert(is_valid_course<Course>, "Course struct is not correctly defined!");
 
   std::vector<Course> courses;
   parse_csv("courses.csv", courses);
 
   write_courses_offered(courses);
   write_courses_not_offered(courses);
 
   return run_autograder();
 }
 