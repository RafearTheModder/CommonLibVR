#pragma once

#include "RE/B/BSImagespaceShader.h"

namespace RE
{
	class BSImagespaceShaderBlur3 : public BSImagespaceShader
	{
	public:
		inline static constexpr auto RTTI = RTTI_BSImagespaceShaderBlur3;
		inline static constexpr auto VTABLE = VTABLE_BSImagespaceShaderBlur3;

		~BSImagespaceShaderBlur3() override;  // 00

		// override (BSImagespaceShader)
		void GetShaderMacros(ShaderMacro* a_macros) override;  // 0D
	private:
		KEEP_FOR_RE()
	};
	static_assert(sizeof(BSImagespaceShaderBlur3) == 0x1A8);
}
