#pragma once

#include <SFML/Graphics.hpp>

namespace sfSnake
{
    class BackGround
    {
    public:
        BackGround();
        void setCellColor();
        void setBackColor();
        void drawCell(sf::RenderWindow& window);
        void drawBack(sf::RenderWindow& window);
    private:
        sf::Color cell_color_, back_color_;
        sf::Sprite cell_, back_;
    };
}
