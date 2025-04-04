#include "user.h"
#include <sstream>
#include <algorithm>  // for std::copy
#include <stdexcept>  // for std::out_of_range

// Constructor
User::User(const std::string& name)
  : _name(name)
  , _friends(nullptr)
  , _size(0)
  , _capacity(0)
{
}

// Destructor
User::~User() {
  delete[] _friends;
}

// Copy constructor
User::User(const User& other)
  : _name(other._name)
  , _size(other._size)
  , _capacity(other._capacity)
  , _friends(other._size ? new std::string[other._capacity] : nullptr)
{
    if (_friends) {
        std::copy(other._friends, other._friends + _size, _friends);
    }
}

// Copy assignment operator
User& User::operator=(const User& other) {
    if (this != &other) {  // Check for self-assignment
        // Create new array first (exception-safe)
        std::string* newFriends = nullptr;
        if (other._size > 0) {
            newFriends = new std::string[other._capacity];
            std::copy(other._friends, other._friends + other._size, newFriends);
        }

        // Delete old array
        delete[] _friends;

        // Assign new values
        _name = other._name;
        _size = other._size;
        _capacity = other._capacity;
        _friends = newFriends;
    }
    return *this;
}

// Add friend
void User::add_friend(const std::string& name) {
    if (_size == _capacity) {
        _capacity = (_capacity == 0) ? 1 : _capacity * 2;
        std::string* newFriends = new std::string[_capacity];
        for (size_t i = 0; i < _size; ++i) {
            newFriends[i] = _friends[i];
        }
        delete[] _friends;
        _friends = newFriends;
    }
    _friends[_size++] = name;
}

// Get name
std::string User::get_name() const {
    return _name;
}

// Get size
size_t User::size() const {
    return _size;
}

// Set friend
void User::set_friend(size_t index, const std::string& name) {
    if (index >= _size) {
        throw std::out_of_range("Friend index out of range");
    }
    _friends[index] = name;
}
// += operator for mutual friendship
User& User::operator+=(User& rhs) {
    // Add rhs's name to this user's friend list
    this->add_friend(rhs.get_name());
    // Add this user's name to rhs's friend list
    rhs.add_friend(this->get_name());
    return *this;  // Return reference to self for chaining
}

// < operator for name comparison
bool User::operator<(const User& rhs) const {
    // Compare names lexicographically
    return this->_name < rhs._name;
}

// Output operator
std::ostream& operator<<(std::ostream& os, const User& user) {
    os << "User(name=" << user._name << ", friends=[";
    for(size_t i = 0; i < user._size; ++i) {
        os << user._friends[i];
        if (i != user._size - 1) {
            os << ", ";
        }
    }
    os << "])";
    return os;
}