#include "Printer.h"
#include "config.h"

namespace rpgText
{
    // Prints consecutive n '-'
    void print_dash(int n)
    {
        log(get_dashes(n));
    }

    // Prints an alphabet and its certain line
    void print_letter(const char c, int line)
    {
        std::string part;
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
        print(part);
    }

    // Prints a given word
    void print_word(const char *word)
    {
        int i = 0;
        char c = word[i];
        for (int j = 0; j < wordLength; j++)
        {
            i = 0;
            c = word[0];
            while (c != '\0')
            {
                if (i != 0)
                {
                    print("   ");
                }
                print_letter(c, j);
                i++;
                c = word[i];
            }
            log("");
        }
    }

    // Prints the Game title
    void print_title()
    {
        print_dash(15);
        print_word(GAME_NAME);
        print_dash(15);
        log("");
    }

    // Prints the Game Ending
    void print_end()
    {
        log("");
        print_dash(15);
        print_word("Game Over");
        print_dash(15);
        log("");
        print("Enter Any Number to Quit: ");
    }

    // Prints the main menu
    void print_menu(bool hasSaveGame)
    {
        log("");
        print_dash(15);
        log("MAIN MENU");
        print_dash(15);
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
        print("Enter any of these numbers: ");
    }

} // namespace rpgText
