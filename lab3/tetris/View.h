#pragma once
#include "Point.h"
#include "Game.h"

class View
{
public:
	View(Game& field);
	void DrawUI();

private:
	void DrawInfoPanel();
	void DrawField();
	void DrawSquare(const PointF& coords, const int& color);
	void DrawScore(PointF coords);
	void DrawLevel(PointF coords);
	void DrawLinesLeft(PointF coords);

	void DrawL(const PointF& coords);
	void DrawE(const PointF& coords);
	void DrawV(const PointF& coords);
	void DrawI(const PointF& coords);
	void DrawN(const PointF& coords);
	void DrawS(const PointF& coords);
	void DrawF(const PointF& coords);
	void DrawT(const PointF& coords);
	void DrawC(const PointF& coords);
	void DrawO(const PointF& coords);
	void DrawR(const PointF& coords);
	void DrawX(const PointF& coords);

	void Draw0(const PointF& coords);
	void Draw1(const PointF& coords);
	void Draw2(const PointF& coords);
	void Draw3(const PointF& coords);
	void Draw4(const PointF& coords);
	void Draw5(const PointF& coords);
	void Draw6(const PointF& coords);
	void Draw7(const PointF& coords);
	void Draw8(const PointF& coords);
	void Draw9(const PointF& coords);

	void DrawDigit(const PointF& coords, const int& digit);
	void DrawColon(const PointF& coords);
	void DrawNextPiece(const PointF& coords);
	void DrawScoreNumber(PointF& coords);
	void DrawLevelNumber(const PointF& coords);
	void DrawLinesLeftNumber(PointF& coords);
	void DrawNextText(PointF& coords);

	Game& m_game;
};
