#include "Piece.h"

Piece::Piece(const PieceContains& piece, const int& color)
	: m_contains(piece)
	, m_coords(Point(START_POS_X, START_POS_Y))
	, m_color(color)
{
}

PieceContains Piece::GetContains() const
{
	return m_contains;
}

PointI Piece::GetCoords()
{
	return m_coords;
}

int Piece::GetColor()
{
	return m_color;
}

void Piece::SetCoords(const PointI& newCoords)
{
	m_coords = newCoords;
}

void Piece::SetContains(const PieceContains& newContains)
{
	m_contains = newContains;
}
