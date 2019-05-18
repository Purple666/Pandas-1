﻿// Copyright (c) rAthena Dev Teams - Licensed under GNU GPL
// For more information, see LICENCE in the main folder

#ifndef MMO_HPP
#define MMO_HPP

#include <time.h>

#include "../config/core.hpp"

#include "cbasetypes.hpp"
#include "db.hpp"
#include "timer.hpp" // t_tick

#ifndef PACKETVER
	#error Please define PACKETVER in src/config/packets.hpp
#endif

///Remove/Comment this line to disable sc_data saving. [Skotlex]
#define ENABLE_SC_SAVING
/** Remove/Comment this line to disable server-side hot-key saving support [Skotlex]
* Note that newer clients no longer save hotkeys in the registry! */
#define HOTKEY_SAVING

#if PACKETVER < 20090603
	// (27 = 9 skills x 3 bars)               (0x02b9,191)
	#define MAX_HOTKEYS 27
#elif PACKETVER < 20090617
	// (36 = 9 skills x 4 bars)               (0x07d9,254)
	#define MAX_HOTKEYS 36
#else
	// (38 = 9 skills x 4 bars & 2 Quickslots)(0x07d9,268)
	#define MAX_HOTKEYS 38
#endif

#define MAX_MAP_PER_SERVER 1500 /// Maximum amount of maps available on a server
#define MAX_INVENTORY 100 ///Maximum items in player inventory
/** Max number of characters per account. Note that changing this setting alone is not enough if the client is not hexed to support more characters as well.
* Max value tested was 265 */
#ifndef MAX_CHARS
	#if PACKETVER >= 20180124
		#define MAX_CHARS 15
	#elif PACKETVER >= 20100413
		#define MAX_CHARS 12
	#else
		#define MAX_CHARS 9
	#endif
#endif
/** Number of slots carded equipment can have. Never set to less than 4 as they are also used to keep the data of forged items/equipment. [Skotlex]
* Note: The client seems unable to receive data for more than 4 slots due to all related packets having a fixed size. */
#define MAX_SLOTS 4
#define MAX_AMOUNT 30000 ////Max amount of a single stacked item
#define MAX_ZENY INT_MAX ///Max zeny
#define MAX_BANK_ZENY SINT32_MAX ///Max zeny in Bank
#define MAX_FAME 1000000000 ///Max fame points
#define MAX_CART 100 ///Maximum item in cart
#define MAX_SKILL 1250 ///Maximum skill can be hold by Player, Homunculus, & Mercenary (skill list) AND skill_db limit
#define DEFAULT_WALK_SPEED 150 ///Default walk speed
#define MIN_WALK_SPEED 20 ///Min walk speed
#define MAX_WALK_SPEED 1000 ///Max walk speed
#define MAX_STORAGE 600 ///Max number of storage slots a player can have
#define MAX_GUILD_STORAGE 600 ///Max number of storage slots a guild
#define MAX_PARTY 12 ///Max party member
#define MAX_GUILD 16+10*6	///Increased max guild members +6 per 1 extension levels [Lupus]
#define MAX_GUILDPOSITION 20	///Increased max guild positions to accomodate for all members [Valaris] (removed) [PoW]
#define MAX_GUILDEXPULSION 32 ///Max Guild expulsion
#define MAX_GUILDALLIANCE 16 ///Max Guild alliance
#define MAX_GUILDSKILL	17 ///Max Guild skills
#define MAX_GUILDLEVEL 50 ///Max Guild level
#define MAX_GUARDIANS 8	///Local max per castle. If this value is increased, need to add more fields on MySQL `guild_castle` table [Skotlex]
#define MAX_QUEST_OBJECTIVES 3 ///Max quest objectives for a quest
#define MAX_QUEST_DROPS 3 ///Max quest drops for a quest
#define MAX_PC_BONUS_SCRIPT 50 ///Max bonus script can be fetched from `bonus_script` table on player load [Cydh]
#define MAX_ITEM_RDM_OPT 5	 /// Max item random option [Napster]
#define DB_NAME_LEN 256 //max len of dbs
#define MAX_CLAN 500
#define MAX_CLANALLIANCE 6

// for produce
#define MIN_ATTRIBUTE 0
#define MAX_ATTRIBUTE 4
#define ATTRIBUTE_NORMAL 0
#define MIN_STAR 0
#define MAX_STAR 3

#define MAX_STATUS_TYPE 5

#define WEDDING_RING_M 2634
#define WEDDING_RING_F 2635

