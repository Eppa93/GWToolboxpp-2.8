#pragma once

#include <Defines.h>
#include "ToolboxWidget.h"

class SoulCounterWidget : public ToolboxWidget {
	SoulCounterWidget() {};
	~SoulCounterWidget() {};
public:
	static SoulCounterWidget& Instance() {
		static SoulCounterWidget instance;
		return instance;
	}

	const char* Name() const override { return "Soul Counter"; }

	// Draw user interface. Will be called every frame if the element is visible
	void Draw(IDirect3DDevice9* pDevice) override;

	void LoadSettings(CSimpleIni* ini) override;
	void SaveSettings(CSimpleIni* ini) override;
	void DrawSettingInternal() override;


	bool show_mobcount = true;
	bool use_coloring = true;

};
