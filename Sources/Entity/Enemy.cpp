#include "../../Includes/Entity/Enemy.h"

Enemy::Enemy() : Entity(), Interactive() {}
Enemy::Enemy(std::string name) : Interactive() {
    SetName(name);
    SetPosition({ 0, 0 });
}
Enemy::Enemy(std::string name, int x, int y) : Interactive() {
    SetName(name);
    SetPosition({ x, y });
}
void Enemy::SetPosition(const std::pair<uint32_t, uint32_t>& position) {
    this->position = position;
}
std::pair<uint32_t, uint32_t> Enemy::GetPosition(void) {
    return position;
}
