#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
// #include <vector>
#include<cmath>
#include <cstdlib>
#include <ctime>
// #include <sstream>

int X = 1920;
int Y = 1080;
// Utility function to generate random positions
sf::Vector2f getRandomPosition(int windowWidth, int windowHeight) {
    return sf::Vector2f(rand() % (windowWidth - 50), rand() % (windowHeight - 50));
}

int main() {
    // Window setup
    sf::RenderWindow window(sf::VideoMode(X, Y), "2D Game FOr MiniProject");
    window.setFramerateLimit(60);

    // Seed random number generator
    srand(static_cast<unsigned>(time(0)));

    // Player setup
    sf::RectangleShape player(sf::Vector2f(50.0f, 50.0f));
    player.setFillColor(sf::Color::Green);
    player.setPosition(375, 275);

    float speed = 5.0f; // Movement speed

    // Score setup
    int score = 0;
    sf::Font font;
    auto placeholder = "assets/Arial.ttf";
    if (!font.loadFromFile(placeholder)) {
      return -1; // Ensure a font file is available
    }
    sf::Text scoreText;
    scoreText.setFont(font);
    scoreText.setCharacterSize(24);
    scoreText.setFillColor(sf::Color::White);
    scoreText.setPosition(10, 10);

    // Collectible setup
    sf::CircleShape collectible(10.0f); // Simple circle for collectibles
    collectible.setFillColor(sf::Color::Yellow);
    collectible.setPosition(getRandomPosition(X, Y));

    // Enemy setup
    sf::RectangleShape enemy(sf::Vector2f(40.0f, 40.0f));
    enemy.setFillColor(sf::Color::Red);
    enemy.setPosition(getRandomPosition(X, Y));

    // Main game loop
    while (window.isOpen()) {
        // Event handling
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        // Player movement with boundary checks
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::W) && player.getPosition().y > 0) {
            player.move(0, -speed); // Move up
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::S) && player.getPosition().y + player.getSize().y < Y) {
            player.move(0, speed); // Move down
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::A) && player.getPosition().x > 0) {
            player.move(-speed, 0); // Move left
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::D) && player.getPosition().x + player.getSize().x < X) {
            player.move(speed, 0); // Move right
        }

        // Collision detection for collectible
        if (player.getGlobalBounds().intersects(collectible.getGlobalBounds())) {
            score += 10; // Increase score
            collectible.setPosition(getRandomPosition(X, Y)); // Move collectible to a new location
        }

        // Enemy movement towards player
        sf::Vector2f enemyDirection = player.getPosition() - enemy.getPosition();
        float magnitude = std::sqrt(enemyDirection.x * enemyDirection.x + enemyDirection.y * enemyDirection.y);
        if (magnitude != 0) {
            enemy.move((enemyDirection.x / magnitude) * 2.0f, (enemyDirection.y / magnitude) * 2.0f); // Constant speed towards player
        }

        // Collision detection with enemy
        if (player.getGlobalBounds().intersects(enemy.getGlobalBounds())) {
            scoreText.setString("Game Over! Final Score: " + std::to_string(score));
            window.clear();
            window.draw(scoreText);
            window.display();
            sf::sleep(sf::seconds(3));
            window.close(); // End the game
        }

        // Update score display
        scoreText.setString("Score: " + std::to_string(score));

        // Rendering
        window.clear();
        window.draw(player);
        window.draw(collectible);
        window.draw(enemy);
        window.draw(scoreText);
        window.display();
    }
    return 0;
}
