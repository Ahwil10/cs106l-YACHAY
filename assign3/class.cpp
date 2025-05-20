#include "class.h"
#include <iostream>

// Default constructor
BankAccount::BankAccount() : accountHolder("Unknown"), balance(0.0) {}

// Custom constructor
BankAccount::BankAccount(const std::string& name, double initialBalance) 
    : accountHolder(name), balance(initialBalance) {
    validateBalance();
}

// Private function to ensure balance is non-negative
void BankAccount::validateBalance() {
    if (balance < 0) {
        std::cout << "Balance cannot be negative. Setting to 0." << std::endl;
        balance = 0;
    }
}

// Getter functions (const-correct)
std::string BankAccount::getAccountHolder() const {
    return accountHolder;
}

double BankAccount::getBalance() const {
    return balance;
}

// Setter functions
void BankAccount::setAccountHolder(const std::string& name) {
    accountHolder = name;
}

void BankAccount::setBalance(double amount) {
    balance = amount;
    validateBalance();
}

// Deposit function
void BankAccount::deposit(double amount) {
    if (amount > 0) {
        balance += amount;
    } else {
        std::cout << "Deposit amount must be positive." << std::endl;
    }
}

// Withdraw function
void BankAccount::withdraw(double amount) {
    if (amount > 0 && amount <= balance) {
        balance -= amount;
    } else {
        std::cout << "Invalid withdrawal amount." << std::endl;
    }
}