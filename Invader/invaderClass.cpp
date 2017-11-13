#include "invaderClass.h"
#include <GLUT/glut.h>
#include <cmath>
#include <iostream>
using namespace std;

INVADER::INVADER(int x, int y){
	life = true;
	drawx = x; drawy = y;//初期位置設定
	move = true;
	Initialization();
}

//DRAW_MAG pix ずつ QUADS 作成し描画
void INVADER::InvaderPoint(int x, int y){
	glColor3d(1.0,0.0,0.0); //赤色
	glBegin(GL_QUADS);
	glVertex2i(x  ,y);
	glVertex2i(x  ,y+DRAW_MAG);
	glVertex2i(x+DRAW_MAG,y+DRAW_MAG);
	glVertex2i(x+DRAW_MAG,y);
	glEnd();
}

//描画座標の決定
void INVADER::Coordinate(){
	int x = invx + drawx,
		y = invy + drawy;
	InvaderPoint(x, y);
}


//倍率変更
void INVADER::Magnification(){
	invx = invx * DRAW_MAG;
	invy = invy * DRAW_MAG;
	Coordinate();
}

//初期化。配列情報取得ループ
void INVADER::Initialization(){
	for(int x = 0; x < 10; x++){
		for(int y = 0; y < 10; y++){
			if(invader[x][y] == true){
				invx = x; invy = y;
				Magnification();
			}
		}
	}
}

//移動
void INVADER::Move(){
	if(life){
		if(move == true){
			drawx -= INVADER_SPEED;//Left
		}else if(move == false){
			drawx += INVADER_SPEED;//Right
		}

		//壁に当たったら一段下がって折り返しの動きをさせる
		mcount++;
		if(mcount > MOVE_COUNT){
			drawy += 10;//Dawn
			mcount = 0;
			move = move ? false : true;
		}
		Initialization();
	}
}

//弾発射
bool INVADER::Shot(int y){
	if(life){
		//x座標の初期設定
		if(y == drawy){
			shotx = drawx;
		}
		glColor3d(1.0,1.0,1.0);
		glPointSize(5);
		glBegin(GL_POINTS);
		glVertex2d(shotx+SHOT_X,y + 40);
		glEnd();

		//弾描画終了判定
		if(y > HEIGHT){
			return false;
		}else return true;
	}
}

//死亡
void INVADER::Dead(){
	life = false;
}

//drawyを渡すだけ
int INVADER::DrawyReturn(){
	return drawy;
}

//shotxを渡すだけ
int INVADER::ShotxReturn(){
	return shotx;
}

//当たり判定部
bool INVADER::Hit(int uShotx, int uShoty){
	if(life){
		double x , y, 
			   maxx = drawx, minx = drawx,
			   maxy = drawy, miny = drawy;

		//円描画
		for(double i = -20.0; i < 20.0; i++){
			y = 20 * sin((i + 180) / PI);
			x = 20 * cos((i + 180) / PI);
			//Invaderの座標を適用
			y += drawy + 20.0;
			x += drawx + 20.0;
			//x,yの最大、最小値を記憶
			if(drawx + 20.0 < x && maxx < x)maxx = x;
			if(drawx + 20.0 > x && minx > x)minx = x;
			if(drawy + 20.0 < y && maxy < y)maxy = y;
			if(drawy + 20.0 > y && miny > y)miny = y;

			//x,yの範囲内に弾の座標が入れば死亡
			//当たり判定は矩形になる
			if(uShotx > minx && uShotx < maxx && uShoty > miny && uShoty < maxy){
				Dead();
				return true;
			}
			return false;
		}
	}
}