#include <iostream>

class Player {
public:
    int health;
    
    Player(int h) {
        health = h;
    }
};

void applyDamageValue(Player p) {
    p.health -= 50;
}

void applyDamagePointer(Player* p) {
    if (p != nullptr) {
        (*p).health -= 50; 
    }
}

void applyDamageReference(Player& p) {
    p.health -= 50;
}

int main() {
    
    Player myPlayer(100);
    std::cout <<"the primary health is "<< myPlayer.health << "\n";

    
    applyDamageValue(myPlayer);
    std::cout << "the health after call by value :" << myPlayer.health << "\n";

    myPlayer.health = 100;

    applyDamagePointer(&myPlayer); 
    std::cout << "the health after call by pointer :  " << myPlayer.health << "\n";

    myPlayer.health = 100;

    applyDamageReference(myPlayer);
    std::cout << "the health after call by Reference  :" << myPlayer.health << " \n";

    return 0;
}