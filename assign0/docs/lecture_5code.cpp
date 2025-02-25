#include <iostream>
#include <map>

// Function to display inventory
void displayInventory(const std::map<std::string, int>& inventory) {
    std::cout << "Current Inventory:\n";
    for (const auto& item : inventory) {
        std::cout << item.first << ": " << item.second << " in stock\n";
    }
    std::cout << std::endl;
}

// Function to add a new product to inventory
void addProduct(std::map<std::string, int>& inventory, const std::string& product, int quantity) {
    if (inventory.find(product) != inventory.end()) {
        inventory[product] += quantity; // If product exists, update the quantity
        std::cout << "Updated " << product << " stock by " << quantity << ".\n";
    } else {
        inventory[product] = quantity; // If product doesn't exist, add it
        std::cout << "Added new product: " << product << " with quantity " << quantity << ".\n";
    }
}
// Function to add a new category to inventory
void addCategory(const std::string& category){

    if (inventory.find(category) == inventory.end()) {
        inventory[category] = {}; // Create an empty category
        std::cout << "Category '" << category << "' added.\n";
    } else {
        std::cout << "Category '" << category << "' already exists.\n";
    }
//Function to display new categories
void displayCategories() {
    std::cout << "Available Categories:\n";
    for (const auto& category : inventory) {
        std::cout << "- " << category.first << "\n";
    }
    std::cout << std::endl;
}

}
int main() {
    std::map<std::string, int> inventory;

    // Adding initial products
    inventory["Laptop"] = 5;
    inventory["Mouse"] = 20;
    inventory["Keyboard"] = 10;

    displayInventory(inventory);

    // Adding new products
    addProduct(inventory, "Monitor", 7);
    addProduct(inventory, "Mouse", 5); // Updating an existing product

    displayInventory(inventory);
    // Adding new categories
    addCategory("Electronics");
    addCategory("Peripherals");

    displayCategories();
    return 0;
}