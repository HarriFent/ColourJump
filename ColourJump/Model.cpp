#include "Model.h"

Model::Model()
{
	player.setGrounded(false);
	player.setPos(500, 200);
	player.setSize(15);
	playButton.setRect(30, 30, 150, 30);


	// 32 x 24 Blocks on the screen
	Block block;
	block.setRect(13 * 32, 16 * 32, 32, 32);
	blocks.push_back(block);
	block.setRect(13 * 32, 17 * 32, 32, 32);
	blocks.push_back(block);
	block.setRect(13 * 32, 18 * 32, 32, 32);
	blocks.push_back(block);
	block.setRect(14 * 32, 18 * 32, 32, 32);
	blocks.push_back(block);
	block.setRect(15 * 32, 18 * 32, 32, 32);
	blocks.push_back(block);
	block.setRect(16 * 32, 18 * 32, 32, 32);
	blocks.push_back(block);
	block.setRect(17 * 32, 18 * 32, 32, 32);
	blocks.push_back(block);
	block.setRect(18 * 32, 18 * 32, 32, 32);
	blocks.push_back(block);
	block.setRect(18 * 32, 17 * 32, 32, 32);
	blocks.push_back(block);
	block.setRect(18 * 32, 16 * 32, 32, 32);
	blocks.push_back(block);
	block.setRect(19 * 32, 16 * 32, 32, 32);
	blocks.push_back(block);
	block.setRect(20 * 32, 16 * 32, 32, 32);
	blocks.push_back(block);
	block.setRect(21 * 32, 16 * 32, 32, 32);
	blocks.push_back(block);
	block.setRect(22 * 32, 16 * 32, 32, 32);
	blocks.push_back(block);
	block.setRect(23 * 32, 16 * 32, 32, 32);
	blocks.push_back(block);
	block.setRect(24 * 32, 16 * 32, 32, 32);
	blocks.push_back(block);
	block.setRect(25 * 32, 16 * 32, 32, 32);
	blocks.push_back(block);
	block.setRect(26 * 32, 16 * 32, 32, 32);
	blocks.push_back(block);
	block.setRect(27 * 32, 16 * 32, 32, 32);
	blocks.push_back(block);
	block.setRect(28 * 32, 16 * 32, 32, 32);
	blocks.push_back(block);
	block.setRect(29 * 32, 16 * 32, 32, 32);
	blocks.push_back(block);
	block.setRect(30 * 32, 16 * 32, 32, 32);
	blocks.push_back(block);
	for (int i = 0; i < 10; i++)
	{
		block.setRect((3 + i) * 32, 16 * 32, 32, 32);
		blocks.push_back(block);
	}
}


Model::~Model()
{
}
