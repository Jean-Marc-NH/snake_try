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
#include <vector>

#include "block.hpp"
#include "snake.hpp"
#include "fruit.hpp"

using namespace std;

void foo(Snake &snake, int a) {
	snake.move(a);

}

int main()
{
	int ct_n = thread::hardware_concurrency()/5;
	vector<thread> ts(ct_n);
	vector<Snake> st(ct_n);
	cout << ct_n;

	// Window
	sf::RenderWindow app(sf::VideoMode(750, 625), "Snake", sf::Style::Close);
	app.setFramerateLimit(10);




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


	for (int i = 0; i < ct_n; i++) {
		st[i].grow();
		st[i].grow();
		st[i].grow();
		st[i].grow();
	}

	while (app.isOpen())
	{
		app.clear();

		for (int i = 0; i < ct_n; i++) {
			ts[i] = thread(foo, ref(st[i]), rand()%4);
		}

		for (int i = 0; i < ct_n; i++) {
			ts[i].join();
		}

		for (int i = 0; i < ct_n; i++) {
			st[i].draw(app, i%4);
		}


		app.display();

	}

	return EXIT_SUCCESS;
}