#pragma once

#include <array>
#include <vector>
#include "Const.h"
#include "Piece.h"

using FieldMatrix = std::array<std::array<int, FIELD_WIDTH>, FIELD_HEIGHT>;

// сделать const методы те которые должны быть
// класс игры не должен знать про клавиши, сделать enum
// уменьшить количество публичных методов, сделать Tick
// неудобно управлять
class Game
{
public:
	Game();

	void AddPiece(const Piece& piece);
	void MovingPieceByGame();
	void MovingPieceByUser(const char& key);
	void RotatePiece();
	void ClearLines();

	void Clear();

	void SetNextPiece();
	void SetCurrentPiece();
	void SetNeededNewPiece();
	void ResetScore();
	void ResetLevel();
	void ResetSpeed();
	void ResetLinesLeft();

	void Pause();
	void Unpause();

	bool IsPaused();
	Piece GetCurrentPiece();
	Piece GetNextPiece();
	Piece GetRandomPiece();
	FieldMatrix GetMatrix() const;
	int GetLevel() const;
	int GetScore() const;
	int GetLinesLeft() const;
	int GetSpeed() const;
	bool IsNeededNewPiece();
	bool IsNoWallDown();
	bool IsNoWallRight();
	bool IsNoWallLeft();
	bool IsFull();
	bool IsPossibleRotate();
	bool IsNeededClearLines();

private:
	void MoveAllDown(const int& fromLine);
	void MovingPieceLeft();
	void MovingPieceRight();

	FieldMatrix m_matrix;
	bool m_isNeededNewPiece = true;
	Piece m_currentPiece;
	Piece m_nextPiece;
	int m_level = GAME_LEVEL_1;
	int m_score = 0;
	int m_linesLeft = GAME_LINES_LEFT_1; 
	std::array<int, MAX_REMOVED_LINES> m_lineIndexes = { -1, -1, -1, -1 };
	int m_lineIndexesCount = 0;
	bool m_isPaused = false;
	int m_speed = GAME_SPEED_LEVEL_1;
};
