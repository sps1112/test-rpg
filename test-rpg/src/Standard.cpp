#include "Standard.h"

namespace rpgText
{
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
            print(std::to_string(int(num)));
        }
    }

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
            log(std::to_string(int(num)));
        }
    }

    int get_int()
    {
        int n{};
        std::cin >> n;
        return n;
    }

    int get_int_prompt(const char *prompt)
    {
        print(prompt);
        return get_int();
    }

    void clear_input()
    {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }

    void clear_screen()
    {
        if (CHECK_WINDOWS)
        {
            system("cls");
        }
        else
        {
            system("clear");
        }
    }

} // namespace rpgText
