#include "ChessPieces.h"
#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/RectangleShape.hpp>


void drawSprite(sf::RenderWindow& window, const double& x, const double& y, const std::string& filepath)
{
	sf::Texture texture{};
	if (!texture.loadFromFile(filepath))
	{
		return;
	}

	sf::Sprite sprite;
	sprite.setTexture(texture);
	sprite.setPosition(x, y);
	window.draw(sprite);
}

void Pawn::draw(sf::RenderWindow& window, const double& x, const double& y)
{
	const std::string filename = m_color == EWhite ? "Chess_plt60.png" : "Chess_pdt60.png";
	m_filepath = SettingsProvider::getInstance().getResImgPath() + filename;

	m_x = x;
	m_y = y;
	drawSprite(window, x, y, m_filepath);
}

void Pawn::showMoves(sf::RenderWindow& window)
{
	sf::RectangleShape rectangle(sf::Vector2f(SettingsProvider::getInstance().getRectSize(), SettingsProvider::getInstance().getRectSize()));
	rectangle.setPosition(m_x, m_y);
	rectangle.setFillColor({ 0, 100, 0 , 100});
	rectangle.setOutlineColor({ 255, 255, 255 });

	window.draw(rectangle);
}

double Pawn::getX() const
{
	return m_x;
}

double Pawn::getY() const
{
	return m_y;
}

PIECE_COLOR Pawn::getColor() const
{
	return m_color;
}


void Rook::draw(sf::RenderWindow& window, const double& x, const double& y)
{
	const std::string filename = m_color == EWhite ? "Chess_rlt60.png" : "Chess_rdt60.png";
	m_filepath = SettingsProvider::getInstance().getResImgPath() + filename;

	m_x = x;
	m_y = y;
	drawSprite(window, x, y, m_filepath);
}

void Rook::showMoves(sf::RenderWindow& window)
{
	
}
double Rook::getX() const
{
	return m_x;
}

double Rook::getY() const
{
	return m_y;
}

PIECE_COLOR Rook::getColor() const
{
	return m_color;
}

void Knight::draw(sf::RenderWindow& window, const double& x, const double& y)
{
	const std::string filename = m_color == EWhite ? "Chess_nlt60.png" : "Chess_ndt60.png";
	m_filepath = SettingsProvider::getInstance().getResImgPath() + filename;

	m_x = x;
	m_y = y;
	drawSprite(window, x, y, m_filepath);
}

void Knight::showMoves(sf::RenderWindow& window)
{

}

double Knight::getX() const
{
	return m_x;
}

double Knight::getY() const
{
	return m_y;
}

PIECE_COLOR Knight::getColor() const
{
	return m_color;
}

void Bishop::draw(sf::RenderWindow& window, const double& x, const double& y)
{
	const std::string filename = m_color == EWhite ? "Chess_blt60.png" : "Chess_bdt60.png";
	m_filepath = SettingsProvider::getInstance().getResImgPath() + filename;

	m_x = x;
	m_y = y;
	drawSprite(window, x, y, m_filepath);
}

void Bishop::showMoves(sf::RenderWindow& window)
{

}

double Bishop::getX() const
{
	return m_x;
}

double Bishop::getY() const
{
	return m_y;
}

PIECE_COLOR Bishop::getColor() const
{
	return m_color;
}

void Queen::draw(sf::RenderWindow& window, const double& x, const double& y)
{
	const std::string filename = m_color == EWhite ? "Chess_qlt60.png" : "Chess_qdt60.png";
	m_filepath = SettingsProvider::getInstance().getResImgPath() + filename;

	m_x = x;
	m_y = y;
	drawSprite(window, x, y, m_filepath);
}

void Queen::showMoves(sf::RenderWindow& window)
{

}

double Queen::getX() const
{
	return m_x;
}

double Queen::getY() const
{
	return m_y;
}

PIECE_COLOR Queen::getColor() const
{
	return m_color;
}

void King::draw(sf::RenderWindow& window, const double& x, const double& y)
{
	const std::string filename = m_color == EWhite ? "Chess_klt60.png" : "Chess_kdt60.png";
	m_filepath = SettingsProvider::getInstance().getResImgPath() + filename;

	m_x = x;
	m_y = y;
	drawSprite(window, x, y, m_filepath);
}

void King::showMoves(sf::RenderWindow& window)
{

}

double King::getX() const
{
	return m_x;
}

double King::getY() const
{
	return m_y;
}

PIECE_COLOR King::getColor() const
{
	return m_color;
}