#include "Board.h"

#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/RectangleShape.hpp>
#include <iostream>


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

void Board::showHighlights(sf::RenderWindow& window, const double& x, const double& y)
{
	for (int i = 0; i < 8; ++i)
	{
		for (int j = 0; j < 8; ++j)
		{
			if (m_boardMatrix[i][j] 
				&& (m_boardMatrix[i][j]->getX() <= x && m_boardMatrix[i][j]->getX() + m_rectSize >= x)
				&& (m_boardMatrix[i][j]->getY() <= y && m_boardMatrix[i][j]->getY() + m_rectSize >= y))
			{
				m_boardMatrix[i][j]->showMoves(window);
			}
		}
	}
}
