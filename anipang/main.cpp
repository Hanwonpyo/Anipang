#include "consoleController.h"
int main()
{
	MapManager::GetInstance()->makeMap();
	consoleController control;
	//�ݺ��ؼ������ؾ���
	control.printInput();
	return 0;
}