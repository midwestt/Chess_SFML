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

void Pawn::showMoves(sf::RenderWindow& window, std::vector<std::vector<ChessPiece*>> board)
{
	int piece_x = m_x / SettingsProvider::getInstance().getRectSize();
	int piece_y = m_y / SettingsProvider::getInstance().getRectSize();

	if (piece_y >= 7)
		return;

	int numOfMoves = m_firstMove ? 3 : 2;

	for (int i = 1; i < numOfMoves; ++i)
	{
		int y_pos;

		if (getColor() == EBlack)
		{
			if (piece_y + i > 7)
				continue;

			if (board[piece_y + i][piece_x] != nullptr)
				continue;

			y_pos = m_y + (i * SettingsProvider::getInstance().getRectSize());
		}
		else
		{
			if (piece_y - i < 0)
				continue;

			if (board[piece_y - i][piece_x] != nullptr)
				continue;

			y_pos = m_y - (i * SettingsProvider::getInstance().getRectSize());
		}

		drawRectangle(window, sf::Color{ 0, 100, 0, 70 }, m_x, y_pos);
	}

	if (getColor() == EWhite)
	{
		if (piece_x == 0)
		{
			if (board[piece_y - 1][piece_x + 1] != nullptr && getColor() != board[piece_y - 1][piece_x + 1]->getColor())
			{
				int x = m_x + SettingsProvider::getInstance().getRectSize();
				int y = m_y - SettingsProvider::getInstance().getRectSize();

				drawRectangle(window, sf::Color{ 150, 0, 0, 70 }, x, y);

			}

			return;
		}
		else if (piece_x == 7)
		{
			if (board[piece_y - 1][piece_x - 1] != nullptr && getColor() != board[piece_y - 1][piece_x - 1]->getColor())
			{
				int x = m_x - SettingsProvider::getInstance().getRectSize();
				int y = m_y - SettingsProvider::getInstance().getRectSize();

				drawRectangle(window, sf::Color{ 150, 0, 0, 70 }, x, y);
			}

			return;
		}
		else
		{
			if (board[piece_y - 1][piece_x + 1] != nullptr && getColor() != board[piece_y - 1][piece_x + 1]->getColor())
			{
				int x = m_x + SettingsProvider::getInstance().getRectSize();
				int y = m_y - SettingsProvider::getInstance().getRectSize();
				drawRectangle(window, sf::Color{ 150, 0, 0, 70 }, x, y);
			}
			if (board[piece_y - 1][piece_x - 1] != nullptr && getColor() != board[piece_y - 1][piece_x - 1]->getColor())
			{
				int x = m_x - SettingsProvider::getInstance().getRectSize();
				int y = m_y - SettingsProvider::getInstance().getRectSize();
				drawRectangle(window, sf::Color{ 150, 0, 0, 70 }, x, y);
			}
		}
	}
	else if (getColor() == EBlack)
	{
		if (piece_x == 0)
		{
			if (board[piece_y + 1][piece_x + 1] != nullptr && getColor() != board[piece_y + 1][piece_x + 1]->getColor())
			{
				int x = m_x + SettingsProvider::getInstance().getRectSize();
				int y = m_y + SettingsProvider::getInstance().getRectSize();

				drawRectangle(window, sf::Color{ 150, 0, 0, 70 }, x, y);

			}

			return;
		}
		else if (piece_x == 7)
		{
			if (board[piece_y + 1][piece_x - 1] != nullptr && getColor() != board[piece_y + 1][piece_x - 1]->getColor())
			{
				int x = m_x - SettingsProvider::getInstance().getRectSize();
				int y = m_y + SettingsProvider::getInstance().getRectSize();

				drawRectangle(window, sf::Color{ 150, 0, 0, 70 }, x, y);
			}

			return;
		}
		else
		{
			if (board[piece_y + 1][piece_x + 1] != nullptr && getColor() != board[piece_y + 1][piece_x + 1]->getColor())
			{
				int x = m_x + SettingsProvider::getInstance().getRectSize();
				int y = m_y + SettingsProvider::getInstance().getRectSize();

				drawRectangle(window, sf::Color{ 150, 0, 0, 70 }, x, y);
			}
			if (board[piece_y + 1][piece_x - 1] != nullptr && getColor() != board[piece_y + 1][piece_x - 1]->getColor())
			{
				int x = m_x - SettingsProvider::getInstance().getRectSize();
				int y = m_y + SettingsProvider::getInstance().getRectSize();

				drawRectangle(window, sf::Color{ 150, 0, 0, 70 }, x, y);
			}
		}
	}
}

void Pawn::drawRectangle(sf::RenderWindow& window, sf::Color& color, const double& x, const double& y)
{
	sf::RectangleShape rectangle(sf::Vector2f(SettingsProvider::getInstance().getRectSize(), SettingsProvider::getInstance().getRectSize()));

	rectangle.setPosition(x, y);
	rectangle.setFillColor(color);

	window.draw(rectangle);
}

