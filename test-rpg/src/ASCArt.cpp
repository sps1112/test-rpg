#include "ASCArt.h"

namespace rpgText
{
    // Returns a Character string such as "------" with n dashes
    char *GetDashes(int n)
    {
        char *line = new char[n + 1];
        for (int i = 0; i < n; i++)
        {
            *(line + i) = '-';
        }
        *(line + n) = '\0';
        return line;
    }

    //  String Array for Letters created with ASCII ART

    int wordLength = 5;

    std::string A[] = {"    *    ",
                       "   * *   ",
                       "  * * *  ",
                       " *     * ",
                       "*       *"};

    std::string B[] = {"***** ",
                       "*    *",
                       "***** ",
                       "*    *",
                       "***** "};

    std::string C[] = {" ****",
                       "*    ",
                       "*    ",
                       "*    ",
                       " ****"};

    std::string D[] = {"****  ",
                       "*   * ",
                       "*    *",
                       "*   * ",
                       "****  "};

    std::string E[] = {"******",
                       "*     ",
                       "******",
                       "*     ",
                       "******"};

    std::string F[] = {"******",
                       "*     ",
                       "******",
                       "*     ",
                       "*     "};

    std::string G[] = {" **** ",
                       "*     ",
                       "*  ***",
                       "*    *",
                       " **** "};

    std::string H[] = {"*    *",
                       "*    *",
                       "******",
                       "*    *",
                       "*    *"};

    std::string I[] = {"*****",
                       "  *  ",
                       "  *  ",
                       "  *  ",
                       "*****"};

    std::string J[] = {"*****",
                       "  *  ",
                       "  *  ",
                       "* *  ",
                       " **  "};

    std::string K[] = {"*  *",
                       "* * ",
                       "**  ",
                       "* * ",
                       "*  *"};

    std::string L[] = {"*    ",
                       "*    ",
                       "*    ",
                       "*    ",
                       "*****"};

    std::string M[] = {"**   **",
                       "* * * *",
                       "*  *  *",
                       "*     *",
                       "*     *"};

    std::string N[] = {"**   *",
                       "* *  *",
                       "*  * *",
                       "*   **",
                       "*    *"};

    std::string O[] = {" **** ",
                       "*    *",
                       "*    *",
                       "*    *",
                       " **** "};

    std::string P[] = {"**** ",
                       "*   *",
                       "**** ",
                       "*    ",
                       "*    "};
    std::string Q[] = {" ***** ",
                       "*     *",
                       "*  *  *",
                       " ***** ",
                       "   *** "};
    std::string R[] = {"**** ",
                       "*   *",
                       "**** ",
                       "**   ",
                       "* *  "};
    std::string S[] = {" ****",
                       "*    ",
                       " *** ",
                       "    *",
                       "**** "};
    std::string T[] = {"*****",
                       "  *  ",
                       "  *  ",
                       "  *  ",
                       "  *  "};
    std::string U[] = {"*    *",
                       "*    *",
                       "*    *",
                       "*    *",
                       " **** "};
    std::string V[] = {"*       *",
                       " *     * ",
                       "  *   *  ",
                       "   * *   ",
                       "    *    "};
    std::string W[] = {"*           *",
                       " *         * ",
                       "  *   *   *  ",
                       "   * * * *   ",
                       "    *   *    "};
    std::string X[] = {"*   *",
                       " * * ",
                       "  *  ",
                       " * * ",
                       "*   *"};
    std::string Y[] = {"*   *",
                       " * * ",
                       "  *  ",
                       "  *  ",
                       "  *  "};
    std::string Z[] = {"*****",
                       "   * ",
                       "  *  ",
                       " *   ",
                       "*****"};
} // namespace rpgText
