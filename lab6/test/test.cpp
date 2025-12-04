#include <gtest/gtest.h>
#include "../include/npc.h"
#include "../include/Factory.h"
#include "../include/Visitor.h"

TEST(CombatTest, RogueKillsWerewolf) {
    auto r = std::make_shared<Rogue>(0, 0, "R1");
    auto w = std::make_shared<Werewolf>(1, 1, "W1");
    std::vector<NPCPtr> npcs = {r, w};
    BattleVisitor v(npcs, 10.0);
    r->accept(v);
    EXPECT_FALSE(w->is_alive());
}

TEST(CombatTest, OrcKillsRogue) {
    auto o = std::make_shared<Orc>(0, 0, "O1");
    auto r = std::make_shared<Rogue>(1, 1, "R1");
    std::vector<NPCPtr> npcs = {o, r};
    BattleVisitor v(npcs, 10.0);
    o->accept(v);
    EXPECT_FALSE(r->is_alive());
}