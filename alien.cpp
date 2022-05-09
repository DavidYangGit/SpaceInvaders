#include "alien.h"

Alien::Alien(AlienType type) {
    this->type = type;
};

Alien::Alien(QGraphicsItem *parent, AlienType type) : Collidable(parent) {
    this->type = type;
}

void Alien::generateFormation() {
    formationPosition = 0;
    while (!formation->empty()) {
        std::vector<Alien *> column = formation->back();
        while (!column.empty()) {
            delete column.back();
            column.pop_back();
        }
        formation->pop_back();
    }

    // TODO: check constants
    // If we have to change alien pushes then do ifs and another for
    // TODO: parent should be scene, probably?
    for (int i = 0; i < 10; i++) {
        std::vector<Alien *> column;
        column.push_back(new Alien(AlienType::LOWER));
        column.push_back(new Alien(AlienType::LOWER));
        column.push_back(new Alien(AlienType::MIDDLE));
        column.push_back(new Alien(AlienType::MIDDLE));
        column.push_back(new Alien(AlienType::UPPER));
    }
}

void Alien::advance(int step) {
    if (step) {
        // Move sideways

        // Potentially move down
    }
}
