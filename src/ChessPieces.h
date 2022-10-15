#ifndef CHESS_PIECES_H
#define CHESS_PIECES_H

#include <SFML/Graphics/RenderWindow.hpp>
#include "SettingsProvider.h"

enum PIECE_COLOR
{
	EWhite,
	EBlack
};


class ChessPiece
{
public:
	ChessPiece(const PIECE_COLOR& color) : m_color(color), m_isSelected(false)
	{}

	virtual void showMoves(sf::RenderWindow& window, std::vector<std::vector<ChessPiece*>> board) = 0;
	virtual void draw(sf::RenderWindow& window, const double& x, const double& y) = 0;
	virtual void makeMove(sf::RenderWindow& window, std::vector<std::vector<ChessPiece*>>& board, const double& x, const double& y) = 0;

	double getX() const
	{
		return m_x;
	}
	double getY() const
	{
		return m_y;
	}

	void setSelected(bool isSelected)
	{
		m_isSelected = isSelected;
	}
	bool getSelected() const
	{
		return m_isSelected;
	}

	PIECE_COLOR getColor() const
	{
		return m_color;
	}

protected:
	double m_x;
	double m_y;

	bool m_firstMove;

	PIECE_COLOR m_color;

	bool m_isSelected;
};

class Pawn : public ChessPiece
{
public:
	explicit Pawn(const PIECE_COLOR& color) : ChessPiece(color), m_firstMove(true)
	{}

	void showMoves(sf::RenderWindow& window, std::vector<std::vector<ChessPiece*>> board) override;
	void draw(sf::RenderWindow& window, const double& x, const double& y) override;
	void makeMove(sf::RenderWindow& window, std::vector<std::vector<ChessPiece*>>& board, const double& x, const double& y) override;

private:
	std::string m_filepath = SettingsProvider::getInstance().getResImgPath() + "Chess_plt60.png";

	bool m_firstMove;
};

class Rook : public ChessPiece
{
public:
	explicit Rook(const PIECE_COLOR& color) : ChessPiece(color)
	{}

	void showMoves(sf::RenderWindow& window, std::vector<std::vector<ChessPiece*>> board) override;
	void draw(sf::RenderWindow& window, const double& x, const double& y) override;
	void makeMove(sf::RenderWindow& window, std::vector<std::vector<ChessPiece*>>& board, const double& x, const double& y) override;

private:
	std::string m_filepath = SettingsProvider::getInstance().getResImgPath() + "Chess_rlt60.png";
};

class Knight : public ChessPiece
{
public:
	explicit Knight(const PIECE_COLOR& color) : ChessPiece(color)
	{}

	void showMoves(sf::RenderWindow& window, std::vector<std::vector<ChessPiece*>> board) override;
	void draw(sf::RenderWindow& window, const double& x, const double& y) override;
	void makeMove(sf::RenderWindow& window, std::vector<std::vector<ChessPiece*>>& board, const double& x, const double& y) override;

private:
	std::string m_filepath = SettingsProvider::getInstance().getResImgPath() + "Chess_nlt60.png";
};

class Bishop : public ChessPiece
{
public:
	explicit Bishop(const PIECE_COLOR& color) : ChessPiece(color)
	{}

	void showMoves(sf::RenderWindow& window, std::vector<std::vector<ChessPiece*>> board) override;
	void draw(sf::RenderWindow& window, const double& x, const double& y) override;
	void makeMove(sf::RenderWindow& window, std::vector<std::vector<ChessPiece*>>& board, const double& x, const double& y) override;

protected:
	std::string m_filepath = SettingsProvider::getInstance().getResImgPath() + "Chess_blt60.png";
};

class Queen : public ChessPiece
{
public:
	explicit Queen(const PIECE_COLOR& color) : ChessPiece(color)
	{}

	void showMoves(sf::RenderWindow& window, std::vector<std::vector<ChessPiece*>> board) override;
	void draw(sf::RenderWindow& window, const double& x, const double& y) override;
	void makeMove(sf::RenderWindow& window, std::vector<std::vector<ChessPiece*>>& board, const double& x, const double& y) override;

private:
	std::string m_filepath = SettingsProvider::getInstance().getResImgPath() + "Chess_qlt60.png";

	double m_x;
	double m_y;

	PIECE_COLOR m_color;
	bool m_isSelected;
};

class King : public ChessPiece
{
public:
	explicit King(const PIECE_COLOR& color) : ChessPiece(color)
	{}

	void showMoves(sf::RenderWindow& window, std::vector<std::vector<ChessPiece*>> board) override;
	void draw(sf::RenderWindow& window, const double& x, const double& y) override;
	void makeMove(sf::RenderWindow& window, std::vector<std::vector<ChessPiece*>>& board, const double& x, const double& y) override;

private:
	std::string m_filepath = SettingsProvider::getInstance().getResImgPath() + "Chess_klt60.png";
};

#endif