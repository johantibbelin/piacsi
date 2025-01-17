//---------------------------------------------------------------------------
//
// SCSI Target Emulator PiSCSI
// for Raspberry Pi
//
// Copyright (C) 2022 Uwe Seimet
//
//---------------------------------------------------------------------------

#pragma once

#include "generated/piscsi_interface.pb.h"
#include <functional>
#include <thread>

class CommandContext;

using namespace std;
using namespace piscsi_interface;

class PiscsiService
{
	using callback = function<bool(const CommandContext&, piscsi_interface::PbCommand&)>;

	callback execute;

	int service_socket = -1;

	thread monthread;

	static inline volatile bool running = false;

public:

	PiscsiService() = default;
	~PiscsiService() = default;

	bool Init(const callback&, int);
	void Cleanup() const;

	bool IsRunning() const { return running; }
	void SetRunning(bool b) const { running = b; }

private:

	void Execute() const;

	PbCommand ReadCommand(CommandContext&) const;

	static void KillHandler(int) { running = false; }
};
