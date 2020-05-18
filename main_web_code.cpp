#include <iostream>
#include "sim_interface.hpp"

int main()
{
    Sim_interface sim_interface;

    std::vector<std::string> armor_vec;
    armor_vec.emplace_back("lionheart_helm");
    armor_vec.emplace_back("onyxia_tooth_pendant");
    armor_vec.emplace_back("drake_talon_pauldrons");
    armor_vec.emplace_back("cape_of_the_black_baron");
    armor_vec.emplace_back("savage_gladiator_chain");
    armor_vec.emplace_back("wristguards_of_stability");
    armor_vec.emplace_back("flameguard_gauntlets");
    armor_vec.emplace_back("onslaught_girdle");
    armor_vec.emplace_back("legguards_of_the_fallen_crusader");
    armor_vec.emplace_back("chromatic_boots");
    armor_vec.emplace_back("don_julios_band");
    armor_vec.emplace_back("master_dragonslayers_ring");
    armor_vec.emplace_back("hand_of_justice");
    armor_vec.emplace_back("diamond_flask");
    armor_vec.emplace_back("blastershot");

    std::vector<std::string> weapons_vec;
    weapons_vec.emplace_back("maladath");
    weapons_vec.emplace_back("brutality_blade");

    Sim_input sim_input{armor_vec, weapons_vec, 60, 63, 10};
    auto sim_output = sim_interface.simulate(sim_input);

    for (double dmg_batch : sim_output.dmg_batches)
    {
        std::cout << "batch = " << dmg_batch << "\n";
    }

    std::cout << "DPS = " << sim_output.mean_dps << "\n";
    for (const auto &message : sim_output.messages)
    {
        std::cout << message << "\n";
    }

    return 0;
}

