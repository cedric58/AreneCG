#pragma once

template <typename T>
struct sRange
{
	sRange(T min, T max, T gap, string comment)
		
	{
		m_min = min; 
		m_max = max;
		m_gap = gap;
		count = 0;
		m_comment = comment;
	}

	T m_min, m_max, m_gap;
	int count;
	string m_comment;
	bool NextValue(T &res)
	{
		res = m_min + m_gap * count;
		if (res > m_max) return false;
		count++;
		return true;
	}
	
};