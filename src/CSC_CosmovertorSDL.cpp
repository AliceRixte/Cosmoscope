#include "CSC_CosmovertorSDL.h"

namespace cosmoscopeSDL {


	CosmovertorSDL::CosmovertorSDL(const cosmoscope::FuncTree& func_tree, double length_scale, Point origin, double max_brush_size) :
		m_lengthScale(length_scale),
		m_origin(origin),
		m_maxBrushSize(max_brush_size),
		m_scheduler(func_tree) {
	}

	CosmovertorSDL::CosmovertorSDL(cosmoscope::FuncTree&& func_tree, double length_scale, Point origin, double max_brush_size) :
		m_lengthScale(length_scale),
		m_origin(origin),
		m_maxBrushSize(max_brush_size),
		m_scheduler(std::move(func_tree)) {

	}

	void CosmovertorSDL::ComputeAndConvert(double t, SnapQueueSDL* snap_q) {
		m_scheduler.ComputeSnaps(t, 1);
		snap_q->WriteSnap(TreeSnapToSDL(m_scheduler.ReadSnaps()[0]));
	}



	double CosmovertorSDL::DistanceToCosmos(double length) const {
		return length / m_lengthScale;
	}

	double CosmovertorSDL::CosmosToDistance(double cosmic_length) const {
		return cosmic_length * m_lengthScale;
	}

	Point CosmovertorSDL::PositionToSDL(const cosmoscope::CartesianPos& pos) const {
		return Point{
			CosmosToDistance(pos.x) + m_origin.get<0>(),
			CosmosToDistance(pos.y) + m_origin.get<1>()
		};
	}



	Uint8 double01to255(double v) {
		return static_cast<Uint8>(255 * v);
	}
	SDL_Color CosmovertorSDL::ColorToSDL(const cosmoscope::Color& color) const  {
		return SDL_Color{ double01to255(color.r),
							double01to255(color.g),
							double01to255(color.b),
							double01to255(color.a)
		};
	}	

	double CosmovertorSDL::TimeToSDL(const cosmoscope::Time& t) const  {
		return t;
	}

	double CosmovertorSDL::BrushRadiusToSDL(double br) const {
		return br * m_maxBrushSize;
	}

	StyleSDL CosmovertorSDL::StyleToSDL(const cosmoscope::Style& style) const {
		return StyleSDL{
			ColorToSDL(style.color),
			BrushStyleSDL{
				BrushRadiusToSDL(style.brush.radius),
				style.brush.h
			},
			ColorToSDL(style.color2)
		};
	}

	FuncSnapSDL CosmovertorSDL::FuncSnapToSDL(const cosmoscope::FuncSnap& fs) const {
		return FuncSnapSDL{
			TimeToSDL(fs.tt),
			PositionToSDL(fs.p),
			StyleToSDL(fs.s)
		};
	}

	TreeSnapSDL CosmovertorSDL::TreeSnapToSDL(const cosmoscope::TreeSnap& ts) const {
		TreeSnapSDL res;
		for (auto fs : ts) {
			res.push_back(FuncSnapToSDL(fs));
		}
		return res;
	}
		
}