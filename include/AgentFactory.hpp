
#ifndef __AGENT_FACTORY__
#define __AGENT_FACTORY__

#include <Agent.hpp>
#include <Agents/Hunter.hpp>
#include <Agents/Follower.hpp>
#include <Agents/Sniper.hpp>
#include <Agents/Simon.hpp>
#include <Agents/Orbiter.hpp>
#include <Agents/Wanderer.hpp>

class AgentFactory {
private:
  int i;
public:
  Agent *createAgent();
};

#endif