#include "Game.h"
#include <iostream>

Game::Game()
{
    // 初始化遊戲狀態和物件
    score = 0;
    level = 1;
    gameOver = false;
}

void Game::startGame()
{
    cout << "遊戲開始！" << endl;

    while (!gameOver) {
        // 更新遊戲狀態和物件
        snake.Logic();

        // 檢查碰撞等遊戲邏輯
        if (snake.collidesWith(food)) {
            snake.Draw();
            food.random();
            updateScore();
        }


        // 假設在此處檢測是否結束遊戲的條件
        if (score >= 10) {
            endGame();
        }
    }
}

void Game::pauseGame()
{
    // 暫停遊戲邏輯
    std::cout << "遊戲已暫停" << std::endl;
}

void Game::endGame()
{
    // 結束遊戲邏輯
    gameOver = true;
    std::cout << "遊戲結束" << std::endl;
}

void Game::updateScore()
{
    // 更新分數邏輯
    score++;
    std::cout << "分數: " << score << std::endl;
}

void Game::updateLevel()
{
    // 更新等級邏輯
    if (score % 5 == 0) {
        level++;
        std::cout << "等級提升為: " << level << std::endl;
    }
}