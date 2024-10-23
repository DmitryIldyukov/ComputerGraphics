#pragma once
#include "Const.h"
#include "Point.h"
#include <array>

using PieceContains = std::array<std::array<int, PIECE_WIDTH>, PIECE_HEIGHT>;

class Piece
{
public:
	Piece(const PieceContains& piece, const int& color);

	PieceContains GetContains() const;
	PointI GetCoords();
	int GetColor();

	void SetCoords(const PointI& newCoords);
	void SetContains(const PieceContains& newContains);
	
private:
	PieceContains m_contains;
	PointI m_coords;
	int m_color;
};

