#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <cstdlib>
#include <ctime>
#include <sstream>

using namespace std;

int main() {
    // Seed the random number generator with the current time
    srand(static_cast<unsigned int>(time(0)));

    // Create a window
    sf::RenderWindow window(sf::VideoMode(800, 600), "Guessing Game");

    // Generate a random number between 1 and 100
    int secretNumber = rand() % 100 + 1;
    int guess = 0;
    int attempts = 0;

    // Create text to display instructions and results
    sf::Font font;
    font.loadFromFile("arial.ttf");

    sf::Text instructions;
    instructions.setFont(font);
    instructions.setCharacterSize(24);
    instructions.setFillColor(sf::Color::White);
    instructions.setString("Welcome to the Guessing Game!\nI have selected a number between 1 and 100. Try to guess it.");
    instructions.setPosition(10, 10);

    sf::Text result;
    result.setFont(font);
    result.setCharacterSize(24);
    result.setFillColor(sf::Color::White);
    result.setPosition(10, 100);

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
            else if (event.type == sf::Event::TextEntered) {
                if (event.text.unicode >= 48 && event.text.unicode <= 57) { // Check if input is a digit
                    guess = guess * 10 + (event.text.unicode - 48);
                } else if (event.text.unicode == 13) { // Enter key pressed
                    attempts++;
                    if (guess < secretNumber) {
                        result.setString("Too low! Try again.");
                    } else if (guess > secretNumber) {
                        result.setString("Too high! Try again.");
                    } else {
                        result.setString("Congratulations!\nYou've guessed the secret number (" + to_string(secretNumber) + ") in " + to_string(attempts) + " attempts.");
                    }
                    guess = 0; // Reset guess
                }
            }
        }

        window.clear(sf::Color::Black);
        window.draw(instructions);
        window.draw(result);
        window.display();
    }

    return 0;
}
