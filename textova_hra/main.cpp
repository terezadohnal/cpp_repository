#include <iostream>
#include "Hra.h"

int main() {

    Hra* hra = new Hra();
    hra->hrej();

    delete hra;
    return 0;
}
