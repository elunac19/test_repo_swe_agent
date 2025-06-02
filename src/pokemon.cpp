#include "pokemon.h"
#include <iostream>

int main() {
    std::cout << "=== POKEMON BATTLE SIMULATOR ===" << std::endl;
    std::cout << "Welcome to the Pokemon Arena!" << std::endl;
    
    // Create Pokemon for battle
    WaterPokemon squirtle("Squirtle", 12, 85, 28, 18);
    FirePokemon charmander("Charmander", 13, 80, 35, 15);
    
    std::cout << "\nToday's fighters:" << std::endl;
    squirtle.show_info();
    std::cout << std::endl;
    charmander.show_info();
    
    std::cout << "\n" << std::string(40, '-') << std::endl;
    std::cout << "THE BATTLE BEGINS!" << std::endl;
    std::cout << std::string(40, '-') << std::endl;
    
    // Round 1 - Normal battle
    std::cout << "\n--- Round 1 ---" << std::endl;
    charmander.attack_target(squirtle);
    std::cout << "Squirtle HP: " << squirtle.get_current_hp() << "/" << squirtle.get_max_hp() << std::endl;
    
    std::cout << std::endl;
    squirtle.attack_target(charmander);
    std::cout << "Charmander HP: " << charmander.get_current_hp() << "/" << charmander.get_max_hp() << std::endl;
    
    // Round 2 - More damage
    std::cout << "\n--- Round 2 ---" << std::endl;
    std::cout << "The battle intensifies!" << std::endl;
    charmander.attack_target(squirtle);
    std::cout << "Squirtle HP: " << squirtle.get_current_hp() << "/" << squirtle.get_max_hp() << std::endl;
    
    std::cout << std::endl;
    squirtle.attack_target(charmander);
    std::cout << "Charmander HP: " << charmander.get_current_hp() << "/" << charmander.get_max_hp() << std::endl;
    
    // Round 3 - Critical hits! (More damage to trigger negative HP)
    std::cout << "\n--- Round 3 ---" << std::endl;
    std::cout << "Critical hit incoming!" << std::endl;
    squirtle.take_damage(95); // This will cause negative HP bug
    std::cout << "Squirtle takes massive damage!" << std::endl;
    std::cout << "Squirtle HP: " << squirtle.get_current_hp() << "/" << squirtle.get_max_hp() << std::endl;
    
    if (squirtle.is_fainted()) {
        std::cout << "Oh no! Squirtle has fainted!" << std::endl;
    }
    
    // Healing attempt on fainted Pokemon
    std::cout << "\n--- Emergency Healing ---" << std::endl;
    std::cout << "Trainer uses Super Potion on Squirtle!" << std::endl;
    squirtle.heal(40); // Bug: healing fainted Pokemon
    std::cout << "Squirtle HP after healing: " << squirtle.get_current_hp() << "/" << squirtle.get_max_hp() << std::endl;
    
    if (squirtle.is_fainted()) {
        std::cout << "The healing didn't work... Squirtle is still fainted." << std::endl;
    } else {
        std::cout << "Amazing recovery!" << std::endl;
    }
    
    // New Pokemon enters
    std::cout << "\n--- New Challenger ---" << std::endl;
    std::cout << "A wild Blastoise appears!" << std::endl;
    WaterPokemon blastoise("Blastoise", 25, 120, 45, 35);
    blastoise.show_info();
    
    // Battle continues with new Pokemon
    std::cout << "\n--- Charmander vs Blastoise ---" << std::endl;
    charmander.attack_target(blastoise);
    std::cout << "Blastoise HP: " << blastoise.get_current_hp() << "/" << blastoise.get_max_hp() << std::endl;
    
    std::cout << std::endl;
    blastoise.attack_target(charmander);
    std::cout << "Charmander HP: " << charmander.get_current_hp() << "/" << charmander.get_max_hp() << std::endl;
    
    // Overhealing scenario
    std::cout << "\n--- Power-up Time! ---" << std::endl;
    std::cout << "Blastoise finds a Max Elixir!" << std::endl;
    std::cout << "Blastoise HP before elixir: " << blastoise.get_current_hp() << "/" << blastoise.get_max_hp() << std::endl;
    blastoise.heal(80); // Bug: overhealing beyond max HP
    std::cout << "Blastoise HP after elixir: " << blastoise.get_current_hp() << "/" << blastoise.get_max_hp() << std::endl;
    
    // Final dramatic battle
    std::cout << "\n--- Final Showdown ---" << std::endl;
    std::cout << "This is it! The final clash!" << std::endl;
    
    // Create a scenario where minimum damage bug might show
    WaterPokemon weakling("Magikarp", 5, 60, 8, 5);
    FirePokemon tank("Arcanine", 30, 150, 25, 45);
    
    std::cout << "\nSuddenly, a Magikarp challenges the mighty Arcanine!" << std::endl;
    std::cout << "Arcanine HP: " << tank.get_current_hp() << "/" << tank.get_max_hp() << std::endl;
    
    std::cout << "\nMagikarp uses Splash... wait, no! It's using Tackle!" << std::endl;
    weakling.attack_target(tank); // This should show minimum damage of 1
    std::cout << "Arcanine HP: " << tank.get_current_hp() << "/" << tank.get_max_hp() << std::endl;
    
    std::cout << "\nArcanine retaliates!" << std::endl;
    tank.attack_target(weakling);
    std::cout << "Magikarp HP: " << weakling.get_current_hp() << "/" << weakling.get_max_hp() << std::endl;
    
    if (weakling.is_fainted()) {
        std::cout << "Magikarp fainted! What a brave little Pokemon!" << std::endl;
    }
    
    std::cout << "\n" << std::string(40, '=') << std::endl;
    std::cout << "BATTLE SIMULATION COMPLETE!" << std::endl;
    std::cout << "Thanks for watching the Pokemon battles!" << std::endl;
    std::cout << std::string(40, '=') << std::endl;
    
    return 0;
}