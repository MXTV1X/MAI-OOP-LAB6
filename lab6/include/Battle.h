#pragma once
#include "npc.h"
#include <vector>

// Функция для проведения раунда сражения между всеми NPC в заданном радиусе
void run_battle(std::vector<NPCPtr>& npcs, double radius);