#include "invaderClass.h"
#include "unitClass.h"
#include <GLUT/glut.h>
#include <cstdlib>
#include <ctime>

#define WIDTH 			640		//画面横幅
#define HEIGHT			480		//画面縦幅
#define INVADER_Y 		40		//インベーダー初期位置Y軸

//UNIT弾発射判定
GLboolean unitBulletParameter = GL_FALSE;
UNIT unit;
int unitMove = 0;

void display(){
	glClear(GL_COLOR_BUFFER_BIT);
	static INVADER inv0( 40, INVADER_Y), inv1(120, INVADER_Y), inv2(200, INVADER_Y), inv3(280, INVADER_Y),
				   inv4(360, INVADER_Y), inv5(440, INVADER_Y), inv6(520, INVADER_Y), inv7(600, INVADER_Y);
	
	//弾発射判定用
	static bool inv0b = false, inv1b = false, inv2b = false, inv3b = false,
				inv4b = false, inv5b = false, inv6b = false, inv7b = false;

	//Invader描画
	inv0.Move();inv1.Move();inv2.Move();inv3.Move();
	inv4.Move();inv5.Move();inv6.Move();inv7.Move();

	//Unit描画
	unit.Initialization();

	//unit射撃のための条件式
	if(unitBulletParameter == GL_TRUE){
		static int i = UNIT_Y;	//弾のy座標
		int x;				//弾のx座標
		x = unit.Shot(i);
		i -= 8;
		if(i < 0){
			i = UNIT_Y;
			unitBulletParameter = GL_FALSE;
		}
		//それぞれの当たり判定に重なるかチェック。重なれば弾は消える。
		if(inv0.Hit(x,i)){unitBulletParameter = GL_FALSE; i = UNIT_Y;}
		if(inv1.Hit(x,i)){unitBulletParameter = GL_FALSE; i = UNIT_Y;}
		if(inv2.Hit(x,i)){unitBulletParameter = GL_FALSE; i = UNIT_Y;}
		if(inv3.Hit(x,i)){unitBulletParameter = GL_FALSE; i = UNIT_Y;}
		if(inv4.Hit(x,i)){unitBulletParameter = GL_FALSE; i = UNIT_Y;}
		if(inv5.Hit(x,i)){unitBulletParameter = GL_FALSE; i = UNIT_Y;}
		if(inv6.Hit(x,i)){unitBulletParameter = GL_FALSE; i = UNIT_Y;}
		if(inv7.Hit(x,i)){unitBulletParameter = GL_FALSE; i = UNIT_Y;}
	}

	//敵弾発射ランダム
	switch(rand() % 400){
		case 0:
			inv0b = true;
			break;
		case 1:
			inv1b = true;
			break;
		case 2:
			inv2b = true;
			break;
		case 3:
			inv3b = true;
			break;
		case 4:
			inv4b = true;
			break;
		case 5:
			inv5b = true;
			break;
		case 6:
			inv6b = true;
			break;
		case 7:
			inv7b = true;
			break;
	}

	//敵の弾発射部分
	if(inv0b){
		bool foo = false;
		int x;
		static int i = 0;
		if(i >= HEIGHT){
			i = inv0.DrawyReturn();
		}
		inv0b = inv0.Shot(i);
		i += 4;
		x = inv0.ShotxReturn();
		unit.Hit(x+SHOT_X, i);
	}

	if(inv1b){
		int x;
		static int i = 0;
		if(i >= HEIGHT){
			i = inv1.DrawyReturn();
		}
		inv1b = inv1.Shot(i);
		i += 4;
		x = inv1.ShotxReturn();
		unit.Hit(x+SHOT_X, i);
	}

	if(inv2b){
		int x;
		static int i = 0;
		if(i >= HEIGHT){
			i = inv2.DrawyReturn();
		}
		inv2b = inv2.Shot(i);
		i += 4;
		x = inv2.ShotxReturn();
		unit.Hit(x+SHOT_X, i);
	}

	if(inv3b){
		int x;
		static int i = 0;
		if(i >= HEIGHT){
			i = inv3.DrawyReturn();
		}
		inv3b = inv3.Shot(i);
		i += 4;
		x = inv3.ShotxReturn();
		unit.Hit(x+SHOT_X, i);
	}

	if(inv4b){
		int x;
		static int i = 0;
		if(i >= HEIGHT){
			i = inv4.DrawyReturn();
		}
		inv4b = inv4.Shot(i);
		i += 4;
		x = inv4.ShotxReturn();
		unit.Hit(x+SHOT_X, i);
	}

	if(inv5b){
		int x;
		static int i = 0;
		if(i >= HEIGHT){
			i = inv5.DrawyReturn();
		}
		inv5b = inv5.Shot(i);
		i += 4;
		x = inv5.ShotxReturn();
		unit.Hit(x+SHOT_X, i);
	}

	if(inv6b){
		int x;
		static int i = 0;
		if(i >= HEIGHT){
			i = inv6.DrawyReturn();
		}
		inv6b = inv6.Shot(i);
		i += 4;
		x = inv6.ShotxReturn();
		unit.Hit(x+SHOT_X, i);
	}

	if(inv7b){
		int x;
		static int i = 0;
		if(i >= HEIGHT){
			i = inv7.DrawyReturn();
		}
		inv7b = inv7.Shot(i);
		i += 4;
		x = inv7.ShotxReturn();
		unit.Hit(x+SHOT_X, i);
	}

	glutSwapBuffers();
}

