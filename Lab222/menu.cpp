#include <string>
#include <iostream>
#include <stdlib.h>
#include "menu.h"

using namespace std;

Menu::Menu()
{
    this->credits = "\nFile System Working \n";
    this->is_work_started = false;
}

void Menu::write_credits()
{
    cout << this->credits << endl;
}

void Menu::write_rules()
{
    cout << "Enter '0' to start work." << endl;
    cout << "Enter '1' to open file." << endl;
    cout << "Enter '2' to close file." << endl;
    cout << "Enter '3' to check is file opened." << endl;
    cout << "Enter '4' to get file name." << endl;
    cout << "Enter '5' to get a line from file." << endl;
    cout << "Enter '6' to check if file ended." << endl;
    cout << "Enter '9' to exit program." << endl;
}

void Menu::do_command(int cmd)
{
    switch (cmd)
    {
        case 0:
            if (this->is_work_started == false)
            {
                cout << "Do you want to use your file name or default?" << endl;
                cout << "Enter 1 to use your file name\nEnter 2 to use default file name\n";
                cout << "Your choice: ";
                int choice;
                cin >> choice;
                while (choice != 1 && choice != 2)
                {
                    cout << "Enter 1 or 2!" << endl;
                    cout << "Your choice: ";
                    cin >> choice;
                }
                if (choice == 1)
                {
                    cout << "Enter your file name: ";
                    string file_name;
                    cin >> file_name;
                    this->file.set_file_name(file_name);
                }
                else
                {
                    this->file.set_file_name("input.txt");
                }

                cout << "Work is starting now!" << endl;
                this->is_work_started = true;
            }
            else
            {
                cout << "Work is ALREADY started!" << endl;
            }
            break;
        case 1:
            if (this->is_work_started)
            {
                this->file.open_file();
            }
            else
            {
                cout << "Start work for the 1st!" << endl;
            }
            break;
        case 2:
            if (this->is_work_started)
            {
                this->file.close_file();
            }
            else
            {
                cout << "Start work for the 1st!" << endl;
            }
            break;

        case 3:
            if (this->is_work_started)
            {
                cout<<this->file.is_file_open()<<endl;
            }
            else
            {
                cout << "Start work for the 1st!" << endl;
            }
            break;
        case 4:
            if (this->is_work_started) {
                cout << this->file.get_file_name() << endl;
            }
            else
            {
                cout << "Start work for the 1st!" << endl;
            }
            break;
        case 5:
            if (this->is_work_started) {
                cout << this->file.get_line_from_file() << endl;
            }
            else
            {
                cout << "Start work for the 1st!" << endl;
            }
            break;
        case 6:
            if (this->is_work_started) {
                cout << this->file.if_file_ended() << endl;
            }
            else
            {
                cout << "Start work for the 1st!" << endl;
            }
            break;
        case 9:
            exit(0);
            break;
        default:
            cout << "No such command, try again!" << endl;
            break;
    }
}

