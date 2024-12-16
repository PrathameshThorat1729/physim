#include <SFML/Graphics.hpp>

int main()
{
  sf::RenderWindow window(sf::VideoMode::getDesktopMode(), "Physim - Simple Physics Simulations", sf::Style::Fullscreen);
  
  sf::Event event;
  while (window.isOpen())
  {
    while (window.pollEvent(event))
    {
      if (event.type == sf::Event::Closed)
        window.close();
      if (event.type == sf::Event::KeyReleased)
      {
        if (event.key.code == sf::Keyboard::Escape)
          window.close();
      }
    }

    window.clear();
    window.display();
  }
  return 0;
}