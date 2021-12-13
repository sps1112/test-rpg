#include "Character.h"

namespace rpgText
{
    Character::Character(std::string name_, int level, float str, float sta,
                         float inte, float agi, float luck)
    {
        name = name_;
        BaseStats bs(str, sta, inte, agi, luck);
        stats = Stats(bs, level);
        cStats = stats;
    }

    void Character::change_health(float amount)
    {
        cStats.health += amount;
        cStats.health = clamp(cStats.health, 0, stats.health);
    }

    void Character::change_mana(float amount)
    {
        cStats.mana += amount;
        cStats.mana = clamp(cStats.mana, 0, stats.mana);
    }

    bool Character::get_status()
    {
        return (cStats.health > 0);
    }

    void Character::print_stats()
    {
        print_dash(10);
        log("[STATS]");

        print("Name:- ");
        log(name);

        print("Level:- ");
        log(stats.level);

        print("Health:- ");
        print(cStats.health);
        print("/");
        log(stats.health);

        print("Mana:- ");
        print(cStats.mana);
        print("/");
        log(stats.mana);

        print("Attack:- ");
        log(cStats.attack);
        print("Defence:- ");
        log(cStats.defence);

        print("Mana Attack:- ");
        log(cStats.mAttack);
        print("Mana Defence:- ");
        log(cStats.mDefence);

        print("Speed:- ");
        log(cStats.speed);
        print("Accuracy:- ");
        log(cStats.accuracy);
        print("Evasion:- ");
        log(cStats.evasion);
        print("Crit Chance:- ");
        log(cStats.crit);

        print_dash(10);
    }

    Enemy::Enemy(std::string name_, int level, float str, float sta,
                 float inte, float agi, float luck, float exp, float money)
    {
        name = name_;
        BaseStats bs(str, sta, inte, agi, luck);
        stats = Stats(bs, level);
        cStats = stats;
        expDrop = exp;
        moneyDrop = money;
    }

    Player::Player(std::string name_, bool viaData, int level, float str, float sta,
                   float inte, float agi, float luck, float exp, float next)
    {
        name = name_;
        BaseStats bs(str, sta, inte, agi, luck);
        stats = Stats(bs, level);
        cStats = stats;
        currentExp = exp;
        expToNextlevel = next;
        write_to_file();
    }

    Player::Player(const char *playerStatsPath)
    {
        std::string statsStr;

        std::ifstream file;
        file.open(playerStatsPath);
        std::stringstream statsStream;
        statsStream << file.rdbuf();
        file.close();

        statsStr = statsStream.str();
        const char *statsCode = statsStr.c_str();

        // Set Name
        int lineStartIndex = get_index_start(statsCode, 0);
        char *lineI = get_line(statsCode, lineStartIndex);
        char *VALUE = get_line(lineI, get_string_end(lineI, ":- "));
        name = arr_to_string(VALUE);

        // Set Strength
        lineStartIndex = get_index_start(statsCode, lineStartIndex);
        lineI = get_line(statsCode, lineStartIndex);
        VALUE = get_line(lineI, get_string_end(lineI, ":- "));
        float str = arr_to_float(VALUE);

        // Set Stamina
        lineStartIndex = get_index_start(statsCode, lineStartIndex);
        lineI = get_line(statsCode, lineStartIndex);
        VALUE = get_line(lineI, get_string_end(lineI, ":- "));
        float sta = arr_to_float(VALUE);

        // Set Intelligence
        lineStartIndex = get_index_start(statsCode, lineStartIndex);
        lineI = get_line(statsCode, lineStartIndex);
        VALUE = get_line(lineI, get_string_end(lineI, ":- "));
        float inte = arr_to_float(VALUE);

        // Set Agility
        lineStartIndex = get_index_start(statsCode, lineStartIndex);
        lineI = get_line(statsCode, lineStartIndex);
        VALUE = get_line(lineI, get_string_end(lineI, ":- "));
        float agi = arr_to_float(VALUE);

        // Set Luck
        lineStartIndex = get_index_start(statsCode, lineStartIndex);
        lineI = get_line(statsCode, lineStartIndex);
        VALUE = get_line(lineI, get_string_end(lineI, ":- "));
        float luck = arr_to_float(VALUE);

        // Set Level
        lineStartIndex = get_index_start(statsCode, lineStartIndex);
        lineI = get_line(statsCode, lineStartIndex);
        VALUE = get_line(lineI, get_string_end(lineI, ":- "));
        int level = int(arr_to_float(VALUE));

        // Set Stats
        BaseStats bs(str, sta, inte, agi, luck);
        stats = Stats(bs, level);
        cStats = stats;

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

        write_to_file();
    }

    Player::~Player()
    {
        write_to_file();
    }

    void Player::write_to_file()
    {
        std::ofstream file;
        file.open(FileSystem::get_path("test-rpg/data/Player.saved.char").c_str(), std::ios::trunc);
        file << "[Stats]" << std::endl;
        file << "Name:- " << name.c_str() << std::endl;
        file << "Level:- " << stats.level << std::endl;

        file << "Health:- " << stats.health << std::endl;
        file << "Mana:- " << stats.mana << std::endl;

        file << "Attack:- " << stats.attack << std::endl;
        file << "Defence:- " << stats.defence << std::endl;
        file << "Mana Attack:- " << stats.mAttack << std::endl;
        file << "Mana Defence:- " << stats.mDefence << std::endl;

        file << "Speed:- " << stats.speed << std::endl;
        file << "Accuracy:- " << stats.accuracy << std::endl;
        file << "Evasion:- " << stats.evasion << std::endl;
        file << "Critical Chance:- " << stats.crit << std::endl;

        file << "CurrentExp:- " << currentExp << std::endl;
        file << "Exp to Next Level:- " << expToNextlevel << std::endl;
        file.close();
    }
} // namespace rpgText
