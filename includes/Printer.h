#ifndef PRINTER_H
#define PRINTER_H

#include <iostream>
#include "Standard.h"
#include "ASCArt.h"

// Namespace for Printer Header
namespace rpgPrinter
{
    // Prints consecutive n '-'
    void PrintDash(int n)
    {
        Log(ascart::GetDashes(n));
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
            part = ascart::A[line];
            break;
        case 'B':
        case 'b':
            part = ascart::B[line];
            break;
        case 'C':
        case 'c':
            part = ascart::C[line];
            break;
        case 'D':
        case 'd':
            part = ascart::D[line];
            break;
        case 'E':
        case 'e':
            part = ascart::E[line];
            break;
        case 'F':
        case 'f':
            part = ascart::F[line];
            break;
        case 'G':
        case 'g':
            part = ascart::G[line];
            break;
        case 'H':
        case 'h':
            part = ascart::H[line];
            break;
        case 'I':
        case 'i':
            part = ascart::I[line];
            break;
        case 'J':
        case 'j':
            part = ascart::J[line];
            break;
        case 'K':
        case 'k':
            part = ascart::K[line];
            break;
        case 'L':
        case 'l':
            part = ascart::L[line];
            break;
        case 'M':
        case 'm':
            part = ascart::M[line];
            break;
        case 'N':
        case 'n':
            part = ascart::N[line];
            break;
        case 'O':
        case 'o':
            part = ascart::O[line];
            break;
        case 'P':
        case 'p':
            part = ascart::P[line];
            break;
        case 'Q':
        case 'q':
            part = ascart::Q[line];
            break;
        case 'R':
        case 'r':
            part = ascart::R[line];
            break;
        case 'S':
        case 's':
            part = ascart::S[line];
            break;
        case 'T':
        case 't':
            part = ascart::T[line];
            break;
        case 'U':
        case 'u':
            part = ascart::U[line];
            break;
        case 'V':
        case 'v':
            part = ascart::V[line];
            break;
        case 'W':
        case 'w':
            part = ascart::W[line];
            break;
        case 'X':
        case 'x':
            part = ascart::X[line];
            break;
        case 'Y':
        case 'y':
            part = ascart::Y[line];
            break;
        case 'Z':
        case 'z':
            part = ascart::Z[line];
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
        for (int j = 0; j < ascart::wordLength; j++)
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
} // namespace rpgPrinter

#endif