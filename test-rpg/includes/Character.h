#ifndef CHARACTER_H
#define CHARACTER_H

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

#include "MathEngine.h"
#include "FileManager.h"

namespace rpgText
{
    // The Generic Character Class
    class Character
    {
    private:
        float maxHealth;
        float maxMana;

    public:
        std::string name;
        int level;
        float health;
        float mana;
        float attack;
        float defence;
        float spcAttack;
        float spcDefence;
        float speed;
        Character()
        {
            //default
        }

        Character(std::string NAME, float HEALTH = 100, float MANA = 30,
                  float ATTACK = 10, float DEFENCE = 10,
                  float SPCATTACK = 10, float SPCDEFENCE = 10,
                  float SPEED = 20)
        {
            name = NAME;
            health = HEALTH;
            mana = MANA;
            attack = ATTACK;
            defence = DEFENCE;
            spcAttack = SPCATTACK;
            spcDefence = SPCDEFENCE;
            speed = SPEED;
            maxHealth = health;
            maxMana = mana;
        }

        void SetPrivate()
        {
            maxHealth = health;
            maxMana = mana;
        }

        void ChangeHealth(float amount)
        {
            health += amount;
            health = Clamp(0, maxHealth, health);
        }

        void ChangeMana(float amount)
        {
            mana += amount;
            mana = Clamp(0, maxMana, mana);
        }

        bool GetStatus()
        {
            if (health > 0)
            {
                return 1;
            }
            return 0;
        }

        void PrintStats()
        {
            PrintDash(10);
            Log("[STATS]");
            Print("Name:- ");
            Log(name);
            Print("Health:- ");
            Log(health);
            Print("Mana:- ");
            Log(mana);
            Print("Attack:- ");
            Log(attack);
            Print("Defence:- ");
            Log(defence);
            Print("Special Attack:- ");
            Log(spcAttack);
            Print("Special Defence:- ");
            Log(spcDefence);
            Print("Speed:- ");
            Log(speed);
            PrintDash(10);
        }
    };

    // The Enemy Class : Child of Character Class
    class Enemy : public Character
    {
    private:
    public:
        float expDrop;
        float moneyDrop;
        Enemy()
        {
            //default
        }
        Enemy(std::string NAME, float HEALTH = 50, float MANA = 30,
              float ATTACK = 10, float DEFENCE = 10,
              float SPCATTACK = 10, float SPCDEFENCE = 10,
              float SPEED = 20, float EXPDROP = 15, float MONEYDROP = 20)
        {
            name = NAME;
            health = HEALTH;
            mana = MANA;
            attack = ATTACK;
            defence = DEFENCE;
            spcAttack = SPCATTACK;
            spcDefence = SPCDEFENCE;
            speed = SPEED;
            expDrop = EXPDROP;
            moneyDrop = MONEYDROP;
            SetPrivate();
        }
    };

    // The Player Class : Child of Character Class
    class Player : public Character
    {
    private:
    public:
        float currentExp;
        float expToNextlevel;
        Player()
        {
            //default
        }

        Player(std::string NAME, bool viaFile, float HEALTH = 100, float MANA = 30,
               float ATTACK = 15, float DEFENCE = 10,
               float SPCATTACK = 10, float SPCDEFENCE = 10,
               float SPEED = 20, float CURRENTEXP = 0, float NEXTEXP = 50)
        {
            name = NAME;
            health = HEALTH;
            mana = MANA;
            attack = ATTACK;
            defence = DEFENCE;
            spcAttack = SPCATTACK;
            spcDefence = SPCDEFENCE;
            speed = SPEED;
            currentExp = CURRENTEXP;
            expToNextlevel = NEXTEXP;
            SetPrivate();
            WriteToFile();
        }

