#include "Character.h"

namespace rpgText
{
    // The Generic Character Class
    Character::Character()
    {
        // default
    }

    Character::Character(std::string NAME, float HEALTH, float MANA,
                         float ATTACK, float DEFENCE,
                         float SPCATTACK, float SPCDEFENCE,
                         float SPEED)
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

    void Character::SetPrivate()
    {
        maxHealth = health;
        maxMana = mana;
    }

    void Character::ChangeHealth(float amount)
    {
        health += amount;
        health = clamp(health, 0, maxHealth);
    }

    void Character::ChangeMana(float amount)
    {
        mana += amount;
        mana = clamp(mana, 0, maxMana);
    }

    bool Character::GetStatus()
    {
        if (health > 0)
        {
            return 1;
        }
        return 0;
    }

    void Character::PrintStats()
    {
        print_dash(10);
        log("[STATS]");
        print("Name:- ");
        log(name);
        print("Health:- ");
        log(health);
        print("Mana:- ");
        log(mana);
        print("Attack:- ");
        log(attack);
        print("Defence:- ");
        log(defence);
        print("Special Attack:- ");
        log(spcAttack);
        print("Special Defence:- ");
        log(spcDefence);
        print("Speed:- ");
        log(speed);
        print_dash(10);
    }

    // The Enemy Class : Child of Character Class
    Enemy::Enemy()
    {
        // default
    }
    Enemy::Enemy(std::string NAME, float HEALTH, float MANA,
                 float ATTACK, float DEFENCE,
                 float SPCATTACK, float SPCDEFENCE,
                 float SPEED, float EXPDROP, float MONEYDROP)
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

    // The Player Class : Child of Character Class
    Player::Player()
    {
        // default
    }

    Player::Player(std::string NAME, bool viaFile, float HEALTH, float MANA,
                   float ATTACK, float DEFENCE,
                   float SPCATTACK, float SPCDEFENCE,
                   float SPEED, float CURRENTEXP, float NEXTEXP)
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

    Player::Player(const char *playerStatsPath)
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
        int lineStartIndex = get_index_start(statsCode, 0);
        char *lineI = get_line(statsCode, lineStartIndex);
        char *VALUE = get_line(lineI, get_string_end(lineI, ":- "));
        name = arr_to_string(VALUE);

        // Set Health
        lineStartIndex = get_index_start(statsCode, lineStartIndex);
        lineI = get_line(statsCode, lineStartIndex);
        VALUE = get_line(lineI, get_string_end(lineI, ":- "));
        health = arr_to_float(VALUE);

        // Set Mana
        lineStartIndex = get_index_start(statsCode, lineStartIndex);
        lineI = get_line(statsCode, lineStartIndex);
        VALUE = get_line(lineI, get_string_end(lineI, ":- "));
        mana = arr_to_float(VALUE);

        // Set Attack
        lineStartIndex = get_index_start(statsCode, lineStartIndex);
        lineI = get_line(statsCode, lineStartIndex);
        VALUE = get_line(lineI, get_string_end(lineI, ":- "));
        attack = arr_to_float(VALUE);

        // Set Defence
        lineStartIndex = get_index_start(statsCode, lineStartIndex);
        lineI = get_line(statsCode, lineStartIndex);
        VALUE = get_line(lineI, get_string_end(lineI, ":- "));
        defence = arr_to_float(VALUE);

        // Set Special Attack
        lineStartIndex = get_index_start(statsCode, lineStartIndex);
        lineI = get_line(statsCode, lineStartIndex);
        VALUE = get_line(lineI, get_string_end(lineI, ":- "));
        spcAttack = arr_to_float(VALUE);

        // Set Special Defence
        lineStartIndex = get_index_start(statsCode, lineStartIndex);
        lineI = get_line(statsCode, lineStartIndex);
        VALUE = get_line(lineI, get_string_end(lineI, ":- "));
        spcDefence = arr_to_float(VALUE);

        // Set Speed
        lineStartIndex = get_index_start(statsCode, lineStartIndex);
        lineI = get_line(statsCode, lineStartIndex);
        VALUE = get_line(lineI, get_string_end(lineI, ":- "));
        speed = arr_to_float(VALUE);

        // Set Current EXP
        lineStartIndex = get_index_start(statsCode, lineStartIndex);
        lineI = get_line(statsCode, lineStartIndex);
        VALUE = get_line(lineI, get_string_end(lineI, ":- "));
        currentExp = arr_to_float(VALUE);

        // Set EXP to Next Level
        lineStartIndex = get_index_start(statsCode, lineStartIndex);
        lineI = get_line(statsCode, lineStartIndex);
        VALUE = get_line(lineI, get_string_end(lineI, ":- "));
        expToNextlevel = arr_to_float(VALUE);

        SetPrivate();
        WriteToFile();
    }

    Player::~Player()
    {
        // WriteToFile();
    }

    void Player::WriteToFile()
    {
        std::ofstream file;
        file.open("../test-rpg/data/Player.saved.char", std::ios::trunc);
        file << "[Stats]" << std::endl;
        file << "Name:- " << name.c_str() << std::endl;
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
} // namespace rpgText
