/*
 * CS106L Assignment 5: TreeBook
 * Created by Fabio Ibanez with modifications by Jacob Roberts-Baca.
 */
#ifndef USER_H
#define USER_H
#include <iostream>
#include <string>

class User
{
public:
   // Constructor
   User(const std::string& name);
    
   // Destructor
   ~User();
   
   // Copy operations
   User(const User& user);
   User& operator=(const User& user);
   
   // Move operations (deleted)
   User(User&& user) = delete;
   User& operator=(User&& user) = delete;
   
   // Member functions
   void add_friend(const std::string& name);
   std::string get_name() const;
   size_t size() const;
   void set_friend(size_t index, const std::string& name);
   // Overload
   User& operator+=(User& rhs);  // Add mutual friendship
   bool operator<(const User& rhs) const;  // Compare by name
   // Friend function for output
   friend std::ostream& operator<<(std::ostream& os, const User& user);
private:
  std::string _name;
  std::string* _friends;
  size_t _size;
  size_t _capacity;
};
#endif // USER_H