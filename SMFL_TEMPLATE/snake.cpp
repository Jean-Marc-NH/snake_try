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

Snake::Snake()
{
	_direction = RIGHT;

	// Draws the initial snake
	_snake.push_front(Block(25, 0));
	_snake.push_front(Block(100, 0));
}


void Snake::move(int random)
{
	shrink();
	
	_direction = random;

	if (random == 0)
	{
		if (_direction != 2)
		{
			_snake.push_front(Block(_snake.front().getX(), _snake.front().getY() - 25));
			_direction = 0;
		}
		else
		{
			_snake.push_front(Block(_snake.front().getX(), _snake.front().getY() + 25));
		}
	}

	else if (random == 3)
	{
		if (_direction != 1)
		{
			_snake.push_front(Block(_snake.front().getX() + 25, _snake.front().getY()));
			_direction = 3;
		}
		else
		{
			_snake.push_front(Block(_snake.front().getX() - 25, _snake.front().getY()));
		}
	}

	else if (random == 2)
	{
		if (_direction != 0)
		{
			_snake.push_front(Block(_snake.front().getX(), _snake.front().getY() + 25));
			_direction = 2;
		}
		else
		{
			_snake.push_front(Block(_snake.front().getX(), _snake.front().getY() - 25));
		}

	}

	else if (random == 1)
	{
		if (_direction != 3)
		{
			_snake.push_front(Block(_snake.front().getX() - 25, _snake.front().getY()));
			_direction = 1;
		}
		else
		{
			_snake.push_front(Block(_snake.front().getX() + 25, _snake.front().getY()));
		}
	}
}

void Snake::draw(sf::RenderWindow& App, int a)
{
	for (list<Block>::iterator it = _snake.begin(); it != _snake.end(); it++)
	{
		float x = it->getX();
		float y = it->getY();

		sf::RectangleShape block(sf::Vector2f(20,20));

		if (a == 0) {
			block.setFillColor(sf::Color::Red);
		}
		else if (a == 1) {
			block.setFillColor(sf::Color::White);
		}else if (a == 2) {
			block.setFillColor(sf::Color::Yellow);
		}else if (a == 3) {
			block.setFillColor(sf::Color::Blue);
		}

		block.move(x, y);

		App.draw(block);
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