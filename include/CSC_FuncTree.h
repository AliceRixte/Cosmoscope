/// @file CSC_FuncTree.h
/// @brief Contains the FuncTree class, which organises all the relative functions so they can be executed.
/// @author Alice Rixte
/// @date 05/04/2022
#pragma once

#include <iostream>
#include <exception>
#include <string>
#include<vector>
#include<functional>

#include "CSC_RelativeFunc.h"
#include "CSC_CoorSystem.h"


// This class regroups all the relative functions. Their frame is tied to their parent function or to the chosen origin if their parent id is -1
namespace cosmoscope {

	/// @brief An exception used by FuncTree when it is unable to solve parent dependencies between relative functions
	class BadFuncOrdering : public std::exception
	{
	public:
		/// @brief Constructor asking for the problematic pair of ids of relative functions
		/// @param id_problem Id of the problematic relative function
		/// @param parent_problem Id of the inaccessible parent it refers to
		BadFuncOrdering(int id_problem, int parent_problem);
		virtual const char* what() const throw();
	private:
		/// @brief Id of the problematic relative function
		int m_idProblem;
		/// @brief Id of the inaccessible parent it refers to
		int m_parentProblem;
	};


	/// @brief Organises in a hierarchy all the relative functions of the cosmoscope
	/// There should only be one instance of this class
	class FuncTree {
	public:
		/// @brief Simple constructor only specifying the main origin point
		/// @param origin The position corresponding to the point (0,0) of the Cosmoscope main cartesian system
		FuncTree(const CartesianPos& origin);

		/// @brief Computes all the positions of the relative functions at a time **t**
		/// @param t The current time
		/// @return A vector containing the position of each relative function
		std::vector<CartesianPos> ComputeAllPos(Time t) const;

		/// @brief Computes all the syules of the relative functions at a time **t**
		/// @param t The current time
		/// @return A vector containing the style of each relative function
		std::vector<Style> ComputeAllStyle(Time t) const;

		/// @brief Adds a new monochrome cartesian relative function to the tree.
		/// @param parent_id The ID of the parent relative function, or -1, if it's bound to the origin
		/// @param param_cb The cartesian parametric callback function 
		/// @param style The style of the function. This will create a constant style function
		/// @return The ID of the newly added relative function.
		int AddMonochromeCartesian(int parent_id, const CartesianCallback& cartesian_cb, const Style& style = {1.0,1.0,1.0,1.0,1.0});

		/// @brief Adds a new monochrome polar relative function to the tree.
		/// @param parent_id The ID of the parent relative function, or -1, if it's bound to the origin
		/// @param param_cb The polar parametric callback function 
		/// @param style The style of the function. This will create a constant style function
		/// @return The ID of the newly added relative function.
		int AddMonochromePolar(int parent_id, const PolarCallback& polar_cb, const Style& style = { 1.0,1.0,1.0,1.0,1.0 });

		/// @brief Adds a new polychrome relative function to the tree.
		/// @param parent_id The ID of the parent relative function, or -1, if it's bound to the origin
		/// @param param_cb A cartesesian parametric callback function 
		/// @param style_cb A style callback function.
		/// @return The ID of the newly added relative function.
		int AddPolychromeCartesian(int parent_id, const CartesianCallback& cartesian_cb, const StyleCallback& style_cb);

		/// @brief Adds a new polychrome polar relative function to the tree.
		/// @param parent_id The ID of the parent relative function, or -1, if it's bound to the origin
		/// @param polar_cb A polar parametric callback function 
		/// @param style_cb A style callback function.
		/// @return The ID of the newly added relative function.
		int AddPolychromePolar(int parent_id, const PolarCallback& polar_cb, const StyleCallback& style_cb);


		/// @brief Sets the default origin. This corresponds to the "-1" parent
		/// @param origin The position corresponding to the point (0,0) of the Cosmoscope main cartesian system
		void SetOrigin(const CartesianPos& origin);

		~FuncTree();


	private:
		std::vector<RelativeFunc*> funcs;
		CartesianPos m_origin;
	};

}