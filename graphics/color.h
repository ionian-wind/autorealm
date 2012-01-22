#ifndef COLOR_H
#define COLOR_H

#include <stdint.h>

class Color
{
	public:
		Color();
		Color(double r, double g, double b, double a);
		double getRed() { return m_red; }
		void setRed(double val) { m_red = val; }
		double getGreen() { return m_green; }
		void setGreen(double  val) { m_green = val; }
		double getBlue() { return m_blue; }
		void setBlue(double val) { m_blue = val; }
		double getAlpha() { return m_alpha; }
		void setAlpha(double val) { m_alpha = val; }
	protected:
	private:
		double m_red;
		double m_green;
		double m_blue;
		double m_alpha;
};

#endif // COLOR_H
