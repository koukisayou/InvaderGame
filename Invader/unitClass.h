#ifndef _UNIT_CLASS
#define _UNIT_CLASS
#include <GLUT/glut.h>
#include <cmath>

#define UNIT_X 			300		//ユニット初期位置ｘ軸
#define UNIT_Y 			400		//ユニット初期位置Y軸
#define DRAW_MAG 		4		//描画時倍率
#define WIDTH 			640		//画面横幅
#define PI 				3.141592//π
#define SHOT_X			20		//弾発射位置を真ん中に調整

class UNIT{
public:
	UNIT();
	void Drawing(int x, int y);			//描画
	void Coordinate();					//座標決定
	void Magnification();				//倍率変更
	void Initialization();				//初期化
	int Shot(int y);					//弾発射
	void LeftMove();					//左移動
	void RightMove();					//右移動
	void Dead();						//死亡
	void Hit(int iShotx, int iShoty);	//当たり判定
private:
	int unitx,unity;//bool arrayの座標取得ループの値保存用
	int drawx,drawy;//描画位置
	bool life;		//生死判定
	//[x][y]
	bool unit[10][10] = {
	// y 0 1 2 3 4 5 6 7 8 9	 x
		{0,0,0,0,0,1,1,1,1,0,},//0
		{0,0,0,0,0,1,1,1,1,0,},//1
		{0,0,0,0,0,1,1,1,1,0,},//2
		{0,0,1,1,1,1,1,1,1,0,},//3
		{0,0,1,1,1,1,1,1,1,0,},//4
		{0,0,1,1,1,1,1,1,1,0,},//5
		{0,0,1,1,1,1,1,1,1,0,},//6
		{0,0,0,0,0,1,1,1,1,0,},//7
		{0,0,0,0,0,1,1,1,1,0,},//8
		{0,0,0,0,0,1,1,1,1,0,},//9
	};
};

#endif