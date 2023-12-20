#pragma once

namespace RE
{
	struct RENDER_TARGETS
	{
		enum RENDER_TARGET
		{
			kNONE = static_cast<std::underlying_type_t<RENDER_TARGET>>(-1),
			kFRAMEBUFFER = 0,
			kMAIN,
			kMAIN_COPY,
			kMAIN_ONLY_ALPHA,
			kNORMAL_TAAMASK_SSRMASK,
			kNORMAL_TAAMASK_SSRMASK_SWAP,
			kNORMAL_TAAMASK_SSRMASK_DOWNSAMPLED,
			kMOTION_VECTOR,
			kWATER_DISPLACEMENT,
			kWATER_DISPLACEMENT_SWAP,
			kWATER_REFLECTIONS,
			kWATER_FLOW,
			kUNDERWATER_MASK,
			kREFRACTION_NORMALS,
			kMENUBG,
			kPLAYER_FACEGEN_TINT,
			kLOCAL_MAP,
			kLOCAL_MAP_SWAP,
			kSHADOW_MASK,
			kGETHIT_BUFFER,
			kGETHIT_BLURSWAP,
			kBLURFULL_BUFFER,
			kHDR_BLURSWAP,
			kLDR_BLURSWAP,
			kHDR_BLOOM,
			kLDR_DOWNSAMPLE0,
			kHDR_DOWNSAMPLE0,
			kHDR_DOWNSAMPLE1,
			kHDR_DOWNSAMPLE2,
			kHDR_DOWNSAMPLE3,
			kHDR_DOWNSAMPLE4,
			kHDR_DOWNSAMPLE5,
			kHDR_DOWNSAMPLE6,
			kHDR_DOWNSAMPLE7,
			kHDR_DOWNSAMPLE8,
			kHDR_DOWNSAMPLE9,
			kHDR_DOWNSAMPLE10,
			kHDR_DOWNSAMPLE11,
			kHDR_DOWNSAMPLE12,
			kHDR_DOWNSAMPLE13,
			kLENSFLAREVIS,
			kIMAGESPACE_TEMP_COPY,
			kIMAGESPACE_TEMP_COPY2,
			kIMAGESPACE_VOLUMETRIC_LIGHTING,
			kIMAGESPACE_VOLUMETRIC_LIGHTING_PREVIOUS,
			kIMAGESPACE_VOLUMETRIC_LIGHTING_COPY,
			kSAO,
			kSAO_DOWNSCALED,
			kSAO_CAMERAZ_MIP_LEVEL_0_ESRAM,
			kSAO_CAMERAZ,
			kSAO_CAMERAZ_MIP_LEVEL_0,
			kSAO_CAMERAZ_MIP_LEVEL_1,
			kSAO_CAMERAZ_MIP_LEVEL_2,
			kSAO_CAMERAZ_MIP_LEVEL_3,
			kSAO_CAMERAZ_MIP_LEVEL_4,
			kSAO_CAMERAZ_MIP_LEVEL_5,
			kSAO_CAMERAZ_MIP_LEVEL_6,
			kSAO_CAMERAZ_MIP_LEVEL_7,
			kSAO_CAMERAZ_MIP_LEVEL_8,
			kSAO_CAMERAZ_MIP_LEVEL_9,
			kSAO_CAMERAZ_MIP_LEVEL_10,
			kSAO_CAMERAZ_MIP_LEVEL_11,
			kSAO_RAWAO,
			kSAO_RAWAO_DOWNSCALED,
			kSAO_RAWAO_PREVIOUS,
			kSAO_RAWAO_PREVIOUS_DOWNSCALED,
			kSAO_TEMP_BLUR,
			kSAO_TEMP_BLUR_DOWNSCALED,
			kINDIRECT,
			kINDIRECT_DOWNSCALED,
			kRAWINDIRECT,
			kRAWINDIRECT_DOWNSCALED,
			kRAWINDIRECT_PREVIOUS,
			kRAWINDIRECT_PREVIOUS_DOWNSCALED,
			kRAWINDIRECT_SWAP,
			kSAVE_GAME_SCREENSHOT,
			kSCREENSHOT,
			kVOLUMETRIC_LIGHTING_HALF_RES,
			kVOLUMETRIC_LIGHTING_BLUR_HALF_RES,
			kVOLUMETRIC_LIGHTING_QUARTER_RES,
			kVOLUMETRIC_LIGHTING_BLUR_QUARTER_RES,
			kTEMPORAL_AA_ACCUMULATION_1,
			kTEMPORAL_AA_ACCUMULATION_2,
			kTEMPORAL_AA_UI_ACCUMULATION_1,
			kTEMPORAL_AA_UI_ACCUMULATION_2,
			kTEMPORAL_AA_MASK,
			kTEMPORAL_AA_WATER_1,
			kTEMPORAL_AA_WATER_2,
			kRAW_WATER,
			kWATER_1,
			kWATER_2,
			kIBLENSFLARES_LIGHTS_FILTER,
			kIBLENSFLARES_DOWNSAMPLE_4X_4X_PING,
			kIBLENSFLARES_DOWNSAMPLE_4X_4X_PONG,
			kIBLENSFLARES_DOWNSAMPLE_16X_4Y_PING,
			kIBLENSFLARES_DOWNSAMPLE_16X_4Y_PONG,
			kIBLENSFLARES_DOWNSAMPLE_16X_4Y_BLUR,
			kIBLENSFLARES_DOWNSAMPLE_16X_4Y_BLUR_SWAP,
			kIBLENSFLARES_DOWNSAMPLE_32X_4Y_PING,
			kIBLENSFLARES_DOWNSAMPLE_32X_4Y_PONG,
			kIBLENSFLARES_DOWNSAMPLE_32X_4Y_BLUR,
			kIBLENSFLARES_DOWNSAMPLE_32X_4Y_BLUR_SWAP,
			kIBLENSFLARES_DOWNSAMPLE_16X_16X_PING,
			kIBLENSFLARES_DOWNSAMPLE_16X_16X_PONG,
			kIBLENSFLARES_DOWNSAMPLE_16X_16X_SWAP,
			kBOOK_TEXT_0,
			kBOOK_TEXT_1,
			kBOOK_TEXT_2,
			kBOOK_TEXT_3,
			kSSR,
			kSSR_RAW,
			kSSR_BLURRED0,
			kSNOW_SPECALPHA,
			kSNOW_SWAP,

