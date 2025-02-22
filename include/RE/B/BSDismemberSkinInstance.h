#pragma once

#include "RE/N/NiSkinInstance.h"

namespace RE
{
	class BSDismemberSkinInstance : public NiSkinInstance
	{
	public:
		inline static constexpr auto RTTI = RTTI_BSDismemberSkinInstance;
		inline static constexpr auto Ni_RTTI = NiRTTI_BSDismemberSkinInstance;
		inline static constexpr auto VTABLE = VTABLE_BSDismemberSkinInstance;

		struct Data
		{
		public:
			// members
			bool          editorVisible;    // 0
			bool          startNetBoneSet;  // 1
			std::uint16_t slot;             // 2 - https://wiki.nexusmods.com/index.php/Skyrim_bodyparts_number
		};
		static_assert(sizeof(Data) == 0x4);

		~BSDismemberSkinInstance() override;  // 00

		// override (NiSkinInstance)
		const NiRTTI* GetRTTI() const override;                           // 02
		NiObject*     CreateClone(NiCloningProcess& a_cloning) override;  // 17
		void          LoadBinary(NiStream& a_stream) override;            // 18
		void          LinkObject(NiStream& a_stream) override;            // 19 - { NiSkinInstance::LinkObject(a_stream); }
		bool          RegisterStreamables(NiStream& a_stream) override;   // 1A - { return NiSkinInstance::RegisterStreamables(a_stream) != false; }
		void          SaveBinary(NiStream& a_stream) override;            // 1B
		bool          IsEqual(NiObject* a_object) override;               // 1C
		void          Unk_25(void) override;                              // 25

		void UpdateDismemberPartion(std::uint16_t a_slot, bool a_enable)
		{
			using func_t = decltype(&BSDismemberSkinInstance::UpdateDismemberPartion);
			static REL::Relocation<func_t> func{ RELOCATION_ID(15576, 15753) };
			return func(this, a_slot, a_enable);
		}

		// members
		std::int32_t  numPartitions;  // 88 VR 68
		std::uint32_t pad8C;          // 8C VR 6C
		Data*         partitions;     // 90 VR 70
		bool          unk98;          // 98 VR 78
		std::uint8_t  pad99;          // 99 VR 79
		std::uint16_t pad9A;          // 9A VR 7A
		std::uint32_t pad9C;          // 9C VA 7C
	private:
		KEEP_FOR_RE()
	};
#ifndef SKYRIMVR
	static_assert(sizeof(BSDismemberSkinInstance) == 0xA0);
#else
	static_assert(sizeof(BSDismemberSkinInstance) == 0x80);
#endif
}
