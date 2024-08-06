#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Product {
    string name;
    double price;

public:
    Product(const string& _name, double _price) : name(_name), price(_price) {}

    string getName() const { return name; }
    double getPrice() const { return price; }
};

class Customer {
    string name;
    string email;
public:
    Customer(const string& _name, const string& _email) : name(_name), email(_email) {}

    string getName() const { return name; }
    string getEmail() const { return email; }
};

class Order {
    Customer customer;
    vector<Product> products;
    double total;
public:
    Order(const Customer& _customer) : customer(_customer), total(0) {}

    void addProduct(const Product& product) {
        products.push_back(product);
        total += product.getPrice();
    }

    void displayOrder() {
        cout << "Order Details:" << endl;
        cout << "Customer: " << customer.getName() << endl;
        cout << "Email: " << customer.getEmail() << endl;
        cout << "Products:" << endl;
        for (const auto& product : products) {
            cout << "- " << product.getName() << " ($" << product.getPrice() << ")" << endl;
        }
        cout << "Total: $" << total << endl;
    }
};

class ShoppingCart {
    vector<Product> products;
public:
    void addProduct(const Product& product) {
        products.push_back(product);
    }

    void displayCart() {
        cout << "Shopping Cart:" << endl;
        for (const auto& product : products) {
            cout << "- " << product.getName() << " ($" << product.getPrice() << ")" << endl;
        }
    }

    double calculateTotal() {
        double total = 0;
        for (const auto& product : products) {
            total += product.getPrice();
        }
        return total;
    }
};

int main() {
    Customer customer("John Doe", "john.doe@example.com");
    Product laptop("Laptop", 1200.00);
    Product phone("Smartphone", 800.00);
    Product headphones("Headphones", 100.00);

    Order order(customer);
    order.addProduct(laptop);
    order.addProduct(phone);
    order.addProduct(headphones);
    order.displayOrder();

    ShoppingCart cart;
    cart.addProduct(laptop);
    cart.addProduct(phone);
    cout << "\nShopping Cart Details:" << endl;
    cart.displayCart();
    cout << "Total: $" << cart.calculateTotal() << endl;

    return 0;
}
