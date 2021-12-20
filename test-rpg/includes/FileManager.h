#ifndef FILEMANAGER_H
#define FILEMANAGER_H

// Custom Headers
#include "Standard.h"

// Standard Headers
#include <iostream>
#include <sstream>
#include <fstream>
#include <string>

namespace rpgText
{
    // Calculates length of character array
    int get_char_arr_len(const char *charArray);
    int get_char_arr_len(char *charArray);

    // Converts character Array to string
    std::string arr_to_string(const char *charArray);
    std::string arr_to_string(char *charArray);

    // Converts chararcter array to float ("70" to 70.0)
    float arr_to_float(const char *charArray);

    // Gets Single Line from a starting Index till '\n'
    char *get_line(const char *charList, int startIndex);
    char *get_line(char *charList, int startIndex);

    // Gets ending index of a line from a starting Index
    int get_index_end(const char *charList, int startIndex);
    int get_index_end(char *charList, int startIndex);

    // Gets starting index of next line from a starting Index
    int get_index_start(const char *charList, int startIndex);
    int get_index_start(char *charList, int startIndex);

    // Get starting Index of a char array in another char array
    int get_string_start(char *mainCharArray, const char *targetCharArray);

    // Get ending Index of a char array in another char array
    int get_string_end(char *mainCharArray, const char *targetCharArray);

    // Opens file and gets data as Char Array
    std::string get_file_data(const char *path);

    // Skips by n lines
    int skip_lines(const char *dataFile, int n, int startIndex = 0);

    // Gets Data point in the data file from the startIndex using the testChar
    char *get_data_point(const char *dataFile, const char *testChar, int index = 0);

} // namespace rpgText

#endif // !FILEMANAGER_H
