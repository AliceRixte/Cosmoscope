#include "CSC_SnapQueue.h"

namespace cosmoscope {
	SnapQueue::SnapQueue(unsigned int history_size) :
		m_start(0),
		m_history(history_size)
	{

	}

	TreeSnap SnapQueue::GetSnap(unsigned int age) const {
		return m_history[(m_start + age) % m_history.size()];
	}

	void SnapQueue::WriteSnap(const TreeSnap& tree_snap) {
		m_start = m_start == 0 ? static_cast<int>(m_history.size()) - 1 : m_start - 1;
		m_history[m_start] = tree_snap;
	}
}