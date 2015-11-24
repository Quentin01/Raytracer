#include <SFML/Graphics.hpp>

int	main(int ac, char *av[])
{
  sf::Window App(sf::VideoMode(800, 600), "Raytracer");

  while (App.isOpen()) {
    sf::Event Event;

    while (App.pollEvent(Event)) {
      if (Event.type == sf::Event::Closed)
	App.close();
    }
    
    App.display();
  }
  
  return (0);
}
