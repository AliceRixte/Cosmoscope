/// @file CSC_CosmovertorSDL.h
/// @brief Allows the cosmoscope to communicate with the rest of the world
///
/// @author Alice Rixte
/// @date 07/04/2022
#pragma once

#include "SDL.h"

#include "CSC_FuncTree.h"
#include "CSC_SnapQueue.h"
#include "CSC_SnapQueueSDL.h"
#include "CSC_CoorSystemSDL.h"


namespace cosmoscopeSDL {
	/// @brief This class aims to facilitate the conversions between real life units and the cosmoscope's narmalized units
	class CosmovertorSDL {
	public :
		/// @brief  Creates an SDL cosmovertor 
		/// @param length_scale This is the SDL length of  the virtual ``1.0`` Cosmscope length
		/// @param angle_scale This is the angle measure of a complete 360 degrees rotation. 
		/// In degrees, this should be 360, in radians, this should be 2*PI.
		/// @param origin The location of the screen of the origin of the relative func tree
		CosmovertorSDL(const cosmoscope::FuncTree& m_func_tree, double length_scale, Point origin, double max_brush_size);

		CosmovertorSDL(cosmoscope::FuncTree&& m_func_tree, double length_scale, Point origin, double max_brush_size);

		/// @brief Converts the cosmic snapqueue to an SDL snapqueue.
		/// @param snap_q_sdl 
		void ComputeAndConvert(double t, SnapQueueSDL* snap_q_sdl);


		/// @brief Converts an application length to a cosmic length
		/// @param length Application length
		/// @return Cosmic length
		double DistanceToCosmos(double length) const;
		/// @brief Converts a cosmic length to an application length 
		/// @param length Cosmic length 
		/// @return Application length
		double CosmosToDistance(double cosmic_length) const;

		/// @brief Converts a cartesian position to a boost geometry point
		/// @param pos A cartesian position (using cosmic length)
		/// @return An boost geoimetry point position
		Point PositionToSDL(const cosmoscope::CartesianPos& pos) const ;

		/// @brief Converts a cartesian position to a float position
		/// @param pos A cartesian position (using cosmic length)
		/// @return An float position
		//floatpix::Position PositionToFloat(const cosmoscope::CartesianPos& pos) const;

		/// @brief Converts a cosmic color to an SDL_color
		/// @param c  A cosmic color
		/// @return An SDL_Color
		SDL_Color ColorToSDL(const cosmoscope::Color& c) const ;

		/// @brief Converts a cosmic time to a standard time 
		/// @param c  A cosmic time
		/// @return A double time
		double TimeToSDL(const cosmoscope::Time& t) const ;

		/// @brief Converts a cosmic brush radius to an SDL radius
		/// @param br  A cosmic brush radius
		/// @return An SDL brush radius
		double BrushRadiusToSDL(double br) const ; 

		/// @brief Converts a cosmic style to an SDL style
		/// @param s A cosmic style
		/// @return An SDL style
		StyleSDL StyleToSDL(const cosmoscope::Style& s) const ;

		/// @brief Converts a cosmic function snapshop to an SDL one
		/// @param fs A cosmic function snapshot
		/// @return An SDL function snapshot
		FuncSnapSDL FuncSnapToSDL(const cosmoscope::FuncSnap& fs) const ;

		/// @brief Converts a cosmic function tree snapshot  to an SDL one
		/// @param s A cosmic function tree snapshot
		/// @return An SDL cosmic function snapshot
		TreeSnapSDL TreeSnapToSDL(const cosmoscope::TreeSnap& fs) const ;


	private :

		/// @brief This is the SDL length of  the virtual ``1.0`` Cosmscope length
		double m_lengthScale;
		double m_maxBrushSize;
		Point m_origin;

		cosmoscope::SnapQueue m_snapQ;
		const cosmoscope::FuncTree m_funcTree;
	};
}

