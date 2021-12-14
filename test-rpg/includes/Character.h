#ifndef CHARACTER_H
#define CHARACTER_H

// Custom Headers
#include "Standard.h"
#include "Printer.h"
#include "MathEngine.h"
#include "FileManager.h"
#include "FileSystem.h"

// Standard Headers
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

namespace rpgText
{
    // Base Stats for all characters
    struct BaseStats
    {
        float strength;     // Determines Attack and HP
        float stamina;      // Determines Defence and HP
        float intelligence; // Determines MP, MAttack and MDefence
        float agility;      // Determines Speed and Evasion
        float luck;         // Determines Evasion, Crit and Accuracy

        // Default Base Stats Constructor
        BaseStats(float strength_ = 5, float stamina_ = 5, float intelligence_ = 5, float agility_ = 5, float luck_ = 5)
            : strength(strength_), stamina(stamina_), intelligence(intelligence_), agility(agility_), luck(luck_) {}
    };

    // Derived Stats for all Characters
    struct Stats
    {
    private:
        // Updates the Stats values based on current level
        void update_stats()
        {
            health = int((level + 1) * (baseStats.strength + baseStats.stamina) * 0.5f);
            mana = int((level + 1) * baseStats.intelligence * 0.2f);
            attack = int((level + 1) * baseStats.strength * 0.1f);
            defence = int((level + 1) * baseStats.stamina * 0.1f);
            mAttack = int((level + 1) * baseStats.intelligence * 0.1f);
            mDefence = int((level + 1) * baseStats.intelligence * 0.1f);
            speed = int((level + 1) * baseStats.agility * 0.1f);
            accuracy = int((level + 1) * baseStats.luck * 0.1f);
            evasion = int((level + 1) * (baseStats.luck + baseStats.agility) * 0.025f);
            crit = int((level + 1) * baseStats.luck * 0.05f);
        }

    public:
        BaseStats baseStats; // Base stats to derive values from
        int level;           // Current Level
        float health;        // Max HP
        float mana;          // Max MP
        float attack;        // Damage done to enemies
        float defence;       // Defence from enemy damage
        float mAttack;       // Damage done via mana attack
        float mDefence;      // Defence towards mana attack
        float speed;         // Speed to determine turn
        float accuracy;      // Chance to hit enemy
        float evasion;       // Chance to dogde enemy's attack
        float crit;          // Chance to land a critical hit

        // Stats Constructor
        Stats(BaseStats baseStats_ = BaseStats(), int level_ = 1)
        {
            baseStats = baseStats_;
            level = level_;
            update_stats();
        }

        // Levels up and updates stats
        void level_up()
        {
            level++;
            level = clamp(level, 1, 99);
            update_stats();
        }
    };

    // The Generic Character Class
    class Character
    {
    private:
    public:
        std::string name; // Character Name
        Stats stats;      // Default Stats
        Stats cStats;     // Current Stats

        // Default Constructor
        Character(std::string name_ = "Dummy", int level = 3, float str = 7, float sta = 7,
                  float inte = 7, float agi = 7, float luck = 7);

        // Changes current health
        void change_health(float amount);

        // Changes current mana
        void change_mana(float amount);

        // Checks if health is zero
        bool get_status();

        // Prints the current stats
        void print_stats();
    };

    // The Enemy Class : Child of Character Class
    class Enemy : public Character
    {
    private:
    public:
        float expDrop;   // Exp gained by player by beating the enemy
        float moneyDrop; // Money dropped by the enemy

        // Enemy Constructor
        Enemy(std::string name_, bool viaData, int level = 2, float str = 5, float sta = 5,
              float inte = 5, float agi = 5, float luck = 5, float exp = 15, float money = 20);

        // Enemy Path Constructor
        Enemy(const char *path);
    };

    // The Player Class : Child of Character Class
    class Player : public Character
    {
    private:
        // Writes player data to file
        void write_to_file();

    public:
        float currentExp;     // Current Exp Value
        float expToNextlevel; // Total Exp needed for next level

        // Player Value Constructor
        Player(std::string name_, bool viaData, int level = 2, float str = 5, float sta = 5,
               float inte = 5, float agi = 5, float luck = 5, float exp = 0, float next = 50);
        // Player Path Constructor
        Player(const char *path);

        // Player Destructor
        ~Player();
    };
} // namespace rpgText

#endif // !CHARACTER_H
