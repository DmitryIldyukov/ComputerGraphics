#include <GLFW/glfw3.h>
#include "View.h"

View::View(Game& game)
	: m_game(game)
{
}

void View::DrawUI()
{
	DrawInfoPanel();
	DrawField();
}

void View::DrawInfoPanel()
{
	PointF coords = { 0.15f, 0.5f };

	glColor3f(0.0f, 0.0f, 0.0f);
	glBegin(GL_LINES);

	DrawLevel(coords);

	coords.y -= 0.07f;
	DrawLinesLeft(coords);

	coords.y -= 0.07f;
	DrawScore(coords);

	coords.y -= 0.07f;
	DrawNextText(coords);

	glEnd();

	coords.x += 0.05f;
	DrawNextPiece(coords);
}

void View::DrawField()
{
	PointF pos = FIELD_LEFT_TOP;

	for (int i = 0; i < FIELD_HEIGHT; i++)
	{
		for (int j = 0; j < FIELD_WIDTH; j++)
		{
			DrawSquare(pos, m_game.GetMatrix().at(i).at(j));
			pos.x += 0.05f;
		}
		pos.x = FIELD_LEFT_TOP.x;
		pos.y -= 0.05f;
	}
	
}

void View::DrawSquare(const PointF& coords, const int& colorIndex)
{
	std::array<float, 3> color = COLORS.at(colorIndex);
	glColor3f(color.at(0), color.at(1), color.at(2));
	glBegin(GL_TRIANGLES);
	glVertex2f(coords.x, coords.y);
	glVertex2f(coords.x + 0.05f, coords.y);
	glVertex2f(coords.x, coords.y - 0.05f);
	glVertex2f(coords.x + 0.05f, coords.y);
	glVertex2f(coords.x + 0.05f, coords.y - 0.05f);
	glVertex2f(coords.x, coords.y - 0.05f);
	glEnd();

	glBegin(GL_LINE_LOOP);
	glColor3f(0.0f, 0.0f, 0.0f);
	glVertex2f(coords.x, coords.y);
	glVertex2f(coords.x + 0.05f, coords.y);
	glVertex2f(coords.x + 0.05f, coords.y - 0.05f);
	glVertex2f(coords.x, coords.y - 0.05f);
	glVertex2f(coords.x, coords.y);
	glEnd();
}

void View::DrawScore(PointF coords)
{
	DrawS(coords);
	coords.x += 0.05f;
	DrawC(coords);
	coords.x += 0.05f;
	DrawO(coords);
	coords.x += 0.05f;
	DrawR(coords);
	coords.x += 0.05f;
	DrawE(coords);

	coords.x += 0.025f;
	DrawColon(coords);

	coords.x += 0.05f;
	DrawScoreNumber(coords);
}

void View::DrawLevel(PointF coords)
{
	DrawL(coords);
	coords.x += 0.05f;
	DrawE(coords);
	coords.x += 0.05f;
	DrawV(coords);
	coords.x += 0.05f;
	DrawE(coords);
	coords.x += 0.05f;
	DrawL(coords);

	coords.x += 0.025f;
	DrawColon(coords);

	coords.x += 0.05f;
	DrawLevelNumber(coords);
}

void View::DrawLinesLeft(PointF coords)
{
	DrawL(coords);
	coords.x += 0.05f;
	DrawI(coords);
	coords.x += 0.05f;
	DrawN(coords);
	coords.x += 0.05f;
	DrawE(coords);
	coords.x += 0.05f;
	DrawS(coords);
	coords.x += 0.1f;

	DrawL(coords);
	coords.x += 0.05f;
	DrawE(coords);
	coords.x += 0.05f;
	DrawF(coords);
	coords.x += 0.05f;
	DrawT(coords);

	coords.x += 0.025f;
	DrawColon(coords);

	coords.x += 0.05f;
	DrawLinesLeftNumber(coords);
}

//todo: переделать
void View::DrawScoreNumber(PointF& coords)
{
	int score = m_game.GetScore();
	std::array<int, 7> digits;
	for (int i = 0; i < 7; i++)
	{
		digits.at(i) = score % 10;
		score /= 10;
	}
	for (int i = 6; i > -1; i--)
	{
		DrawDigit(coords, digits.at(i));
		coords.x += 0.05f;
	}
}

void View::DrawLevelNumber(const PointF& coords)
{
	int level = m_game.GetLevel();
	DrawDigit(coords, level);
}

void View::DrawLinesLeftNumber(PointF& coords)
{
	int linesLeft = m_game.GetLinesLeft();
	std::array<int, 2> digits;
	for (int i = 0; i < 2; i++)
	{
		digits.at(i) = linesLeft % 10;
		linesLeft /= 10;
	}
	for (int i = 1; i > -1; i--)
	{
		DrawDigit(coords, digits.at(i));
		coords.x += 0.05f;
	}
}

