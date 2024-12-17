#ifndef PHYSIM_STATE_MANAGER_HPP
#define PHYSIM_STATE_MANAGER_HPP

#include <stack>
#include <memory>
#include <State.hpp>
#include "State.hpp"
namespace phy
{
  class StateManager
  {
  private:
    std::stack<std::unique_ptr<State>> _states;
    State *getCurrentState();
    State *pendingPushState = nullptr;

  public:
    void pushState(std::unique_ptr<State> state);

    void popState();

    void renderCurrentState(sf::RenderTarget &target);

    void updateCurrentState(const sf::Time &dt);

    void handleEvents(const sf::Event &event);

  }; // class StateManager

} // namespace phy

#endif // PHYSIM_STATE_MANAGER_HPP