//For character names, title names, guilds, maps, etc.
//Includes null-terminator as it is the length of the array.
#define NAME_LENGTH (23 + 1)
#define PASSWD_LENGTH (32+1)
//NPC names can be longer than it's displayed on client (NAME_LENGTH).
#define NPC_NAME_LENGTH 50
// <NPC_NAME_LENGTH> for npc name + 2 for a "::" + <NAME_LENGTH> for label + 1 for EOS
#define EVENT_NAME_LENGTH ( NPC_NAME_LENGTH + 2 + NAME_LENGTH + 1 )
//For item names, which tend to have much longer names.
#define ITEM_NAME_LENGTH 50
//For Map Names, which the client considers to be 16 in length including the .gat extension
#define MAP_NAME_LENGTH (11 + 1)
#define MAP_NAME_LENGTH_EXT (MAP_NAME_LENGTH + 4)
//Pincode Length
#define PINCODE_LENGTH 4

#define MAX_FRIENDS 40
#define MAX_MEMOPOINTS 3
#define MAX_SKILLCOOLDOWN 20

//Size of the fame list arrays.
#define MAX_FAME_LIST 10

//Limits to avoid ID collision with other game objects
#define START_ACCOUNT_NUM 2000000
#define END_ACCOUNT_NUM 100000000
#define START_CHAR_NUM 150000

//Guilds
#define MAX_GUILDMES1 60
#define MAX_GUILDMES2 120

//Base Homun skill.
#define HM_SKILLBASE 8001
#define MAX_HOMUNSKILL 43
#define MAX_HOMUNCULUS_CLASS	52	//[orn], Increased to 60 from 16 to allow new Homun-S.
#define HM_CLASS_BASE 6001
#define HM_CLASS_MAX (HM_CLASS_BASE+MAX_HOMUNCULUS_CLASS-1)

//Mail System
#define MAIL_MAX_INBOX 30
#define MAIL_TITLE_LENGTH 40
#if PACKETVER < 20150513
#define MAIL_BODY_LENGTH 200
#define MAIL_MAX_ITEM 1
#else
#define MAIL_BODY_LENGTH 500
#define MAIL_MAX_ITEM 5
#define MAIL_PAGE_SIZE 7
#endif

//Mercenary System
#define MC_SKILLBASE 8201
#define MAX_MERCSKILL 41

//Elemental System
#define MAX_ELEMENTALSKILL 42
#define EL_SKILLBASE 8401
#define MAX_ELESKILLTREE 3
#define MAX_ELEMENTAL_CLASS 12
#define EL_CLASS_BASE 2114
#define EL_CLASS_MAX (EL_CLASS_BASE+MAX_ELEMENTAL_CLASS-1)

//Achievement System
#define MAX_ACHIEVEMENT_RANK 20 /// Maximum achievement level
#define MAX_ACHIEVEMENT_OBJECTIVES 10 /// Maximum different objectives in achievement_db.yml
#define MAX_ACHIEVEMENT_DEPENDENTS 20 /// Maximum different dependents in achievement_db.yml
#define ACHIEVEMENT_NAME_LENGTH 50 /// Max Achievement Name length

enum item_types {
	IT_HEALING = 0,
	IT_UNKNOWN, //1
	IT_USABLE,  //2
	IT_ETC,     //3
	IT_ARMOR,   //4
	IT_WEAPON,  //5
	IT_CARD,    //6
	IT_PETEGG,  //7
	IT_PETARMOR,//8
	IT_UNKNOWN2,//9
	IT_AMMO,    //10
	IT_DELAYCONSUME,//11
	IT_SHADOWGEAR,  //12
	IT_CASH = 18,
#ifdef Pandas_ItemAmulet_System
	IT_AMULET,	//19
#endif // Pandas_ItemAmulet_System
	IT_MAX
};

/// Monster mode definitions to clear up code reading. [Skotlex]
enum e_mode {
	MD_NONE					= 0x0000000,
	MD_CANMOVE				= 0x0000001,
	MD_LOOTER				= 0x0000002,
	MD_AGGRESSIVE			= 0x0000004,
	MD_ASSIST				= 0x0000008,
	MD_CASTSENSOR_IDLE		= 0x0000010,
	MD_NORANDOM_WALK		= 0x0000020,
	MD_NOCAST_SKILL			= 0x0000040,
	MD_CANATTACK			= 0x0000080,
	//FREE					= 0x0000100,
	MD_CASTSENSOR_CHASE		= 0x0000200,
	MD_CHANGECHASE			= 0x0000400,
	MD_ANGRY				= 0x0000800,
	MD_CHANGETARGET_MELEE	= 0x0001000,
	MD_CHANGETARGET_CHASE	= 0x0002000,
	MD_TARGETWEAK			= 0x0004000,
	MD_RANDOMTARGET			= 0x0008000,
	MD_IGNOREMELEE			= 0x0010000,
	MD_IGNOREMAGIC			= 0x0020000,
	MD_IGNORERANGED			= 0x0040000,
	MD_MVP					= 0x0080000,
	MD_IGNOREMISC			= 0x0100000,
	MD_KNOCKBACK_IMMUNE		= 0x0200000,
	MD_TELEPORT_BLOCK		= 0x0400000,
	//FREE					= 0x0800000,
	MD_FIXED_ITEMDROP		= 0x1000000,
	MD_DETECTOR				= 0x2000000,
	MD_STATUS_IMMUNE		= 0x4000000,
	MD_SKILL_IMMUNE			= 0x8000000,
};

