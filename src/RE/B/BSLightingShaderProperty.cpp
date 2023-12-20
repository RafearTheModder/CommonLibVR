#include "RE/B/BSLightingShaderProperty.h"

namespace RE
{
	void BSLightingShaderProperty::CopyMembers(BSLightingShaderProperty* a_other)
	{
		flags = a_other->flags;
		alpha = a_other->alpha;
		lastRenderPassState = (std::numeric_limits<std::int32_t>::max)();
		if (flags.all(EShaderPropertyFlag::kOwnEmit) && a_other->emissiveColor) {
			if (!emissiveColor) {
				emissiveColor = new NiColor();
			}
			emissiveColor->red = a_other->emissiveColor->red;
			emissiveColor->green = a_other->emissiveColor->green;
			emissiveColor->blue = a_other->emissiveColor->blue;
		}
		projectedUVParams = a_other->projectedUVParams;
		projectedUVColor = a_other->projectedUVColor;
		emissiveMult = a_other->emissiveMult;
	}
#ifdef SKYRIMVR
	void BSLightingShaderProperty::InvalidateTextures(std::uint32_t a_unk1)
	{
		using func_t = decltype(&BSLightingShaderProperty::InvalidateTextures);
		REL::Relocation<func_t> func{ REL::ID(5388393136) };
		func(this, a_unk1);
	}
#endif
}
