#pragma once

#include <Windows.h>
#include <vector>
#include <Defines.h>

#include "ToolboxWindow.h"

class DomainOfAnguishTimer : public ToolboxWindow {
	DomainOfAnguishTimer() {};
	~DomainOfAnguishTimer() {};
public:
	static DomainOfAnguishTimer& Instance() {
		static DomainOfAnguishTimer instance;
		return instance;
	}

	float doaChestX[4] = { 227,-14436,3435,10943 };
	float doaChestY[4] = { -10264,-523,15590,-10151 };
	long doaQ[4] = { 0,0,0,0 };
	static char timer[32];
	bool reset = false;
	long min = doaQ[0];
	long min_i;


	const char* Name() const override { return "DoA Timer"; }


	// Draw user interface. Will be called every frame if the element is visible
	void Draw(IDirect3DDevice9* pDevice) override;

	void LoadSettings(CSimpleIni* ini) override;
	void SaveSettings(CSimpleIni* ini) override;
	void DrawSettingInternal() override;

	void Initialize() override;
	void Terminate() override;

};
