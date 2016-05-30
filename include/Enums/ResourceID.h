#pragma once

enum class ResourceID {
	VOID,

	BitmapFont_default_8,
	BitmapFont_default_12,
	BitmapFont_shadowed_8,
	BitmapFont_shadowed_12,
	Configuration,
	Quicksave,
	Save_folder,
	Items,
	Npc_folder,
	Texture_mapmarkers,
	Texture_spellicons,
	Texture_spellscroll,
	Texture_damageTypes,
	Texture_mainChar,
	Texture_mapMainChar,
	Texture_spell_fireball,
	Texture_spell_iceball,
	Texture_spell_divineshield,
	Texture_spell_aureola,
	Texture_spell_fear,
	Texture_spell_icyambush,
	Texture_spell_unlock,
	Texture_spell_telekinesis,
	Texture_spell_flash,
	Texture_spell_leapoffaith,
	Texture_spell_ghost,
	Texture_spell_shadowtrap,
	Texture_spell_projectile,
	Texture_spell_returningprojectile,
	Texture_spell_boomerang,
	Texture_tile_ice,
	Texture_tile_destructible,
	Texture_tile_torch,
	Texture_tile_chest,
	Texture_tile_spikestop,
	Texture_tile_spikesbottom,
	Texture_tile_frozenwater,
	Texture_tile_shiftable,
	Texture_tile_checkpoint,
	Texture_tile_lever,
	Texture_tile_switchable,
	Texture_tile_cooking,
	Texture_tile_moving,
	Texture_tile_waypoint,
	Texture_tile_book,
	Texture_tile_sign_map,
	Texture_tile_sign_level,
	Texture_tile_unstable,
	Texture_tile_falling,
	Texture_tile_jumping,
	Texture_tile_shooting,
	Texture_debuff_fear,
	Texture_debuff_stun,
	Texture_screen_splash,
	Texture_screen_splash_fireanimation,
	Texture_screen_error_fileNotFound,
	Texture_screen_error_dataCorrupted,
	Texture_screen_gameover,
	Texture_screen_overlay,
	Texture_screen_overlay_stunned,
	Texture_screen_overlay_feared,
	Texture_screen_menu,
	Texture_screen_credits,
	Texture_text_gameover,
	Texture_text_gamepaused,
	Texture_text_defeated,
	Texture_enemy_rat,
	Texture_enemy_firerat,
	Texture_enemy_nekomata,
	Texture_enemy_crow,
	Texture_enemy_skeleton,
	Texture_enemy_gargoyle,
	Texture_enemy_hunter,
	Texture_enemy_wisp,
	Texture_enemy_seagull,
	Texture_enemy_wolf,
	Texture_enemy_stoneman,
	Texture_boss_zeff,
	Texture_levelitems,
	Texture_items,
	Texture_dialogue,
	Texture_inventorytabs,
	Texture_equipmentplaceholders,
	Texture_gems,
	Texture_misc_cooking,
	Texture_GUI_rounded_rectangle,
	Texture_GUI_ornament_none,
	Texture_GUI_ornament_small,
	Texture_GUI_ornament_medium,
	Texture_GUI_ornament_large,
	Texture_GUI_window_close_button,
	Texture_GUI_arrow,
	Texture_GUI_arrow_left,
	Texture_GUI_arrow_right,
	Texture_GUI_exit_arrow,
	Texture_GUI_checkbox,
	Texture_GUI_slider,
	Texture_GUI_knob,
	Texture_GUI_spell_color_elemental,
	Texture_GUI_spell_color_twilight,
	Texture_GUI_spell_color_necromancy,
	Texture_GUI_spell_color_divine,
	Texture_GUI_spell_color_illusion,
	Texture_GUI_slot_inventory,
	Texture_GUI_slot_inventory_selected,
	Texture_GUI_slot_modifier,
	Texture_GUI_slot_modifier_selected,
	Texture_GUI_slot_spell,
	Texture_GUI_slot_spell_selected,
	Texture_GUI_slot_spell_gem,
	Texture_GUI_slot_highlight,
	Texture_GUI_tab_inactive,
	Texture_GUI_tab_active,
	Texture_GUI_cursor,
	Texture_GUI_speechbubble_pointer,
	Texture_GUI_healthbar_mainChar_border,
	Texture_GUI_healthbar_enemy_border,
	Texture_GUI_healthbar_content,
	Texture_GUI_healthbar_content_hit,
	Texture_GUI_healthbar_content_highlight,
	Texture_Particle_circle,
	Texture_Particle_blob,
	Texture_Particle_blob2,
	Texture_Particle_longblob,
	Texture_Particle_snowflake,
	Texture_Particle_smoke,
	Texture_Particle_flame,
	Texture_Particle_star,
	Texture_Particle_rain,
	Texture_Particle_snow,
	Sound_spell_fireball,
	Sound_tile_water,
	Sound_tile_lever,
	Sound_tile_waypoint,
	Sound_tile_checkpoint,
	Sound_tile_destructible,
	Sound_gui_turnpage,
	Sound_gui_menucursor,
	Sound_gui_openwindow,
	Sound_item_gold,
	Sound_cendric_death,
};