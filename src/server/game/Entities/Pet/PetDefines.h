/*
 * Copyright (C) 2008-2013 TrinityCore <http://www.trinitycore.org/>
 * Copyright (C) 2005-2009 MaNGOS <http://getmangos.com/>
 *
 * This program is free software; you can redistribute it and/or modify it
 * under the terms of the GNU General Public License as published by the
 * Free Software Foundation; either version 2 of the License, or (at your
 * option) any later version.
 *
 * This program is distributed in the hope that it will be useful, but WITHOUT
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
 * FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for
 * more details.
 *
 * You should have received a copy of the GNU General Public License along
 * with this program. If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef TRINITYCORE_PET_DEFINES_H
#define TRINITYCORE_PET_DEFINES_H

enum PetType
{
    SUMMON_PET              = 0,
    HUNTER_PET              = 1,
    MAX_PET_TYPE            = 4
};

#define MAX_PET_STABLES         20

// stored in character_pet.slot
enum PetSaveMode
{
    PET_SAVE_AS_DELETED        = -1,                        // not saved in fact
    PET_SAVE_AS_CURRENT        =  0,                        // in current slot (with player)
    PET_SAVE_FIRST_STABLE_SLOT =  5,
    PET_SAVE_LAST_STABLE_SLOT  =  MAX_PET_STABLES + PET_SAVE_FIRST_STABLE_SLOT - 1,  // last in DB stable slot index (including), all higher have same meaning as PET_SAVE_NOT_IN_SLOT
    PET_SAVE_NOT_IN_SLOT       =  100,                       // for avoid conflict with stable size grow will use 100
	PET_SAVE_REAGENTS          =  101,                      // PET_SAVE_NOT_IN_SLOT with reagents return
	PET_SAVE_FIRST_AVAILABLE   =  102,
};

enum PetSlot
{
    //Some not-in-db slots
    PET_SLOT_FULL_LIST         = -4,        //Used when there is no slot free for tameing
    PET_SLOT_UNK_SLOT          = -3,        //Used in some scripts.

    PET_SLOT_ACTUAL_PET_SLOT   = -2,        //Save the pet in his actual slot.
    PET_SLOT_DELETED           = -1,        //Delete the pet

    //Hunter pet slots, sended to client at stable.
    PET_SLOT_HUNTER_FIRST      = 0,        //PetType == HUNTER_PET
    PET_SLOT_HUNTER_LAST       = 4,        //PetType == HUNTER_PET
    PET_SLOT_STABLE_FIRST      = 5,
    PET_SLOT_STABLE_LAST       = 24,

    //Non-hunter pet slot
    PET_SLOT_OTHER_PET       = 100,        //PetType != HUNTER_PET
};

enum HappinessState
{
    UNHAPPY = 1,
    CONTENT = 2,
    HAPPY   = 3
};

enum PetSummonState
{
    PETSUMMON_NONE                  = 0x0,
    PETSUMMON_SUMMONING             = (1 << 1),                    // Not yet summoned
    PETSUMMON_RESUMMONED            = (1 << 2),
    PETSUMMON_UNSUMMONED            = (1 << 3),
    PETSUMMON_TEMPORARY_UNSUMMONED  = (1 << 4),

    // Unions
    PETSUMMON_SUMMON_STATE          = (PETSUMMON_SUMMONING   | PETSUMMON_RESUMMONED),
    PETSUMMON_UNSUMMON_STATE        = (PETSUMMON_UNSUMMONED | PETSUMMON_TEMPORARY_UNSUMMONED),
    PETSUMMON_ALL                   = (PETSUMMON_SUMMONING   | PETSUMMON_RESUMMONED |
                                        PETSUMMON_UNSUMMONED | PETSUMMON_TEMPORARY_UNSUMMONED)
};

enum PetSpellState
{
    PETSPELL_UNCHANGED = 0,
    PETSPELL_CHANGED   = 1,
    PETSPELL_NEW       = 2,
    PETSPELL_REMOVED   = 3
};

enum PetSpellType
{
    PETSPELL_NORMAL = 0,
    PETSPELL_FAMILY = 1,
    PETSPELL_TALENT = 2
};

enum ActionFeedback
{
    FEEDBACK_NONE            = 0,
    FEEDBACK_PET_DEAD        = 1,
    FEEDBACK_NOTHING_TO_ATT  = 2,
    FEEDBACK_CANT_ATT_TARGET = 3
};

enum PetTalk
{
    PET_TALK_SPECIAL_SPELL  = 0,
    PET_TALK_ATTACK         = 1
};

#define PET_FOLLOW_DIST  1.0f
#define PET_FOLLOW_ANGLE (M_PI/2)

#endif
