#include <iostream>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <vector>
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
// Function to add a new category 
void addCategory(std::set<std::string>& categories, const std::string& category) {
    auto result = categories.insert(category);
    if (result.second) {
        std::cout << "Category '" << category << "' added successfully.\n";
    } else {
        std::cout << "Category '" << category << "' already exists.\n";
    }
}
//Function to display new categories
void displayCategories(const std::set<std::string>& categories) {
    std::cout << "Product Categories:\n";
    for (const auto& category : categories) {
        std::cout << "- " << category << "\n";
    }
    std::cout << std::endl;
}
// Function to add a new order
void addOrder(std::queue<std::string>& orders, const std::string& order) {
    orders.push(order);
    std::cout << "Added " << order << " to the queue.\n";
}

// Function to process an order
void processOrder(std::queue<std::string>& orders) {
    if (!orders.empty()) {
        std::cout << "Processing " << orders.front() << std::endl;
        orders.pop();
    } else {
        std::cout << "No orders to process.\n";
    }
}
// Function to restack
// Function to add a restock batch
void addRestockBatch(std::stack<std::pair<std::string, int>>& restocks, const std::string& product, int quantity) {
    restocks.push({product, quantity});
    std::cout << "Added restock batch: " << quantity << " units of " << product << ".\n";
}

// Function to process a restock batch
void processRestockBatch(std::stack<std::pair<std::string, int>>& restocks) {
    if (!restocks.empty()) {
        auto item = restocks.top();
        std::cout << "Processing restock: " << item.second << " units of " << item.first << ".\n";
        restocks.pop();
    } else {
        std::cout << "No restock batches to process.\n";
    }
}
// Function to add an item to the cart
void addToCart(std::vector<std::string>& cart, const std::string& item) {
    cart.push_back(item);
    std::cout << item << " added to the cart.\n";
}
// Diplay items in the cart
void displayCart(std::vector<std::string>& cart){
    if (cart.empty()){
    std::cout<< "the cart is empty. \n";
    return;
    }
    std::cout<< "items in costumers cart. \n";
    for (const auto& item : cart){
        std::cout << "- " << item << "\n";
    }
    //std::cout << std::endl;
}
int main() {
    std::map<std::string, int> inventory;
    std::set<std::string> productCategories;
    std::queue<std::string> orders;
    std::stack<std::pair<std::string, int>> restocks;
    std::vector<std::string> customerCart;
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
    addCategory(productCategories, "Electronics");
    addCategory(productCategories, "Peripherals");

    displayCategories(productCategories);
    //Adding orders
    addOrder(orders, "Order#2: Mouse");
    addOrder(orders, "Order#3: Keyboard");

    std::cout << "\nProcessing Orders:\n";
    while (!orders.empty()) {
        processOrder(orders);
    }
    // Adding restock batches
    restocks.push({"Mouse", 10});
    restocks.push({"Laptop", 2});
    restocks.push({"Keyboard", 5});

    // Processing restocks
    while (!restocks.empty()) {
        auto item = restocks.top();
        std::cout << "Restocking " << item.second << " units of " << item.first << std::endl;
        restocks.pop();
    }
      // Adding items to cart
      customerCart.push_back("Laptop");
      customerCart.push_back("Mouse");
      customerCart.push_back("Keyboard");
  
      std::cout << "Items in customer cart:\n";
      for (const auto& item : customerCart) {
          std::cout << "- " << item << "\n";
      }
    return 0;
}