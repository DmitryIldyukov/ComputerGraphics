#pragma once
#include "Piece.h"
#include "Const.h"
#include <array>

const Piece O = Piece({ 
	std::array<int, PIECE_WIDTH>{ 0, 0, 0, 0 },
	std::array<int, PIECE_WIDTH>{ 0, RED_COLOR, RED_COLOR, 0 },
	std::array<int, PIECE_WIDTH>{ 0, RED_COLOR, RED_COLOR, 0 },
	std::array<int, PIECE_WIDTH>{ 0, 0, 0, 0 },
					  }, 
	RED_COLOR);

const Piece I = Piece({ 
	std::array<int, PIECE_WIDTH>{ 0, 0, 0, 0}, 
	std::array<int, PIECE_WIDTH>{ 0, 0, 0, 0 },
	std::array<int, PIECE_WIDTH>{ BLUE_COLOR, BLUE_COLOR, BLUE_COLOR, BLUE_COLOR },
	std::array<int, PIECE_WIDTH>{ 0, 0, 0, 0 },
					  },
	BLUE_COLOR);

const Piece L = Piece({
	std::array<int, PIECE_WIDTH>{ 0, 0, 0, 0 },
	std::array<int, PIECE_WIDTH>{ 0, 0, YELLOW_COLOR, 0 },
	std::array<int, PIECE_WIDTH>{ YELLOW_COLOR, YELLOW_COLOR, YELLOW_COLOR, 0 },
	std::array<int, PIECE_WIDTH>{ 0, 0, 0, 0 },
					  },
	YELLOW_COLOR);

const Piece Z = Piece({ 
	std::array<int, PIECE_WIDTH>{ 0, 0, 0, 0 },
	std::array<int, PIECE_WIDTH>{ 0, GREEN_COLOR, GREEN_COLOR, 0 },
	std::array<int, PIECE_WIDTH>{ 0, 0, GREEN_COLOR, GREEN_COLOR },
	std::array<int, PIECE_WIDTH>{ 0, 0, 0, 0 },
					  },
	GREEN_COLOR);

const Piece T = Piece({ 
	std::array<int, PIECE_WIDTH>{ 0, 0, 0, 0 },
	std::array<int, PIECE_WIDTH>{ 0, 0, ORANGE_COLOR, 0 },
	std::array<int, PIECE_WIDTH>{ 0, ORANGE_COLOR, ORANGE_COLOR, ORANGE_COLOR },
	std::array<int, PIECE_WIDTH>{ 0, 0, 0, 0 },
					  },
	ORANGE_COLOR);

const Piece Z_MIRROR = Piece({ 
	std::array<int, PIECE_WIDTH>{ 0, 0, 0, 0 },
	std::array<int, PIECE_WIDTH>{ 0, 0, PURPLE_COLOR, PURPLE_COLOR },
	std::array<int, PIECE_WIDTH>{ 0, PURPLE_COLOR, PURPLE_COLOR, 0 },
	std::array<int, PIECE_WIDTH>{ 0, 0, 0, 0 },
							 },
	PURPLE_COLOR);

const Piece L_MIRROR = Piece({ 
	std::array<int, PIECE_WIDTH>{ 0, 0, 0, 0 },
	std::array<int, PIECE_WIDTH>{ 0, BLACK_COLOR, 0, 0 },
	std::array<int, PIECE_WIDTH>{ 0, BLACK_COLOR, BLACK_COLOR, BLACK_COLOR },
	std::array<int, PIECE_WIDTH>{ 0, 0, 0, 0 },
							 },
	BLACK_COLOR);

std::array<Piece, 7> ALL_PIECES = { O, I, L, Z, T, Z_MIRROR, L_MIRROR };