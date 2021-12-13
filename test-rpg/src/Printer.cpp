#include "Printer.h"
#include "config.h"

namespace rpgText
{
    // Prints consecutive n '-'
    void PrintDash(int n)
    {
        log(GetDashes(n));
    }

    // Prints an alphabet and its certain line
    void PrintLetter(const char c, int line)
    {
        std::string part;
        // log(line);
        switch (c)
        {
        case 'A':
        case 'a':
            part = A[line];
            break;
        case 'B':
        case 'b':
            part = B[line];
            break;
        case 'C':
        case 'c':
            part = C[line];
            break;
        case 'D':
        case 'd':
            part = D[line];
            break;
        case 'E':
        case 'e':
            part = E[line];
            break;
        case 'F':
        case 'f':
            part = F[line];
            break;
        case 'G':
        case 'g':
            part = G[line];
            break;
        case 'H':
        case 'h':
            part = H[line];
            break;
        case 'I':
        case 'i':
            part = I[line];
            break;
        case 'J':
        case 'j':
            part = J[line];
            break;
        case 'K':
        case 'k':
            part = K[line];
            break;
        case 'L':
        case 'l':
            part = L[line];
            break;
        case 'M':
        case 'm':
            part = M[line];
            break;
        case 'N':
        case 'n':
            part = N[line];
            break;
        case 'O':
        case 'o':
            part = O[line];
            break;
        case 'P':
        case 'p':
            part = P[line];
            break;
        case 'Q':
        case 'q':
            part = Q[line];
            break;
        case 'R':
        case 'r':
            part = R[line];
            break;
        case 'S':
        case 's':
            part = S[line];
            break;
        case 'T':
        case 't':
            part = T[line];
            break;
        case 'U':
        case 'u':
            part = U[line];
            break;
        case 'V':
        case 'v':
            part = V[line];
            break;
        case 'W':
        case 'w':
            part = W[line];
            break;
        case 'X':
        case 'x':
            part = X[line];
            break;
        case 'Y':
        case 'y':
            part = Y[line];
            break;
        case 'Z':
        case 'z':
            part = Z[line];
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
        for (int j = 0; j < wordLength; j++)
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
            log("");
        }
    }

    // Prints the Game title
    void PrintTitle()
    {
        PrintDash(15);
        PrintWord(GAME_NAME);
        PrintDash(15);
        log("");
    }

    // Prints the Game Ending
    void PrintEnd()
    {
        log("");
        PrintDash(15);
        PrintWord("Game Over");
        PrintDash(15);
        log("");
        std::cout << "Enter Any Number to Quit: ";
    }

    // Prints the main menu
    void PrintMenu(bool hasSaveGame)
    {
        log("");
        PrintDash(15);
        log("MAIN MENU");
        PrintDash(15);
        log("");
        if (hasSaveGame)
        {
            log("1. Continue");
            log("2. New Game");
            log("3. Options");
            log("4. Quit");
        }
        else
        {
            log("1. New Game");
            log("2. Options");
            log("3. Quit");
        }
        log("");
        std::cout << "Enter any of these numbers: ";
    }
} // namespace rpgText