#define MD_MASK 0x000FFFF
#define ATR_MASK 0x0FF0000
#define CL_MASK 0xF000000

// Questlog states
enum quest_state {
	Q_INACTIVE, ///< Inactive quest (the user can toggle between active and inactive quests)
	Q_ACTIVE,   ///< Active quest
	Q_COMPLETE, ///< Completed quest
};

/// Questlog entry
struct quest {
	int quest_id;                    ///< Quest ID
	unsigned int time;               ///< Expiration time
	int count[MAX_QUEST_OBJECTIVES]; ///< Kill counters of each quest objective
	enum quest_state state;          ///< Current quest state
};

struct s_item_randomoption {
	short id;
	short value;
	char param;
};

/// Achievement log entry
struct achievement {
	int achievement_id;                    ///< Achievement ID
	int count[MAX_ACHIEVEMENT_OBJECTIVES]; ///< Counters of each achievement objective
	time_t completed;                      ///< Date completed
	time_t rewarded;                       ///< Received reward?
	int score;                             ///< Amount of points achievement is worth
};

struct item {
	int id;
	unsigned short nameid;
	short amount;
	unsigned int equip; // location(s) where item is equipped (using enum equip_pos for bitmasking)
	char identify;
	char refine;
	char attribute;
	unsigned short card[MAX_SLOTS];
	struct s_item_randomoption option[MAX_ITEM_RDM_OPT];		// max of 5 random options can be supported.
	unsigned int expire_time;
	char favorite, bound;
	uint64 unique_id;
	unsigned int equipSwitch; // location(s) where item is equipped for equip switching (using enum equip_pos for bitmasking)
};

//Equip position constants
enum equip_pos {
	EQP_HEAD_LOW         = 0x000001,
	EQP_HEAD_MID         = 0x000200, // 512
	EQP_HEAD_TOP         = 0x000100, // 256
	EQP_HAND_R           = 0x000002, // 2
	EQP_HAND_L           = 0x000020, // 32
	EQP_ARMOR            = 0x000010, // 16
	EQP_SHOES            = 0x000040, // 64
	EQP_GARMENT          = 0x000004, // 4
	EQP_ACC_R            = 0x000008, // 8
	EQP_ACC_L            = 0x000080, // 128
	EQP_COSTUME_HEAD_TOP = 0x000400, // 1024
	EQP_COSTUME_HEAD_MID = 0x000800, // 2048
	EQP_COSTUME_HEAD_LOW = 0x001000, // 4096
	EQP_COSTUME_GARMENT  = 0x002000, // 8192
	//EQP_COSTUME_FLOOR  = 0x004000, // 16384
	EQP_AMMO             = 0x008000, // 32768
	EQP_SHADOW_ARMOR     = 0x010000, // 65536
	EQP_SHADOW_WEAPON    = 0x020000, // 131072
	EQP_SHADOW_SHIELD    = 0x040000, // 262144
	EQP_SHADOW_SHOES     = 0x080000, // 524288
	EQP_SHADOW_ACC_R     = 0x100000, // 1048576
	EQP_SHADOW_ACC_L     = 0x200000, // 2097152

	// Combined
	EQP_ACC_RL			= EQP_ACC_R|EQP_ACC_L,
	EQP_SHADOW_ACC_RL	= EQP_SHADOW_ACC_R|EQP_SHADOW_ACC_L,
};

struct point {
	unsigned short map;
	short x,y;
};

struct startitem {
	unsigned short nameid, amount;
	short pos;
};

enum e_skill_flag
{
	SKILL_FLAG_PERMANENT,
	SKILL_FLAG_TEMPORARY,
	SKILL_FLAG_PLAGIARIZED,
	SKILL_FLAG_PERM_GRANTED, // Permanent, granted through someway e.g. script
	SKILL_FLAG_TMP_COMBO, //@FIXME for homunculus combo atm

	//! NOTE: This flag be the last flag, and don't change the value if not needed!
	SKILL_FLAG_REPLACED_LV_0 = 10, // temporary skill overshadowing permanent skill of level 'N - SKILL_FLAG_REPLACED_LV_0',
};

struct s_skill {
	uint16 id;
	uint8 lv;
	uint8 flag; // see enum e_skill_flag
};

