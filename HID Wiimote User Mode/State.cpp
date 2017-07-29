/*

Copyright (C) 2016 Julian L�hr
All rights reserved.

Filename:
	State.cpp

Abstract:
	Implementation of the Status Class

*/
#include "stdafx.h"
#include "State.h"

#include "Log.h"

#include "../HID Wiimote/SettingsInterface.h"

namespace HIDWiimote
{
	namespace UserModeLib
	{
		State::State()
		{
			Status = gcnew UserModeLib::Status();	
			Mode = DriverMode::PassThrough;
		}

		State::State(const WIIMOTE_STATE_IOCTL_DATA & StateData)
		{
			Status = gcnew UserModeLib::Status(StateData.Status);

			Mode = (UserModeLib::DriverMode)StateData.Settings.Mode;

			EnableWiimoteXAxisAccelerometer = (StateData.Settings.EnableWiimoteXAxisAccelerometer != FALSE);
			EnableWiimoteYAxisAccelerometer = (StateData.Settings.EnableWiimoteYAxisAcceleromenter != FALSE);
			SwitchMouseButtons = (StateData.Settings.SwitchMouseButtons != FALSE);
			SwitchTriggerAndShoulder = (StateData.Settings.SwitchTriggerAndShoulder != FALSE);
			SplitTrigger = (StateData.Settings.SplitTriggerAxis != FALSE);
			MapTriggerAsAxis = (StateData.Settings.MapTriggerAsAxis != FALSE);
			MapTriggerAsButtons = (StateData.Settings.MapTriggerAsButtons != FALSE);
		}
	}
}
