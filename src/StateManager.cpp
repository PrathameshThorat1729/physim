#include "StateManager.hpp"

namespace phy
{
  void StateManager::pushState(std::unique_ptr<State> state)
  {
    if (!_states.empty())
    {
      _states.top()->onExit();
    }
    _states.push(std::move(state));
    _states.top()->onEnter();
  }

  void StateManager::popState()
  {
    if (!_states.empty())
    {
      _states.top()->onExit();
      _states.pop();
      if (!_states.empty())
      {
        _states.top()->onEnter();
      }
    }
  }

  State *StateManager::getCurrentState()
  {
    return _states.empty() ? nullptr : _states.top().get();
  }

  void StateManager::renderCurrentState(sf::RenderTarget &target)
  {
    if (State *state = getCurrentState())
      state->render(target);
  }

  void StateManager::updateCurrentState(const sf::Time &dt)
  {
    if (State *state = getCurrentState())
      state->update(dt);
  }

  void StateManager::handleEvents(const sf::Event &event)
  {
    State *state;

    if (!(state = getCurrentState()))
      return;

    if (state->handleEvents(event) == StateAction::STATE_POPPED)
      popState();
  }

} // namespace phy