struct script_reg_state {
	unsigned int type : 1; // because I'm a memory hoarder and having them in the same struct would be a 8-byte/instance waste while ints outnumber str on a 10000-to-1 ratio.
	unsigned int update : 1; // whether it needs to be sent to char server for insertion/update/delete
};

struct script_reg_num {
	struct script_reg_state flag;
	int value;
};

struct script_reg_str {
	struct script_reg_state flag;
	char *value;
};

//For saving status changes across sessions. [Skotlex]
struct status_change_data {
	unsigned short type; //SC_type
	long val1, val2, val3, val4;
	t_tick tick; //Remaining duration.
};

#define MAX_BONUS_SCRIPT_LENGTH 512
struct bonus_script_data {
	char script_str[MAX_BONUS_SCRIPT_LENGTH]; //< Script string
	t_tick tick; ///< Tick
	uint16 flag; ///< Flags @see enum e_bonus_script_flags
	int16 icon; ///< Icon SI
	uint8 type; ///< 0 - None, 1 - Buff, 2 - Debuff
};

struct skill_cooldown_data {
	unsigned short skill_id;
	t_tick tick;
};

enum storage_type {
	TABLE_INVENTORY = 1,
	TABLE_CART,
	TABLE_STORAGE,
	TABLE_GUILD_STORAGE,
};

enum e_storage_mode {
	STOR_MODE_NONE = 0x0,
	STOR_MODE_GET = 0x1,
	STOR_MODE_PUT = 0x2,
	STOR_MODE_ALL = 0x3,
};

struct s_storage {
	bool dirty; ///< Dirty status, data needs to be saved
	bool status; ///< Current status of storage (opened or closed)
	uint16 amount; ///< Amount of items in storage
	bool lock; ///< If locked, can't use storage when item bound retrieval
	uint32 id; ///< Account ID / Character ID / Guild ID (owner of storage)
	enum storage_type type; ///< Type of storage (inventory, cart, storage, guild storage)
	uint16 max_amount; ///< Maximum amount of items in storage
	uint8 stor_id; ///< Storage ID
	struct {
		unsigned get : 1;
		unsigned put : 1;
	} state;
	union { // Max for inventory, storage, cart, and guild storage are 1637 each without changing this struct and struct item [2014/10/27]
		struct item items_inventory[MAX_INVENTORY];
		struct item items_storage[MAX_STORAGE];
		struct item items_cart[MAX_CART];
		struct item items_guild[MAX_GUILD_STORAGE];
	} u;
};

struct s_storage_table {
	char name[NAME_LENGTH];
	char table[DB_NAME_LEN];
	uint16 max_num;
	uint8 id;
};

struct s_pet {
	uint32 account_id;
	uint32 char_id;
	int pet_id;
	short class_;
	short level;
	unsigned short egg_id;//pet egg id
	unsigned short equip;//pet equip name_id
	short intimate;//pet friendly
	short hungry;//pet hungry
	char name[NAME_LENGTH];
	char rename_flag;
	char incubate;
	bool autofeed;
};

struct s_homunculus {	//[orn]
	char name[NAME_LENGTH];
	int hom_id;
	uint32 char_id;
	short class_;
	short prev_class;
	int hp,max_hp,sp,max_sp;
	unsigned int intimacy;	//[orn]
	short hunger;
	struct s_skill hskill[MAX_HOMUNSKILL]; //albator
	short skillpts;
	short level;
	unsigned int exp;
	short rename_flag;
	short vaporize; //albator
	int str;
	int agi;
	int vit;
	int int_;
	int dex;
	int luk;

	int str_value;
	int agi_value;
	int vit_value;
	int int_value;
	int dex_value;
	int luk_value;

	char spiritball; //for homun S [lighta]
	bool autofeed;
};

struct s_mercenary {
	int mercenary_id;
	uint32 char_id;
	short class_;
	int hp, sp;
	unsigned int kill_count;
	t_tick life_time;
};

struct s_elemental {
	int elemental_id;
	uint32 char_id;
	short class_;
	enum e_mode mode;
	int hp, sp, max_hp, max_sp, matk, atk, atk2;
	short hit, flee, amotion, def, mdef;
	t_tick life_time;
};

struct s_friend {
	uint32 account_id;
	uint32 char_id;
	char name[NAME_LENGTH];
};

#ifdef HOTKEY_SAVING
struct hotkey {
	unsigned int id;
	unsigned short lv;
	unsigned char type; // 0: item, 1: skill
};
#endif

struct mmo_charstatus {
	uint32 char_id;
	uint32 account_id;
	uint32 partner_id;
	uint32 father;
	uint32 mother;
	uint32 child;

	unsigned int base_exp,job_exp;
	int zeny;

