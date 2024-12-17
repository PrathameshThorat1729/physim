#ifndef PHYSIM_WINIDOW_HPP
#define PHYSIM_WINIDOW_HPP

#include <SFML/Graphics.hpp>
#include <string>
#include <filesystem>
#include "StateManager.hpp"
namespace fs = std::filesystem;

namespace phy
{
  class App
  {
  private:
    sf::RenderWindow window;
    fs::path _homepath;
    StateManager _state_manager;
    sf::Clock clk;

  public:
    /// @param homepath path to main directory where application is stored
    App(const fs::path &homepath);

    void start();
  }; // class App

} // namespace phy

#endif // PHYSIM_WINIDOW_HPP