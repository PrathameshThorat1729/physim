#include "App.hpp"
#include "States/Home.hpp"

namespace phy
{
  App::App(const fs::path &homepath) : window(
                                           sf::VideoMode::getDesktopMode(),
                                           "Physim - Simple Physics Simulations",
                                           sf::Style::Fullscreen),
                                       _homepath(homepath)
  {
    window.setVerticalSyncEnabled(true);

    sf::Image icon;
    icon.loadFromFile(_homepath / "assets" / "images" / "Icon.bmp");
    window.setIcon(256, 256, icon.getPixelsPtr());

    _state_manager.pushState(std::make_unique<HomeState>(&_state_manager));
  }

  void App::start()
  {
    sf::Event event;
    while (window.isOpen())
    {
      while (window.pollEvent(event))
      {
        if (event.type == sf::Event::Closed)
          window.close();
        _state_manager.handleEvents(event);
      }

      sf::Time dt = clk.restart();
      _state_manager.updateCurrentState(dt);

      window.clear(sf::Color::Black);
      _state_manager.renderCurrentState(window);
      window.display();
    }
  }

} // namespace phy