#ifndef _TIMER_H_
#define _TIMER_H_

// see http://lists.boost.org/boost-users/2004/05/6635.php for a comparision of the precision of the
// various ways to grab system ticks.

#include <ctime>

class Timer
{

  public:
  Timer () { m_start_time = std::clock(); timestep = 0.05f; };
  void restart () { m_start_time = std::clock(); };
  double getStep () const { return timestep; };
  double getTime () const { return double(std::clock() - m_start_time) / CLOCKS_PER_SEC; };

  private:
  std::clock_t m_start_time;
  double timestep; // Aim for 60fps

};

#endif