	short class_; ///< Player's JobID
	unsigned int status_point,skill_point;
	int hp,max_hp,sp,max_sp;
	unsigned int option;
	short manner; // Defines how many minutes a char will be muted, each negative point is equivalent to a minute.
	unsigned char karma;
	short hair,hair_color,clothes_color,body;
	int party_id,guild_id,pet_id,hom_id,mer_id,ele_id,clan_id;
	int fame;

	// Mercenary Guilds Rank
	int arch_faith, arch_calls;
	int spear_faith, spear_calls;
	int sword_faith, sword_calls;

	short weapon; // enum weapon_type
	short shield; // view-id
	short head_top,head_mid,head_bottom;
	short robe;

	char name[NAME_LENGTH];
	unsigned int base_level,job_level;
	unsigned short str,agi,vit,int_,dex,luk;
	unsigned char slot,sex;

	uint32 mapip;
	uint16 mapport;

	struct point last_point,save_point,memo_point[MAX_MEMOPOINTS];
	struct s_skill skill[MAX_SKILL];

	struct s_friend friends[MAX_FRIENDS]; //New friend system [Skotlex]
#ifdef HOTKEY_SAVING
	struct hotkey hotkeys[MAX_HOTKEYS];
#endif
	bool show_equip,allow_party;
	short rename;

	time_t delete_date;
	time_t unban_time;

	// Char server addon system
	unsigned int character_moves;

	unsigned char font;

	bool cashshop_sent; // Whether the player has received the CashShop list

	uint32 uniqueitem_counter;

	unsigned char hotkey_rowshift;
	unsigned long title_id;
};

typedef enum mail_status {
	MAIL_NEW,
	MAIL_UNREAD,
	MAIL_READ,
} mail_status;

enum mail_inbox_type {
	MAIL_INBOX_NORMAL = 0,
	MAIL_INBOX_ACCOUNT,
	MAIL_INBOX_RETURNED
};

enum mail_attachment_type {
	MAIL_ATT_NONE = 0,
	MAIL_ATT_ZENY = 1,
	MAIL_ATT_ITEM = 2,
	MAIL_ATT_ALL = MAIL_ATT_ZENY | MAIL_ATT_ITEM
};

struct mail_message {
	int id;
	uint32 send_id;                 //hold char_id of sender
	char send_name[NAME_LENGTH];    //sender nickname
	uint32 dest_id;                 //hold char_id of receiver
	char dest_name[NAME_LENGTH];    //receiver nickname
	char title[MAIL_TITLE_LENGTH];
	char body[MAIL_BODY_LENGTH];
	enum mail_inbox_type type;
	time_t scheduled_deletion;

	mail_status status;
	time_t timestamp; // marks when the message was sent

	uint32 zeny;
	struct item item[MAIL_MAX_ITEM];
};

struct mail_data {
	short amount;
	bool full;
	short unchecked, unread;
	struct mail_message msg[MAIL_MAX_INBOX];
};

struct auction_data {
	unsigned int auction_id;
	int seller_id;
	char seller_name[NAME_LENGTH];
	int buyer_id;
	char buyer_name[NAME_LENGTH];

	struct item item;
	// This data is required for searching, as itemdb is not read by char server
	char item_name[ITEM_NAME_LENGTH];
	short type;

	unsigned short hours;
	int price, buynow;
	time_t timestamp; // auction's end time
	int auction_end_timer;
};

struct party_member {
	uint32 account_id;
	uint32 char_id;
	char name[NAME_LENGTH];
	unsigned short class_;
	unsigned short map;
	unsigned short lv;
	unsigned leader : 1,
	         online : 1;
};

struct party {
	int party_id;
	char name[NAME_LENGTH];
	unsigned char count; //Count of online characters.
	unsigned exp : 1,
				item : 2; //&1: Party-Share (round-robin), &2: pickup style: shared.
	struct party_member member[MAX_PARTY];
};

struct map_session_data;
struct guild_member {
	uint32 account_id, char_id;
	short hair,hair_color,gender,class_,lv;
	uint64 exp;
	int exp_payper;
	short online,position;
	char name[NAME_LENGTH];
	struct map_session_data *sd;
	unsigned char modified;
	uint32 last_login;
};

struct guild_position {
	char name[NAME_LENGTH];
	int mode;
	int exp_mode;
	unsigned char modified;
};

struct guild_alliance {
	int opposition;
	int guild_id;
	char name[NAME_LENGTH];
};

struct guild_expulsion {
	char name[NAME_LENGTH];
	char mes[40];
	uint32 account_id;
};

struct guild_skill {
	int id,lv;
};