void UnitMove(){
	if(unitMove == 1)unit.LeftMove();
	else if(unitMove == 2)unit.RightMove();
	glutPostRedisplay();
}

void keyboard(unsigned char key, int x, int y){
	switch(key){
		case ' ':
			unitBulletParameter = GL_TRUE;
			glutPostRedisplay();
			break;
		case 'a':
		case 'A':
			unitMove = 1;
			break;
		case 'd':
		case 'D':
			unitMove = 2;
			break;
		case 'q':
		case 'Q':
		case '\033':
			exit(0);
	}
}

void keyboardup(unsigned char key, int x, int y){
	switch(key){
		case 'a':
		case 'A':
			unitMove = 0;
			break;
		case 'd':
		case 'D':
			unitMove = 0;
			break;
	}
}

void specialKey(int key, int x, int y){
	switch(key){
		case GLUT_KEY_LEFT:
			unitMove = 1;
			break;
		case GLUT_KEY_RIGHT:
			unitMove = 2;
			break;
	}
}

void specialUpKey(int key, int x, int y){
	switch(key){
		case GLUT_KEY_LEFT:
			unitMove = 0;
			break;
		case GLUT_KEY_RIGHT:
			unitMove = 0;
			break;
	}
}

void timer(int value){
	glutIdleFunc(UnitMove);
	glutTimerFunc(50,timer,0);
}

void Init(){
	glClearColor(0.0,0.0,0.0,0.0);
	glOrtho(0,WIDTH,HEIGHT,0,-1,1);
}

void resize(int w, int h){
	glViewport(0,0,w,h);
	glLoadIdentity();
	glOrtho(0,WIDTH,HEIGHT,0,-1,1);
}

int main(int argc, char *argv[]){
	srand((unsigned int)time(NULL));
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGBA | GLUT_DOUBLE);
	glutInitWindowSize(WIDTH,HEIGHT);
	glutCreateWindow("Invader");
	glutDisplayFunc(display);
	glutKeyboardFunc(keyboard);
	glutKeyboardUpFunc(keyboardup);
	glutSpecialFunc(specialKey);
	glutSpecialUpFunc(specialUpKey);
	glutIgnoreKeyRepeat(GL_TRUE);	 //キーの繰り返し入力を無視
	glutReshapeFunc(resize);
	glutTimerFunc(100,timer,0);
	Init();
	glutMainLoop();
	return 0;
}