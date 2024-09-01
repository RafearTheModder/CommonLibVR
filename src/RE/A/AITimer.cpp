#include "RE/A/AITimer.h"

namespace RE
{
	float AITimer::GetTimer()
	{
		REL::Relocation<float**> singleton{ RELOCATION_ID(517597, 404125) };
		return **singleton;
	}
}
