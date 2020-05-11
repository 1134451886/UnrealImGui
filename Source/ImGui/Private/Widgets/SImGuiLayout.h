// Distributed under the MIT License (MIT) (see accompanying LICENSE file)

#pragma once

#include <Widgets/SCompoundWidget.h>


class FImGuiModuleManager;
class UGameViewportClient;

// Layout preset for ImGui Widget.
class SImGuiLayout : public SCompoundWidget
{
	typedef SCompoundWidget Super;

public:

	SLATE_BEGIN_ARGS(SImGuiLayout)
	{}
	SLATE_ARGUMENT(FImGuiModuleManager*, ModuleManager)
	SLATE_ARGUMENT(UGameViewportClient*, GameViewport)
	SLATE_ARGUMENT(int32, ContextIndex)
	SLATE_END_ARGS()

	void Construct(const FArguments& InArgs);

	~SImGuiLayout();

	const TWeakObjectPtr<UGameViewportClient>& GetGameViewport() const { return GameViewport; }

private:

	float GetDPIScale() const { return DPIScale; }
	void SetDPIScale(float Scale) { DPIScale = Scale; }


	FImGuiModuleManager* ModuleManager = nullptr;
	TWeakObjectPtr<UGameViewportClient> GameViewport;

	float DPIScale = 1.f;
};
