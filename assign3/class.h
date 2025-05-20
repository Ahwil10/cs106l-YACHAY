#ifndef CLASS_H
#define CLASS_H

#include <string>

class BankAccount {
private:
    std::string accountHolder;
    double balance;

    void validateBalance();  // Private helper function

public:
    // Default constructor
    BankAccount();

    // Custom constructor
    BankAccount(const std::string& name, double initialBalance);

    // Getter function (const-correct)
    std::string getAccountHolder() const;
    double getBalance() const;

    // Setter function
    void setAccountHolder(const std::string& name);
    void setBalance(double amount);

    // Public methods
    void deposit(double amount);
    void withdraw(double amount);
};

#endif // CLASS_H