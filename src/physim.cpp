#include <SFML/Graphics.hpp>
#include <filesystem>
#include "App.hpp"
namespace fs = std::filesystem;

int main(int arg, char **args)
{
  phy::App app(fs::path(args[0]).remove_filename());

  app.start();
  return 0;
}