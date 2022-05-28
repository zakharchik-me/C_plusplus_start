#include <iostream>
#include <fstream>
#include "menu.h"

using namespace std;

int main()
{
    Menu menu;

    menu.write_rules();
    while (true)
    {
        cout << "Your command: ";
        int cmd;
        cin >> cmd;
        menu.do_command(cmd);
    }
    return 0;
}
