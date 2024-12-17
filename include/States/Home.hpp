#ifndef PHYSIM_STATE_HOME_HPP
#define PHYSIM_STATE_HOME_HPP

#include "State.hpp"

namespace phy
{
  class HomeState : public State
  {
  private:
    sf::CircleShape c;

  public:
    HomeState(StateManager *stateManager);

    void render(sf::RenderTarget &target) const;

    void update(const sf::Time &dt);

    sf::Uint8 handleEvents(const sf::Event &event);
  }; // class HomeState

} // namespace phy

#endif // PHYSIM_STATE_HOME_HPP