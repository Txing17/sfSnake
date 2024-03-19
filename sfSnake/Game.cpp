#include <SFML/Graphics.hpp>
#include <cstdlib>
#include <memory>
#include <string>
#include "MenuScreen.h"
#include "Game.h"

using namespace sfSnake;

const sf::Time Game::TimePerFrame = sf::seconds(1.f / 10.f);

//由于使用相当路径时总是打不开文件，因而使用了绝对路径
std::shared_ptr<Screen> Game::Screen = std::make_shared<MenuScreen>();
std::string Game::back_loc[3] = { "D:/cproject/Snake2/Images/white_back.png","D:/cproject/Snake2/Images/black_back.png","D:/cproject/Snake2/Images/brown_back.png" };
std::string Game::cell_loc[3] = { "D:/cproject/Snake2/Images/white_cells.png","D:/cproject/Snake2/Images/black_cells.png","D:/cproject/Snake2/Images/brown_cells.png" };
std::string Game::snakebody_loc[3] = { "D:/cproject/Snake2/Images/pink_node.png","D:/cproject/Snake2/Images/yellow_node.png","D:/cproject/Snake2/Images/node.png" };
std::string Game::snakehead_loc[3] = { "D:/cproject/Snake2/Images/pink_head.png","D:/cproject/Snake2/Images/yellow_head.png","D:/cproject/Snake2/Images/head.png" };

Game::Game()
	: window_(sf::VideoMode(Game::Width, Game::Height), "sfSnake")
{
	bgMusic_.openFromFile("D:/cproject/Snake2/Music/bg_music.wav");
	bgMusic_.setLoop(true);
	bgMusic_.play();
}

sf::Vector2i Game::window_pos()
{
	return window_.getPosition();
}

void Game::handleInput()
{
	sf::Event event;

	while (window_.pollEvent(event))
	{
		if (event.type == sf::Event::Closed)
			window_.close();
	}

	Game::Screen->handleInput(window_);
}

void Game::update(sf::Time delta)
{
	Game::Screen->update(delta);
}

void Game::render()
{
	window_.clear();
	Game::Screen->render(window_);
	window_.display();
}

void Game::run()
{
	sf::Clock clock;
	sf::Time timeSinceLastUpdate = sf::Time::Zero;

	while (window_.isOpen())
	{
		sf::Time delta = clock.restart();
		timeSinceLastUpdate += delta;

		while (timeSinceLastUpdate > Game::TimePerFrame)
		{
			timeSinceLastUpdate -= TimePerFrame;
			handleInput();
			update(TimePerFrame);
		}

		render();
	}
}