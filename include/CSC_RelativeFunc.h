/// @file CSC_RelativeFunc.h
/// @brief Contains the class RelativeFunc, which ties each function to another function, called the parent function. 
/// The origin of the coordinate system of the child function is most of the time moving.
/// The main origin, at a position of (0,0), is represented by ``id = -1``
/// 
/// @author Alice Rixte
/// @date 05/04/2022
#pragma once

#include<functional>
#include "CSC_CallbackFuncs.h"

namespace cosmoscope {

    /// @brief A relative function that relies on a parent function to be traced.
    /// The relative function uses callbacks to be able to, at each moment in time, compute its position, its style and its own time distortion.
    class RelativeFunc {
    public:
        /// @brief A constructor allowing to create a monochrome cartesian relative function
        /// @param id_parent The id of the parent relative function. Set to -1 to tie to the main origin.
        /// @param cartesian_cb A cartesian parametric callback function
        /// @param style The style of the function
        explicit RelativeFunc(int id_parent, const CartesianCallback& cartesian_cb, const Style& style = Style {255,255,255,255});

        /// @brief A constructor allowing to create a monochrome polar relative function
        /// @param id_parent The id of the parent relative function. Set to -1 to tie to the main origin.
        /// @param polar_cb A polar parametric callback function
        /// @param style The style of the function
        explicit RelativeFunc(int id_parent, const PolarCallback& polar_cb, const Style& style = Style{ 255,255,255,255});



        /// @brief A constructor allowing to create a polychrome cartesian relative function.
        /// @param id_parent The id of the parent relative function. Set to -1 to tie to the main origin.
        /// @param param_cb A cartesian parametric callback function
        /// @param style_cb A style callback function
        explicit RelativeFunc(int id_parent, const CartesianCallback& cartesian_cb, const StyleCallback& style_cb);

        // @brief A constructor allowing to create a polychrome polar relative function.
        /// @param id_parent The id of the parent relative function. Set to -1 to tie to the main origin.
        /// @param polar_cb A polar parametric callback function
        /// @param style_cb A style callback function
        explicit RelativeFunc(int id_parent, const PolarCallback& polar_cb, const StyleCallback& style_cb);



        /// @brief A constructor allowing to create a fully customized cartesian relative function
        /// @param id_parent The id of the parent relative function. Set to -1 to tie to the main origin.
        /// @param cartesian_cb A cartesian parametric callback function
        /// @param style_cb A style callback function
        /// @param time_cb A time callback function
        explicit RelativeFunc(int id_parent, const CartesianCallback& cartesian_cb, const StyleCallback& style_cb, const TimeCallback& time_cb);

       /// @brief A constructor allowing to create a fully customized polar relative function
       /// @param id_parent The id of the parent relative function. Set to -1 to tie to the main origin.
       /// @param polar_cb A cartesian parametric callback function
       /// @param style_cb A style callback function
       /// @param time_cb A time callback function
        explicit RelativeFunc(int id_parent, const PolarCallback& polar_cb, const StyleCallback& style_cb, const TimeCallback& time_cb);


            
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
        /// @return The absolute position of the function at time **t**
        CartesianPos ComputePos(Time t, const CartesianPos& origin);

        /// @brief Compute the style of the relative function at a time **t**
        /// @param t  The current time
        /// @return The style of the function at time **t**
        Style ComputeStyle(Time t);

    private:

        int m_parent;
        ParamFunc m_paramFunc;
        StyleFunc m_styleFunc;
        TimeFunc  m_timeFunc;

    };


}