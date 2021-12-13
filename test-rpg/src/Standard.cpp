#include "Standard.h"

namespace rpgText
{
    // Prints message on a single line without moving over
    void print(const char *message)
    {
        std::cout << message;
    }

    void print(std::string message)
    {
        print(message.c_str());
    }

    void print(const float num, int isChar)
    {
        if (isChar)
        {
            char c = int(num);
            print(std::string(1, c));
        }
        else
        {
            print(std::to_string(num));
        }
    }

    // Prints message on a single line and then moves to next line
    void log(const char *message)
    {
        print(message);
        print("\n");
    }

    void log(std::string message)
    {
        log(message.c_str());
    }

    void log(const float num, int isChar)
    {
        if (isChar)
        {
            char c = int(num);
            log(std::string(1, c));
        }
        else
        {
            log(std::to_string(num));
        }
    }

    // Gets Input from Keyboard
    int get_int()
    {
        int n{};
        std::cin >> n;
        return n;
    }

    int get_int_prompt(const char *prompt)
    {
        print(prompt);
        int n{};
        std::cin >> n;
        return n;
    }

    // Clears the input buffer to take a single value each time
    void clear_input()
    {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
} // namespace rpgText
