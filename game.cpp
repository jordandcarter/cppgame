#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <sstream>

int main()
{
  // Create the main window
  sf::RenderWindow window(sf::VideoMode(800, 600), "SFML window");

  // Framerate
  sf::Clock Clock;
  window.setFramerateLimit(1000);

  // Load a sprite to display
  sf::Texture texture;
  if (!texture.loadFromFile("particle.png"))
    return EXIT_FAILURE;
  sf::Sprite sprite(texture);

  // Create a graphical text to display
  sf::Font font;
  if (!font.loadFromFile("arial.ttf"))
    return EXIT_FAILURE;
  // Start the game loop
  while (window.isOpen())
  {
    sf::Time elapsedTime = Clock.restart();
    std::ostringstream s;
    s << "FPS: " << (1000.0 / elapsedTime.asMilliseconds());
    sf::Text text(s.str(), font, 12);
    text.setPosition(700, 0);
  

    // Process events
    sf::Event event;
    while (window.pollEvent(event))
    {
      // Close window : exit
      if (event.type == sf::Event::Closed)
        window.close();
    }

    // Clear screen
    window.clear();

    // Draw the sprite
    window.draw(sprite);

    // Draw the string
    window.draw(text);

    // Update the window
    window.display();
  }

  return EXIT_SUCCESS;
}
