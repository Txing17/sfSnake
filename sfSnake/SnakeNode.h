#pragma once
#ifndef SNAKE_NODE_H
#define SNAKE_NODE_H

#include <SFML/Graphics.hpp>

namespace sfSnake
{
	class SnakeNode
	{
	public:
		SnakeNode(sf::Vector2f position = sf::Vector2f(0, 0), int indx = 1, sf::Vector2f direction = sf::Vector2f(0, -1));

		void setPosition(sf::Vector2f position);
		void setDirection(sf::Vector2f position);
		void setPosition(float x, float y);

		void move(float xOffset, float yOffset);

		void render(sf::RenderWindow& window);

		sf::Vector2f getPosition() const;
		sf::Vector2f getDirection() const;
		sf::FloatRect getBounds() const;

		static const float Width;
		static const float Height;

	private:
		sf::Vector2f position_, direction_;
		sf::Sprite sprite_;
	};
}

#endif