void View::DrawNextText(PointF& coords)
{
	DrawN(coords);
	coords.x += 0.05f;
	DrawE(coords);
	coords.x += 0.05f;
	DrawX(coords);
	coords.x += 0.05f;
	DrawT(coords);

	coords.x += 0.025f;
	DrawColon(coords);
}

void View::DrawL(const PointF& coords)
{
	glVertex2f(coords.x, coords.y);
	glVertex2f(coords.x, coords.y - 0.05f);
	glVertex2f(coords.x, coords.y - 0.05f);
	glVertex2f(coords.x + 0.03f, coords.y - 0.05f);
}

void View::DrawE(const PointF& coords)
{
	glVertex2f(coords.x, coords.y);
	glVertex2f(coords.x, coords.y - 0.05f);
	glVertex2f(coords.x, coords.y);
	glVertex2f(coords.x + 0.03f, coords.y);
	glVertex2f(coords.x, coords.y - 0.025f);
	glVertex2f(coords.x + 0.03f, coords.y - 0.025f);
	glVertex2f(coords.x, coords.y - 0.05f);
	glVertex2f(coords.x + 0.03f, coords.y - 0.05f);
}

void View::DrawV(const PointF& coords)
{
	glVertex2f(coords.x, coords.y);
	glVertex2f(coords.x + 0.015f, coords.y - 0.05f);
	glVertex2f(coords.x + 0.015f, coords.y - 0.05f);
	glVertex2f(coords.x + 0.03f, coords.y);
}

void View::DrawI(const PointF& coords)
{
	glVertex2f(coords.x, coords.y);
	glVertex2f(coords.x + 0.03f,coords.y);
	glVertex2f(coords.x + 0.015f, coords.y);
	glVertex2f(coords.x + 0.015f, coords.y - 0.05f);
	glVertex2f(coords.x, coords.y - 0.05f);
	glVertex2f(coords.x + 0.03f, coords.y - 0.05f);
}

void View::DrawN(const PointF& coords)
{
	glVertex2f(coords.x, coords.y);
	glVertex2f(coords.x, coords.y - 0.05f);
	glVertex2f(coords.x, coords.y);
	glVertex2f(coords.x + 0.03f, coords.y - 0.05f);
	glVertex2f(coords.x + 0.03f, coords.y - 0.05f);
	glVertex2f(coords.x + 0.03f, coords.y);
}

void View::DrawS(const PointF& coords)
{
	glVertex2f(coords.x, coords.y);
	glVertex2f(coords.x + 0.03f, coords.y);
	glVertex2f(coords.x, coords.y);
	glVertex2f(coords.x, coords.y - 0.025f);
	glVertex2f(coords.x, coords.y - 0.025f);
	glVertex2f(coords.x + 0.03f, coords.y - 0.025f);
	glVertex2f(coords.x + 0.03f, coords.y - 0.025f);
	glVertex2f(coords.x + 0.03f, coords.y - 0.05f);
	glVertex2f(coords.x + 0.03f, coords.y - 0.05f);
	glVertex2f(coords.x, coords.y - 0.05f);
}

void View::DrawF(const PointF& coords)
{
	glVertex2f(coords.x, coords.y);
	glVertex2f(coords.x, coords.y - 0.05f);
	glVertex2f(coords.x, coords.y);
	glVertex2f(coords.x + 0.03f, coords.y);
	glVertex2f(coords.x, coords.y - 0.025f);
	glVertex2f(coords.x + 0.03f, coords.y - 0.025f);
}

void View::DrawT(const PointF& coords)
{
	glVertex2f(coords.x, coords.y);
	glVertex2f(coords.x + 0.03f, coords.y);
	glVertex2f(coords.x + 0.015f, coords.y);
	glVertex2f(coords.x + 0.015f, coords.y - 0.05f);

}

void View::DrawC(const PointF& coords)
{
	glVertex2f(coords.x, coords.y);
	glVertex2f(coords.x + 0.03f, coords.y);
	glVertex2f(coords.x, coords.y);
	glVertex2f(coords.x, coords.y - 0.05f);
	glVertex2f(coords.x + 0.03f, coords.y - 0.05f);
	glVertex2f(coords.x, coords.y - 0.05f);
}

void View::DrawO(const PointF& coords)
{
	glVertex2f(coords.x, coords.y);
	glVertex2f(coords.x + 0.03f, coords.y);
	glVertex2f(coords.x, coords.y);
	glVertex2f(coords.x, coords.y - 0.05f);
	glVertex2f(coords.x + 0.03f, coords.y - 0.05f);
	glVertex2f(coords.x, coords.y - 0.05f);
	glVertex2f(coords.x + 0.03f, coords.y);
	glVertex2f(coords.x + 0.03f, coords.y - 0.05f);
}

