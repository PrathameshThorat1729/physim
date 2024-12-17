#include "States/Home.hpp"

namespace phy
{
  HomeState::HomeState(StateManager *stateManager) : State(stateManager)
  {
    c.setRadius(10);
  }

  void HomeState::render(sf::RenderTarget &target) const
  {
    target.draw(c);
  }

  void HomeState::update(const sf::Time &dt)
  {
    if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
      c.setFillColor(sf::Color::Red);
    else
      c.setFillColor(sf::Color::White);

    c.setPosition(sf::Mouse::getPosition().x - 10, sf::Mouse::getPosition().y - 10);
  }

  sf::Uint8 HomeState::handleEvents(const sf::Event &event)
  {
    return StateAction::NONE;
  }
} // namespace phy
