#include "CSC_SnapQueue.h"

namespace cosmoscope {
	SnapQueue::SnapQueue(unsigned int history_size) :
		m_start(0),
		m_history(history_size),
		m_readIndex(0)
	{

	}

	TreeSnap SnapQueue::GetSnap(unsigned int age) const {
		return m_history[(m_start + age) % m_history.size()];
	}

	int SnapQueue::NextIndex(int i) {
		if (i == 0) {
			return static_cast<int>(m_history.size()) - 1;
		}
		else {
			return i - 1;
		}
	}

	void SnapQueue::WriteSnap(const TreeSnap& tree_snap) {
		m_start = m_start == 0 ? static_cast<int>(m_history.size()) - 1 : m_start - 1;
		m_history[m_start] = tree_snap;
	}

	bool SnapQueue::ReadSnap(TreeSnap* tree_snap) {
		if (m_readIndex == m_start) {
			return false;
		}
		else {
			*tree_snap = m_history[m_readIndex];
			m_readIndex = NextIndex(m_readIndex);
			return true;
		}
	}
}