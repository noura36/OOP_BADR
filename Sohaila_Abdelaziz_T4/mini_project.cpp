#include <iostream>
#include <string>

struct AttackStats {
    int damage;
    int range;
};

class Monster {
    protected :
    std::string name;
    int health;

    public : 
    Monster(std::string monestername, int monesterhealth) : name(monestername), health(monesterhealth) {}

    void display() const {
        std::cout << "Name: " << name << ", Health: " << health << "\n";

    }
};

class Dragon : public Monster {
    private:
    AttackStats stats;

    public:
    Dragon(std::string dragonname, int dragonhealth, int dmg, int rng) : Monster(dragonname, dragonhealth), stats{dmg, rng} {};

};

void captureMonster(Monster m) {
    std:: cout << "Inside captureMonster -> sizeof(m): " << sizeof(m) << " bytes\n";

}

int main() {

    Dragon d("Ignis", 300, 75, 25);

    d.display();
    std::cout << "In main -> sizeof(d): " << sizeof(d) << "bytes\n";
    captureMonster(d);
    return 0;
}