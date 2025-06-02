#include "gtest/gtest.h"
#include "pokemon.h"
#include <sstream>
#include <iostream>

// Test Fixture for Pokemon tests
class PokemonTest : public ::testing::Test {
protected:
    void SetUp() override {
        // Create test Pokémon before each test
        squirtle = std::make_unique<WaterPokemon>("Squirtle", 5, 44, 48, 65);
        bulbasaur = std::make_unique<GrassPokemon>("Bulbasaur", 5, 45, 49, 65);
        charmander = std::make_unique<FirePokemon>("Charmander", 5, 39, 52, 60);
    }

    void TearDown() override {
        // Clean up after each test
        squirtle.reset();
        bulbasaur.reset();
        charmander.reset();
    }

    std::unique_ptr<WaterPokemon> squirtle;
    std::unique_ptr<GrassPokemon> bulbasaur;
    std::unique_ptr<FirePokemon> charmander;
};

// =================== BASIC TESTS ===================

TEST_F(PokemonTest, PokemonCreation) {
    EXPECT_EQ(squirtle->get_name(), "Squirtle");
    EXPECT_EQ(squirtle->get_level(), 5);
    EXPECT_EQ(squirtle->get_current_hp(), 44);
    EXPECT_EQ(squirtle->get_max_hp(), 44);
    EXPECT_EQ(squirtle->get_attack(), 48);
    EXPECT_EQ(squirtle->get_defense(), 65);
    EXPECT_EQ(squirtle->get_type(), PokemonType::WATER);
}

TEST_F(PokemonTest, SpecialAbilities) {
    EXPECT_EQ(squirtle->get_special_ability(), "Torrent");
    EXPECT_EQ(bulbasaur->get_special_ability(), "Overgrow");
    EXPECT_EQ(charmander->get_special_ability(), "Blaze");
}

TEST_F(PokemonTest, InitialStateNotFainted) {
    EXPECT_FALSE(squirtle->is_fainted());
    EXPECT_FALSE(bulbasaur->is_fainted());
    EXPECT_FALSE(charmander->is_fainted());
}

// =================== TYPE SYSTEM TESTS ===================

TEST_F(PokemonTest, WaterTypeMultiplier) {
    EXPECT_DOUBLE_EQ(squirtle->calculate_type_multiplier(PokemonType::FIRE), 2.0); // Super effective
    EXPECT_DOUBLE_EQ(squirtle->calculate_type_multiplier(PokemonType::GRASS), 0.5); // Not very effective
    EXPECT_DOUBLE_EQ(squirtle->calculate_type_multiplier(PokemonType::WATER), 1.0); // Neutral
}

TEST_F(PokemonTest, GrassTypeMultiplier) {
    EXPECT_DOUBLE_EQ(bulbasaur->calculate_type_multiplier(PokemonType::WATER), 2.0); // Super effective
    EXPECT_DOUBLE_EQ(bulbasaur->calculate_type_multiplier(PokemonType::FIRE), 0.5); // Not very effective
    EXPECT_DOUBLE_EQ(bulbasaur->calculate_type_multiplier(PokemonType::GRASS), 1.0); // Neutral
}

TEST_F(PokemonTest, FireTypeMultiplier) {
    EXPECT_DOUBLE_EQ(charmander->calculate_type_multiplier(PokemonType::GRASS), 2.0); // Super effective
    EXPECT_DOUBLE_EQ(charmander->calculate_type_multiplier(PokemonType::WATER), 0.5); // Not very effective
    EXPECT_DOUBLE_EQ(charmander->calculate_type_multiplier(PokemonType::FIRE), 1.0); // Neutral
}

// =================== DAMAGE AND COMBAT TESTS ===================

TEST_F(PokemonTest, ReceivesDamageCorrectly) {
    int initial_hp = squirtle->get_current_hp();
    squirtle->take_damage(10);
    EXPECT_EQ(squirtle->get_current_hp(), initial_hp - 10);
}

TEST_F(PokemonTest, HPDoesNotGoNegative) {
    squirtle->take_damage(1000); // Excessive damage
    EXPECT_EQ(squirtle->get_current_hp(), 0);
    EXPECT_TRUE(squirtle->is_fainted());
}

TEST_F(PokemonTest, CannotHealFaintedPokemon) {
    squirtle->take_damage(squirtle->get_current_hp());
    
    EXPECT_TRUE(squirtle->is_fainted());
    EXPECT_EQ(squirtle->get_current_hp(), 0);
    
    squirtle->heal(20);
    
    EXPECT_TRUE(squirtle->is_fainted());
    EXPECT_EQ(squirtle->get_current_hp(), 0);
}

TEST_F(PokemonTest, HealingWorks) {
    squirtle->take_damage(20);
    int hp_after_damage = squirtle->get_current_hp();
    squirtle->heal(10);
    EXPECT_EQ(squirtle->get_current_hp(), hp_after_damage + 10);
}

TEST_F(PokemonTest, BasicAttackDealsDamage) {
    int initial_hp = bulbasaur->get_current_hp();

    // Capture output to avoid test spam
    std::ostringstream buffer;
    std::streambuf* orig = std::cout.rdbuf(buffer.rdbuf());

    squirtle->attack_target(*bulbasaur);

    std::cout.rdbuf(orig); // Restore cout

    // HP should have decreased
    EXPECT_LT(bulbasaur->get_current_hp(), initial_hp);
}