struct Channel;
struct guild {
	int guild_id;
	short guild_lv, connect_member, max_member, average_lv;
	uint64 exp;
	unsigned int next_exp;
	int skill_point;
	char name[NAME_LENGTH],master[NAME_LENGTH];
	struct guild_member member[MAX_GUILD];
	struct guild_position position[MAX_GUILDPOSITION];
	char mes1[MAX_GUILDMES1],mes2[MAX_GUILDMES2];
	int emblem_len,emblem_id;
	char emblem_data[2048];
	struct guild_alliance alliance[MAX_GUILDALLIANCE];
	struct guild_expulsion expulsion[MAX_GUILDEXPULSION];
	struct guild_skill skill[MAX_GUILDSKILL];
	struct Channel *channel;
	unsigned short instance_id;
	time_t last_leader_change;

	/* Used by char-server to save events for guilds */
	unsigned short save_flag;
};

struct guild_castle {
	int castle_id;
	int mapindex;
	char castle_name[NAME_LENGTH];
	char castle_event[EVENT_NAME_LENGTH];
	int guild_id;
	int economy;
	int defense;
	int triggerE;
	int triggerD;
	int nextTime;
	int payTime;
	int createTime;
	int visibleC;
	struct {
		unsigned visible : 1;
		int id; // object id
	} guardian[MAX_GUARDIANS];
	int* temp_guardians; // ids of temporary guardians (mobs)
	int temp_guardians_max;
};

/// Enum for guild castle data script commands
enum e_castle_data : uint8 {
	CD_NONE = 0,
	CD_GUILD_ID, ///< Guild ID
	CD_CURRENT_ECONOMY, ///< Castle Economy score
	CD_CURRENT_DEFENSE, ///< Castle Defense score
	CD_INVESTED_ECONOMY, ///< Number of times the economy was invested in today
	CD_INVESTED_DEFENSE, ///< Number of times the defense was invested in today
	CD_NEXT_TIME, ///< unused
	CD_PAY_TIME, ///< unused
	CD_CREATE_TIME, ///< unused
	CD_ENABLED_KAFRA, ///< Is 1 if a Kafra was hired for this castle, 0 otherwise
	CD_ENABLED_GUARDIAN00, ///< Is 1 if the 1st guardian is present (Soldier Guardian)
	// The others in between are not needed in src, but are exported for the script engine
	CD_MAX = CD_ENABLED_GUARDIAN00 + MAX_GUARDIANS
};

/// Guild Permissions
enum e_guild_permission {
	GUILD_PERM_INVITE	= 0x001,
	GUILD_PERM_EXPEL	= 0x010,
	GUILD_PERM_STORAGE	= 0x100,
#if PACKETVER >= 20140205
	GUILD_PERM_ALL		= GUILD_PERM_INVITE|GUILD_PERM_EXPEL|GUILD_PERM_STORAGE,
#else
	GUILD_PERM_ALL		= GUILD_PERM_INVITE|GUILD_PERM_EXPEL,
#endif
	GUILD_PERM_DEFAULT	= GUILD_PERM_ALL,
};

struct fame_list {
	int id;
	int fame;
	char name[NAME_LENGTH];
};

enum e_guild_info { //Change Guild Infos
	GBI_EXP	=1,		// Guild Experience (EXP)
	GBI_GUILDLV,		// Guild level
	GBI_SKILLPOINT,		// Guild skillpoints
	GBI_SKILLLV,		// Guild skill_lv ?? seem unused
};

enum e_guild_member_info { //Change Member Infos
	GMI_POSITION	=0,
	GMI_EXP,
	GMI_HAIR,
	GMI_HAIR_COLOR,
	GMI_GENDER,
	GMI_CLASS,
	GMI_LEVEL,
};

enum e_guild_skill {
	GD_SKILLBASE=10000,
	GD_APPROVAL=10000,
	GD_KAFRACONTRACT=10001,
	GD_GUARDRESEARCH=10002,
	GD_GUARDUP=10003,
	GD_EXTENSION=10004,
	GD_GLORYGUILD=10005,
	GD_LEADERSHIP=10006,
	GD_GLORYWOUNDS=10007,
	GD_SOULCOLD=10008,
	GD_HAWKEYES=10009,
	GD_BATTLEORDER=10010,
	GD_REGENERATION=10011,
	GD_RESTORE=10012,
	GD_EMERGENCYCALL=10013,
	GD_DEVELOPMENT=10014,
	GD_ITEMEMERGENCYCALL=10015,
	GD_GUILD_STORAGE=10016,
	GD_MAX,
};

#define MAX_SKILL_ID GD_MAX

