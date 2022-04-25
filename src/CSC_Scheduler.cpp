#include "CSC_Scheduler.h"

namespace cosmoscope {
	Scheduler::Scheduler(const FuncTree& func_tree) :
		m_start(0),
		m_snapBuf(),
		m_readIndex(0),
		m_ftree(func_tree)
	{

	}

	void Scheduler::ComputeSnaps(Time t, int nb_snaps) {
		for (int i = 0; i < nb_snaps; i++) {

			m_snapBuf.push_back(m_ftree.Compute(t)); 
		}
	}

	std::vector<TreeSnap> Scheduler::ReadSnaps()  {
		std::vector<TreeSnap> res = m_snapBuf;
		m_snapBuf = {};
		return res;
	}
}