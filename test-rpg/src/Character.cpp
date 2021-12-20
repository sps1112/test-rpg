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

    void Character::reset_stats()
    {
        cStats.health = stats.health;
        cStats.mana = stats.mana;
    }

    bool Character::get_status()
    {
        return (cStats.health > 0);
    }

    void Character::print_stats()
    {
        print_line();
        log("[STATS]");

        print("Name:- ");
        log(name);

        print_data("Level:- ", stats.level);

        print("Health:- ");
        print(cStats.health);
        print("/");
        log(stats.health);

        print("Mana:- ");
        print(cStats.mana);
        print("/");
        log(stats.mana);

        print_data("Attack:- ", cStats.attack);
        print_data("Defence:- ", cStats.defence);
        print_data("Mana Attack:- ", cStats.mAttack);
        print_data("Mana Defence:- ", cStats.mDefence);
        print_data("Speed:- ", cStats.speed);
        print_data("Accuracy:- ", cStats.accuracy);
        print_data("Evasion:- ", cStats.evasion);
        print_data("Crit Chance:- ", cStats.crit);

        print_line();
    }

    Enemy::Enemy(std::string name_, bool viaData, int level, float str, float sta,
                 float inte, float agi, float luck, float exp, float money)
    {
        name = name_;
        BaseStats bs(str, sta, inte, agi, luck);
        stats = Stats(bs, level);
        cStats = stats;
        expDrop = exp;
        moneyDrop = money;
    }

    Enemy::Enemy(const char *path)
    {
        std::string statsStr = get_file_data(path);
        const char *statsCode = statsStr.c_str();
        int index = 0;

        // Set Name
        index = skip_lines(statsCode, 1, index);
        name = arr_to_string(get_data_point(statsCode, ":- ", index));

        // Set Strength
        index = skip_lines(statsCode, 1, index);
        float str = arr_to_float(get_data_point(statsCode, ":- ", index));

        // Set Stamina
        index = skip_lines(statsCode, 1, index);
        float sta = arr_to_float(get_data_point(statsCode, ":- ", index));

        // Set Intelligence
        index = skip_lines(statsCode, 1, index);
        float inte = arr_to_float(get_data_point(statsCode, ":- ", index));

        // Set Agility
        index = skip_lines(statsCode, 1, index);
        float agi = arr_to_float(get_data_point(statsCode, ":- ", index));

        // Set Luck
        index = skip_lines(statsCode, 1, index);
        float luck = arr_to_float(get_data_point(statsCode, ":- ", index));

        // Set Level
        index = skip_lines(statsCode, 1, index);
        int level = int(arr_to_float(get_data_point(statsCode, ":- ", index)));

        // Set Stats
        BaseStats bs(str, sta, inte, agi, luck);
        stats = Stats(bs, level);
        cStats = stats;

        // Set Exp Drop
        index = skip_lines(statsCode, 1, index);
        expDrop = arr_to_float(get_data_point(statsCode, ":- ", index));

        // Set Money Drop
        index = skip_lines(statsCode, 1, index);
        moneyDrop = arr_to_float(get_data_point(statsCode, ":- ", index));
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

    Player::Player(const char *path)
    {
        std::string statsStr = get_file_data(path);
        const char *statsCode = statsStr.c_str();
        int index = 0;

        // Set Name
        index = skip_lines(statsCode, 1, index);
        name = arr_to_string(get_data_point(statsCode, ":- ", index));

        // Set Strength
        index = skip_lines(statsCode, 1, index);
        float str = arr_to_float(get_data_point(statsCode, ":- ", index));

        // Set Stamina
        index = skip_lines(statsCode, 1, index);
        float sta = arr_to_float(get_data_point(statsCode, ":- ", index));

        // Set Intelligence
        index = skip_lines(statsCode, 1, index);
        float inte = arr_to_float(get_data_point(statsCode, ":- ", index));

        // Set Agility
        index = skip_lines(statsCode, 1, index);
        float agi = arr_to_float(get_data_point(statsCode, ":- ", index));

        // Set Luck
        index = skip_lines(statsCode, 1, index);
        float luck = arr_to_float(get_data_point(statsCode, ":- ", index));

        // Set Level
        index = skip_lines(statsCode, 1, index);
        int level = int(arr_to_float(get_data_point(statsCode, ":- ", index)));

        // Set Stats
        BaseStats bs(str, sta, inte, agi, luck);
        stats = Stats(bs, level);
        cStats = stats;

        // Set Current EXP
        index = skip_lines(statsCode, 1, index);
        currentExp = arr_to_float(get_data_point(statsCode, ":- ", index));

        // Set EXP to Next Level
        index = skip_lines(statsCode, 1, index);
        expToNextlevel = arr_to_float(get_data_point(statsCode, ":- ", index));

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
