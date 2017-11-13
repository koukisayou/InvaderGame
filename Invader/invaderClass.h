#ifndef _INVADER_CLASS
#define _INVADER_CLASS

#include <GLUT/glut.h>
#include <cmath>
using namespace std;

#define DRAW_MAG 		4		//描画時倍率
#define INVADER_SPEED	0.1		//インベーダーの移動速度
#define MOVE_COUNT		400		//インベーダーの折り返しカウント
#define PI 				3.141592//π
#define HEIGHT			480		//画面縦幅
#define SHOT_X			20		//弾発射位置を真ん中に調整

class INVADER{
public:
	INVADER(int x, int y);				//constructor
	void InvaderPoint(int x, int y);	//描画
	void Coordinate();					//座標
	void Magnification();				//倍率変更
	void Initialization();				//初期化
	void Move();						//動き
	bool Shot(int y);					//攻撃
	void Dead();						//死亡
	int DrawyReturn();					//弾発射時用drawy渡し
	int ShotxReturn();					//当たり判定時shotx渡し
	bool Hit(int uShotx, int uShoty);	//当たり判定
private:
	bool life;			//生死判定
	double invx,invy;	//bool invaderの座標取得ループの値保存用
	double drawx, drawy;//描画位置
	int shotx; 			//弾発射時のx座標保存
	int mcount; 		//移動距離記憶
	bool move; 			//移動方向記憶
	const bool invader[10][10] = {
	// y 0 1 2 3 4 5 6 7 8 9     x
		{0,0,0,0,0,1,1,1,0,0,},//0
		{0,0,0,0,1,1,0,0,0,0,},//1
		{0,1,0,1,1,1,1,1,0,0,},//2
		{0,0,1,1,0,1,1,0,1,0,},//3
		{0,0,0,1,1,1,1,0,0,0,},//4
		{0,0,0,1,1,1,1,0,0,0,},//5
		{0,0,1,1,0,1,1,0,1,0,},//6
		{0,1,0,1,1,1,1,1,0,0,},//7
		{0,0,0,0,1,1,0,0,0,0,},//8
		{0,0,0,0,0,1,1,1,0,0,},//9
		};
};

#endif