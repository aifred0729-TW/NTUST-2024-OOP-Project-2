#include "../../Includes/Entity/Enemy.h"

Enemy::Enemy() : position({ 0, 0 }) { mode = ENEMY; }
Enemy::Enemy(std::string name) : position({ 0, 0 }) {
	SetName(name);
	SetMode(ENEMY);
}

void Enemy::SetPosition(const std::pair<uint32_t, uint32_t>& position) {
	this->position = position;
}

std::pair<uint32_t, uint32_t> Enemy::GetPosition(void) const {
	return position;
}