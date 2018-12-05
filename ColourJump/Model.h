#pragma once
#include "Player.h"
#include "Block.h"
#include "Button.h"
#include <vector>


class Model
{
public:
	Model();
	~Model();

	void incScore() { this->score += 0.1; }
	void setScore(double score) { this->score = score; }
	double getScore() { return this->score; }

	Player player;
	std::vector<Block> blocks;
	Button playButton;
private:
	double score;
};

