#include <string>
#include <vector>
#include <fstream>
#include <iostream>
#include "file.h"

using namespace std;

FileClass::FileClass()
{
    this->is_file_opened = false;
}

FileClass::FileClass(const string& name)
{
    this->file_name = name;
    this->is_file_opened = false;
}

void FileClass::set_file_name(const string& name)
{
    this->file_name = name;
}

const string& FileClass::get_file_name()
{
    if (this->is_file_opened) {
        return this->file_name;
    }
    else {
        return "File is not opened!";
    }
}

void FileClass::open_file()
{
    if (this->is_file_opened)
    {
        cout << "File is already opened!" << endl;
    }
    else
    {
        this->out_file.open(this->file_name.c_str());
        this->is_file_opened = true;
        cout << "File is opened now!" << endl;
    }
}

void FileClass::close_file()
{
    if (this->is_file_opened == false)
    {
        cout << "File is not opened!" << endl;
    }
    else
    {
        this->out_file.close();
        this->is_file_opened = false;
        cout << "File is closed now!" << endl;
    }
}

bool FileClass::is_file_open()
{
    return this->is_file_opened;
}

string FileClass::get_line_from_file()
{
    if (this->is_file_opened) {
        if(!this->out_file.eof()) {
            string s;
            getline (this->out_file, s);
            return s;
        }
        else {
            return "";
        }
    }
    else {
        return "";
    }
}

bool FileClass::if_file_ended()
{
    if (this->is_file_opened) {
        if(!this->out_file.eof()) {
            return false;
        }
        else {
            return true;
        }
    }
    else {
        return true;
    }
}