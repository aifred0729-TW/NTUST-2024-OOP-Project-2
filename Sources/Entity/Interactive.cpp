#include "../../Includes/Entity/Interactive.h"

// Public

void Interactive::TriggeredBy(Role*) {
    ;
}

void Interactive::SetRole(const Role* role) {
    this->role = role;
}
Role* Interactive::GetRole(void) {
    return role;
}