#include "Piano.hpp"

int main()
{

    DISPLAY::init();

    Piano p;

    Played<Displayed<Track>> t{"两只老虎.txt"};

    KEYBOARD::wait_key(VK_ESCAPE);

    return 0;
}
