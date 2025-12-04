#include "include/Factory.h"
#include "include/Observer.h"
#include "include/Battle.h"
#include "include/Visitor.h"
#include <iostream>

int main() {
    observers.push_back(std::make_unique<ConsoleObserver>());
    observers.push_back(std::make_unique<FileObserver>());

    std::vector<NPCPtr> dungeon;
    dungeon.push_back(NPCFactory::create("Rogue", 10, 10, "Robin"));
    dungeon.push_back(NPCFactory::create("Werewolf", 12, 12, "Wolfy"));
    dungeon.push_back(NPCFactory::create("Orc", 50, 50, "Thrall"));

    std::cout << "Characters in dungeon:\n";
    for(auto& n : dungeon) std::cout << n->type() << " " << n->name << " at " << n->x << "," << n->y << "\n";

    std::cout << "\nStarting battle...\n";
    run_battle(dungeon, 20.0);

    std::cout << "\nSurvivors:\n";
    for(auto& n : dungeon) std::cout << n->name << " is alive.\n";

    return 0;
}