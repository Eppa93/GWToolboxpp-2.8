#pragma once

#include <Defines.h>
#include "ToolboxWidget.h"
#include <Windows\UnderworldTimer.h>
#include <Windows\DomainOfAnguishTimer.h>

class SpamWidget : public ToolboxWidget {
	SpamWidget() {};
	~SpamWidget() {};
public:
	static SpamWidget& Instance() {
		static SpamWidget instance;
		return instance;
	}

	const char* Name() const override { return "Spam"; }

	// Draw user interface. Will be called every frame if the element is visible
	void Draw(IDirect3DDevice9* pDevice) override;

	void LoadSettings(CSimpleIni* ini) override;
	void SaveSettings(CSimpleIni* ini) override;


private:

	char buf[120];

	bool spam = false;
	bool resigned = false;

};