void View::DrawR(const PointF& coords)
{
	glVertex2f(coords.x, coords.y);
	glVertex2f(coords.x, coords.y - 0.05f);
	glVertex2f(coords.x, coords.y);
	glVertex2f(coords.x + 0.03f, coords.y);
	glVertex2f(coords.x + 0.03f, coords.y);
	glVertex2f(coords.x + 0.03f, coords.y - 0.025f);
	glVertex2f(coords.x + 0.03f, coords.y - 0.025f);
	glVertex2f(coords.x, coords.y - 0.025f);
	glVertex2f(coords.x, coords.y - 0.025f);
	glVertex2f(coords.x + 0.03f, coords.y - 0.05f);

}

void View::DrawX(const PointF& coords)
{
	glVertex2f(coords.x, coords.y);
	glVertex2f(coords.x + 0.03f, coords.y - 0.05f);
	glVertex2f(coords.x, coords.y - 0.05f);
	glVertex2f(coords.x + 0.03f, coords.y);
}

void View::Draw0(const PointF& coords)
{
	glVertex2f(coords.x, coords.y);
	glVertex2f(coords.x + 0.03f, coords.y);
	glVertex2f(coords.x + 0.03f, coords.y);
	glVertex2f(coords.x + 0.03f, coords.y - 0.05f);
	glVertex2f(coords.x + 0.03f, coords.y - 0.05f);
	glVertex2f(coords.x, coords.y - 0.05f);
	glVertex2f(coords.x, coords.y - 0.05f);
	glVertex2f(coords.x, coords.y);
}

void View::Draw1(const PointF& coords)
{
	glVertex2f(coords.x + 0.03f, coords.y);
	glVertex2f(coords.x + 0.03f, coords.y - 0.05f);
}

void View::Draw2(const PointF& coords)
{
	glVertex2f(coords.x, coords.y);
	glVertex2f(coords.x + 0.03f, coords.y);
	glVertex2f(coords.x + 0.03f, coords.y);
	glVertex2f(coords.x + 0.03f, coords.y - 0.025f);
	glVertex2f(coords.x + 0.03f, coords.y - 0.025f);
	glVertex2f(coords.x, coords.y - 0.025f);
	glVertex2f(coords.x, coords.y - 0.025f);
	glVertex2f(coords.x, coords.y - 0.05f);
	glVertex2f(coords.x, coords.y - 0.05f);
	glVertex2f(coords.x + 0.03f, coords.y - 0.05f);
}

void View::Draw3(const PointF& coords)
{
	glVertex2f(coords.x, coords.y);
	glVertex2f(coords.x + 0.03f, coords.y);
	glVertex2f(coords.x, coords.y - 0.025f);
	glVertex2f(coords.x + 0.03f, coords.y - 0.025f);
	glVertex2f(coords.x, coords.y - 0.05f);
	glVertex2f(coords.x + 0.03f, coords.y - 0.05f);
	glVertex2f(coords.x + 0.03f, coords.y);
	glVertex2f(coords.x + 0.03f, coords.y - 0.05f);
}

void View::Draw4(const PointF& coords)
{
	glVertex2f(coords.x, coords.y);
	glVertex2f(coords.x, coords.y - 0.025f);
	glVertex2f(coords.x, coords.y - 0.025f);
	glVertex2f(coords.x + 0.03f, coords.y - 0.025f);
	glVertex2f(coords.x + 0.03f, coords.y);
	glVertex2f(coords.x + 0.03f, coords.y - 0.05f);
}

void View::Draw5(const PointF& coords)
{
	glVertex2f(coords.x, coords.y);
	glVertex2f(coords.x + 0.03f, coords.y);
	glVertex2f(coords.x, coords.y);
	glVertex2f(coords.x, coords.y - 0.025f);
	glVertex2f(coords.x, coords.y - 0.025f);
	glVertex2f(coords.x + 0.03f, coords.y - 0.025f);
	glVertex2f(coords.x + 0.03f, coords.y - 0.025f);
	glVertex2f(coords.x + 0.03f, coords.y - 0.05f);
	glVertex2f(coords.x + 0.03f, coords.y - 0.05f);
	glVertex2f(coords.x, coords.y - 0.05f);
}

