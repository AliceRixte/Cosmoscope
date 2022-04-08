#include "CSC_Cosmovertor.h"

namespace cosmoscope {


	Cosmovertor::Cosmovertor(double length_scale, double angle_scale) :m_angleScale(length_scale), m_lengthScale(angle_scale) {

	}

	double Cosmovertor::lengthToCosmos(double length) {
		return length / m_lengthScale;
	}

	double Cosmovertor::cosmosToLength(double cosmic_length) {
		return cosmic_length * m_lengthScale;
	}

	double Cosmovertor::angleToCosmos(double angle) {
		return angle / m_angleScale;
	}

	double Cosmovertor::cosmosToAngle(double cosmic_angle) {
		return cosmic_angle * m_angleScale;
	}

	CartesianCallback Cosmovertor::cartesianCbToCosmos(CartesianCallback param_cb) {
		return [this, param_cb](Time t) {
			CartesianPos res = param_cb(t);
			return CartesianPos{ lengthToCosmos(res.x), lengthToCosmos(res.y) };
		};
	}
}