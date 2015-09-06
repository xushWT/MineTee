#ifndef ENGINE_SHARED_BLOCK_PROVIDER_H
#define ENGINE_SHARED_BLOCK_PROVIDER_H
#include <engine/external/json-parser/json.h>
#include <map>
#include <base/tl/array.h>


class CBlockManager
{
public:
    enum
    {
		AIR=0,
		STONE,
		DIRT,
		GRASS,
		BROWN_TABLE_HORIZONTAL,
		STONE_CLEAN_B,
		STONE_CLEAN,
		BRICK,
		TNT,
		SPIDER_WEB=11,
		ROSE,
		DAISY,
		BROWN_TREE_SAPLING=15,
		STONE_B,
		BEDROCK=19,
		WOOD_BROWN,
		IRON_BLOCK=22,
		GOLD_BLOCK,
		DIAMOND_BLOCK,
		CHEST=27,
		MUSHROOM_RED,
		MUSHROOM_BROWN,
		COAL,
		GUNPOWDER,
		GOLD_ORE,
		IRON_ORE,
		COAL_ORE,
		LIBRARY,
		VIOLET_BLOCK=37,
		MIDDLE_STONE_TOP,
		LARGE_CHEST_LEFT=41,
		LARGE_CHEST_RIGHT,
		OVEN_OFF=44,
		WHEAT=47,
		GLASS=49,
		DIAMOND_ORE,
		REDSTONE_ORE,
		STONE_BRICK=54,
		OVEN_ON=61,
		WHITE_WOOL=64,
		MONSTER_SPAWNER,
		SNOW,
		GLASS_BLUE,
		DIRT_SNOW,
		LEAFS,
		CACTUS,
		SUGAR_CANE=73,
		DIRT_STONE=77,
		DIRT_STONE_BLOCK,
		BIRCH_TREE_SAPLING,
		TORCH,
		WOODEN_WINDOW_B,
		IRON_WINDOW,
		WOODEN_FENCE,
		WOODEN_WINDOW_A,
		IRON_FENCE,
		GROUND_CULTIVATION_WET,
		GROUND_CULTIVATION_DRY,
		GRASS_A,
		GRASS_B,
		GRASS_C,
		GRASS_D,
		GRASS_E,
		GRASS_F,
		GRASS_G,
		WHEAT_PLANT,
		BROWN_TABLE_VERTICAL=97,
		STONE_BRICK_IVY=100,
		STONE_BRICK_DIRTY,
		STONE_W_SMALL_TABLE=108,
		STONE_STICK=111,
		DARK_WOOL=113,
		GRAY_WOOL,
		WOOD_BIRCH=117,
		PUMPKIN,
		PUMPKIN_ON,
		PUMPKIN_OFF,
		CAKE=122,
		HALF_CAKE,
		RED_WOOL=129,
		PINK_WOOL,
		STONE_WINDOW=132,
		STONE_WINDOW_CLOSED,
		RED_BLOCK,
		MELON=136,
		EMPTY_INDICATOR=138,
		DARK_GRAY_BLOCK,
		LAPISLAZULIS=144,
		DARK_GREEN_WOOL,
		GREEN_WOOL,
		LASER_STICK=148,
		CHAIR,
		LARGE_BED_LEFT,
		LARGE_BED_RIGHT,
		BED,
		SHADOW_A=154,
		BREWING_STAND=157,
		END_PORTAL_FRAME,
		END_PORTAL_STONE,
		LAPISLAZULIS_ORE,
		BROWN_WOOL,
		YELLOW_WOOL,
		IRON_STICK_HORIZONTAL=165,
		ENCHANTING_BLOCK,
		OBSIDIAN_B,
		BONE,
		SHADOW_B=170,
		CAULDRON,
		PAPER,
		BOOK,
		SPOT_LIGHT,
		END_STONE,
		SAND,
		DARK_BLUE_WOOL,
		BLUE_WOOL,
		ENCHANTING_TABLE=182,
		OBSIDIAN_A,
		SEED,
		SHADOW_C=186,
		COW_LEATHER,
		SANDSTONE=192,
		DARK_MAGENTA_WOOL,
		MAGENTA_WOOL,
		SHADOW_D=202,
		WATER_D=204,
		WATER_C,
		WATER_B,
		WATER_A,
		CYAN_WOOL=209,
		ORANGE_WOOL,
		IRON_INGOT,
		GOLD_INGOT,
		DIAMOND,
		DARK_BRICK=224,
		LIGHT_GRAY_WOOL,
		RED_MUSHROOM_A,
		RED_MUSHROOM_B,
		RED_MUSHROOM_C,
		LAVA_A=236,
		LAVA_B,
		LAVA_C,
		LAVA_D,
		MAX_BLOCKS=256,

		FLUID_WATER=1,
		FLUID_LAVA,
    };

	struct CBlockInfo
	{
    	void Reset()
    	{
    		mem_zero(m_aName, sizeof(m_aName));
    		m_Health = 1;
    		m_LightSize = 0;
    		m_CraftNum = 1;
    		m_Gravity = false;
    		m_Damage = false;
    		m_HalfTile = false;
    		m_PlayerCollide = true;
    		m_OnPut = -1;
    		m_vOnBreak.clear();
    		m_vOnCook.clear();
    		m_vCraft.clear();
    	}

		char m_aName[24];
		int m_Health;
		int m_LightSize;
		int m_CraftNum;
		bool m_Gravity;
		bool m_Damage;
		bool m_HalfTile;
		bool m_PlayerCollide;
		int m_OnPut;
		std::map<int, unsigned char> m_vOnBreak;
		std::map<int, unsigned char> m_vOnCook;
		std::map<int, unsigned char> m_vCraft;
	};

	CBlockManager();
	~CBlockManager();

	bool Init();

	bool GetBlockInfo(unsigned char BlockID, CBlockInfo *pBlockInfo);
	bool IsFluid(int BlockID, int *pType = 0x0);

private:
	json_value *m_pJsonData;
	json_settings m_JsonSettings;
};

#endif