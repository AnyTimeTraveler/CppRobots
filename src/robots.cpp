/**
*   \copyright Copyright 2016 Hochschule Emden/Leer. This project is released
* under
* the MIT License, see the file LICENSE.md for rights and limitations.
*   \file robots.cpp
*   \author Jan-Niklas Braak
*/

#include "CppRobots.hpp"

#include "Agents/Orbiter.hpp"
#include "Agents/Wanderer.hpp"
#include "Agents/Follower.hpp"
#include "Agents/Sniper.hpp"
#include "Agents/Hunter.hpp"
#include "Agents/Simon.hpp"

#include <chrono>
#include <fstream>
#include <AgentFactory.hpp>

/**
    This is the main function of the program.
    \return returns 0 on success
*/
int main() {

  // load Rules
  Rules rules;
  std::ifstream inFile(selfpath() + "/config/Rules.json", std::ios::in);
  if (inFile.is_open()) {
    inFile >> rules;
    inFile.close();
  } else {
    std::cout << "Unable to load Rules.json. Using defaults instead."
              << std::endl;
    // rules = Rules::defaultRules();
  }

  // generate "random" seed
  std::size_t seed = std::hash<std::string>()("Not Random");

  // create a Game
  Game game(new Simulation(rules, seed), new ViewSFML());
  // Game game(new Simulation(rules, seed), new ViewConsole());

  // load list of names
  Json::Value names;

  std::ifstream nameFile(selfpath() + "/config/Names.json", std::ios::in);
  if (!nameFile.is_open()) {
    throw std::runtime_error("Unable to load Names.json");
  }
  nameFile >> names;
  nameFile.close();

  if (!names.isArray()) {
    throw std::runtime_error("Names.json is not an array.");
  }

  // add players
  auto agentFactory = new AgentFactory();
  for (auto const &name : names) {
    game.addPlayer(name.asString(), agentFactory);
  }

  // run the game
  game.run();

  return 0;
}
