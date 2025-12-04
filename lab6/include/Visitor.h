#pragma once
#include "npc.h"
#include "Observer.h"
#include <vector>
#include <memory>

class Observer;
extern std::vector<std::unique_ptr<Observer>> observers;

class Visitor {
public:
    virtual ~Visitor() = default;
    virtual void visit(Rogue& npc) = 0;
    virtual void visit(Orc& npc) = 0;
    virtual void visit(Werewolf& npc) = 0;
};

class BattleVisitor : public Visitor {
public:
    const std::vector<NPCPtr>& npcs;
    double radius;

    BattleVisitor(const std::vector<NPCPtr>& npcs, double radius);
    void visit(Rogue& npc) override;
    void visit(Orc& npc) override;
    void visit(Werewolf& npc) override;
private:
    void fight(NPC& attacker, NPC& defender);
};