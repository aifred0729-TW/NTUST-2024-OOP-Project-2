#include <Interactive.h>
#include <Role.h>

// Public

void Interactive::TriggeredBy(Role*) {
    ;
}

void Interactive::SetRole(Role* role) {
    this->role = role;
}
Role* Interactive::GetRole(void) {
    return role;
}