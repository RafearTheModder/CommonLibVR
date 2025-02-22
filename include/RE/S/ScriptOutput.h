#pragma once

namespace RE
{
	enum class ScriptOutput
	{
		kScriptConsoleBase = 0x100,
		kScriptConsoleTotal = 0x1B4,
		kScriptFunctionBase = 0x1000,
		kScriptFunctionTotal = 0x2E0,

		kGetGlobalValue = kScriptFunctionBase + 0x4A,
		kDamageObject = kScriptFunctionBase + 0x16C,
		kIsCurrentSpell = kScriptFunctionBase + 0x253,
		kEntryPointMagicSpellHasKeyword = kScriptFunctionBase + 0x2B5,
		kEntryPointMagicSpellHasSkill = kScriptFunctionBase + 0x2B8
	};
	static_assert(sizeof(ScriptOutput) == 0x4);
}