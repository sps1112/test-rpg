#include "Standard.h"

namespace rpgText
{
    // Prints message on a single line without moving over
    void Print(const char *message)
    {
        std::cout << message;
    }

    void Print(std::string message)
    {
        Print(message.c_str());
    }

    void Print(const float num, int isChar)
    {
        if (isChar)
        {
            char c = int(num);
            Print(std::string(1, c));
        }
        else
        {
            Print(std::to_string(num));
        }
    }

    // Prints message on a single line and then moves to next line
    void Log(const char *message)
    {
        Print(message);
        Print("\n");
    }

    void Log(std::string message)
    {
        Log(message.c_str());
    }

    void Log(const float num, int isChar)
    {
        if (isChar)
        {
            char c = int(num);
            Log(std::string(1, c));
        }
        else
        {
            Log(std::to_string(num));
        }
    }

    // Gets Input from Keyboard
    int GetInt()
    {
        int n{};
        std::cin >> n;
        return n;
    }

    int GetIntWithPrompt(const char *prompt)
    {
        Print(prompt);
        int n{};
        std::cin >> n;
        return n;
    }

    // Clears the input buffer to take a single value each time
    void ClearInput()
    {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
} // namespace rpgText
