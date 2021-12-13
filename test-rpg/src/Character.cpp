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
        PrintDash(10);
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
        PrintDash(10);
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
