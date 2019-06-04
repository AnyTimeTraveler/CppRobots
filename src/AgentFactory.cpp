
#include <AgentFactory.hpp>

Agent *AgentFactory::createAgent() {
  switch (i++ % 6) {
    case 0:
      return new Hunter(100, 20, 30);
    case 1:
      return new Follower(100, 20, 30);
    case 2:
      return new Sniper();
    case 3:
      return new Simon(100, 20, 30);
    case 4:
      return new Wanderer(100, 20, 30);
    case 5:
      return new Orbiter(20, 30);
    default:
      return nullptr;
  }
}