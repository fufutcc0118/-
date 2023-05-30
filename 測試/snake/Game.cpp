#include "Game.h"
#include <iostream>

Game::Game()
{
    // ��l�ƹC�����A�M����
    score = 0;
    level = 1;
    gameOver = false;
}

void Game::startGame()
{
    cout << "�C���}�l�I" << endl;

    while (!gameOver) {
        // ��s�C�����A�M����
        snake.Logic();

        // �ˬd�I�����C���޿�
        if (snake.collidesWith(food)) {
            snake.Draw();
            food.random();
            updateScore();
        }


        // ���]�b���B�˴��O�_�����C��������
        if (score >= 10) {
            endGame();
        }
    }
}

void Game::pauseGame()
{
    // �Ȱ��C���޿�
    std::cout << "�C���w�Ȱ�" << std::endl;
}

void Game::endGame()
{
    // �����C���޿�
    gameOver = true;
    std::cout << "�C������" << std::endl;
}

void Game::updateScore()
{
    // ��s�����޿�
    score++;
    std::cout << "����: " << score << std::endl;
}

void Game::updateLevel()
{
    // ��s�����޿�
    if (score % 5 == 0) {
        level++;
        std::cout << "���Ŵ��ɬ�: " << level << std::endl;
    }
}