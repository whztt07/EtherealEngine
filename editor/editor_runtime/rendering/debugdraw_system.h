#pragma once

#include "core/system/subsystem.h"
#include <chrono>
#include <memory>

class gpu_program;

namespace editor
{
class debugdraw_system : public core::subsystem
{
public:
	//-----------------------------------------------------------------------------
	//  Name : initialize ()
	/// <summary>
	///
	///
	///
	/// </summary>
	//-----------------------------------------------------------------------------
	bool initialize();

	//-----------------------------------------------------------------------------
	//  Name : dispose ()
	/// <summary>
	///
	///
	///
	/// </summary>
	//-----------------------------------------------------------------------------
	void dispose();

	//-----------------------------------------------------------------------------
	//  Name : frame_render ()
	/// <summary>
	///
	///
	///
	/// </summary>
	//-----------------------------------------------------------------------------
	void frame_render(std::chrono::duration<float> dt);

private:
	///
	std::unique_ptr<gpu_program> _program;
};
}
