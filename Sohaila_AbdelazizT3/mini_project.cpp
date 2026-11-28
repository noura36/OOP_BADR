/*
====================================================================
 PART 3: MINI-PROJECT CAPSTONE - "THE SMART GRID"
====================================================================
*/

#include <iostream>
#include <string>
#include <utility>

// 1. Aggregate Data Container
struct EngineSpecs {
    int horsepower;
    int max_temp;
};

class Generator {
private:
    std::string name_;
    int current_output_;
    EngineSpecs specs_;

    // 2. Shared State: inline static for total grid power (C++17)
    inline static int total_grid_power = 0;

public:
    // 3. Safe, explicit constructor
    explicit Generator(std::string name, int output, EngineSpecs specs)
        : name_(std::move(name)), current_output_(output), specs_(specs) {
        total_grid_power += current_output_;
    }

    // Copying is disabled so the destructor never subtracts more than the constructor added
    Generator(const Generator&) = delete;
    Generator& operator=(const Generator&) = delete;

    // Destructor to subtract output when the generator is taken offline
    ~Generator() {
        total_grid_power -= current_output_;
    }

    // 4. Operator+= overloading to boost power and update static total
    Generator& operator+=(int boost) {
        current_output_ += boost;
        total_grid_power += boost;
        return *this;
    }

    // 4. Friend operator<< for clean printing to std::cout
    friend std::ostream& operator<<(std::ostream& os, const Generator& g) {
        const std::ios_base::fmtflags savedFlags = os.flags();
        const std::streamsize savedPrec = os.precision();

        os << "Generator [" << g.name_ << "] Output: " << g.current_output_ << " kW";

        os.flags(savedFlags);
        os.precision(savedPrec);
        return os;
    }

    // 5. The Saboteur: Friend function to bypass encapsulation and inspect hidden max_temp
    friend void gridInspector(const Generator& g);

    // Static method to access total grid power directly from the class
    static int getTotalGridPower() {
        return total_grid_power;
    }
};

// Definition of the global friend function
void gridInspector(const Generator& g) {
    std::cout << "[Inspector] Generator " << g.name_
              << " max allowed temperature is " << g.specs_.max_temp << " C\n";
}

int main() {
    // 6. The Test in main:
    // Instantiate two generators using aggregate initialization for the specs
    Generator gen1("Alpha-Turbine", 1200, {450, 1100});
    Generator gen2("Beta-Reactor", 2500, {800, 1400});

    // Print both using std::cout
    std::cout << gen1 << "\n";
    std::cout << gen2 << "\n\n";

    // Use += to increase one's power
    gen1 += 300;
    std::cout << "After power boost:\n" << gen1 << "\n\n";

    // Print the static total_grid_power directly from the class
    std::cout << "Total Grid Power: " << Generator::getTotalGridPower() << " kW\n\n";

    // Call gridInspector() on one of them
    gridInspector(gen1);

    return 0;
}