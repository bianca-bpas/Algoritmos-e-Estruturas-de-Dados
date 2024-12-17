#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

// Base Product class
class Product {
protected:
    long barcode;
    string name;

public:
    // Constructor with default values
    Product(long code = 0, string productName = "") : barcode(code), name(productName) {}

    // Access methods
    void setCode(long code) { barcode = code; }
    long getCode() const { return barcode; }

    void setName(const string& productName) { name = productName; }
    string getName() const { return name; }

    // Scanner and Printer methods
    virtual void scanner() {
        cout << "Enter barcode: ";
        cin >> barcode;
        cout << "Enter product name: ";
        cin.ignore();
        getline(cin, name);
    }

    virtual void printer() const {
        cout << "Product [Barcode: " << barcode << ", Name: " << name << "]\n";
    }

    virtual ~Product() = default;
};

// PrepackedFood class derived from Product
class PrepackedFood : public Product {
private:
    double unitPrice;

public:
    // Constructor with default values
    PrepackedFood(long code = 0, string productName = "", double price = 0.0)
        : Product(code, productName), unitPrice(price) {}

    // Access methods
    void setUnitPrice(double price) { unitPrice = price; }
    double getUnitPrice() const { return unitPrice; }

    // Scanner and Printer methods
    void scanner() override {
        Product::scanner();
        cout << "Enter unit price: ";
        cin >> unitPrice;
    }

    void printer() const override {
        Product::printer();
        cout << "Unit Price: " << unitPrice << "\n";
    }
};

// FreshFood class derived from Product
class FreshFood : public Product {
private:
    double weight;
    double pricePerKilo;

public:
    // Constructor with default values
    FreshFood(long code = 0, string productName = "", double wt = 0.0, double pricePerKg = 0.0)
        : Product(code, productName), weight(wt), pricePerKilo(pricePerKg) {}

    // Access methods
    void setWeight(double wt) { weight = wt; }
    double getWeight() const { return weight; }

    void setPricePerKilo(double pricePerKg) { pricePerKilo = pricePerKg; }
    double getPricePerKilo() const { return pricePerKilo; }

    double calculatePrice() const { return weight * pricePerKilo; }

    // Scanner and Printer methods
    void scanner() override {
        Product::scanner();
        cout << "Enter weight: ";
        cin >> weight;
        cout << "Enter price per kilo: ";
        cin >> pricePerKilo;
    }

    void printer() const override {
        Product::printer();
        cout << "Weight: " << weight << " kg, Price per kilo: " << pricePerKilo
             << ", Total Price: " << calculatePrice() << "\n";
    }
};

// Function to find the product with the lower barcode
Product& isLowerCode(Product& prod1, Product& prod2) {
    return (prod1.getCode() < prod2.getCode()) ? prod1 : prod2;
}

int main() {
    // Create array of Product pointers
    Product* products[3];
    products[0] = new Product(11111, "Generic Product");
    products[1] = new PrepackedFood(22222, "Cereal Box", 4.99);
    products[2] = new FreshFood(33333, "Bananas", 2.0, 1.99);

    // Dynamically allocate FreshFood object
    FreshFood* freshPtr = new FreshFood(44444, "Apples", 1.5, 2.99);

    cout << "--- Calling printer() for all products ---\n";
    for (int i = 0; i < 3; ++i) {
        products[i]->printer();
    }
    freshPtr->printer();

    cout << "\n--- Downcasting to execute correct printer() ---\n";
    for (int i = 0; i < 3; ++i) {
        if (auto* prepacked = dynamic_cast<PrepackedFood*>(products[i])) {
            prepacked->printer();
        } else if (auto* fresh = dynamic_cast<FreshFood*>(products[i])) {
            fresh->printer();
        } else {
            products[i]->printer();
        }
    }

    // Display pointer values before and after downcasting
    cout << "\nPointer values before downcasting: " << freshPtr << "\n";
    Product* basePtr = freshPtr; // Upcasting
    basePtr->printer(); // Calls base class version

    // Test isLowerCode()
    cout << "\n--- Testing isLowerCode() ---\n";
    Product& lower = isLowerCode(*products[0], *products[1]);
    cout << "Lower barcode product: ";
    lower.printer();

    Product& lower2 = isLowerCode(*products[1], *freshPtr);
    cout << "Lower barcode product: ";
    lower2.printer();

    // Clean up dynamic memory
    for (int i = 0; i < 3; ++i) {
        delete products[i];
    }
    delete freshPtr;

    return 0;
}
