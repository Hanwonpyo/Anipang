#include "consoleController.h"
int main()
{
	MapManager::GetInstance()->makeMap();
	consoleController control;
	//�ݺ��ؼ������ؾ���
	while (1) {
		control.printInput();
	}
	return 0;
}