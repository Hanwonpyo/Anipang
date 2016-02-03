#include "MapManager.h"
#include "Block.h"
#include <vector>
using namespace std;

class DeleteBlock {
private:
	vector<Block> vec_delete;
public:
	DeleteBlock(vector<Block> vec_delete);
};