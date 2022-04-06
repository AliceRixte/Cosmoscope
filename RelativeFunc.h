/// @file RelativeFunc.h
/// @brief Contains the class RelativeFunc, which ties each function to another function, called the parent function. 
/// The origin of the coordinate system of the child function is most of the time moving.
/// The main origin, at a position of (0,0), is represented by ``id = -1``
/// 
/// @author Alice Rixte
/// @date 05/04/2022
#pragma once

#include<functional>
#include "CallbackFuncs.h"

namespace cosmoscope {

    /// @brief A relative function that relies on a parent function to be traced.
    /// The relative function uses callbacks to be able to, at each moment in time, compute its position, its style and its own time distortion.
    class RelativeFunc {
    public:
        /// @brief A constructor allowing to create a monochrome relative function
        /// @param id_parent The id of the parent relative function. Set to -1 to tie to the main origin.
        /// @param param_cb A parametric callback function
        /// @param coor The coordinate system type
        /// @param style The style of the function
        explicit RelativeFunc(int id_parent, const ParamCallback& param_cb,
                const CoorSystem& coor = CoorSystem::Cartesian, 
                const Style& style = Style {255,255,255,255});

        /// @brief Get the relative function's parent id.
        /// @return The parent id of the function
        int GetParent();

        /// @brief Get the relative function's parent id.
        /// @param id_parent The new parent id. Set to -1 to tie to the main origin.
        void SetParent(int id_parent);
       
        /// @brief Compute the position of the relative function at a time **t**
        /// @param t  The current time
        /// @param origin The relative origin of the function. 
        /// This should be the result of the ComputePos method of the parent relative function, or (0,0) if the parent id is ``-1``.
        /// @return The current absolute position of the function
        Position ComputePos(const Time& t, const Position& origin);

    private:

        int m_parent;
        ParamFunc m_paramFunc;
        StyleFunc m_styleFunc;

    };


}