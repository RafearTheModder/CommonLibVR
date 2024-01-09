#include "RE/A/ActorValueOwner.h"

namespace RE
{
	float ActorValueOwner::GetArmorRatingSkillMultiplier(float a_skillLevel) const
	{
		using func_t = decltype(&ActorValueOwner::GetArmorRatingSkillMultiplier);
		REL::Relocation<func_t> func(RELOCATION_ID(25858, 26424));
		return func(this, a_skillLevel);
	}

	float ActorValueOwner::GetClampedActorValue(ActorValue a_akValue) const
	{
		using func_t = decltype(&ActorValueOwner::GetClampedActorValue);
		REL::Relocation<func_t> func{ Offset::ActorValueOwner::GetClampedActorValue };
		return func(this, a_akValue);
	}

	float ActorValueOwner::GetDualCastingEffectiveness(float a_cost) const
	{
		using func_t = decltype(&ActorValueOwner::GetDualCastingEffectiveness);
#ifdef SKYRIMVR
		REL::Relocation<func_t> func(REL::Offset(0x3d0f80)); // Remove this ifdef when REL::ID(25931) is added to the VR library
#else
		REL::Relocation<func_t> func(RELOCATION_ID(25931, 26518));
#endif
		return func(this, a_cost);
	}
}
