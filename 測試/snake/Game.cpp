#include "Game.h"
#include <iostream>

Game::Game()
{
    // ��l�ƹC�����A�M����
    score = 0;
    level = 1;
    isOver = false;
}

void Game::startGame()
{
    std::cout << "�C���}�l�I" << std::endl;

    while (!isOver) {
        // ��s�C�����A�M����
        snake.move();

        // �ˬd�I�����C���޿�
        if (snake.collidesWith(food)) {
            snake.grow();
            food.random();
            updateScore();
        }

        // ø�s�C���e��
        // ...

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
    isOver = true;
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