			kTOTAL,  // SE 114, 125 in VR
			kVRTOTAL = 125,
			kFRAMEBUFFER_TOTAL = kMAIN,
		};
	};

	struct RENDER_TARGETS_CUBEMAP
	{
		enum RENDER_TARGET_CUBEMAP
		{
			kNONE = static_cast<std::underlying_type_t<RENDER_TARGET_CUBEMAP>>(-1),
			kREFLECTIONS = 0,

			kTOTAL,
		};
	};

	struct RENDER_TARGETS_3D
	{
		enum RENDER_TARGET_3D
		{
			kNONE = static_cast<std::underlying_type_t<RENDER_TARGET_3D>>(-1),
			kVOLUMETRIC_LIGHTING_ACCUMULATION = 0,
			kVOLUMETRIC_LIGHTING_ACCUMULATION_COPY,
			kVOLUMETRIC_LIGHTING_NOISE,

			kTOTAL,
		};
	};

	struct RENDER_TARGETS_DEPTHSTENCIL
	{
		enum RENDER_TARGET_DEPTHSTENCIL
		{
			kNONE = static_cast<std::underlying_type_t<RENDER_TARGET_DEPTHSTENCIL>>(-1),
			kMAIN = 0,
			kMAIN_COPY,
			kSHADOWMAPS_ESRAM,
			kVOLUMETRIC_LIGHTING_SHADOWMAPS_ESRAM,
			kSHADOWMAPS,
			kDECAL_OCCLUSION,
			kCUBEMAP_REFLECTIONS,
			kPOST_ZPREPASS_COPY,
			kPOST_WATER_COPY,
			kBOOK_TEXT,
			kPRECIPITATION_OCCLUSION_MAP,
			kFOCUS_NEO,

			kTOTAL,  // 12 in SSE, 21 in VR
			kVRTOTAL = 21,
		};
	};

	using RENDER_TARGET = RENDER_TARGETS::RENDER_TARGET;
	using RENDER_TARGET_CUBEMAP = RENDER_TARGETS_CUBEMAP::RENDER_TARGET_CUBEMAP;
	using RENDER_TARGET_3D = RENDER_TARGETS_3D::RENDER_TARGET_3D;
	using RENDER_TARGET_DEPTHSTENCIL = RENDER_TARGETS_DEPTHSTENCIL::RENDER_TARGET_DEPTHSTENCIL;
}