bool Pawn::makeMove(sf::RenderWindow& window, std::vector<std::vector<ChessPiece*>>& board, const double& x, const double& y)
{
	int piece_x = m_x / SettingsProvider::getInstance().getRectSize();
	int piece_y = m_y / SettingsProvider::getInstance().getRectSize();

	int new_x = x / SettingsProvider::getInstance().getRectSize();
	int new_y = y / SettingsProvider::getInstance().getRectSize();

	bool isAvailable = false;
	// Check if move is available
	if ((piece_x != new_x && std::abs(piece_x - new_x) != 1) || (piece_x == new_x && piece_y == new_y))
	{
		return false;
	}

	int moveCount = m_firstMove ? 2 : 1;
	if (getColor() == EBlack && new_y - piece_y <= moveCount && board[new_y][new_x] == nullptr)
	{
		std::swap(board[piece_y][piece_x], board[new_y][new_x]);

		if (m_firstMove)
			m_firstMove = false;

		return true;
	}
	if (getColor() == EWhite && piece_y - new_y <= moveCount && board[new_y][new_x] == nullptr)
	{
		std::swap(board[piece_y][piece_x], board[new_y][new_x]);

		if (m_firstMove)
			m_firstMove = false;

		return true;
	}
	// Take piece
	if (board[new_y][new_x] != nullptr && board[new_y][new_x]->getColor() != getColor())
	{
		auto tmp = board[piece_y][piece_x];
		board[piece_y][piece_x] = nullptr;
		board[new_y][new_x] = tmp;

		if (m_firstMove)
			m_firstMove = false;

		return true;
	}

	return false;
}

void Rook::draw(sf::RenderWindow& window, const double& x, const double& y)
{
	const std::string filename = m_color == EWhite ? "Chess_rlt60.png" : "Chess_rdt60.png";
	m_filepath = SettingsProvider::getInstance().getResImgPath() + filename;

	m_x = x;
	m_y = y;
	drawSprite(window, x, y, m_filepath);
}

void Rook::showMoves(sf::RenderWindow& window, std::vector<std::vector<ChessPiece*>> board)
{
	int piece_x = m_x / SettingsProvider::getInstance().getRectSize();
	int piece_y = m_y / SettingsProvider::getInstance().getRectSize();

	if (piece_y >= 7)
		return;

	for (int i = 0; i < 7; ++i)
	{
		int y_pos;

		if (m_y < 250)
		{
			if (piece_y + i > 7)
				continue;

			if (board[piece_y + i][piece_x] != nullptr)
				break;

			y_pos = m_y + (i * SettingsProvider::getInstance().getRectSize());
		}
		else
		{
			if (piece_y - i < 0)
				continue;

			if (board[piece_y - i][piece_x] != nullptr)
				continue;

			y_pos = m_y - (i * SettingsProvider::getInstance().getRectSize());
		}

		sf::RectangleShape rectangle(sf::Vector2f(SettingsProvider::getInstance().getRectSize(), SettingsProvider::getInstance().getRectSize()));

		rectangle.setPosition(m_x, y_pos);
		rectangle.setFillColor({ 0, 100, 0 , 70 });
		rectangle.setOutlineColor({ 255, 255, 255 });

		window.draw(rectangle);
	}
}

bool Rook::makeMove(sf::RenderWindow& window, std::vector<std::vector<ChessPiece*>>& board, const double& x, const double& y)
{
	return true;
}

void Knight::draw(sf::RenderWindow& window, const double& x, const double& y)
{
	const std::string filename = m_color == EWhite ? "Chess_nlt60.png" : "Chess_ndt60.png";
	m_filepath = SettingsProvider::getInstance().getResImgPath() + filename;

	m_x = x;
	m_y = y;
	drawSprite(window, x, y, m_filepath);
}

void Knight::showMoves(sf::RenderWindow& window, std::vector<std::vector<ChessPiece*>> board)
{

}

bool Knight::makeMove(sf::RenderWindow& window, std::vector<std::vector<ChessPiece*>>& board, const double& x, const double& y)
{
	return true;

}

void Bishop::draw(sf::RenderWindow& window, const double& x, const double& y)
{
	const std::string filename = m_color == EWhite ? "Chess_blt60.png" : "Chess_bdt60.png";
	m_filepath = SettingsProvider::getInstance().getResImgPath() + filename;

	m_x = x;
	m_y = y;
	drawSprite(window, x, y, m_filepath);
}

void Bishop::showMoves(sf::RenderWindow& window, std::vector<std::vector<ChessPiece*>> board)
{

}

bool Bishop::makeMove(sf::RenderWindow& window, std::vector<std::vector<ChessPiece*>>& board, const double& x, const double& y)
{
	return true;
}

void Queen::draw(sf::RenderWindow& window, const double& x, const double& y)
{
	const std::string filename = m_color == EWhite ? "Chess_qlt60.png" : "Chess_qdt60.png";
	m_filepath = SettingsProvider::getInstance().getResImgPath() + filename;

	m_x = x;
	m_y = y;
	drawSprite(window, x, y, m_filepath);
}

void Queen::showMoves(sf::RenderWindow& window, std::vector<std::vector<ChessPiece*>> board)
{

}

bool Queen::makeMove(sf::RenderWindow& window, std::vector<std::vector<ChessPiece*>>& board, const double& x, const double& y)
{
	return true;

}

void King::draw(sf::RenderWindow& window, const double& x, const double& y)
{
	const std::string filename = m_color == EWhite ? "Chess_klt60.png" : "Chess_kdt60.png";
	m_filepath = SettingsProvider::getInstance().getResImgPath() + filename;

	m_x = x;
	m_y = y;
	drawSprite(window, x, y, m_filepath);
}

void King::showMoves(sf::RenderWindow& window, std::vector<std::vector<ChessPiece*>> board)
{

}

bool King::makeMove(sf::RenderWindow& window, std::vector<std::vector<ChessPiece*>>& board, const double& x, const double& y)
{
	return true;

}