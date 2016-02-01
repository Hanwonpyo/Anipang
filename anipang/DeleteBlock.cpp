#include "DeleteBlock.h"

DeleteBlock::DeleteBlock(vector vec_delete)
{
	for (int i = 0; i < vec_delete.size(); i++) {
		MapManager::GetInstance()->deleteBlock(vec_delete[i].getX, vec_delete[i].getY);
	}
}