#include "RE/E/EnchantmentItem.h"

namespace RE
{
	float EnchantmentItem::ModifyPower(float power, float enchantingSkill)
	{
		using func_t = decltype(&EnchantmentItem::ModifyPower);
		static REL::Relocation<func_t> func{ RELOCATION_ID(25910, 26493) };
		return func(power, enchantingSkill);
	}
}
