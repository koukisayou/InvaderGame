#include "unitClass.h"
#include <GLUT/glut.h>
#include <cmath>

UNIT::UNIT(){
	drawx = UNIT_X;
	drawy = UNIT_Y;
	life = true;
}

//DRAW_MAG pix ずつ QUADS 作成し描画
void UNIT::Drawing(int x, int y){
	glColor3d(1.0,1.0,1.0);
	glBegin(GL_QUADS);
	glVertex2i(x  ,y);
	glVertex2i(x  ,y+DRAW_MAG);
	glVertex2i(x+DRAW_MAG,y+DRAW_MAG);
	glVertex2i(x+DRAW_MAG,y);
	glEnd();
}



//描画座標の決定
void UNIT::Coordinate(){
	int x = unitx + drawx,
		y = unity + drawy;
		Drawing(x, y);
}

//倍率変更
void UNIT::Magnification(){
	unitx = unitx * DRAW_MAG;
	unity = unity * DRAW_MAG;
	Coordinate();
}

//初期化。配列情報取得ループ
void UNIT::Initialization(){
	if(life){
		for(int x = 0; x < 10; x++){
			for(int y = 0; y < 10; y++){
				if(unit[x][y] == true){
					unitx = x; unity = y;
					Magnification();
				}
			}
		}
	}
}

//左移動
void UNIT::LeftMove(){
	drawx -= 4;
	if(drawx < 0)drawx = 0;
	Initialization();
}

//右移動
void UNIT::RightMove(){
	drawx += 4;
	if(drawx > WIDTH - DRAW_MAG * 10)drawx = WIDTH - DRAW_MAG * 10;
	Initialization();
}

//死亡
void UNIT::Dead(){
	life = false;
}

//弾発射
int UNIT::Shot(int y){
	if(life){
		static int x = 0;
		//x座標の初期設定
		if(y == UNIT_Y){
			x = drawx;
		}
		glColor3d(1.0,1.0,1.0);
		glPointSize(4);
		glBegin(GL_POINTS);
		glVertex2d(x+SHOT_X,y);
		glEnd();
		//戻り値をUnit描画の中心に調整
		return x + SHOT_X;
	}
}

//当たり判定
void UNIT::Hit(int iShotx, int iShoty){
	double x , y,
		   maxx = drawx, minx = drawx,
		   maxy = drawy, miny = drawy;

	//円描画
	for(double i = -20.0; i < 20.0; i++){
		y = 20 * sin((i + 180) / PI);
		x = 20 * cos((i + 180) / PI);
		//Unitの座標を適用
		y += drawy + 20.0;
		x += drawx + 20.0;
		//x,yの最大、最小値を記憶
		if(drawx + 20.0 < x && maxx < x)maxx = x;
		if(drawx + 20.0 > x && minx > x)minx = x;
		if(drawy + 20.0 < y && maxy < y)maxy = y;
		if(drawy + 20.0 > y && miny > y)miny = y;
		
		//x,yの範囲内に弾の座標が入れば死亡
		if(iShotx > minx && iShotx < maxx && iShoty + 40 > miny && iShoty + 40 < maxy){
			Dead();
		}
		
	}
}