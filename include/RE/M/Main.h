#pragma once

#include "RE/B/BSTEvent.h"
#include "RE/B/BSTMessageQueue.h"
#include "RE/S/ScrapHeap.h"

#include "REX/W32/BASE.h"

namespace RE
{
	class NiNode;
	class NiCamera;
	class Scenegraph;
	class ScrapHeap;
	struct BSGamerProfileEvent;
	struct BSPackedTask;
	struct PositionPlayerEvent;

	struct BSPackedTaskQueue
	{
	public:
		using UnpackFunc_t = void(const BSPackedTask*);

		struct Semaphore
		{
		public:
			// members
			void*         handle;    // 00
			std::uint32_t size;      // 08
			std::uint32_t capacity;  // 0C
		};
		static_assert(sizeof(Semaphore) == 0x10);

		// members
		BSTCommonScrapHeapMessageQueue<BSPackedTask> queue;       // 00
		mutable Semaphore                            semaphore;   // 28
		UnpackFunc_t*                                unpackFunc;  // 38
	};
	static_assert(sizeof(BSPackedTaskQueue) == 0x40);

	struct BSSaveDataSystemUtilityImage
	{
	public:
		// members
		std::uint32_t size;    // 00
		std::uint32_t width;   // 04
		std::uint32_t height;  // 08
		std::uint32_t pad0C;   // 0C
		char*         buffer;  // 10
	};
	static_assert(sizeof(BSSaveDataSystemUtilityImage) == 0x18);

	class Main :
#ifndef SKYRIMVR
		public BSTEventSink<PositionPlayerEvent>,  // 00
		public BSTEventSink<BSGamerProfileEvent>   // 08
#else
		public BSTEventSink<PositionPlayerEvent>  // 00
#endif
	{
	public:
		inline static constexpr auto RTTI = RTTI_Main;
		inline static constexpr auto VTABLE = VTABLE_Main;

		~Main() override;  // 00

		// override (BSTEventSink<PositionPlayerEvent>)
		BSEventNotifyControl ProcessEvent(const PositionPlayerEvent* a_event, BSTEventSource<PositionPlayerEvent>* a_eventSource) override;  // 01 - { return BSEventNotifyControl::kContinue; }

#ifndef SKYRIMVR
		// override (BSTEventSink<BSGamerProfileEvent>)
		BSEventNotifyControl ProcessEvent(const BSGamerProfileEvent* a_event, BSTEventSource<BSGamerProfileEvent>* a_eventSource) override;  // 01
#endif
		static Main* GetSingleton();

		static float       QFrameAnimTime();
		static NiCamera*   WorldRootCamera();
		static Scenegraph* WorldRootNode();

		bool IsRoomVisible(NiNode* a_room);
		void SetActive(bool a_active);

		// members
		bool                         quitGame;                     // 010 VR 08
		bool                         resetGame;                    // 011 VR 09
		bool                         fullReset;                    // 012 VR 0a
		bool                         gameActive;                   // 013 VR 0b
		bool                         onIdle;                       // 014 VR 0c
		bool                         reloadContent;                // 015 VR 0d
		bool                         freezeTime;                   // 016 VR 0e
		bool                         freezeNextFrame;              // 017 VR 0f This continues for all members I assume
		REX::W32::HWND               wnd;                          // 018
		REX::W32::HINSTANCE          instance;                     // 020
		std::uint32_t                threadID;                     // 028
		std::uint32_t                unk02C;                       // 02C
		std::uint64_t                unk030;                       // 030
		ScrapHeap                    packedTaskHeap;               // 038
		BSPackedTaskQueue            taskQueue;                    // 0C8
		ScrapHeap                    secondaryPackedTaskHeap;      // 108
		BSPackedTaskQueue            secondaryTaskQueue;           // 198
		std::uint8_t                 unk1D8;                       // 1D8
		std::uint8_t                 unk1D9;                       // 1D9
		std::uint16_t                unk1DA;                       // 1DA
		std::uint32_t                unk1DC;                       // 1DC
		BSSaveDataSystemUtilityImage saveDataBackgroundImages[3];  // 1E0
		BSSaveDataSystemUtilityImage saveDataIconImages[3];        // 228
	private:
		KEEP_FOR_RE()
	};
#ifndef SKYRIMVR
	static_assert(sizeof(Main) == 0x270);
#else
	static_assert(sizeof(Main) == 0x268);
#endif
}
