/**
*   \copyright Copyright 2016 Hochschule Emden/Leer. This project is released under
* the MIT License, see the file LICENSE.md for rights and limitations.
*   \file Game.hpp
*   \author Jan-Niklas Braak
*/

#ifndef __CPPROBOTS_GAME__
#define __CPPROBOTS_GAME__

#include "SignalSlot.hpp"
#include "Simulation.hpp"
#include "ViewSFML.hpp"
#include "version.h"
#include "AgentFactory.hpp"

#include <functional>
#include <map>
#include <memory>
#include <string>

/**
  \brief A Class that encapsulates the Game logic of the program.
*/
class Game {
  Slot<std::string> _onDeath{[this](std::string name) { this->onDeath(name); }};
  Slot<> _onSimulationStep{[this]() { this->onSimulationStep(); }};

protected:
  /**
  \brief Structure, that holds the data of a Player.
  */
  struct Player {
    /**
      \brief A factory function for Agents. This function is called when the
      Player (re)spawns.
    */
    AgentFactory* agentFactory;
    /**
      \brief Number of lives of the Player.
    */
    int lives;
  };

  /**
    \brief Players in the game.
  */
  std::map<std::string, Player> players;
  /**
    \brief Pointer to the Simulation used by the Game.
  */
  std::shared_ptr<Simulation> simulation;

  /**
  \brief Pointer to the View used for User interaction.
  */
  std::shared_ptr<View> view;

  /**
    \brief Number of lives a Player starts with.
  */
  int startingLives = 0;
  /**
    \brief Wheter the Game is currently running.
  */
  bool running = true;

public:
  /**
  \brief Create a new Game using the given Simulation and View.

  \param simulation A pointer to a Simulation.
  \param view A Pointer to a View.
  */
  Game(Simulation *simulation, View *view);

  /**
    /brief Adds a player to the Game.

    \param name The name of the player.
    \param agentFactory A funtion, that returns a new Agent.
  */
  void addPlayer(std::string name, AgentFactory* agentFactory);

  /**
    \brief Run the Game until it is finished.
  */
  void run();

  /**
    \brief Function, that is called when a player dies.
    \param name The name of the player, that died.
    */
  virtual void onDeath(std::string name);
  /**
    \brief Function, that is called once per simulation step.
  */
  virtual void onSimulationStep();
};

#endif /* end of include guard: __CPPROBOTS_GAME__ */