//These mark the ID of the jobs, as expected by the client. [Skotlex]
enum e_job {
	JOB_NOVICE,
	JOB_SWORDMAN,
	JOB_MAGE,
	JOB_ARCHER,
	JOB_ACOLYTE,
	JOB_MERCHANT,
	JOB_THIEF,
	JOB_KNIGHT,
	JOB_PRIEST,
	JOB_WIZARD,
	JOB_BLACKSMITH,
	JOB_HUNTER,
	JOB_ASSASSIN,
	JOB_KNIGHT2,
	JOB_CRUSADER,
	JOB_MONK,
	JOB_SAGE,
	JOB_ROGUE,
	JOB_ALCHEMIST,
	JOB_BARD,
	JOB_DANCER,
	JOB_CRUSADER2,
	JOB_WEDDING,
	JOB_SUPER_NOVICE,
	JOB_GUNSLINGER,
	JOB_NINJA,
	JOB_XMAS,
	JOB_SUMMER,
	JOB_HANBOK,
	JOB_OKTOBERFEST,
	JOB_SUMMER2,
	JOB_MAX_BASIC,

	JOB_NOVICE_HIGH = 4001,
	JOB_SWORDMAN_HIGH,
	JOB_MAGE_HIGH,
	JOB_ARCHER_HIGH,
	JOB_ACOLYTE_HIGH,
	JOB_MERCHANT_HIGH,
	JOB_THIEF_HIGH,
	JOB_LORD_KNIGHT,
	JOB_HIGH_PRIEST,
	JOB_HIGH_WIZARD,
	JOB_WHITESMITH,
	JOB_SNIPER,
	JOB_ASSASSIN_CROSS,
	JOB_LORD_KNIGHT2,
	JOB_PALADIN,
	JOB_CHAMPION,
	JOB_PROFESSOR,
	JOB_STALKER,
	JOB_CREATOR,
	JOB_CLOWN,
	JOB_GYPSY,
	JOB_PALADIN2,

	JOB_BABY,
	JOB_BABY_SWORDMAN,
	JOB_BABY_MAGE,
	JOB_BABY_ARCHER,
	JOB_BABY_ACOLYTE,
	JOB_BABY_MERCHANT,
	JOB_BABY_THIEF,
	JOB_BABY_KNIGHT,
	JOB_BABY_PRIEST,
	JOB_BABY_WIZARD,
	JOB_BABY_BLACKSMITH,
	JOB_BABY_HUNTER,
	JOB_BABY_ASSASSIN,
	JOB_BABY_KNIGHT2,
	JOB_BABY_CRUSADER,
	JOB_BABY_MONK,
	JOB_BABY_SAGE,
	JOB_BABY_ROGUE,
	JOB_BABY_ALCHEMIST,
	JOB_BABY_BARD,
	JOB_BABY_DANCER,
	JOB_BABY_CRUSADER2,
	JOB_SUPER_BABY,

	JOB_TAEKWON,
	JOB_STAR_GLADIATOR,
	JOB_STAR_GLADIATOR2,
	JOB_SOUL_LINKER,

	JOB_GANGSI,
	JOB_DEATH_KNIGHT,
	JOB_DARK_COLLECTOR,

	JOB_RUNE_KNIGHT = 4054,
	JOB_WARLOCK,
	JOB_RANGER,
	JOB_ARCH_BISHOP,
	JOB_MECHANIC,
	JOB_GUILLOTINE_CROSS,

	JOB_RUNE_KNIGHT_T,
	JOB_WARLOCK_T,
	JOB_RANGER_T,
	JOB_ARCH_BISHOP_T,
	JOB_MECHANIC_T,
	JOB_GUILLOTINE_CROSS_T,

	JOB_ROYAL_GUARD,
	JOB_SORCERER,
	JOB_MINSTREL,
	JOB_WANDERER,
	JOB_SURA,
	JOB_GENETIC,
	JOB_SHADOW_CHASER,

	JOB_ROYAL_GUARD_T,
	JOB_SORCERER_T,
	JOB_MINSTREL_T,
	JOB_WANDERER_T,
	JOB_SURA_T,
	JOB_GENETIC_T,
	JOB_SHADOW_CHASER_T,

	JOB_RUNE_KNIGHT2,
	JOB_RUNE_KNIGHT_T2,
	JOB_ROYAL_GUARD2,
	JOB_ROYAL_GUARD_T2,
	JOB_RANGER2,
	JOB_RANGER_T2,
	JOB_MECHANIC2,
	JOB_MECHANIC_T2,

	JOB_BABY_RUNE = 4096,
	JOB_BABY_WARLOCK,
	JOB_BABY_RANGER,
	JOB_BABY_BISHOP,
	JOB_BABY_MECHANIC,
	JOB_BABY_CROSS,
	JOB_BABY_GUARD,
	JOB_BABY_SORCERER,
	JOB_BABY_MINSTREL,
	JOB_BABY_WANDERER,
	JOB_BABY_SURA,
	JOB_BABY_GENETIC,
	JOB_BABY_CHASER,

