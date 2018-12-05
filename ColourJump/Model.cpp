#include "Model.h"

Model::Model()
{
	player.setGrounded(false);
	player.setPos(500,200);
	player.setSize(15);
	playButton.setRect(30, 30, 150, 30);

	Block block;
	block.setRect(500,400,32,32);
	blocks.push_back(block);
	block.setRect(532, 400, 32, 32);
	blocks.push_back(block);
	block.setRect(564, 400, 32, 32);
	blocks.push_back(block);
	block.setRect(468, 400, 32, 32);
	blocks.push_back(block);
}


Model::~Model()
{
}
