#include "raylib.h"
#include<stdio.h>
#include <stdlib.h>
#include <time.h>
#define size 10
typedef struct {//蛇身定义
	int x;
	int y;
}CELL;
typedef struct {//蛇的性质
	int length;//蛇长度
	CELL body[800];
	int score;//得分
	int drix;
	int driy;//运动方向
	int foodx;
	int foody;//食物坐标
}Snack;
void DrawSetting() {//画板初始化
	int x = 0;
	int y = 0;
	while (x <= 800 && y <= 800)
	{
		DrawLine(x, 0, x, 800, BLACK);
		DrawLine(0, y, 800, y, BLACK);
		x += 20;
		y += 20;
	}
}
void InitSnack(Snack* s) {//蛇身初始化
	int j = 100;
	s->score = 0;
	s->length = size;
	s->foodx = 140;
	s->foody = 140;//初始化食物坐标
	for (int i = 0; i < s->length; i++)
	{
		s->body[i].x = j;
		s->body[i].y = 400;
		j -= 20;
	}
	s->drix = 20;
	s->driy = 0;//初始移动方向：x正方向
}
void SnackMove(Snack*s,int *e) {//蛇身移动
	for (int i = s->length - 1; i >= 1; i--) {
		(*s).body[i] = (*s).body[i - 1];
	}
	(*s).body[0].x += (*s).drix;
	(*s).body[0].y += (*s).driy;//初始的移动
	if (IsKeyDown(KEY_S) && (*s).driy >= 0) {
		(*s).drix = 0;
		(*s).driy = 20;
	}
	if (IsKeyDown(KEY_W) && (*s).driy <= 0) {
		(*s).drix = 0;
		(*s).driy = -20;
	}
	if (IsKeyDown(KEY_A) && (*s).drix <= 0) {
		(*s).drix = -20;
		(*s).driy = 0;
	}
	if (IsKeyDown(KEY_D) && (*s).drix >= 0) {
		(*s).drix = 20;
		(*s).driy = 0;
	}//WASD改变蛇身移动方向
	for (int i = 0; i < s->length; i++) {
		DrawRectangle((*s).body[i].x, (*s).body[i].y, 20, 20, RED);
		DrawRectangleLines((*s).body[i].x, (*s).body[i].y, 20, 20, BLACK);
	}//绘制蛇身移动
	if (s->body[0].x < 0 || s->body[0].x + 20>800 || s->body[0].y < 0 || s->body[0].y + 20>800)
		*e = 0;//当蛇碰到边界，就停止游戏
	for (int i = 1; i < s->length; i++)
	{
		if (s->body[i].x == s->body[0].x && s->body[i].y == s->body[0].y)
			*e = 0;
	}
}
void Food(Snack*s) {//随机食物代码：碰到一个食物长度就+1
		if (s->body[0].x == s->foodx && s->body[0].y == s->foody) {
			s->length += 1;
			s->score += 5;
			s->foodx = (rand() % 39) * 20 + 20;
			s->foody = (rand() % 39) * 20 + 20;//随机数生成：20-780，间隔20
		}
		DrawRectangle(s->foodx, s->foody, 20, 20, BLUE);
}
int main() {
	InitWindow(800,800, "SnackDemo");
	SetTargetFPS(10);
	Snack s;
	int game = -1;
	InitSnack(&s);
	srand((unsigned)time(NULL)); // 只初始化一次种子
	while (!WindowShouldClose())
	{
		BeginDrawing();
		ClearBackground(WHITE);
		DrawSetting();//绘制背景
		if (game == -1) {//
			DrawText("Press 'SPACE' to Start", 100, 400, 50, BLUE);
			if (IsKeyDown(KEY_SPACE))
				game = 1;
		}
		if (game == 1) {
			SnackMove(&s, &game);
			Food(&s);
		}
		if (game == 0) {
			DrawText("Game Over", 150, 300, 100, PINK);
			for (int i = 0; i < s.length; i++) {
				DrawRectangle(s.body[i].x, s.body[i].y, 20, 20, RED);
				DrawRectangleLines(s.body[i].x, s.body[i].y, 20, 20, BLACK);
				DrawText(TextFormat("Score: %d", s.score), 500, 500, 50, PURPLE);
				DrawText("Press 'R' restart", 400, 400, 40, ORANGE);
			}
		}
		if (game == 0 && IsKeyDown(KEY_R))
		{
			InitSnack(&s);
			game = 1;
		}//游戏主要运行程序
		EndDrawing();
	}
	CloseWindow();
	return 0;
}