	JOB_BABY_RUNE2,
	JOB_BABY_GUARD2,
	JOB_BABY_RANGER2,
	JOB_BABY_MECHANIC2,

	JOB_SUPER_NOVICE_E = 4190,
	JOB_SUPER_BABY_E,

	JOB_KAGEROU = 4211,
	JOB_OBORO,

	JOB_REBELLION = 4215,

	JOB_SUMMONER = 4218,

	JOB_BABY_SUMMONER = 4220,

	JOB_BABY_NINJA = 4222,
	JOB_BABY_KAGEROU,
	JOB_BABY_OBORO,
	JOB_BABY_TAEKWON,
	JOB_BABY_STAR_GLADIATOR,
	JOB_BABY_SOUL_LINKER,
	JOB_BABY_GUNSLINGER,
	JOB_BABY_REBELLION,

	JOB_BABY_STAR_GLADIATOR2 = 4238,

	JOB_STAR_EMPEROR,
	JOB_SOUL_REAPER,
	JOB_BABY_STAR_EMPEROR,
	JOB_BABY_SOUL_REAPER,
	JOB_STAR_EMPEROR2,
	JOB_BABY_STAR_EMPEROR2,

	JOB_MAX,
};

enum e_sex {
	SEX_FEMALE = 0,
	SEX_MALE,
	SEX_SERVER,
	SEX_ACCOUNT = 99
};

/// Item Bound Type
enum bound_type {
	BOUND_NONE = 0, /// No bound
	BOUND_ACCOUNT, /// 1- Account Bound
	BOUND_GUILD, /// 2 - Guild Bound
	BOUND_PARTY, /// 3 - Party Bound
	BOUND_CHAR, /// 4 - Character Bound
	BOUND_MAX,

	BOUND_ONEQUIP = 1, ///< Show notification when item will be bound on equip
	BOUND_DISPYELLOW = 2, /// Shows the item name in yellow color
};

enum e_pc_reg_loading {
	PRL_NONE = 0x0,
	PRL_CHAR = 0x1,
	PRL_ACCL = 0x2, // local
	PRL_ACCG = 0x4, // global
	PRL_ALL = 0xFF,
};

enum e_party_member_withdraw {
	PARTY_MEMBER_WITHDRAW_LEAVE,	  ///< /leave
	PARTY_MEMBER_WITHDRAW_EXPEL,	  ///< Kicked
	PARTY_MEMBER_WITHDRAW_CANT_LEAVE, ///< TODO: Cannot /leave
	PARTY_MEMBER_WITHDRAW_CANT_EXPEL, ///< TODO: Cannot be kicked
};

enum e_rank {
	RANK_BLACKSMITH = 0,
	RANK_ALCHEMIST = 1,
	RANK_TAEKWON = 2,
	RANK_KILLER = 3
};

struct clan_alliance {
	int opposition;
	int clan_id;
	char name[NAME_LENGTH];
};

struct clan{
	int id;
	char name[NAME_LENGTH];
	char master[NAME_LENGTH];
	char map[MAP_NAME_LENGTH_EXT];
	short max_member, connect_member;
	struct map_session_data *members[MAX_CLAN];
	struct clan_alliance alliance[MAX_CLANALLIANCE];
	unsigned short instance_id;
};

// Sanity checks...
#if MAX_ZENY > INT_MAX
#error MAX_ZENY is too big
#endif

// This sanity check is required, because some other places(like skill.cpp) rely on this
#if MAX_PARTY < 2
#error MAX_PARTY is too small, you need at least 2 players for a party
#endif

#ifndef VIP_ENABLE
	#define MIN_STORAGE MAX_STORAGE // If the VIP system is disabled the min = max.
	#define MIN_CHARS MAX_CHARS // Default number of characters per account.
	#define MAX_CHAR_BILLING 0
	#define MAX_CHAR_VIP 0
#endif

#if (MIN_CHARS + MAX_CHAR_VIP + MAX_CHAR_BILLING) > MAX_CHARS
#error Config of MAX_CHARS is invalid
#endif

#if MIN_STORAGE > MAX_STORAGE
#error Config of MIN_STORAGE is invalid
#endif

#ifdef PACKET_OBFUSCATION
	#if PACKETVER < 20110817
		#undef PACKET_OBFUSCATION
	#endif
#endif

/* Feb 1st 2012 */
#if PACKETVER >= 20120201
	#define NEW_CARTS
	#ifndef ENABLE_SC_SAVING
	#warning "Cart won't be able to be saved for relog"
	#endif
#if PACKETVER >= 20150826
	#define MAX_CARTS 12		// used for 3 new cart design
#else
	#define MAX_CARTS 9
#endif
#else
	#define MAX_CARTS 5
#endif

#endif /* MMO_HPP */
