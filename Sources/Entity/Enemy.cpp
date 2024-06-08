#include "../../Includes/Entity/Enemy.h"

Enemy::Enemy() : Entity(), Interactive() {}
Enemy::Enemy(std::string name) : Interactive() {
	SetName(name);
}