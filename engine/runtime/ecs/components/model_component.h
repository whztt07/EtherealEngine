#pragma once

#include "../../rendering/model.h"
#include "../ecs.h"

class material;
//-----------------------------------------------------------------------------
// Main Class Declarations
//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
//  Name : model_component (Class)
/// <summary>
/// Class that contains core data for meshes.
/// </summary>
//-----------------------------------------------------------------------------
class model_component : public runtime::component_impl<model_component>
{
	SERIALIZABLE(model_component)
	REFLECTABLEV(model_component, component)

public:
	//-------------------------------------------------------------------------
	// Public Virtual Methods (Override)

	//-------------------------------------------------------------------------
	// Public Methods
	//-------------------------------------------------------------------------
	//-----------------------------------------------------------------------------
	//  Name : set_casts_shadow ()
	/// <summary>
	///
	///
	///
	/// </summary>
	//-----------------------------------------------------------------------------
	model_component& set_casts_shadow(bool cast_shadow);

	//-----------------------------------------------------------------------------
	//  Name : set_casts_reflection ()
	/// <summary>
	///
	///
	///
	/// </summary>
	//-----------------------------------------------------------------------------
	model_component& set_casts_reflection(bool casts_reflection);

	//-----------------------------------------------------------------------------
	//  Name : set_static ()
	/// <summary>
	///
	///
	///
	/// </summary>
	//-----------------------------------------------------------------------------
	model_component& set_static(bool is_static);

	//-----------------------------------------------------------------------------
	//  Name : casts_shadow ()
	/// <summary>
	///
	///
	///
	/// </summary>
	//-----------------------------------------------------------------------------
	bool casts_shadow() const;

	//-----------------------------------------------------------------------------
	//  Name : casts_reflection ()
	/// <summary>
	///
	///
	///
	/// </summary>
	//-----------------------------------------------------------------------------
	bool casts_reflection() const;

	//-----------------------------------------------------------------------------
	//  Name : is_static ()
	/// <summary>
	///
	///
	///
	/// </summary>
	//-----------------------------------------------------------------------------
	bool is_static() const;

	//-----------------------------------------------------------------------------
	//  Name : get_model ()
	/// <summary>
	///
	///
	///
	/// </summary>
	//-----------------------------------------------------------------------------
	const model& get_model() const;

	//-----------------------------------------------------------------------------
	//  Name : set_model ()
	/// <summary>
	///
	///
	///
	/// </summary>
	//-----------------------------------------------------------------------------
	model_component& set_model(const model& model);

	model_component& set_bone_entities(const std::vector<runtime::entity>& bone_entities);
	const std::vector<runtime::entity>& get_bone_entities() const;
	model_component& set_bone_transforms(const std::vector<math::transform>& bone_transforms);
	const std::vector<math::transform>& get_bone_transforms() const;

private:
	//-------------------------------------------------------------------------
	// Private Member Variables.
	//-------------------------------------------------------------------------
	///
	bool _static = true;
	///
	bool _casts_shadow = true;
	///
	bool _casts_reflection = true;
	///
	model _model;
	///
	std::vector<runtime::entity> _bone_entities;
	std::vector<math::transform> _bone_transforms;
};
