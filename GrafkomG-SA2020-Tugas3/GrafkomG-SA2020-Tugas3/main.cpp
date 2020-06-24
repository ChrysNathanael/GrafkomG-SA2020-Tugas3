#include <iostream>
#include <array>
#include <vector>
#include <GL/freeglut.h>

using namespace std;

int un[1000];
int idx;

void display() {

}


void myMouse(int mouseX, int mouseY)//harus di klik
{
	system("cls");
	std::cout <<  " mouseX: " << mouseX << " | mouseY: " << mouseY << std::endl;
}
void myKeyboard(unsigned char key, int mouseX, int mouseY)
{
	int ukur = sizeof(un) / sizeof(un[0]);
	int search = key;
	auto cek = find(un, un + ukur, key);
	std::cout << key << " ";

	if (cek == end(un)) {
		un[idx] = key;
		idx++;
	}
}

void myKeyboardup(unsigned char key, int mouseX, int mouseY)
{
	system("cls");
	int ukur = sizeof(un) / sizeof(un[0]);
	int search = key;
	auto cek = find(un, un + ukur, key);
	std::cout << key << " ";

	if (cek == end(un)) {
		un[distance(un,cek)] = 0;
		idx++;
	}

}

void myinit() {
	glClearColor(1.0, 1.0, 1.0, 1.0);
	glColor3f(1.0, 0.0, 0.0);
	glPointSize(2.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0.0, 100.0, 0.0, 100.0);
}

int main(int argc, char** argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(400, 400);
	glutInitWindowPosition(0, 300);
	glutCreateWindow("Points");
	glutDisplayFunc(display);
	glutKeyboardFunc(myKeyboard);
	glutKeyboardUpFunc(myKeyboardup);
	glutPassiveMotionFunc(myMouse);
	myinit();
	glutMainLoop();

	return 0;
}