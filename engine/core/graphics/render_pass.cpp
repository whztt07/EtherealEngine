#include "render_pass.h"
#include "../common/assert.hpp"
#include <bitset>
#include <limits>
namespace gfx
{
static std::uint8_t s_index = 0;
static std::uint8_t s_last_index = 0;

std::uint8_t generate_id()
{
	if(s_index == std::numeric_limits<decltype(s_index)>::max())
	{
		frame();
		s_index = 0;
	}
	// find the first unset bit
	std::uint8_t idx = s_index++;

	s_last_index = idx;
	return idx;
}

render_pass::render_pass(const std::string& n)
{
	id = generate_id();
	set_view_name(id, n.c_str());
}

void render_pass::bind(const frame_buffer* fb) const
{
	expects(fb != nullptr);

	const auto size = fb->get_size();
	const auto width = size.width;
	const auto height = size.height;
	set_view_rect(id, std::uint16_t(0), std::uint16_t(0), std::uint16_t(width), std::uint16_t(height));
	set_view_scissor(id, std::uint16_t(0), std::uint16_t(0), std::uint16_t(width), std::uint16_t(height));
	set_view_frame_buffer(id, fb->native_handle());
	touch(id);
}

void render_pass::bind() const
{
	std::uint16_t width = 0;
	std::uint16_t height = 0;
	get_size_from_ratio(backbuffer_ratio::Equal, width, height);
	set_view_rect(id, std::uint16_t(0), std::uint16_t(0), std::uint16_t(width), std::uint16_t(height));
	set_view_scissor(id, std::uint16_t(0), std::uint16_t(0), std::uint16_t(width), std::uint16_t(height));
	touch(id);
}

void render_pass::clear(std::uint16_t _flags, std::uint32_t _rgba /*= 0x000000ff */, float _depth /*= 1.0f */,
						std::uint8_t _stencil /*= 0*/) const
{
	set_view_clear(id, _flags, _rgba, _depth, _stencil);
}

void render_pass::clear() const
{
	set_view_clear(id, BGFX_CLEAR_COLOR | BGFX_CLEAR_DEPTH | BGFX_CLEAR_STENCIL, 0x000000FF, 1.0f, 0);
}

void render_pass::set_view_proj(const float* v, const float* p)
{
	set_view_transform(id, v, p);
}

void render_pass::reset()
{
	for(std::uint8_t i = 0; i < s_index; ++i)
	{
		reset_view(i);
	}
	s_index = 0;
	s_last_index = 0;
}

std::uint8_t render_pass::get_pass()
{
	return s_last_index;
}
}
