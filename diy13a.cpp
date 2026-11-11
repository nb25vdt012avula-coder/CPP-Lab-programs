#include <iostream>
#include <memory>
#include <string>

class Resource {
public:
    Resource(const std::string& name) : name(name) {
        std::cout << "Resource " << name << " acquired.\n";
    }
    ~Resource() {
        std::cout << "Resource " << name << " destroyed automatically.\n";
    }
    void doWork() const {
        std::cout << "Using resource: " << name << "\n";
    }
private:
    std::string name;
};

int main() {
    // Replaces raw pointer and 'new' with std::unique_ptr
    std::unique_ptr<Resource> res = std::make_unique<Resource>("DatabaseConnection");
    
    res->doWork();

    // Memory is freed automatically when 'res' goes out of scope; no 'delete' needed
    return 0;
}