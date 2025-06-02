#ifndef POKEMON_H
#define POKEMON_H

#include <iostream>
#include <string>
#include <vector>
#include <memory>
#include <cmath>

// Enum for Pokémon types
enum class PokemonType {
    WATER,
    GRASS,
    FIRE
};

// Abstract base class Pokemon
class Pokemon {
protected:
    std::string name;
    int level;
    int max_hp;
    int current_hp;
    int attack;
    int defense;
    PokemonType type;

public:
    // Constructor
    Pokemon(const std::string& n, int lvl, int hp, int atk, int def, PokemonType t)
        : name(n), level(lvl), max_hp(hp), current_hp(hp), attack(atk), defense(def), type(t) {}

    // Virtual destructor
    virtual ~Pokemon() {}

    // Pure virtual methods
    virtual void attack_target(Pokemon& target) = 0;
    virtual std::string get_special_ability() const = 0;
    virtual double calculate_type_multiplier(PokemonType opponent_type) const = 0;

    // Common methods
    virtual void take_damage(int damage) {
        current_hp -= damage;
        if (current_hp < 0) current_hp = 0;
    }

    virtual void heal(int amount) {
        if (is_fainted()) {
            return;
        }
        current_hp += amount;
        if (current_hp > max_hp) current_hp = max_hp;
    }

    virtual bool is_fainted() const {
        return current_hp <= 0;
    }

    // Getters
    std::string get_name() const { return name; }
    int get_level() const { return level; }
    int get_current_hp() const { return current_hp; }
    int get_max_hp() const { return max_hp; }
    int get_attack() const { return attack; }
    int get_defense() const { return defense; }
    PokemonType get_type() const { return type; }

    // Method to show information
    virtual void show_info() const {
        std::cout << "Name: " << name << std::endl;
        std::cout << "Level: " << level << std::endl;
        std::cout << "HP: " << current_hp << "/" << max_hp << std::endl;
        std::cout << "Attack: " << attack << std::endl;
        std::cout << "Defense: " << defense << std::endl;
    }
};
// ---

// Water-type Pokémon
class WaterPokemon : public Pokemon {
public:
    WaterPokemon(const std::string& name, int level, int hp, int atk, int def)
        : Pokemon(name, level, hp, atk, def, PokemonType::WATER) {}

    void attack_target(Pokemon& target) override {
        double multiplier = calculate_type_multiplier(target.get_type());
        int base_damage = attack - target.get_defense();
        if (base_damage < 1) base_damage = 1;

        int final_damage = static_cast<int>(std::round(base_damage * multiplier));

        std::cout << name << " uses Water Gun on " << target.get_name() << "!" << std::endl;
        target.take_damage(final_damage);
        std::cout << "It deals " << final_damage << " damage!" << std::endl;
    }

    std::string get_special_ability() const override {
        return "Torrent";
    }

    double calculate_type_multiplier(PokemonType opponent_type) const override {
        switch (opponent_type) {
            case PokemonType::FIRE:
                return 2.0;
            case PokemonType::GRASS:
                return 0.5;
            case PokemonType::WATER:
                return 1.0;
            default:
                return 1.0;
        }
    }

    void show_info() const override {
        std::cout << "=== WATER-TYPE POKÉMON ===" << std::endl;
        Pokemon::show_info();
        std::cout << "Ability: " << get_special_ability() << std::endl;
    }
};
// ---

// Grass-type Pokémon
class GrassPokemon : public Pokemon {
public:
    GrassPokemon(const std::string& name, int level, int hp, int atk, int def)
        : Pokemon(name, level, hp, atk, def, PokemonType::GRASS) {}

    void attack_target(Pokemon& target) override {
        double multiplier = calculate_type_multiplier(target.get_type());
        int base_damage = attack - target.get_defense(); 
        if (base_damage < 1) base_damage = 1;

        int final_damage = static_cast<int>(std::round(base_damage * multiplier));

        std::cout << name << " uses Vine Whip on " << target.get_name() << "!" << std::endl;
        target.take_damage(final_damage);
        std::cout << "It deals " << final_damage << " damage!" << std::endl;
    }

    std::string get_special_ability() const override {
        return "Overgrow";
    }

    double calculate_type_multiplier(PokemonType opponent_type) const override {
        switch (opponent_type) {
            case PokemonType::WATER:
                return 2.0;
            case PokemonType::FIRE:
                return 0.5;
            case PokemonType::GRASS:
                return 1.0;
            default:
                return 1.0;
        }
    }

    void show_info() const override {
        std::cout << "=== GRASS-TYPE POKÉMON ===" << std::endl;
        Pokemon::show_info();
        std::cout << "Ability: " << get_special_ability() << std::endl;
    }
};
// ---

// Fire-type Pokémon
class FirePokemon : public Pokemon {
public:
    FirePokemon(const std::string& name, int level, int hp, int atk, int def)
        : Pokemon(name, level, hp, atk, def, PokemonType::FIRE) {}

    void attack_target(Pokemon& target) override {
        double multiplier = calculate_type_multiplier(target.get_type());
        int base_damage = attack - target.get_defense(); 
        if (base_damage < 1) base_damage = 1;

        int final_damage = static_cast<int>(std::round(base_damage * multiplier));

        std::cout << name << " uses Ember on " << target.get_name() << "!" << std::endl;
        target.take_damage(final_damage);
        std::cout << "It deals " << final_damage << " damage!" << std::endl;
    }

    std::string get_special_ability() const override {
        return "Blaze";
    }

    double calculate_type_multiplier(PokemonType opponent_type) const override {
        switch (opponent_type) {
            case PokemonType::GRASS:
                return 2.0;
            case PokemonType::WATER:
                return 0.5;
            case PokemonType::FIRE:
                return 1.0;
            default:
                return 1.0;
        }
    }

    void show_info() const override {
        std::cout << "=== FIRE-TYPE POKÉMON ===" << std::endl;
        Pokemon::show_info();
        std::cout << "Ability: " << get_special_ability() << std::endl;
    }
};
// ---

// Utility class to handle battles
class Battle {
public:
    static void simple_battle(Pokemon& pokemon1, Pokemon& pokemon2) {
        std::cout << "\nThe battle begins between " << pokemon1.get_name() 
                  << " and " << pokemon2.get_name() << "!" << std::endl;

        int turn = 1;
        while (!pokemon1.is_fainted() && !pokemon2.is_fainted()) {
            std::cout << "\n--- Turn " << turn << " ---" << std::endl;

            // Pokemon 1 attacks
            if (!pokemon1.is_fainted()) {
                pokemon1.attack_target(pokemon2);
                if (pokemon2.is_fainted()) {
                    std::cout << pokemon2.get_name() << " has fainted!" << std::endl;
                    break;
                }
            }

            // Pokemon 2 attacks
            if (!pokemon2.is_fainted()) {
                pokemon2.attack_target(pokemon1);
                if (pokemon1.is_fainted()) {
                    std::cout << pokemon1.get_name() << " has fainted!" << std::endl;
                    break;
                }
            }

            turn++;
            if (turn > 50) {
                std::cout << "The battle lasted too long! It's a draw." << std::endl;
                break;
            }
        }

        if (!pokemon1.is_fainted() && pokemon2.is_fainted()) {
            std::cout << "\n" << pokemon1.get_name() << " is the winner!" << std::endl;
        } else if (pokemon1.is_fainted() && !pokemon2.is_fainted()) {
            std::cout << "\n" << pokemon2.get_name() << " is the winner!" << std::endl;
        }
    }
};

#endif