void View::Draw6(const PointF& coords)
{
	glVertex2f(coords.x, coords.y);
	glVertex2f(coords.x + 0.03f, coords.y);
	glVertex2f(coords.x, coords.y);
	glVertex2f(coords.x, coords.y - 0.05f);
	glVertex2f(coords.x, coords.y - 0.025f);
	glVertex2f(coords.x + 0.03f, coords.y - 0.025f);
	glVertex2f(coords.x + 0.03f, coords.y - 0.025f);
	glVertex2f(coords.x + 0.03f, coords.y - 0.05f);
	glVertex2f(coords.x + 0.03f, coords.y - 0.05f);
	glVertex2f(coords.x, coords.y - 0.05f);
}

void View::Draw7(const PointF& coords)
{
	glVertex2f(coords.x, coords.y);
	glVertex2f(coords.x + 0.03f, coords.y);
	glVertex2f(coords.x + 0.03f, coords.y);
	glVertex2f(coords.x + 0.03f, coords.y - 0.05f);
}

void View::Draw8(const PointF& coords)
{
	glVertex2f(coords.x, coords.y);
	glVertex2f(coords.x + 0.03f, coords.y);
	glVertex2f(coords.x, coords.y - 0.025f);
	glVertex2f(coords.x + 0.03f, coords.y - 0.025f);
	glVertex2f(coords.x, coords.y - 0.05f);
	glVertex2f(coords.x + 0.03f, coords.y - 0.05f);
	glVertex2f(coords.x + 0.03f, coords.y);
	glVertex2f(coords.x + 0.03f, coords.y - 0.05f);
	glVertex2f(coords.x, coords.y);
	glVertex2f(coords.x, coords.y - 0.05f);
}

void View::Draw9(const PointF& coords)
{
	glVertex2f(coords.x, coords.y);
	glVertex2f(coords.x + 0.03f, coords.y);
	glVertex2f(coords.x, coords.y);
	glVertex2f(coords.x, coords.y - 0.025f);
	glVertex2f(coords.x, coords.y - 0.025f);
	glVertex2f(coords.x + 0.03f, coords.y - 0.025f);
	glVertex2f(coords.x + 0.03f, coords.y);
	glVertex2f(coords.x + 0.03f, coords.y - 0.05f);
	glVertex2f(coords.x + 0.03f, coords.y - 0.05f);
	glVertex2f(coords.x, coords.y - 0.05f);
}

void View::DrawDigit(const PointF& coords, const int& digit)
{
	switch (digit)
	{
	case 0:
		Draw0(coords);
		break;
	case 1:
		Draw1(coords);
		break;
	case 2:
		Draw2(coords);
		break;
	case 3:
		Draw3(coords);
		break;
	case 4:
		Draw4(coords);
		break;
	case 5:
		Draw5(coords);
		break;
	case 6:
		Draw6(coords);
		break;
	case 7:
		Draw7(coords);
		break;
	case 8:
		Draw8(coords);
		break;
	case 9:
		Draw9(coords);
		break;
	}
}

void View::DrawColon(const PointF& coords)
{
	glVertex2f(coords.x + 0.012f, coords.y - 0.0122f);
	glVertex2f(coords.x + 0.018f, coords.y - 0.0122f);
	glVertex2f(coords.x + 0.018f, coords.y - 0.0122f);
	glVertex2f(coords.x + 0.018f, coords.y - 0.0128f);
	glVertex2f(coords.x + 0.018f, coords.y - 0.0128f);
	glVertex2f(coords.x + 0.012f, coords.y - 0.0128f);
	glVertex2f(coords.x + 0.012f, coords.y - 0.0128f);
	glVertex2f(coords.x + 0.012f, coords.y - 0.0122f);
	glVertex2f(coords.x + 0.012f, coords.y - 0.0372f);
	glVertex2f(coords.x + 0.018f, coords.y - 0.0372f);
	glVertex2f(coords.x + 0.018f, coords.y - 0.0322f);
	glVertex2f(coords.x + 0.018f, coords.y - 0.0378f);
	glVertex2f(coords.x + 0.018f, coords.y - 0.0378f);
	glVertex2f(coords.x + 0.012f, coords.y - 0.0378f);
	glVertex2f(coords.x + 0.012f, coords.y - 0.0378f);
	glVertex2f(coords.x + 0.012f, coords.y - 0.0372f);
}

void View::DrawNextPiece(const PointF& coords)
{
	PointF pos = coords;
	Piece nextPiece = m_game.GetNextPiece();
	PieceContains pieceContains = nextPiece.GetContains();
	
	for (int i = 0; i < PIECE_HEIGHT; i++)
	{
		for (int j = 0; j < PIECE_WIDTH; j++)
		{
			if (pieceContains.at(i).at(j) != EMPTY_SQUARE)
			{
				DrawSquare(pos, pieceContains.at(i).at(j));
			}
			pos.x += 0.05f;
		}
		pos.x = coords.x;
		pos.y -= 0.05f;
	}
}
