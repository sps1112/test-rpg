#ifndef CHARACTER_H
#define CHARACTER_H

// Custom Headers
#include "Standard.h"
#include "Printer.h"
#include "MathEngine.h"
#include "FileManager.h"

// Standard Headers
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

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
        void set_private();
        void change_health(float amount);
        void change_mana(float amount);
        bool get_status();
        void print_stats();
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
        int level;
        float currentExp;
        float expToNextlevel;
        Player();
        Player(std::string NAME, bool viaFile, float HEALTH = 100, float MANA = 30,
               float ATTACK = 15, float DEFENCE = 10,
               float SPCATTACK = 10, float SPCDEFENCE = 10,
               float SPEED = 20, float CURRENTEXP = 0, float NEXTEXP = 50);
        Player(const char *playerStatsPath);
        ~Player();
        void write_to_file();
    };
} // namespace rpgText

#endif // !CHARACTER_H
