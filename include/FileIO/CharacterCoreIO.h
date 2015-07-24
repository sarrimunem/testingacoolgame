#pragma once

#include "global.h"

// some constants used by character core reader & writer
class CharacterCoreIO
{
protected:
	const char* TIME_PLAYED = "time.played";

	// attributes
	const char* ATTRIBUTES = "attributes";

	// position & progress
	const char* MAP_ID = "map.id";
	const char* MAP_POSITION = "map.position";
	const char* LEVEL_ID = "level.id";
	const char* LEVEL_POSITION = "level.position";
	const char* LEVEL_KILLED = "level.killed";
	const char* LEVEL_LOOTED = "level.looted";
	const char* QUEST_STATE = "quest.state";
	const char* NPC_STATE = "npc.state";

	// equipment & items
	const char* GOLD = "gold";
	const char* ITEM_ID = "item.id";
	const char* EQUIPPED_WEAPON = "equipped.weapon";
	const char* EQUIPPED_HEAD = "equipped.head";
	const char* EQUIPPED_BODY = "equipped.body";
	const char* EQUIPPED_RING_1 = "equipped.ring1";
	const char* EQUIPPED_RING_2 = "equipped.ring2";
	const char* EQUIPPED_NECK = "equipped.neck";
	const char* EQUIPPED_BACK = "equipped.back";
};