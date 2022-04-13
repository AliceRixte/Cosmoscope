/// @file CSC_Cosmovertor.h
/// @brief Allows the cosmoscope to communicate with the rest of the world
///
/// @author Alice Rixte
/// @date 07/04/2022
#pragma once

#include "CSC_CallbackFuncs.h"

namespace cosmoscope {
		/// @brief This class aims to facilitate the conversions between real life units and the cosmoscope's narmalized units
		struct Cosmovertor {
			/// @brief  Creates a cosmovertor 
			/// @param length_scale This is the SDL length of  the virtual ``1.0`` Cosmscope length
			/// @param angle_scale This is the angle measure of a complete 360 degrees rotation. 
			/// In degrees, this should be 360, in radians, this should be 2*PI.
			Cosmovertor(double length_scale, double angle_scale);

			/// @brief Converts an application length to a cosmic length
			/// @param length Application length
			/// @return Cosmic length
			double lengthToCosmos(double length);
			/// @brief Converts a cosmic length to an application length 
			/// @param length Cosmic length 
			/// @return Application length
			double cosmosToLength(double cosmic_length);

			/// @brief Converts an application angle to a cosmic angle
			/// @param length Application angle
			/// @return Cosmic angle
			double angleToCosmos(double angle);
			/// @brief Converts a cosmic angle to an application angle
			/// @param length Cosmic angle
			/// @return Application angle
			double cosmosToAngle(double cosmic_angle);

			/// @brief Prepares a cartesian callback to be added in the relative function tree. 
			/// The generated callback MUST be deleted, which is why this class is private in the cosmoscope namespace
			/// @param param_cb A parametric (cartesian) callback function
			/// @return A new callback function (to be deleted)
			cosmoscope::CartesianCallback cartesianCbToCosmos(cosmoscope::CartesianCallback param_cb);


			/// @brief This is the SDL length of  the virtual ``1.0`` Cosmscope length
			double m_lengthScale;
			/// @brief This is the angle measure of a complete 360 degrees rotation. 
			/// In degrees, this should be 360, in radians, this should be 2*PI.
			double m_angleScale;
		};
}

