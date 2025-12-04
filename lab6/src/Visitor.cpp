#include "../include/Visitor.h"
#include "../include/Observer.h"
#include <cmath>

BattleVisitor::BattleVisitor(const std::vector<NPCPtr>& npcs, double radius)
    : npcs(npcs), radius(radius) {}

void BattleVisitor::visit(Rogue& npc) {
    for (auto& other : npcs) {
        if (other->is_alive() && other.get() != &npc) {
            if (std::hypot(npc.x - other->x, npc.y - other->y) <= radius) fight(npc, *other);
        }
    }
}

void BattleVisitor::visit(Orc& npc) {
    for (auto& other : npcs) {
        if (other->is_alive() && other.get() != &npc) {
            if (std::hypot(npc.x - other->x, npc.y - other->y) <= radius) fight(npc, *other);
        }
    }
}

void BattleVisitor::visit(Werewolf& npc) {
    for (auto& other : npcs) {
        if (other->is_alive() && other.get() != &npc) {
            if (std::hypot(npc.x - other->x, npc.y - other->y) <= radius) fight(npc, *other);
        }
    }
}

void BattleVisitor::fight(NPC& attacker, NPC& defender) {
    std::string a = attacker.type();
    std::string d = defender.type();

    bool can_kill = false;
    if (a == "Rogue" && d == "Werewolf") can_kill = true;    // Разбойник убивает оборотней
    else if (a == "Werewolf" && d == "Rogue") can_kill = true; // Оборотень убивает разбойников
    else if (a == "Orc" && d == "Rogue") can_kill = true;      // Орк убивает разбойника

    if (can_kill) {
        for (auto& obs : observers) obs->on_kill(attacker.name, defender.name);
        defender.die();
    }
}