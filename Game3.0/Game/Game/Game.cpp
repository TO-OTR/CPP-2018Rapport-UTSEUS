// Game.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>
#include <windows.h>
#include"BodyManager.h"
#include"Ball.h"
#include"Barre.h"
#include"Brick.h"
#include"Frame.h"
#include"GameConsole.h"
#include"Introduction_fin.h"
int main() {
	Gamestart();
	GameConsole gameConsole;
	gameConsole.set_title(L"game");
	gameConsole.set_dimensions(100, 30);
	BodyManager bodyManager(Box(100, 30), gameConsole);
	char barrePix[] = { 0xC9u, 0xCDu,0xCDu,0xCBu,0x0u };
	//Barre barre(Box(8,1),Position(46, 29), "╔══╦");
	Barre barre(Box(4, 1), Position(48, 28), barrePix);
	barre.setSpeed(1.0);
	//char ballPix[] = { 0xDBu, 0x0u };
	//char ballPix[] = { 0xFEu, 0x0u };
	char ballPix[] = { 0xDDu, 0x0u };
	
	Ball ball(Box(1, 1), Position(49, 27), ballPix);
	ball.setSpeed(0, -0.1);
	bodyManager.addBody(barre);
	gameConsole.setBarre(barre);
	bodyManager.addBody(ball);
	Frame *frameTop[10];
	Frame *frameLeft[10];
	Frame *frameRight[10];
	Frame *frameBottom[10];
	Brick *brick[100];
	int brickN=0;
	char frameTopPix[100] ;
	for (int i = 0;i < 99;i++) {
		frameTopPix[i] = 0xCDu;
	}
	frameTopPix[99] = 0x0u;

	char frameBottomPix[100] ;
	for (int i = 0;i < 99;i++) {
		frameBottomPix[i] = 0xCDu;
	}
	frameBottomPix[99] = 0x0u;

	char frameLeftPix[32] ;
	for (int i = 0;i < 28;i++) {
		//frameLeftPix[i] = 0xDEu;
		frameLeftPix[i] = 204u;
	}
	frameLeftPix[28] = 0x0u;

	char frameRightPix[32];
	for (int i = 0;i < 28;i++) {
		frameRightPix[i] = 204u;
	}
	frameRightPix[28] = 0x0u;
	for (int i = 0; i < 1; i++) {
		frameTop[i] = new Frame(Box(99, 1), Position(0, 0), frameTopPix);
		frameBottom[i] = new Frame(Box(99, 1), Position(0, 29), frameBottomPix);

		frameLeft[i] = new Frame(Box(1, 28), Position(0, 1), frameLeftPix);
		frameRight[i] = new Frame(Box(1, 28), Position(98, 1), frameRightPix);
		frameTop[i]->setQuit(false);
		frameBottom[i]->setQuit(true);
		frameLeft[i]->setQuit(false);
		frameRight[i]->setQuit(false);
		frameTop[i]->setRate(1.0, -1.0);
		frameBottom[i]->setRate(1.0, -1.0);
		frameLeft[i]->setRate(-1.0, 1.0);
		frameRight[i]->setRate(-1.0, 1.0);
		bodyManager.addBody(*frameTop[i]);
		bodyManager.addBody(*frameBottom[i]);
		bodyManager.addBody(*frameLeft[i]);
		bodyManager.addBody(*frameRight[i]);
	}
	//char brickPix[] = { 0xDCu, 0x0u };
	char brickPix[] = { 0xDDu, 0x0u };
	brickN=0;
	int hardness=2;
	for (int i = 0; i < 8; i++) {
		for(int j=0; j<2*i+1; j++){
			brick[brickN] = new Brick(Box(1,1),Position(2*(j-i) + 49 , 12-i), brickPix);
			brick[brickN]->setRate(0.7 + 0.1*i);
			brick[brickN]->setHardness(hardness);
			bodyManager.addBody(*brick[brickN]);
			brickN++;
			hardness=3-hardness;
		}
	}

	bodyManager.run();

	for (int i = 0; i < 1; i++) {
		delete frameTop[i];
		delete frameLeft[i];
		delete frameRight[i];
		delete frameBottom[i];
	}
	for (int i = 0; i < brickN; i++) {
		delete brick[i];
	}
	system("cls");

	std::cout << " " << "\n"
			<< "			    YOUR SCORE IS " << bodyManager.score << "\n"
			<< "			    THANK YOU FOR PLAYING 					" << "\n"
			<< "			    PRESS ANT BUTTON TO LEAVE YOU ADVENTURE	" << std::endl;
		system("pause");
	
	return 0;
}

// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单

// 入门提示: 
//   1. 使用解决方案资源管理器窗口添加/管理文件
//   2. 使用团队资源管理器窗口连接到源代码管理
//   3. 使用输出窗口查看生成输出和其他消息
//   4. 使用错误列表窗口查看错误
//   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
//   6. 将来，若要再次打开此项目，请转到“文件”>“打开”>“项目”并选择 .sln 文件
