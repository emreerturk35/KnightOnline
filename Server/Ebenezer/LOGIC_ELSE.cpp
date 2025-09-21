// LOGIC_ELSE.cpp: implementation of the LOGIC_ELSE class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "ebenezer.h"
#include "Define.h"
#include "LOGIC_ELSE.h"

#include <djb2/djb2_hasher.h>
#include <spdlog/spdlog.h>

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

LOGIC_ELSE::LOGIC_ELSE()
{
	m_LogicElse = FALSE;
	m_bAnd = TRUE;
	for (int i = 0; i < MAX_LOGIC_ELSE_INT; i++)
		m_LogicElseInt[i] = -1;
}

LOGIC_ELSE::~LOGIC_ELSE()
{
}

void LOGIC_ELSE::Init()
{
	for (int i = 0; i < MAX_LOGIC_ELSE_INT; i++)
		m_LogicElseInt[i] = -1;

	m_bAnd = TRUE;
}

void LOGIC_ELSE::Parse_and(const char* line, const std::wstring& filename, int lineNumber)
{
	int index = 0, i = 0;
	char temp[1024];

	index += ParseSpace(temp, line + index);

	size_t opcode = hashing::djb2::hash(std::string_view(temp));
	switch (opcode)
	{
		case "CHECK_UNDER_WEIGHT"_djb2:
			m_LogicElse = LOGIC_CHECK_UNDER_WEIGHT;

			index += ParseSpace(temp, line + index);
			m_LogicElseInt[i++] = atoi(temp);		// Weight & Empty Slot
			break;

		case "CHECK_OVER_WEIGHT"_djb2:
			m_LogicElse = LOGIC_CHECK_OVER_WEIGHT;

			index += ParseSpace(temp, line + index);
			m_LogicElseInt[i++] = atoi(temp);		// Weight & Empty Slot
			break;

		case "CHECK_SKILL_POINT"_djb2:
			m_LogicElse = LOGIC_CHECK_SKILL_POINT;

			index += ParseSpace(temp, line + index);
			m_LogicElseInt[i++] = atoi(temp);		// SkillPoint

			index += ParseSpace(temp, line + index);
			m_LogicElseInt[i++] = atoi(temp);		// Below

			index += ParseSpace(temp, line + index);
			m_LogicElseInt[i++] = atoi(temp);		// Above
			break;

		case "CHECK_EXIST_ITEM"_djb2:
			m_LogicElse = LOGIC_CHECK_EXIST_ITEM;

			index += ParseSpace(temp, line + index);
			m_LogicElseInt[i++] = atoi(temp);		// Item no.

			index += ParseSpace(temp, line + index);
			m_LogicElseInt[i++] = atoi(temp);		// Item count
			break;

		case "CHECK_NOEXIST_ITEM"_djb2:
			m_LogicElse = LOGIC_CHECK_NOEXIST_ITEM;

			index += ParseSpace(temp, line + index);
			m_LogicElseInt[i++] = atoi(temp);		// Item no.

			index += ParseSpace(temp, line + index);
			m_LogicElseInt[i++] = atoi(temp);		// Item count
			break;

		case "CHECK_CLASS"_djb2:
			m_LogicElse = LOGIC_CHECK_CLASS;

			index += ParseSpace(temp, line + index);
			m_LogicElseInt[i++] = atoi(temp);		// Class 1

			index += ParseSpace(temp, line + index);
			m_LogicElseInt[i++] = atoi(temp);		// Class 2

			index += ParseSpace(temp, line + index);
			m_LogicElseInt[i++] = atoi(temp);		// Class 3

			index += ParseSpace(temp, line + index);
			m_LogicElseInt[i++] = atoi(temp);		// Class 4

			index += ParseSpace(temp, line + index);
			m_LogicElseInt[i++] = atoi(temp);		// Class 5

			index += ParseSpace(temp, line + index);
			m_LogicElseInt[i++] = atoi(temp);		// Class 6
			break;

		case "CHECK_WEIGHT"_djb2:
			m_LogicElse = LOGIC_CHECK_WEIGHT;

			index += ParseSpace(temp, line + index);
			m_LogicElseInt[i++] = atoi(temp);		// Weight & Empty Slot

			index += ParseSpace(temp, line + index);
			m_LogicElseInt[i++] = atoi(temp);		// Weight & Empty Slot
			break;

		// 비러머글 복권!!!
		case "CHECK_EDITBOX"_djb2:
			m_LogicElse = LOGIC_CHECK_EDITBOX;

			index += ParseSpace(temp, line + index);
			m_LogicElseInt[i++] = atoi(temp);
			break;

		case "RAND"_djb2:
			m_LogicElse = LOGIC_RAND;

			index += ParseSpace(temp, line + index);
			m_LogicElseInt[i++] = atoi(temp);		// Chances of you hitting the jackpot
			break;

		case "CHECK_NOAH"_djb2:
			m_LogicElse = LOGIC_CHECK_NOAH;

			index += ParseSpace(temp, line + index);
			m_LogicElseInt[i++] = atoi(temp);		// Minimum

			index += ParseSpace(temp, line + index);
			m_LogicElseInt[i++] = atoi(temp);		// Maximum
			break;
			
		case "CHECK_LV"_djb2:
			m_LogicElse = LOGIC_CHECK_LV;

			index += ParseSpace(temp, line + index);
			m_LogicElseInt[i++] = atoi(temp);		// Minimum

			index += ParseSpace(temp, line + index);
			m_LogicElseInt[i++] = atoi(temp);		// Maximum
			break;

		case "HOWMUCH_ITEM"_djb2:
			m_LogicElse = LOGIC_HOWMUCH_ITEM;

			index += ParseSpace(temp, line + index);
			m_LogicElseInt[i++] = atoi(temp);		// Item no.

			index += ParseSpace(temp, line + index);
			m_LogicElseInt[i++] = atoi(temp);		// Minimum

			index += ParseSpace(temp, line + index);
			m_LogicElseInt[i++] = atoi(temp);		// Maximum
			break;

		case "NOEXIST_COM_EVENT"_djb2:
			m_LogicElse = LOGIC_NOEXIST_COM_EVENT;

			index += ParseSpace(temp, line + index);
			m_LogicElseInt[i++] = atoi(temp);
			break;

		case "CHECK_NATION"_djb2:
			m_LogicElse = LOGIC_CHECK_NATION;

			index += ParseSpace(temp, line + index);
			m_LogicElseInt[i++] = atoi(temp);		// Nation
			break;
			
		case "EXIST_COM_EVENT"_djb2:
			m_LogicElse = LOGIC_EXIST_COM_EVENT;

			index += ParseSpace(temp, line + index);
			m_LogicElseInt[i++] = atoi(temp);
			break;

#if 0 // TODO
		case "CHECK_PROMOTION_ELIGIBLE"_djb2:
			m_LogicElse = LOGIC_CHECK_PROMOTION_ELIGIBLE;

			index += ParseSpace(temp, line + index);
			m_LogicElseInt[i++] = atoi(temp);
			break;

		case "CHECK_MONSTER_CHALLENGE_TIME"_djb2:
			m_LogicElse = LOGIC_CHECK_MONSTER_CHALLENGE_TIME;

			index += ParseSpace(temp, line + index);
			m_LogicElseInt[i++] = atoi(temp);
			break;

		case "CHECK_PPCARD_SERIAL"_djb2:
			m_LogicElse = LOGIC_CHECK_PPCARD_SERIAL;

			index += ParseSpace(temp, line + index);
			m_LogicElseInt[i++] = atoi(temp);
			break;

		case "CHECK_EXIST_EVENT"_djb2:
			m_LogicElse = LOGIC_CHECK_EXIST_EVENT;

			index += ParseSpace(temp, line + index);
			m_LogicElseInt[i++] = atoi(temp);		// Quest ID

			index += ParseSpace(temp, line + index);
			m_LogicElseInt[i++] = atoi(temp);		// Quest state
			break;

		case "CHECK_ITEMCHANGE_NUM"_djb2:
			m_LogicElse = LOGIC_CHECK_ITEMCHANGE_NUM;

			index += ParseSpace(temp, line + index);
			m_LogicElseInt[i++] = atoi(temp); // Number (1~5) indicating which slot was last given in the last exchange (e.g. nExchangeItemNum1..5).
			break;

		case "CHECK_NOCLASS"_djb2:
			m_LogicElse = LOGIC_CHECK_NOCLASS;

			index += ParseSpace(temp, line + index);
			m_LogicElseInt[i++] = atoi(temp); // Class 1

			index += ParseSpace(temp, line + index);
			m_LogicElseInt[i++] = atoi(temp); // Class 2

			index += ParseSpace(temp, line + index);
			m_LogicElseInt[i++] = atoi(temp); // Class 3

			index += ParseSpace(temp, line + index);
			m_LogicElseInt[i++] = atoi(temp); // Class 4

			index += ParseSpace(temp, line + index);
			m_LogicElseInt[i++] = atoi(temp); // Class 5

			index += ParseSpace(temp, line + index);
			m_LogicElseInt[i++] = atoi(temp); // Class 6
			break;
#endif

		case "CHECK_LOYALTY"_djb2:
			m_LogicElse = LOGIC_CHECK_LOYALTY;

			index += ParseSpace(temp, line + index);
			m_LogicElseInt[i++] = atoi(temp); // Minimum

			index += ParseSpace(temp, line + index);
			m_LogicElseInt[i++] = atoi(temp); // Maximum
			break;

		case "CHECK_CHIEF"_djb2:
			m_LogicElse = LOGIC_CHECK_CHIEF;

			index += ParseSpace(temp, line + index);
			m_LogicElseInt[i++] = atoi(temp);
			break;

		case "CHECK_NO_CHIEF"_djb2:
			m_LogicElse = LOGIC_CHECK_NO_CHIEF;

			index += ParseSpace(temp, line + index);
			m_LogicElseInt[i++] = atoi(temp);
			break;

#if 0 // TODO
		case "CHECK_CLAN_GRADE"_djb2:
			m_LogicElse = LOGIC_CHECK_CLAN_GRADE;

			index += ParseSpace(temp, line + index);
			m_LogicElseInt[i++] = atoi(temp); // Minimum

			index += ParseSpace(temp, line + index);
			m_LogicElseInt[i++] = atoi(temp); // Maximum
			break;

		case "CHECK_KNIGHT"_djb2:
			m_LogicElse = LOGIC_CHECK_KNIGHT;

			index += ParseSpace(temp, line + index);
			m_LogicElseInt[i++] = atoi(temp);
			break;

		case "CHECK_MIDDLE_STATUE_NOCAPTURE"_djb2:
			m_LogicElse = LOGIC_CHECK_MIDDLE_STATUE_NOCAPTURE;

			index += ParseSpace(temp, line + index);
			m_LogicElseInt[i++] = atoi(temp);
			break;

		case "CHECK_MIDDLE_STATUE_CAPTURE"_djb2:
			m_LogicElse = LOGIC_CHECK_MIDDLE_STATUE_CAPTURE;

			index += ParseSpace(temp, line + index);
			m_LogicElseInt[i++] = atoi(temp);
			break;

		case "CHECK_EMPTY_SLOT"_djb2:
			m_LogicElse = LOGIC_CHECK_EMPTY_SLOT;

			index += ParseSpace(temp, line + index);
			m_LogicElseInt[i++] = atoi(temp); // Required number of empty slots
			break;

		case "CHECK_NO_CASTLE"_djb2:
			m_LogicElse = LOGIC_CHECK_NO_CASTLE;

			index += ParseSpace(temp, line + index);
			m_LogicElseInt[i++] = atoi(temp);
			break;

		case "CHECK_CASTLE"_djb2:
			m_LogicElse = LOGIC_CHECK_CASTLE;

			index += ParseSpace(temp, line + index);
			m_LogicElseInt[i++] = atoi(temp);
			break;

		case "CHECK_MONSTER_CHALLENGE_USERCOUNT"_djb2:
			m_LogicElse = LOGIC_CHECK_MONSTER_CHALLENGE_USERCOUNT;

			index += ParseSpace(temp, line + index);
			m_LogicElseInt[i++] = atoi(temp); // Current Forgotten Temple (Monster Challenge) user count
			break;

		case "CHECK_STAT_TOTAL"_djb2:
			m_LogicElse = LOGIC_CHECK_STAT_TOTAL;

			index += ParseSpace(temp, line + index);
			m_LogicElseInt[i++] = atoi(temp); // Minimum total stat points

			index += ParseSpace(temp, line + index);
			m_LogicElseInt[i++] = atoi(temp); // Maximum total stat points
			break;

		case "CHECK_SKILL_TOTAL"_djb2:
			m_LogicElse = LOGIC_CHECK_SKILL_TOTAL;

			index += ParseSpace(temp, line + index);
			m_LogicElseInt[i++] = atoi(temp); // Minimum total skill points

			index += ParseSpace(temp, line + index);
			m_LogicElseInt[i++] = atoi(temp); // Maximum total skill points
			break;
#endif // 0

		default:
			spdlog::warn("LOGIC_ELSE::Parse_And: unhandled opcode '{}' ({}:{})", temp, WideToUtf8(filename), lineNumber);
			break;
	}
////////////////////////////////////////////////////////////////////////////

	m_bAnd = TRUE;
}
