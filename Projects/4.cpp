#include <iostream>
#include <string>
using namespace std;
struct EngineSpecs {
    int horsepower;
    int max_temp;
};
class Generator {
private:
    string name;
    int current_output;
    EngineSpecs specs;
public:
    inline static int total_grid_power = 0;
    explicit Generator(string n, int output, EngineSpecs s)
        : name(n), current_output(output), specs(s) {
        total_grid_power += current_output;
    }
    Generator(const Generator&) = delete;
    Generator& operator=(const Generator&) = delete;
    ~Generator() {
        total_grid_power -= current_output;
    }
    Generator& operator+=(int extra_power) {
        current_output += extra_power;
        total_grid_power += extra_power;
        return *this;
    }
    friend ostream& operator<<(ostream& os, const Generator& g) {
        os << "Generator Name: " << g.name
           << "\nCurrent Output: " << g.current_output << " KW"
           << "\nHorsepower: " << g.specs.horsepower;
        return os;
    }
    friend void gridInspector(const Generator& g);
};
void gridInspector(const Generator& g) {
    cout << "Grid Inspector Report"
         << "\nGenerator: " << g.name
         << "\nMaximum Temperature: " << g.specs.max_temp
         << " C" << endl;
}
int main() {
    Generator gen1("Solar Generator", 2000, {1500, 90});
    Generator gen2("Wind Generator", 3000, {2200, 110});

    gen1 += 500;

    cout << gen1 << "\n\n";
    cout << gen2 << "\n\n";

    cout << "Total Grid Power: "
         << Generator::total_grid_power << " KW" << endl;

    gridInspector(gen1);

    return 0;
}