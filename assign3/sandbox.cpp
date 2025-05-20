/*
 * CS106L Assignment 3: Make a Class
 * Created by Fabio Ibanez with modifications by Jacob Roberts-Baca.
 */
#include "class.h"
#include <iostream>

void sandbox() {
    // Create an instance using the default constructor
    BankAccount account1;
    std::cout << "Default Account Holder: " << account1.getAccountHolder() << std::endl;
    std::cout << "Default Balance: $" << account1.getBalance() << std::endl;

    // Create an instance using the custom constructor with uniform initialization
    BankAccount account2{"Alice Johnson", 750.0};
    std::cout << "\nAccount Holder: " << account2.getAccountHolder() << std::endl;
    std::cout << "Initial Balance: $" << account2.getBalance() << std::endl;

    // Modify account details using setters
    account2.setAccountHolder("Bob Smith");
    account2.setBalance(1200.0);
    std::cout << "\nUpdated Account Holder: " << account2.getAccountHolder() << std::endl;
    std::cout << "Updated Balance: $" << account2.getBalance() << std::endl;

    // Perform some transactions
    account2.deposit(300.0);
    std::cout << "After Deposit of $300: $" << account2.getBalance() << std::endl;

    account2.withdraw(500.0);
    std::cout << "After Withdrawal of $500: $" << account2.getBalance() << std::endl;

    // Attempt to withdraw more than the balance (should print an error)
    account2.withdraw(2000.0);
}
