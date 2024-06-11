#include <KeyBoard.h>

int KeyBoard::keyUpdate(bool key[]) {
    for (long long i = 0; i < ValidInput::INVALID; i++) {
        key[i] = false;
    }
    char input = _getch();
    switch (input) {
    case 'a':
        key[ValidInput::EA] = true;
        return EA;
        break;
    case 'c':
        key[ValidInput::EC] = true;
        return EC;
        break;
    case 'd':
        key[ValidInput::ED] = true;
        return ED;
        break;
    case 'e':
        key[ValidInput::EE] = true;
        return EE;
        break;
    case 'f':
        key[ValidInput::EF] = true;
        return EF;
        break;
    case 'i':
        key[ValidInput::EI] = true;
        return EI;
        break;
    case 'p':
        key[ValidInput::EP] = true;
        return EP;
        break;
    case 'q':
        key[ValidInput::EQ] = true;
        return EQ;
        break;
    case 'r':
        key[ValidInput::ER] = true;
        return ER;
        break;
    case 's':
        key[ValidInput::ES] = true;
        return ES;
        break;
    case 'v':
        key[ValidInput::EV] = true;
        return EV;
        break;
    case 'w':
        key[ValidInput::EW] = true;
        return EW;
        break;
    case 'x':
        key[ValidInput::EX] = true;
        return EX;
        break;
    case ' ':
        key[ValidInput::ESPACE] = true;
        return ESPACE;
        break;
    case 'z':
        key[ValidInput::EZ] = true;
        return EZ;
        break;
    case 27:
        key[ValidInput::EESC] = true;
        return EESC;
        break;
    case 9:
        key[ValidInput::ETAB] = true;
        return ETAB;
        break;
    case 13:
        key[ValidInput::EENTER] = true;
        return EENTER;
        break;
    case 72:
        key[ValidInput::EDU] = true;
        return EDU;
        break;
    case 75:
        key[ValidInput::EDL] = true;
        return EDL;
        break;
    case 77:
        key[ValidInput::EDR] = true;
        return EDR;
        break;
    case 80:
        key[ValidInput::EDD] = true;
        return EDD;
        break;
    default:
        break;
    }
    return -1;
}