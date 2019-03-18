#include "chapters.h"
#include <string>

// yeah

static std::string sp_a1 = "sp_a1";
static std::string sp_a2 = "sp_a2";
static std::string sp_a3 = "sp_a3";
static std::string sp_a4 = "sp_a4";
static std::string sp_a4_finale = "sp_a4_finale";

static const char* ch1name = "The Courtesy Call";
static const char* ch2name = "The Cold Boot";
static const char* ch3name = "The Return";
static const char* ch4name = "The Surprise";
static const char* ch6name = "The Fall";

static std::string mp_coop_lobby = "mp_coop_lobby";
static std::string mp_coop_tbeam = "mp_coop_tbeam";

static const char* c1name = "Team Building";
static const char* c2name = "Mass and Velocity";
static const char* c3name = "Hard-Light Surfaces";
static const char* c5name = "Mobility Gels";
static const char* c6name = "Art Therapy";

const char* GetChapterName(const char* mapname) {
	std::string map = mapname;

	// sp
	if (map.compare(0, sp_a1.length(), sp_a1) == 0) return ch1name;
	if (map == "sp_a2_intro") return ch1name;

	if (map.compare(0, sp_a2.length(), sp_a2) == 0) {
		if (map == "sp_a2_laser_intro") return ch2name;
		if (map == "sp_a2_laser_stairs") return ch2name;
		if (map == "sp_a2_dual_lasers") return ch2name;
		if (map == "sp_a2_laser_over_goo") return ch2name;
		if (map == "sp_a2_catapult_intro") return ch2name;
		if (map == "sp_a2_trust_fling") return ch2name;
		if (map == "sp_a2_pit_flings") return ch2name;
		if (map == "sp_a2_fizzler_intro") return ch2name;

		if (map == "sp_a2_sphere_peek") return ch3name;
		if (map == "sp_a2_ricochet") return ch3name;
		if (map == "sp_a2_bridge_intro") return ch3name;
		if (map == "sp_a2_bridge_the_gap") return ch3name;
		if (map == "sp_a2_turret_intro") return ch3name;
		if (map == "sp_a2_laser_relays") return ch3name;
		if (map == "sp_a2_turret_blocker") return ch3name;
		if (map == "sp_a2_laser_vs_turret") return ch3name;
		if (map == "sp_a2_pull_the_rug") return ch3name;

		if (map == "sp_a2_column_blocker") return ch4name;
		if (map == "sp_a2_laser_chaining") return ch4name;
		if (map == "sp_a2_triple_laser") return ch4name;
		if (map == "sp_a2_bts1") return ch4name;
		if (map == "sp_a2_bts2") return ch4name;

		return "The Escape";
	}

	if (map.compare(0, sp_a3.length(), sp_a3) == 0) {
		if (map == "sp_a3_00") return ch6name;
		if (map == "sp_a3_01") return ch6name;
		if (map == "sp_a3_03") return ch6name;
		if (map == "sp_a3_jump_intro") return ch6name;
		if (map == "sp_a3_bomb_flings") return ch6name;
		if (map == "sp_a3_crazy_box") return ch6name;
		if (map == "sp_a3_transition01") return ch6name;

		return "The Reunion";
	}

	if (map.compare(0, sp_a4.length(), sp_a4) == 0) {
		if (map.compare(0, sp_a4_finale.length(), sp_a4_finale) == 0) return "The Part Where...";
		return "The Itch";
	}

	if (map == "sp_a5_credits") return "The Credits";

	// coop
	if (map.compare(0, mp_coop_lobby.length(), mp_coop_lobby) == 0) return "The Hub";
	if (map == "mp_coop_start") return "Calibration Course";

	if (map == "mp_coop_doors") return c1name;
	if (map == "mp_coop_race_2") return c1name;
	if (map == "mp_coop_laser_2") return c1name;
	if (map == "mp_coop_rat_maze") return c1name;
	if (map == "mp_coop_laser_crusher") return c1name;
	if (map == "mp_coop_teambts") return c1name;

	if (map == "mp_coop_fling3") return c2name;
	if (map == "mp_coop_infinifling_train") return c2name;
	if (map == "mp_coop_come_along") return c2name;
	if (map == "mp_coop_fling_1") return c2name;
	if (map == "mp_coop_catapult_1") return c2name;
	if (map == "mp_coop_multifling_1") return c2name;
	if (map == "mp_coop_fling_crushers") return c2name;
	if (map == "mp_coop_fan") return c2name;

	if (map == "mp_coop_wall_intro") return c3name;
	if (map == "mp_coop_wall_2") return c3name;
	if (map == "mp_coop_catapult_wall_intro") return c3name;
	if (map == "mp_coop_wall_block") return c3name;
	if (map == "mp_coop_catapult_2") return c3name;
	if (map == "mp_coop_turret_walls") return c3name;
	if (map == "mp_coop_turret_ball") return c3name;
	if (map == "mp_coop_wall_5") return c3name;

	if (map.compare(0, mp_coop_tbeam.length(), mp_coop_tbeam) == 0) return "Excursion Funnels";

	if (map == "mp_coop_paint_come_along") return c5name;
	if (map == "mp_coop_paint_redirect") return c5name;
	if (map == "mp_coop_paint_bridge") return c5name;
	if (map == "mp_coop_paint_walljumps") return c5name;
	if (map == "mp_coop_paint_speed_fling") return c5name;
	if (map == "mp_coop_paint_red_racer") return c5name;
	if (map == "mp_coop_paint_speed_catch") return c5name;
	if (map == "mp_coop_paint_longjump_intro") return c5name;

	if (map == "mp_coop_separation_1") return c6name;
	if (map == "mp_coop_tripleaxis") return c6name;
	if (map == "mp_coop_catapult_catch") return c6name;
	if (map == "mp_coop_2paints_1bridge") return c6name;
	if (map == "mp_coop_paint_conversion") return c6name;
	if (map == "mp_coop_bridge_catch") return c6name;
	if (map == "mp_coop_laser_tbeam") return c6name;
	if (map == "mp_coop_paint_rat_maze") return c6name;
	if (map == "mp_coop_paint_crazy_box") return c6name;

	if (map == "mp_coop_credits") return "The Credits";

	if (map == "e1912") return "Super 8 - Interactive Teaser";

	return mapname;
}