#include "ChessPieces.h"
#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/Sprite.hpp>


void drawSprite(sf::RenderWindow& window, const double& x, const double& y, const std::string& filepath)
{
	sf::Texture texture{};
	if (!texture.loadFromFile(filepath))
	{
		texture;
		return;
	}

	sf::Sprite sprite;
	sprite.setTexture(texture);
	sprite.setPosition(x, y);
	window.draw(sprite);
}

void WhitePawn::draw(sf::RenderWindow& window, const double& x, const double& y)
{
	m_x = x;
	m_y = y;
	drawSprite(window, x, y, m_filepath);
}

void WhitePawn::showMoves()
{
	
}

void WhiteRook::draw(sf::RenderWindow& window, const double& x, const double& y)
{
	m_x = x;
	m_y = y;
	drawSprite(window, x, y, m_filepath);
}

void WhiteRook::showMoves()
{
	
}

void WhiteKnight::draw(sf::RenderWindow& window, const double& x, const double& y)
{
	m_x = x;
	m_y = y;
	drawSprite(window, x, y, m_filepath);
}

void WhiteKnight::showMoves()
{

}

void WhiteBishop::draw(sf::RenderWindow& window, const double& x, const double& y)
{
	m_x = x;
	m_y = y;
	drawSprite(window, x, y, m_filepath);
}

void WhiteBishop::showMoves()
{

}

void WhiteQueen::draw(sf::RenderWindow& window, const double& x, const double& y)
{
	m_x = x;
	m_y = y;
	drawSprite(window, x, y, m_filepath);
}

void WhiteQueen::showMoves()
{

}

void WhiteKing::draw(sf::RenderWindow& window, const double& x, const double& y)
{
	m_x = x;
	m_y = y;
	drawSprite(window, x, y, m_filepath);
}

void WhiteKing::showMoves()
{

}

void BlackPawn::draw(sf::RenderWindow& window, const double& x, const double& y)
{
	m_x = x;
	m_y = y;
	drawSprite(window, x, y, m_filepath);
}

void BlackPawn::showMoves()
{

}

void BlackRook::draw(sf::RenderWindow& window, const double& x, const double& y)
{
	m_x = x;
	m_y = y;
	drawSprite(window, x, y, m_filepath);
}

void BlackRook::showMoves()
{

}

void BlackKnight::draw(sf::RenderWindow& window, const double& x, const double& y)
{
	m_x = x;
	m_y = y;
	drawSprite(window, x, y, m_filepath);
}

void BlackKnight::showMoves()
{

}

void BlackBishop::draw(sf::RenderWindow& window, const double& x, const double& y)
{
	m_x = x;
	m_y = y;
	drawSprite(window, x, y, m_filepath);
}

void BlackBishop::showMoves()
{

}

void BlackQueen::draw(sf::RenderWindow& window, const double& x, const double& y)
{
	m_x = x;
	m_y = y;
	drawSprite(window, x, y, m_filepath);
}

void BlackQueen::showMoves()
{

}

void BlackKing::draw(sf::RenderWindow& window, const double& x, const double& y)
{
	m_x = x;
	m_y = y;
	drawSprite(window, x, y, m_filepath);
}

void BlackKing::showMoves()
{

}