        Player(const char *playerStatsPath)
        {
            std::string stats;
            std::ifstream file;
            file.open(playerStatsPath);
            std::stringstream statsStream;
            statsStream << file.rdbuf();
            file.close();
            stats = statsStream.str();
            const char *statsCode = stats.c_str();

            // Set Name
            int lineStartIndex = GetLineStartIndex(statsCode, 0);
            char *lineI = GetLine(statsCode, lineStartIndex);
            char *VALUE = GetLine(lineI, GetEndIndexString(lineI, ":- "));
            name = ConvertToString(VALUE);

            // Set Health
            lineStartIndex = GetLineStartIndex(statsCode, lineStartIndex);
            lineI = GetLine(statsCode, lineStartIndex);
            VALUE = GetLine(lineI, GetEndIndexString(lineI, ":- "));
            health = ConvertToFloat(VALUE);

            // Set Mana
            lineStartIndex = GetLineStartIndex(statsCode, lineStartIndex);
            lineI = GetLine(statsCode, lineStartIndex);
            VALUE = GetLine(lineI, GetEndIndexString(lineI, ":- "));
            mana = ConvertToFloat(VALUE);

            // Set Attack
            lineStartIndex = GetLineStartIndex(statsCode, lineStartIndex);
            lineI = GetLine(statsCode, lineStartIndex);
            VALUE = GetLine(lineI, GetEndIndexString(lineI, ":- "));
            attack = ConvertToFloat(VALUE);

            // Set Defence
            lineStartIndex = GetLineStartIndex(statsCode, lineStartIndex);
            lineI = GetLine(statsCode, lineStartIndex);
            VALUE = GetLine(lineI, GetEndIndexString(lineI, ":- "));
            defence = ConvertToFloat(VALUE);

            // Set Special Attack
            lineStartIndex = GetLineStartIndex(statsCode, lineStartIndex);
            lineI = GetLine(statsCode, lineStartIndex);
            VALUE = GetLine(lineI, GetEndIndexString(lineI, ":- "));
            spcAttack = ConvertToFloat(VALUE);

            // Set Special Defence
            lineStartIndex = GetLineStartIndex(statsCode, lineStartIndex);
            lineI = GetLine(statsCode, lineStartIndex);
            VALUE = GetLine(lineI, GetEndIndexString(lineI, ":- "));
            spcDefence = ConvertToFloat(VALUE);

            // Set Speed
            lineStartIndex = GetLineStartIndex(statsCode, lineStartIndex);
            lineI = GetLine(statsCode, lineStartIndex);
            VALUE = GetLine(lineI, GetEndIndexString(lineI, ":- "));
            speed = ConvertToFloat(VALUE);

            // Set Current EXP
            lineStartIndex = GetLineStartIndex(statsCode, lineStartIndex);
            lineI = GetLine(statsCode, lineStartIndex);
            VALUE = GetLine(lineI, GetEndIndexString(lineI, ":- "));
            currentExp = ConvertToFloat(VALUE);

            // Set EXP to Next Level
            lineStartIndex = GetLineStartIndex(statsCode, lineStartIndex);
            lineI = GetLine(statsCode, lineStartIndex);
            VALUE = GetLine(lineI, GetEndIndexString(lineI, ":- "));
            expToNextlevel = ConvertToFloat(VALUE);

            SetPrivate();
            WriteToFile();
        }

        ~Player()
        {
            // WriteToFile();
        }

        void WriteToFile()
        {
            std::ofstream file;
            file.open("../test-rpg/data/Player.saved.char", std::ios::trunc);
            file << "[Stats]" << std::endl;
            file << "Name:- " << name << std::endl;
            file << "Health:- " << health << std::endl;
            file << "Mana:- " << mana << std::endl;
            file << "Attack:- " << attack << std::endl;
            file << "Defence:- " << defence << std::endl;
            file << "SpecialAttack:- " << spcAttack << std::endl;
            file << "SpecialDefence:- " << spcDefence << std::endl;
            file << "Speed:- " << speed << std::endl;
            file << "CurrentExp:- " << currentExp << std::endl;
            file << "Exp to Next Level:- " << expToNextlevel << std::endl;
            file.close();
        }
    };
} // namespace rpgText

#endif