#include<iostream>
#include<cstring>

using namespace std;

const int maxOrders = 100;
const int maxProduct = 100;
const int maxCostomer = 100;

class Product {
public:
    char name[50];
    double price;
    bool availability;

    Product() {
        strcpy(name, "");
        price = 0.0;
        availability = false;
    }


    void AddProduct(const char* prodName, double prodPrice, bool isAvailable) {
        strcpy(name, prodName);
        price = prodPrice;
        availability = isAvailable;
    }

    void UpdateAvailability(bool isAvailable) {
        availability = isAvailable;
    }
};

class Order {
public:
    int orderID;
    char date[20];
    Product products[maxProduct];
    int productQuantities[maxProduct];
    int pCount;

    Order() {
        orderID = 0;
        strcpy(date, "");
        pCount = 0;
    }

    void AddOrder(int id, const char* orderDate) {
        orderID = id;
        strcpy(date, orderDate);
    }

    void AddProductToOrder(const Product& product, int quantity) {
        if (pCount < maxProduct) {
            products[pCount] = product;
            productQuantities[pCount] = quantity;
            pCount++;
        }
    }

    double CalculateTotal() {
        double total = 0.0;
        for (int i = 0; i < pCount; i++) {
            if (products[i].availability) {

                total += products[i].price * productQuantities[i];
            }
        }
        return total;
    }

    void ViewOrderDetails() {

        cout << "Order ID: " << orderID << ", Date: " << date << endl;
        for (int i = 0; i < pCount; i++) {
            
            cout << "Product: " << products[i].name << ", Quantity: " << productQuantities[i] << ", Price: $" << products[i].price << endl;
        }
        cout << "Total Cost: $" << CalculateTotal() << endl;
    }
};

class Customer {
public:
    char name[50];
    char address[100];
    Order orders[maxOrders];
    int orderCount;

    Customer() {
        strcpy(name, "");
        strcpy(address, "");
        orderCount = 0;
    }

    void AddCustomer(const char* custName, const char* custAddress) {
        strcpy(name, custName);
        strcpy(address, custAddress);
    }

    void PlaceOrder(Order& order) {
        if (orderCount < maxOrders) {
            orders[orderCount++] = order;
        }
    }

    void ViewOrders() {
        cout << "Customer: " << name << ", Address: " << address << endl;
        for (int i = 0; i < orderCount; i++) {
            orders[i].ViewOrderDetails();
        }
    }
};

int main() {
    // Sample usage
    Customer customer;
    customer.AddCustomer("John Doe", "123 Main St");

    Product product1, product2;
    product1.AddProduct("laptoop", 1200.00, true);
    product2.AddProduct("Mouse", 25.00, true);

    Order order;
    order.AddOrder(1, "2024-03-30");
    order.AddProductToOrder(product1, 1);
    order.AddProductToOrder(product2, 2);

    customer.PlaceOrder(order);

    customer.ViewOrders();

    return 0;
}