TEST_F(PokemonTest, SuperEffectiveAttackDealsMoreDamage) {
    // Create two identical Pokémon for comparison
    FirePokemon charmander1("Charmander1", 5, 100, 52, 60);
    FirePokemon charmander2("Charmander2", 5, 100, 52, 60);
    GrassPokemon victim_bulbasaur("Bulbasaur", 5, 100, 49, 65);
    WaterPokemon victim_squirtle("Squirtle", 5, 100, 48, 65);

    std::ostringstream buffer;
    std::streambuf* orig = std::cout.rdbuf(buffer.rdbuf());

    // Super effective (Fire vs Grass)
    charmander1.attack_target(victim_bulbasaur);
    int damage_super = 100 - victim_bulbasaur.get_current_hp();

    // Not very effective (Fire vs Water)
    charmander2.attack_target(victim_squirtle);
    int damage_not_effective = 100 - victim_squirtle.get_current_hp();

    std::cout.rdbuf(orig);

    EXPECT_GT(damage_super, damage_not_effective);
}

// =================== POLYMORPHISM TESTS ===================

TEST_F(PokemonTest, PolymorphismWorks) {
    Pokemon* pokemon_ptr = squirtle.get();

    EXPECT_EQ(pokemon_ptr->get_name(), "Squirtle");
    EXPECT_EQ(pokemon_ptr->get_type(), PokemonType::WATER);
    EXPECT_EQ(pokemon_ptr->get_special_ability(), "Torrent");
}

TEST_F(PokemonTest, PolymorphicAttack) {
    Pokemon* attacker = charmander.get();
    Pokemon* victim = bulbasaur.get();

    int initial_hp = victim->get_current_hp();

    std::ostringstream buffer;
    std::streambuf* orig = std::cout.rdbuf(buffer.rdbuf());

    attacker->attack_target(*victim);

    std::cout.rdbuf(orig);

    EXPECT_LT(victim->get_current_hp(), initial_hp);
}

// =================== EDGE CASE TESTS ===================

TEST_F(PokemonTest, PokemonWithZeroHPIsFainted) {
    squirtle->take_damage(squirtle->get_current_hp());
    EXPECT_TRUE(squirtle->is_fainted());
    EXPECT_EQ(squirtle->get_current_hp(), 0);
}

// =================== TYPE-SPECIFIC TESTS ===================

TEST_F(PokemonTest, CorrectTypes) {
    EXPECT_EQ(squirtle->get_type(), PokemonType::WATER);
    EXPECT_EQ(bulbasaur->get_type(), PokemonType::GRASS);
    EXPECT_EQ(charmander->get_type(), PokemonType::FIRE);
}

// =================== POTENTIAL BUG TESTS ===================

TEST_F(PokemonTest, DoubleToIntConversionDoesNotBreak) {
    // Test to verify that damage calculation (double to int) works
    WaterPokemon attacker("WaterTest", 5, 50, 33, 50); // Odd attack
    FirePokemon victim("FireTest", 5, 50, 30, 31);   // Causes decimal result

    std::ostringstream buffer;
    std::streambuf* orig = std::cout.rdbuf(buffer.rdbuf());

    int initial_hp = victim.get_current_hp();
    attacker.attack_target(victim);

    std::cout.rdbuf(orig);

    // Ensure HP changed (not broken due to cast)
    EXPECT_NE(victim.get_current_hp(), initial_hp);
    EXPECT_GE(victim.get_current_hp(), 0);
}

TEST_F(PokemonTest, BattleDoesNotCauseInfiniteLoop) {
    // Create two evenly matched Pokémon
    WaterPokemon poke1("Balanced1", 5, 100, 45, 45);
    WaterPokemon poke2("Balanced2", 5, 100, 45, 45);

    std::ostringstream buffer;
    std::streambuf* orig = std::cout.rdbuf(buffer.rdbuf());

    // Should not hang the program
    Battle::simple_battle(poke1, poke2);

    std::cout.rdbuf(orig);

    // Test passes if we reach here
    EXPECT_TRUE(true);
}

// =================== REGRESSION TESTS ===================

TEST_F(PokemonTest, ShowInfoDoesNotCrash) {
    // Test to ensure show info doesn't crash
    std::ostringstream buffer;
    std::streambuf* orig = std::cout.rdbuf(buffer.rdbuf());

    squirtle->show_info();
    bulbasaur->show_info();
    charmander->show_info();

    std::cout.rdbuf(orig);

    EXPECT_TRUE(true); // If we got here, no crash occurred
}

TEST_F(PokemonTest, MultipleFightsDoNotCorruptState) {
    // Ensure multiple fights don't cause state issues
    FirePokemon fighter("Fighter", 5, 60, 55, 50);

    for (int i = 0; i < 3; i++) {
        GrassPokemon opponent("Opponent" + std::to_string(i), 5, 40, 45, 50);

        std::ostringstream buffer;
        std::streambuf* orig = std::cout.rdbuf(buffer.rdbuf());

        Battle::simple_battle(fighter, opponent);

        std::cout.rdbuf(orig);

        // Fighter should still be alive and in valid state
        EXPECT_GE(fighter.get_current_hp(), 0);
        EXPECT_LE(fighter.get_current_hp(), fighter.get_max_hp());
    }
}