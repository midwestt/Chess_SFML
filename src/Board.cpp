#include "Board.h"

#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/RectangleShape.hpp>


Board::Board() : m_rectSize(SettingsProvider::getInstance().getRectSize())
{}

void Board::draw(sf::RenderWindow& window)
{
	bool isBlack;
	double x = 0;
	double y = 0;
	for (int i = 0; i < m_boardMatrix.size(); ++i)
	{
		isBlack = i % 2 == 0;

		for (int j = 0; j < m_boardMatrix[i].size(); ++j)
		{
			sf::RectangleShape rectangle(sf::Vector2f(m_rectSize, m_rectSize));
			rectangle.setPosition(x, y);
			if (isBlack)
			{
				rectangle.setFillColor({ 255, 137, 81 });
				isBlack = false;
			}
			else
			{
				rectangle.setFillColor({ 255, 215, 174 });
				isBlack = true;
			}
			window.draw(rectangle);

			if (m_boardMatrix[i][j])
			{
				m_boardMatrix[i][j]->draw(window, x, y);
			}

			x += m_rectSize;
		}

		y += m_rectSize;
		x = 0;
	}
}