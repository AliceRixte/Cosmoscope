#include "CSC_CosmovertorSDL.h"

namespace cosmoscopeSDL {

	//converts a double ranging from 0 to 1 to an integer ranging from 0 to 255
	

	CosmovertorSDL::CosmovertorSDL(const cosmoscope::FuncTree* func_tree, double length_scale, floatpix::Position origin) :
		m_funcTree(func_tree), 
		m_lengthScale(length_scale),
		m_origin(origin),
		m_snapQ(func_tree->GetRecurrenceDepth()+1) {

	}

	void CosmovertorSDL::ComputeAndConvert(double t, SnapQueueSDL* snap_q) {
		m_funcTree->ComputeAll(t, &m_snapQ);
		cosmoscope::TreeSnap ts;
		while (m_snapQ.ReadSnap(&ts)) {
			snap_q->WriteSnap(TreeSnapToSDL(ts));
		}
	}



	double CosmovertorSDL::DistanceToCosmos(floatpix::Distance  length) const {
		return length / m_lengthScale;
	}

	floatpix::Distance CosmovertorSDL::CosmosToDistance(double cosmic_length) const {
		return cosmic_length * m_lengthScale;
	}

	SDL_Point CosmovertorSDL::PositionToSDL(const cosmoscope::CartesianPos& pos) const {
		return SDL_Point{
			static_cast<int>(CosmosToDistance(pos.x) + m_origin.x),
			static_cast<int>(CosmosToDistance(pos.y) + m_origin.y)
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

	StyleSDL CosmovertorSDL::StyleToSDL(const cosmoscope::Style& style) const {
		return StyleSDL{
			ColorToSDL(style.color),
			BrushStyleSDL{
				style.brush.h,
				static_cast<int>(CosmosToDistance(style.brush.radius))
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