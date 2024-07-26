#include "RE/C/CombatController.h"

#include "RE/C/CombatState.h"

namespace RE
{
	void CombatController::DamagedByAttacker(Actor* a_attacker, float a_damage)
	{
		this->state->DamagedByAttacker(a_attacker, a_damage);
	}
}
