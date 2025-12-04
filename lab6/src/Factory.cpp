#include "../include/Factory.h"
#include <fstream>
#include <iomanip>
#include <unordered_set>

NPCPtr NPCFactory::create(const std::string& type, int x, int y, const std::string& name) {
    if (x < 0 || x > 500 || y < 0 || y > 500) return nullptr;

    if (type == "Rogue") return std::make_shared<Rogue>(x, y, name);
    if (type == "Orc") return std::make_shared<Orc>(x, y, name);
    if (type == "Werewolf") return std::make_shared<Werewolf>(x, y, name);
    return nullptr;
}

std::vector<NPCPtr> NPCFactory::load(const std::string& filename) {
    std::ifstream f(filename);
    std::vector<NPCPtr> result;
    if (!f) return result;

    std::string header, type, name;
    std::getline(f, header);
    int x, y;
    while (f >> type >> x >> y >> name) {
        auto npc = create(type, x, y, name);
        if (npc) result.push_back(npc);
    }
    return result;
}

void NPCFactory::save(const std::vector<NPCPtr>& npcs, const std::string& filename) {
    std::ofstream f(filename);
    f << std::left << std::setw(12) << "Type" << std::setw(5) << "X" << std::setw(5) << "Y" << "Name\n";
    for (auto& npc : npcs) {
        f << std::left << std::setw(12) << npc->type() << std::setw(5) << npc->x << std::setw(5) << npc->y << npc->name << "\n";
    }
}