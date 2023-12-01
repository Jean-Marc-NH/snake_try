/*
 *  snake.cpp
 *  snake
 *
 *  Created by Mathieu Allaire on 11-01-23.
 *  Copyright 2011 mathieuallaire.ca. All rights reserved.
 *
 */

#include <SFML/Graphics.hpp>

#include "snake.hpp"
#include "block.hpp"

using namespace std;

Snake::Snake(sf::RenderWindow& App)
{
	_app = &App;
	_direction = RIGHT;

	// Draws the initial snake
	_snake.push_front(Block(25, 0));
	_snake.push_front(Block(50, 0));
}


void Snake::move()
{
	shrink();
	int random = rand() % 4;

	if (random == 0)
	{
		if (_direction != DOWN)
		{
			_snake.push_front(Block(_snake.front().getX(), _snake.front().getY() - 25));
			_direction = UP;
		}
		else
		{
			_snake.push_front(Block(_snake.front().getX(), _snake.front().getY() + 25));
		}
	}

	else if (random == 1)
	{
		if (_direction != LEFT)
		{
			_snake.push_front(Block(_snake.front().getX() + 25, _snake.front().getY()));
			_direction = RIGHT;
		}
		else
		{
			_snake.push_front(Block(_snake.front().getX() - 25, _snake.front().getY()));
		}
	}

	else if (random == 2)
	{
		if (_direction != UP)
		{
			_snake.push_front(Block(_snake.front().getX(), _snake.front().getY() + 25));
			_direction = DOWN;
		}
		else
		{
			_snake.push_front(Block(_snake.front().getX(), _snake.front().getY() - 25));
		}

	}

	else if (random == 3)
	{
		if (_direction != RIGHT)
		{
			_snake.push_front(Block(_snake.front().getX() - 25, _snake.front().getY()));
			_direction = LEFT;
		}
		else
		{
			_snake.push_front(Block(_snake.front().getX() + 25, _snake.front().getY()));
		}
	}
}

void Snake::draw()
{
	for (list<Block>::iterator it = _snake.begin(); it != _snake.end(); it++)
	{
		float x = it->getX();
		float y = it->getY();

		sf::RectangleShape block(sf::Vector2f(20,20));
		block.setFillColor(sf::Color::Red);
		block.move(x, y);

		_app->draw(block);
	}
}

void Snake::grow()
{
	_snake.push_back(Block(_snake.back().getX(), _snake.back().getY()));
}

void Snake::shrink()
{
	_snake.pop_back();
}

list<Block> Snake::getBlocks()
{
	return _snake;
}

int Snake::getX()
{
	return _snake.front().getX();
}

int Snake::getY()
{
	return _snake.front().getY();
}