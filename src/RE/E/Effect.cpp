#include "RE/E/Effect.h"

#include "RE/E/EffectSetting.h"

namespace RE
{
	Effect::EffectItem::EffectItem() :
		magnitude(0.0),
		area(0),
		duration(0)
	{}

	Effect::Effect() :
		effectItem(),
		pad0C(0),
		baseEffect(nullptr),
		cost(0.0),
		pad1C(0),
		conditions()
	{}

	inline bool essentially_equal(float a, float b)
	{
		constexpr float EPSILON = std::numeric_limits<float>::epsilon();
		return fabs(a - b) <= ((fabs(a) > fabs(b) ? fabs(b) : fabs(a)) * EPSILON);
	}

	bool Effect::IsMatch(EffectSetting* a_base, float a_mag, std::uint32_t a_area, std::uint32_t a_dur, float a_cost)
	{
		return baseEffect == a_base &&
		       essentially_equal(effectItem.magnitude, a_mag) && effectItem.area == a_area && effectItem.duration == a_dur && essentially_equal(cost, a_cost);
	}

	float Effect::GetMagnitude() const
	{
		if (baseEffect->data.flags.any(EffectSetting::EffectSettingData::Flag::kNoMagnitude)) {
			return 0.0f;
		}
		return effectItem.magnitude;
	}

	std::uint32_t Effect::GetArea() const
	{
		if (baseEffect->data.flags.any(EffectSetting::EffectSettingData::Flag::kNoArea)) {
			return 0;
		}
		return effectItem.area;
	}

	std::uint32_t Effect::GetDuration() const
	{
		if (baseEffect->data.flags.any(EffectSetting::EffectSettingData::Flag::kNoDuration)) {
			return 0;
		}
		return effectItem.duration;
	}

	bool Effect::IsHostile() const
	{
		return baseEffect->IsHostile();
	}

	void Effect::ResetCost()
	{
		using func_t = decltype(&Effect::ResetCost);
		static REL::Relocation<func_t> func{ RELOCATION_ID(10932, 11021) };
		return func(this);
	}

	bool Effect::SetDuration(std::uint32_t duration)
	{
		if (this->baseEffect->data.flags.all(EffectSetting::EffectSettingData::Flag::kNoDuration) || duration < 0)
		{
			return false;
		}

		this->effectItem.duration = duration;

		this->ResetCost();

		return true;
	}

	bool Effect::SetMagnitude(float magnitude)
	{
		if (this->baseEffect->data.flags.all(EffectSetting::EffectSettingData::Flag::kNoMagnitude) || magnitude < 0.0F)
		{
			return false;
		}

		this->effectItem.magnitude = magnitude;

		this->ResetCost();

		return true;
	}
}
