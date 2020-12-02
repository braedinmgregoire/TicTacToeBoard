/**
 * Unit Tests for TicTacToeBoard
**/

#include <gtest/gtest.h>
#include "TicTacToeBoard.h"

class TicTacToeBoardTest : public ::testing::Test
{
	protected:
		TicTacToeBoardTest(){} //constructor runs before each test
		virtual ~TicTacToeBoardTest(){} //destructor cleans up after tests
		virtual void SetUp(){} //sets up before each test (after constructor)
		virtual void TearDown(){} //clean up after each test, (before destructor)
};

/* EXAMPLE TEST FORMAT
TEST(TicTacToeBoardTest, unitTestName)
{
	TicTacToeBoard board;
	ASSERT_TRUE(true);
}
*/

TEST(TicTacToeBoardTest, checkWinWhenIncomplete) //checks if there is a winner early, before the game is finished
{
  TicTacToeBoard board;
  Piece p;
  p = board.getWinner();
	ASSERT_EQ(p,'?');
}

TEST(TicTacToeBoardTest, invalidWrite) //attempts to write at an invalid space
{
	TicTacToeBoard board;
	ASSERT_EQ(board.placePiece(1,3), Invalid);
}

TEST(TicTacToeBoardTest, attemptOverwrite) //Attempt to write over a current piece
{
	TicTacToeBoard board;
	Piece first = board.placePiece(0,1);
	ASSERT_EQ(board.placePiece(0,1), first);
}

TEST(TicTacToeBoardTest, fullGame) //plays a full game, giving the expected output
{
	TicTacToeBoard board;
	for(int i=0; i<BOARDSIZE; i++)
    for(int j=0; j<BOARDSIZE; j++)
      board.placePiece(i,j);
	ASSERT_EQ(board.getWinner(), 'X');
}

TEST(TicTacToeBoardTest, fullBoard) //tests whether a full board will yield the correct results
{
	TicTacToeBoard board;
	board.placePiece(0,0);
	board.placePiece(0,1);
	board.placePiece(0,2);
	board.placePiece(1,1);
	board.placePiece(1,0);
	board.placePiece(2,0);
	board.placePiece(1,2);
	board.placePiece(2,2);
	board.placePiece(2,1);
	ASSERT_EQ(board.getWinner(), Blank);
}

TEST(TicTacToeBoardTest, fullRow) //Assert that O wins with a row
{
	TicTacToeBoard board;
	board.placePiece(1,0);
	board.placePiece(0,0);
	board.placePiece(2,0);
	board.placePiece(0,1);
	board.placePiece(1,2);
	board.placePiece(0,2);
	ASSERT_EQ(board.getWinner(), 'O');
}
