#include "FileManager.h"

namespace rpgText
{
    // Calculates length of character array
    int get_char_arr_len(const char *charArray)
    {
        int index = 0;
        while ((char)charArray[index] != '\0')
        {
            index++;
        }
        return (index + 1);
    }

    int get_char_arr_len(char *charArray)
    {
        int index = 0;
        while ((char)charArray[index] != '\0')
        {
            index++;
        }
        return (index + 1);
    }

    // Converts character Array to string
    std::string arr_to_string(const char *charArray)
    {
        std::string s = "";
        for (int i = 0; i < get_char_arr_len(charArray); i++)
        {
            s = s + charArray[i];
        }
        return s;
    }

    std::string arr_to_string(char *charArray)
    {
        std::string s = "";
        for (int i = 0; i < get_char_arr_len(charArray); i++)
        {
            s = s + charArray[i];
        }
        return s;
    }

    // Converts chararcter array to float ("70" to 70.0)
    float arr_to_float(const char *charArray)
    {
        std::string s = arr_to_string(charArray);
        std::stringstream ss(s);
        float value{0};
        ss >> value;
        return value;
    }

    // Gets Single Line from a starting Index till '\n'
    char *get_line(const char *charList, int startIndex)
    {
        char *newLine = new char[get_char_arr_len(charList)];
        int index = startIndex;
        while ((char)charList[index] != '\n')
        {
            newLine[index - startIndex] = charList[index];
            index++;
        }
        newLine[index - startIndex] = '\0';
        return newLine;
    }

    char *get_line(char *charList, int startIndex)
    {
        char *newLine = new char[get_char_arr_len(charList)];
        int index = startIndex;
        int count = 0;
        while ((char)charList[index] != '\n' && (char)charList[index] != '\0')
        {
            newLine[index - startIndex] = charList[index];
            index++;
        }
        newLine[index - startIndex] = '\0';
        return newLine;
    }

    // Gets ending index of a line from a starting Index
    int get_index_end(const char *charList, int startIndex)
    {
        int index = startIndex;
        while ((char)charList[index] != '\n')
        {
            index++;
        }
        return index;
    }

    int get_index_end(char *charList, int startIndex)
    {
        int index = startIndex;
        while ((char)charList[index] != '\n')
        {
            index++;
        }
        return index;
    }

    // Gets starting index of next line from a starting Index
    int get_index_start(const char *charList, int startIndex)
    {
        return (get_index_end(charList, startIndex) + 1);
    }

    int get_index_start(char *charList, int startIndex)
    {
        return (get_index_end(charList, startIndex) + 1);
    }

    // Get starting Index of a char array in another char array
    int get_string_start(char *mainCharArray, const char *targetCharArray)
    {
        int mainLength = get_char_arr_len(mainCharArray);
        int targetLength = get_char_arr_len(targetCharArray);
        if (mainLength >= targetLength)
        {
            int index = 0;
            bool isChecking = false;
            bool hasIndex = false;
            int stringIndex = -1;
            int targetIndex = 0;
            while ((char)mainCharArray[index] != '\0')
            {
                if (isChecking)
                {
                    if (targetIndex < targetLength - 1)
                    {
                        if (mainCharArray[index] != targetCharArray[targetIndex])
                        {
                            isChecking = false;
                        }
                    }
                    else
                    {
                        hasIndex = true;
                        stringIndex = index - (targetLength - 1);
                        break;
                    }
                }
                if (!isChecking)
                {
                    if (mainCharArray[index] == targetCharArray[0])
                    {
                        isChecking = true;
                        targetIndex = 0;
                    }
                }
                index++;
                if (isChecking)
                {
                    targetIndex++;
                }
            }
            return stringIndex;
        }
        log("INVALID TARGET STRING");
        return -1;
    }

    // Get ending Index of a char array in another char array
    int get_string_end(char *mainCharArray, const char *targetCharArray)
    {
        int mainLength = get_char_arr_len(mainCharArray);
        int targetLength = get_char_arr_len(targetCharArray);
        if (mainLength >= targetLength)
        {
            int index = get_string_start(mainCharArray, targetCharArray);
            index += targetLength - 1;
            return index;
        }
        log("INVALID TARGET STRING");
        return -1;
    }

} // namespace rpgText
