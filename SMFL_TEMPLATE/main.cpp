/*
 *  main.cpp
 *  snake
 *
 *  Created by Mathieu Allaire on 11-01-23.
 *  Copyright 2011 mathieuallaire.ca. All rights reserved.
 *
 */

#include <iostream>
#include <list>
#include <SFML/Graphics.hpp>
#include <thread>

#include "block.hpp"
#include "snake.hpp"
#include "fruit.hpp"

using namespace std;

void foo(Snake &snake) {
	snake.move();
	snake.draw();

}


int main()
{
	int ct_n = thread::hardware_concurrency();
	thread threads[5];
	cout << ct_n;

	// Window
	sf::RenderWindow app(sf::VideoMode(750, 625), "Snake 1.0 par Mathieu Allaire", sf::Style::Close);
	app.setFramerateLimit(12);

	// The snake himself
	Snake snakes[5] = {
		Snake(app),
		Snake(app),
		Snake(app),
		Snake(app),
		Snake(app)
	};



	// All the blocks that build up the snake
	list<Block> blocks;
	list<Block>::iterator it;

	// Direction of the snake
	enum direction { UP, RIGHT, DOWN, LEFT };
	int direction = RIGHT;

	// The fruit himself
	Fruit fruit(app);

	// Tells if we need to respawn a fruit
	bool mustSpawnFruit = true;

	// Coords of the fruit
	int fruitX;
	int fruitY;

	while (app.isOpen())
	{
		app.clear();


		for (int i = 0; i < 5; i++) {
			threads[i] = thread(foo,ref(snakes[i]));
		}
		for (int i = 0; i < 5; i++) {
			threads[i].join();
		}


		app.display();
	}

	return EXIT_SUCCESS;
}