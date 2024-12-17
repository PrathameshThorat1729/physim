#ifndef PHYSIM_STATE_HPP
#define PHYSIM_STATE_HPP

#include <SFML/Graphics.hpp>

namespace phy
{
  class StateManager; // Forward Declaration

  namespace StateAction
  {
    /// @brief Defines the Action can be done on States
    enum StateAction
    {
      NONE = 0,
      STATE_PUSHED,
      STATE_POPPED,
    };
  }; // namespace StateAction

  class State
  {
  protected:
    StateManager *_stateManager;

  public:
    State(StateManager *stateManager) : _stateManager(stateManager) {};

    virtual ~State() = default;

    virtual void render(sf::RenderTarget &target) const = 0;

    virtual void update(const sf::Time &dt) = 0;

    /// @return value of phy::StateAction
    virtual sf::Uint8 handleEvents(const sf::Event &event) = 0;

    virtual void onEnter() {}

    virtual void onExit() {}
  }; // class State

} // namespace phy

#endif // PHYSIM_STATE_HPP