#ifndef PRINTER_H
#define PRINTER_H

#include <iostream>
#include "Standard.h"
#include "ASCArt.h"

// Namespace for Printer Header
namespace rpgText
{
    // Prints consecutive n '-'
    void PrintDash(int n)
    {
        Log(rpgText::GetDashes(n));
    }

    // Prints an alphabet and its certain line
    void PrintLetter(const char c, int line = 0)
    {
        std::string part;
        // Log(line);
        switch (c)
        {
        case 'A':
        case 'a':
            part = rpgText::A[line];
            break;
        case 'B':
        case 'b':
            part = rpgText::B[line];
            break;
        case 'C':
        case 'c':
            part = rpgText::C[line];
            break;
        case 'D':
        case 'd':
            part = rpgText::D[line];
            break;
        case 'E':
        case 'e':
            part = rpgText::E[line];
            break;
        case 'F':
        case 'f':
            part = rpgText::F[line];
            break;
        case 'G':
        case 'g':
            part = rpgText::G[line];
            break;
        case 'H':
        case 'h':
            part = rpgText::H[line];
            break;
        case 'I':
        case 'i':
            part = rpgText::I[line];
            break;
        case 'J':
        case 'j':
            part = rpgText::J[line];
            break;
        case 'K':
        case 'k':
            part = rpgText::K[line];
            break;
        case 'L':
        case 'l':
            part = rpgText::L[line];
            break;
        case 'M':
        case 'm':
            part = rpgText::M[line];
            break;
        case 'N':
        case 'n':
            part = rpgText::N[line];
            break;
        case 'O':
        case 'o':
            part = rpgText::O[line];
            break;
        case 'P':
        case 'p':
            part = rpgText::P[line];
            break;
        case 'Q':
        case 'q':
            part = rpgText::Q[line];
            break;
        case 'R':
        case 'r':
            part = rpgText::R[line];
            break;
        case 'S':
        case 's':
            part = rpgText::S[line];
            break;
        case 'T':
        case 't':
            part = rpgText::T[line];
            break;
        case 'U':
        case 'u':
            part = rpgText::U[line];
            break;
        case 'V':
        case 'v':
            part = rpgText::V[line];
            break;
        case 'W':
        case 'w':
            part = rpgText::W[line];
            break;
        case 'X':
        case 'x':
            part = rpgText::X[line];
            break;
        case 'Y':
        case 'y':
            part = rpgText::Y[line];
            break;
        case 'Z':
        case 'z':
            part = rpgText::Z[line];
            break;
        default:
            part = std::string(1, c);
        }
        std::cout << part;
    }

    // Prints a given word
    void PrintWord(const char *word)
    {
        int i = 0;
        // int count = 0;
        char c = word[i];
        /*
    while (c != '\0')
    {
        i++;
        count++;
        c = word[i];
    }
    */
        for (int j = 0; j < rpgText::wordLength; j++)
        {
            i = 0;
            c = word[0];
            while (c != '\0')
            {
                if (i != 0)
                {
                    std::cout << "   ";
                }
                PrintLetter(c, j);
                i++;
                c = word[i];
            }
            Log("");
        }
    }

    // Prints the Game title
    void PrintTitle()
    {
        PrintDash(15);
        PrintWord("RPG");
        PrintDash(15);
        Log("");
    }

    // Prints the Game Ending
    void PrintEnd()
    {
        Log("");
        PrintDash(15);
        PrintWord("Game Over");
        PrintDash(15);
        Log("");
        std::cout << "Enter Any Number to Quit: ";
    }

    // Prints the main menu
    void PrintMenu(bool hasSaveGame)
    {
        Log("");
        PrintDash(15);
        Log("MAIN MENU");
        PrintDash(15);
        Log("");
        if (hasSaveGame)
        {
            Log("1. Continue");
            Log("2. New Game");
            Log("3. Options");
            Log("4. Quit");
        }
        else
        {
            Log("1. New Game");
            Log("2. Options");
            Log("3. Quit");
        }
        Log("");
        std::cout << "Enter any of these numbers: ";
    }
} // namespace rpgText

#endif