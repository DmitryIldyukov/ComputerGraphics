#pragma once

#include <array>
#include "Point.h"

const int WINDOW_SIZE = 600;
const int PIECE_WIDTH = 4;
const int PIECE_HEIGHT = PIECE_WIDTH;

const int FIELD_WIDTH = 10 + 2;
const int FIELD_HEIGHT = 20 + 1;
const PointF FIELD_LEFT_TOP = { -0.6f, 0.5f }; 
const int START_POS_X = 4;
const int START_POS_Y = 0;

const int EMPTY_SQUARE = 0;
const int RED_COLOR = 1;
const int BLUE_COLOR = 2;
const int YELLOW_COLOR = 3;
const int GREEN_COLOR = 4;
const int ORANGE_COLOR = 5;
const int PURPLE_COLOR = 6;
const int BLACK_COLOR = 7;
const int GREY_COLOR = 8;

const std::array<std::array<float, 3>, 9> COLORS = {
	std::array<float, 3>{ 1.0f, 1.0f, 1.0f },
	std::array<float, 3>{ 1.0f, 0.0f, 0.0f },
	std::array<float, 3>{ 0.0f, 0.0f, 1.0f },
	std::array<float, 3>{ 1.0f, 1.0f, 0.0f },
	std::array<float, 3>{ 0.0f, 1.0f, 0.0f },
	std::array<float, 3>{ 1.0f, 0.64f, 0.0f },
	std::array<float, 3>{ 0.54f, 0.17f, 0.87f },
	std::array<float, 3>{ 0.0f, 0.0f, 0.0f },
	std::array<float, 3>{ 0.66f, 0.66f, 0.66f },
};

const char LEFT_DIRECTION = 'L';
const char DOWN_DIRECTION = 'D';
const char RIGHT_DIRECTION = 'R';
const char UP_DIRECTION = 'U';

const int GAME_LEVEL_1 = 1;
const int GAME_LEVEL_2 = 2;
const int GAME_LEVEL_3 = 3;

const int GAME_SPEED_LEVEL_1 = 500;
const int GAME_SPEED_LEVEL_2 = 250;
const int GAME_SPEED_LEVEL_3 = 125;

const int GAME_LINES_LEFT_1 = 10;
const int GAME_LINES_LEFT_2 = 20;
const int GAME_LINES_LEFT_3 = 30;
 
const int MAX_REMOVED_LINES = 4;