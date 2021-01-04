#ifndef CHARACTER_H
#define CHARACTER_H

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

#include "Standard.h"
#include "Printer.h"
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
        Character();
        Character(std::string NAME, float HEALTH = 100, float MANA = 30,
                  float ATTACK = 10, float DEFENCE = 10,
                  float SPCATTACK = 10, float SPCDEFENCE = 10,
                  float SPEED = 20);
        void SetPrivate();
        void ChangeHealth(float amount);
        void ChangeMana(float amount);
        bool GetStatus();
        void PrintStats();
    };

    // The Enemy Class : Child of Character Class
    class Enemy : public Character
    {
    private:
    public:
        float expDrop;
        float moneyDrop;
        Enemy();
        Enemy(std::string NAME, float HEALTH = 50, float MANA = 30,
              float ATTACK = 10, float DEFENCE = 10,
              float SPCATTACK = 10, float SPCDEFENCE = 10,
              float SPEED = 20, float EXPDROP = 15, float MONEYDROP = 20);
    };

    // The Player Class : Child of Character Class
    class Player : public Character
    {
    private:
    public:
        float currentExp;
        float expToNextlevel;
        Player();
        Player(std::string NAME, bool viaFile, float HEALTH = 100, float MANA = 30,
               float ATTACK = 15, float DEFENCE = 10,
               float SPCATTACK = 10, float SPCDEFENCE = 10,
               float SPEED = 20, float CURRENTEXP = 0, float NEXTEXP = 50);
        Player(const char *playerStatsPath);
        ~Player();
        void WriteToFile();
    };
} // namespace rpgText

#endif