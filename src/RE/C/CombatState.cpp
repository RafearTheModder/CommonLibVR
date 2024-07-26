#include "RE/C/CombatState.h"

namespace RE
{
	void CombatState::DamagedByAttacker(Actor* a_attacker, float a_damage)
	{
		this->damagedByAttackerTime.timeStamp = AITimer::GetTimer();
	}
}
