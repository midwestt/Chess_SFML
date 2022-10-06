#ifndef CHESS_PIECES_H
#define CHESS_PIECES_H

#include <SFML/Graphics/RenderWindow.hpp>
#include "SettingsProvider.h"

enum PIECE_COLOR
{
	EWhite,
	EBlack
};


class IChessPiece
{
public:
	virtual void showMoves(sf::RenderWindow& window) = 0;
	virtual void draw(sf::RenderWindow& window, const double& x, const double& y) = 0;

	virtual double getX() const = 0;
	virtual double getY() const = 0;

	virtual PIECE_COLOR getColor() const = 0;
};

class Pawn : public IChessPiece
{
public:
	explicit Pawn(const PIECE_COLOR& color) : m_color(color)
	{}

	void showMoves(sf::RenderWindow& window) override;
	void draw(sf::RenderWindow& window, const double& x, const double& y) override;

	PIECE_COLOR getColor() const override;

	double getX() const override;
	double getY() const override;

protected:
	std::string m_filepath = SettingsProvider::getInstance().getResImgPath() + "Chess_plt60.png";

	double m_x;
	double m_y;

	PIECE_COLOR m_color;
};

class Rook : public IChessPiece
{
public:
	explicit Rook(const PIECE_COLOR& color) : m_color(color)
	{}

	void showMoves(sf::RenderWindow& window) override;
	void draw(sf::RenderWindow& window, const double& x, const double& y) override;

	double getX() const override;
	double getY() const override;

	PIECE_COLOR getColor() const override;

protected:
	std::string m_filepath = SettingsProvider::getInstance().getResImgPath() + "Chess_rlt60.png";

	double m_x;
	double m_y;

	PIECE_COLOR m_color;
};

class Knight : public IChessPiece
{
public:
	explicit Knight(const PIECE_COLOR& color) : m_color(color)
	{}

	void showMoves(sf::RenderWindow& window) override;
	void draw(sf::RenderWindow& window, const double& x, const double& y) override;

	double getX() const override;
	double getY() const override;
	
	PIECE_COLOR getColor() const override;

private:
	std::string m_filepath = SettingsProvider::getInstance().getResImgPath() + "Chess_nlt60.png";

	double m_x;
	double m_y;

	PIECE_COLOR m_color;
};

class Bishop : public IChessPiece
{
public:
	explicit Bishop(const PIECE_COLOR& color) : m_color(color)
	{}

	void showMoves(sf::RenderWindow& window) override;
	void draw(sf::RenderWindow& window, const double& x, const double& y) override;

	double getX() const override;
	double getY() const override;
	
	PIECE_COLOR getColor() const override;

protected:
	std::string m_filepath = SettingsProvider::getInstance().getResImgPath() + "Chess_blt60.png";

	double m_x;
	double m_y;

	PIECE_COLOR m_color;
};

class Queen : public IChessPiece
{
public:
	explicit Queen(const PIECE_COLOR& color) : m_color(color)
	{}

	void showMoves(sf::RenderWindow& window) override;
	void draw(sf::RenderWindow& window, const double& x, const double& y) override;

	double getX() const override;
	double getY() const override;

	PIECE_COLOR getColor() const override;

private:
	std::string m_filepath = SettingsProvider::getInstance().getResImgPath() + "Chess_qlt60.png";

	double m_x;
	double m_y;

	PIECE_COLOR m_color;
};

class King : public IChessPiece
{
public:
	explicit King(const PIECE_COLOR& color) : m_color(color)
	{}

	void showMoves(sf::RenderWindow& window) override;
	void draw(sf::RenderWindow& window, const double& x, const double& y) override;

	double getX() const override;
	double getY() const override;

	PIECE_COLOR getColor() const override;

private:
	std::string m_filepath = SettingsProvider::getInstance().getResImgPath() + "Chess_klt60.png";
	double m_x;
	double m_y;

	PIECE_COLOR m_color;
};

#endif