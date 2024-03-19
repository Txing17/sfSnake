#include <SFML/Graphics.hpp>
#include <iostream>
#include <cmath>
#include "SnakeNode.h"
#include "orMenuScreen.h"
#include "Game.h"

using namespace sfSnake;

const float SnakeNode::Width = 20.0f;
const float SnakeNode::Height = 20.0f;

sf::Texture body_tex;
sf::Texture head_tex;

SnakeNode::SnakeNode(sf::Vector2f position, int indx, sf::Vector2f direction)
    : position_(position), direction_(direction)
{

    if (!body_tex.loadFromFile(Game::snakebody_loc[orMenuScreen::snake_choose]))
    {
        std::cout << "Failed to load snakenodes' picture" << std::endl;
    }
    if (!head_tex.loadFromFile(Game::snakehead_loc[orMenuScreen::snake_choose]))
    {
        std::cout << "Failed to load snakehead's picture" << std::endl;
    }
    sprite_.setTexture(indx == 0 ? head_tex : body_tex);
    sprite_.setPosition(position);
    sprite_.setOrigin(Width / 2, Height / 2);
    sprite_.setRotation(std::atan2(direction.y, direction.x) / (2 * 3.1415926535) * 360.0 + 90.0);
}

void SnakeNode::setPosition(sf::Vector2f position)
{
    position_ = position;
    sprite_.setPosition(position_);
}
void SnakeNode::setDirection(sf::Vector2f direction)
{
    direction_ = direction;
    sprite_.setRotation(std::atan2(direction.y, direction.x) / (2 * 3.1415926) * 360.0 + 90.0);
}
void SnakeNode::setPosition(float x, float y)
{
    position_.x = x;
    position_.y = y;
    sprite_.setPosition(position_);
}


void SnakeNode::move(float xOffset, float yOffset)
{
    position_.x += xOffset;
    position_.y += yOffset;
    sprite_.setPosition(position_);
    setDirection(sf::Vector2f(xOffset, yOffset));
}

sf::FloatRect SnakeNode::getBounds() const
{
    return sprite_.getGlobalBounds();
}

sf::Vector2f SnakeNode::getPosition() const
{
    return position_;
}
sf::Vector2f SnakeNode::getDirection() const
{
    return direction_;
}

void SnakeNode::render(sf::RenderWindow& window)
{
    window.draw(sprite_);
}
