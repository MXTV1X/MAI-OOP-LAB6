#include "../include/npc.h"
#include "../include/Visitor.h"

void Rogue::accept(Visitor& v) { v.visit(*this); }
void Orc::accept(Visitor& v) { v.visit(*this); }
void Werewolf::accept(Visitor& v) { v.visit(*this); }