#include <GLFW/glfw3.h>
#include "TimeFunctions.h"
#include "View.h"
#include "Game.h"

Game game;
View view(game);

void KeyCallback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
	if (key == GLFW_KEY_LEFT && (action == GLFW_REPEAT || action == GLFW_PRESS))
	{
		if (game.IsNoWallLeft())
		{
			game.MovingPieceByUser(LEFT_DIRECTION);
			view.DrawUI();
		}
	}
	else if (key == GLFW_KEY_RIGHT && (action == GLFW_REPEAT || action == GLFW_PRESS))
	{
		if (game.IsNoWallRight())
		{
			game.MovingPieceByUser(RIGHT_DIRECTION);
			view.DrawUI();
		}
	}
	else if (key == GLFW_KEY_DOWN && (action == GLFW_REPEAT || action == GLFW_PRESS))
	{
		if (game.IsNoWallDown())
		{
			game.MovingPieceByUser(DOWN_DIRECTION);
			view.DrawUI();
		}
	}
	else if (key == GLFW_KEY_UP && (action == GLFW_REPEAT || action == GLFW_PRESS))
	{
		if (game.IsPossibleRotate())
		{
			game.RotatePiece();
			view.DrawUI();
		}
	}
	else if (key == GLFW_KEY_P && action == GLFW_PRESS)
	{
		game.Pause();
	}
	else if (key == GLFW_KEY_U && action == GLFW_PRESS)
	{
		game.Unpause();
	}
}

int main()
{
	GLFWwindow* window;

	if (!glfwInit())
		return -1;

	window = glfwCreateWindow(WINDOW_SIZE, WINDOW_SIZE, "Tetris", NULL, NULL);
	if (!window)
	{
		glfwTerminate();
		return -1;
	}

	glfwMakeContextCurrent(window);
	glfwSetKeyCallback(window, KeyCallback);

	while (!glfwWindowShouldClose(window))
	{
		// играть невозможно
		glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);
		glViewport(0, 0, WINDOW_SIZE, WINDOW_SIZE);

		if (!game.IsPaused())
		{
			if (game.IsNeededNewPiece())
			{
				game.AddPiece(game.GetCurrentPiece());
			}
			else
			{
				if (game.IsNoWallDown())
				{
					game.MovingPieceByGame();
				}
				else
				{
					if (game.IsFull())
					{
						game.Pause();
						game.Clear();
						game.ResetScore();
						game.ResetLevel();
						game.ResetLinesLeft();
						game.ResetSpeed();
					}
					if (game.IsNeededClearLines())
					{
						game.ClearLines();
					}

					game.SetCurrentPiece();
					game.AddPiece(game.GetCurrentPiece());
					game.SetNextPiece();
				}
			}
		}

		view.DrawUI();

		glfwSwapBuffers(window);
		glfwPollEvents();
		
		WaitTime(game.GetSpeed()); 
	}

	glfwTerminate();
	return 0;
}
