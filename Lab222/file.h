// FILE CLASS H

#ifndef FILE_CLASS_H_INCLUDED
#define FILE_CLASS_H_INCLUDED

#include <fstream>
#include <string>
#include <vector>

using namespace std;

class FileClass {
private:
    string file_name;
    ifstream out_file;
    bool is_file_opened;
public:
    FileClass();
    FileClass(const string& name);

    void set_file_name(const string& file_name);
    const string& get_file_name();

    void open_file();
    void close_file();

    string get_line_from_file();
    bool if_file_ended();

    bool is_file_open();
};
#endif
