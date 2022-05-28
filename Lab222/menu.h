#ifndef MENU_H_INCLUDED
#define MENU_H_INCLUDED

#include <string>
#include "file.h"

class Menu
{
private:
    string credits;
    FileClass file;
    bool is_work_started;
public:
    Menu();
    void write_credits();
    void write_rules();
    void do_command(int cmd);
};

#endif

