/**
 * The Ruby Server - a free and open-source Pokémon MMORPG server emulator
 * Copyright (C) 2018  Mark Samman (TFS) <mark.samman@gmail.com>
 *                     Leandro Matheus <kesuhige@gmail.com>
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License along
 * with this program; if not, write to the Free Software Foundation, Inc.,
 * 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.
 */

#ifndef FS_EVENTS_H_BD444CC0EE167E5777E4C90C766B36DC
#define FS_EVENTS_H_BD444CC0EE167E5777E4C90C766B36DC

#include "luascript.h"

class Party;
class ItemType;
class Tile;
class PokemonType;
class PokeballType;
class FoodType;

class Events
{
	struct EventsInfo {
		// Creature
		int32_t creatureOnChangeOutfit = -1;
		int32_t creatureOnAreaCombat = -1;
		int32_t creatureOnTargetCombat = -1;

		// Party
		int32_t partyOnJoin = -1;
		int32_t partyOnLeave = -1;
		int32_t partyOnDisband = -1;

		// Player
		int32_t playerOnBrowseField = -1;
		int32_t playerOnLook = -1;
		int32_t playerOnLookInBattleList = -1;
		int32_t playerOnLookInTrade = -1;
		int32_t playerOnLookInShop = -1;
		int32_t playerOnMoveItem = -1;
		int32_t playerOnMoveCreature = -1;
		int32_t playerOnReportRuleViolation = -1;
		int32_t playerOnReportBug = -1;
		int32_t playerOnTurn = -1;
		int32_t playerOnTradeRequest = -1;
		int32_t playerOnTradeAccept = -1;
		int32_t playerOnGainExperience = -1;
		int32_t playerOnLoseExperience = -1;
		int32_t playerOnGainSkillTries = -1;
		int32_t playerOnCatchPokemon = -1;
		int32_t playerOnDontCatchPokemon = -1;
		int32_t playerOnTryCatchPokemon = -1;
		int32_t playerOnFeedPokemon = -1;
		int32_t playerOnFeedHimself = -1;
		int32_t playerOnFeed = -1;
	};

	public:
		Events();

		bool load();

		// Creature
		bool eventCreatureOnChangeOutfit(Creature* creature, const Outfit_t& outfit);
		ReturnValue eventCreatureOnAreaCombat(Creature* creature, Tile* tile, bool aggressive);
		ReturnValue eventCreatureOnTargetCombat(Creature* creature, Creature* target);

		// Party
		bool eventPartyOnJoin(Party* party, Player* player);
		bool eventPartyOnLeave(Party* party, Player* player);
		bool eventPartyOnDisband(Party* party);

		// Player
		bool eventPlayerOnBrowseField(Player* player, const Position& position);
		void eventPlayerOnLook(Player* player, const Position& position, Thing* thing, uint8_t stackpos, int32_t lookDistance);
		void eventPlayerOnLookInBattleList(Player* player, Creature* creature, int32_t lookDistance);
		void eventPlayerOnLookInTrade(Player* player, Player* partner, Item* item, int32_t lookDistance);
		bool eventPlayerOnLookInShop(Player* player, const ItemType* itemType, uint16_t count);
		bool eventPlayerOnMoveItem(Player* player, Item* item, uint16_t count, const Position& fromPosition, const Position& toPosition, Cylinder* fromCylinder, Cylinder* toCylinder);
		bool eventPlayerOnMoveCreature(Player* player, Creature* creature, const Position& fromPosition, const Position& toPosition);
		void eventPlayerOnReportRuleViolation(Player* player, const std::string& targetName, uint8_t reportType, uint8_t reportReason, const std::string& comment, const std::string& translation);
		bool eventPlayerOnReportBug(Player* player, const std::string& message, const Position& position, uint8_t category);
		bool eventPlayerOnTurn(Player* player, Direction direction);
		bool eventPlayerOnTradeRequest(Player* player, Player* target, Item* item);
		bool eventPlayerOnTradeAccept(Player* player, Player* target, Item* item, Item* targetItem);
		void eventPlayerOnGainExperience(Player* player, Creature* source, uint64_t& exp, uint64_t rawExp);
		void eventPlayerOnLoseExperience(Player* player, uint64_t& exp);
		void eventPlayerOnGainSkillTries(Player* player, skills_t skill, uint64_t& tries);
		void eventPlayerOnCatchPokemon(uint32_t playerId, PokemonType* pokemonType, const PokeballType* pokeballType, Pokemon* pokemon);
		void eventPlayerOnDontCatchPokemon(uint32_t playerId, PokemonType* pokemonType, const PokeballType* pokeballType);
		void eventPlayerOnTryCatchPokemon(uint32_t playerId, PokemonType* pokemonType, const PokeballType* pokeballType);
		bool eventPlayerOnFeedPokemon(Player* player, Pokemon* pokemon, const FoodType* foodType);
		bool eventPlayerOnFeedHimself(Player* player, const FoodType* foodType);
		bool eventPlayerOnFeed(Player* player, Creature* creature, const FoodType* foodType);

	private:
		LuaScriptInterface scriptInterface;
		EventsInfo info;
};

#endif