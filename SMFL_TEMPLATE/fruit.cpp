#include <SFML/Graphics.hpp>

#include "fruit.hpp"

using namespace std;

Fruit::Fruit(sf::RenderWindow& App)
{
	_app = &App;
}

void Fruit::spawn(float x, float y)
{
	sf::RectangleShape block(sf::Vector2f(20,20));
	block.setFillColor(sf::Color::Green);
	block.move(x, y);

	_x = x;
	_y = y;

	_app->draw(block);
}

float Fruit::getX()
{
	return _x;
}

float Fruit::getY()
{
	return _y;
}