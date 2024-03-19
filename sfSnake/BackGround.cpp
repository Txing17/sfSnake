#include <SFML/Graphics.hpp>
#include "BackGround.h"
#include "Game.h"
#include "orMenuScreen.h"

using namespace sfSnake;
sf::Texture tex_cell, tex_back;
BackGround::BackGround()
{
    setCellColor();
    setBackColor();
}
//设置网格颜色
void BackGround::setCellColor()
{
    tex_cell.loadFromFile(Game::cell_loc[orMenuScreen::cell_choose]);
    cell_.setTexture(tex_cell);
    cell_.setPosition(0.0f, 0.0f);
}
//设置背景颜色
void BackGround::setBackColor()
{
    tex_back.loadFromFile(Game::back_loc[orMenuScreen::back_choose]);
    back_.setTexture(tex_back);
    back_.setPosition(0.0f, 0.0f);
}

void BackGround::drawCell(sf::RenderWindow& window)
{
    window.draw(cell_);
}
void BackGround::drawBack(sf::RenderWindow& window)
{
    window.draw(back_);
}

