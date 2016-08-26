#pragma once

#include <vector>

class BlockPos;
class Item;
class ItemInstance;
class Level;
class Player;
class Vec3;

namespace Json {
	class Value;
}

// size: 36 bytes
class FoodItemComponent {

public:
	class Effect;

	Item &item; // 0
	float nutrition; // 4
	float saturationModifier; // 8
	bool isMeat; // 12
	std::string eatSound; // 16
	char filler[16]; // 20

	FoodItemComponent(Item&);

	void _applyEatEffects(ItemInstance&, Player&, Level&);
	void _loadEffects(std::vector<FoodItemComponent::Effect>&, Json::Value&);
	int getNutrition();
	int getSaturationModifier();
	void init(Json::Value&);
	void use(ItemInstance&, Player&);
	bool useOn(ItemInstance&, Player&, BlockPos const&, signed char, Vec3 const&);
	void useTimeDepleted(ItemInstance&, Player&, Level&);
	
};
