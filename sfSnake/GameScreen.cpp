#include <SFML/Graphics.hpp>

#include <cstdlib>
#include <random>
#include <memory>
#include <iostream>

#include "GameScreen.h"
#include "GameOverScreen.h"
#include "Game.h"

using namespace sfSnake;

GameScreen::GameScreen() : snake_(), back_ground_()
{

}

void GameScreen::handleInput(sf::RenderWindow& window)
{
	snake_.handleInput(window);
}

void GameScreen::update(sf::Time delta)
{
	snake_.update(delta);
	snake_.checkFruitCollisions(fruit_);

	if (snake_.hitSelf()) {
		Game::Screen = std::make_shared<GameOverScreen>(snake_.getSize());
	}
	while (fruit_.size() < 5)//保持水果数量大于5
		generateFruit();
}

void GameScreen::render(sf::RenderWindow& window)
{
	back_ground_.drawBack(window);
	back_ground_.drawCell(window);
	snake_.render(window);

	for (auto fruit : fruit_)
		fruit.render(window);
}

void GameScreen::generateFruit()
{
	static std::random_device rd;
	static std::default_random_engine engine(rd());
	static std::uniform_int_distribution<int> xDistribution(0, Game::Width - SnakeNode::Width);
	static std::uniform_int_distribution<int> yDistribution(0, Game::Height - SnakeNode::Height);

	fruit_.push_back(Fruit(sf::Vector2f(xDistribution(engine), yDistribution(engine))));
}

