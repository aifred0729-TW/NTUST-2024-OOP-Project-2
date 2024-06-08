#include "../../Includes/Incident/Event.h"

// Public

int Event::Attack(Entity*, std::vector<Entity*>) {
	return 0;
}

int Event::Flee(std::vector<Entity*>) {
	return 0;
}

int Event::Random(std::vector<Entity*>, std::vector<Entity*>) {
	return 0;
}