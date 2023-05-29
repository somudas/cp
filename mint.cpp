#include <iostream>
namespace MINT {
	class mint {
	private:
		
		long long conv(int x) {
			return (x - (x / M) * M + M) % M;
		}
		long long conv(long long x) {
			return (x - (x / M) * M + M) % M;
		}
		long long binexp(long long base, long long pow) {
			long long res = 1;
			while (pow > 0) {
				if (pow & 1) {
					res = (res % M * base % M) % M;
				}
				base = (base % M * base % M) % M;
				pow >>= 1;
			}
			return res;
		}
		long long inverse(long long x) {
			return binexp(x, M - 2);
		}


	public:
		long long m_x;
		const long long M = 1e9 + 7;

		// contructor initializes m_x
		mint() : m_x(0) {}
		mint(long long x) {
			x = conv(x);
			m_x = x;
		}

		friend std::ostream& operator<<(std::ostream& stream, const mint& x2);
		friend std::ostream& operator>>(std::ostream& stream, const mint& x2);

		// addition operator overloading
		mint operator+(mint const& x) {
			return (m_x % M + x.m_x % M) % M;
		}
		mint operator+(long long const& x) {
			return (m_x % M + conv(x) % M) % M;
		}
		mint& operator+=(long long const& x) {
			m_x = (m_x % M + conv(x) % M) % M;
			return *this;
		}
		mint& operator+=(mint const& x) {
			m_x = (m_x % M + x.m_x % M) % M;
			return *this;
		}
		mint& operator++(int) {
			m_x++;
			if (m_x >= M) m_x -= M;
			return *this;
		}

		// minus operation
		mint operator-(mint const& x) {
			return (m_x % M + conv(-x.m_x) % M) % M;
		}
		mint operator-(long long const& x) {
			return (m_x % M + conv(-x) % M) % M;
		}
		mint& operator-=(long long const& x) {
			m_x = (m_x % M + conv(-x) % M) % M;
			return *this;
		}
		mint& operator-=(mint const& x) {
			m_x = (m_x % M + conv(-x.m_x) % M) % M;
			return *this;
		}
		mint& operator--(int) {
			m_x--;
			if (m_x < 0) m_x = (m_x + M) % M;
			return *this;
		}

		// multiply
		mint operator*(mint const& x) {
			return (m_x % M * x.m_x % M) % M;
		}
		mint operator*(long long const& x) {
			return (m_x % M * conv(x) % M) % M;
		}
		mint& operator*=(long long const& x) {
			m_x = (m_x % M * conv(x) % M) % M;
			return *this;
		}
		mint& operator*=(mint const& x) {
			m_x = (m_x % M * x.m_x % M) % M;
			return *this;
		}

		// division
		mint operator/(mint const& x) {
			return (m_x % M * inverse(x.m_x) % M) % M;
		}
		mint operator/(long long const& x) {
			return (m_x % M * inverse(conv(x)) % M) % M;
		}
		mint& operator/=(long long const& x) {
			m_x = (m_x % M * inverse(conv(x)) % M) % M;
			return *this;
		}
		mint& operator/=(mint const& x) {
			m_x = (m_x % M * inverse(x.m_x) % M) % M;
			return *this;
		}

		//bitwise operators
		mint operator<<(unsigned int& x) {
			return conv(m_x << x);
		}
		mint& operator<<=(unsigned int& x) {
			m_x <<= x;
			m_x = conv(m_x);
			return *this;
		}
		mint operator>>(unsigned int& x) {
			return conv(m_x >> x);
		}
		mint& operator>>=(unsigned int& x) {
			m_x >>= x;
			m_x = conv(m_x);
			return *this;
		}
		mint operator&(unsigned int& x) {
			return conv(m_x & x);
		}
		mint operator&(mint& x) {
			return conv(m_x & x.m_x);
		}
		mint operator|(unsigned int& x) {
			return conv(m_x | x);
		}
		mint operator|(mint& x) {
			return conv(m_x | x.m_x);
		}
		mint& operator!() {
			m_x = conv(!m_x);
			return *this;
		}
		mint operator^(unsigned int& x) {
			return conv(m_x ^ x);
		}
		mint operator^(mint& x) {
			return conv(m_x ^ x.m_x);
		}


		// equals operator
		mint& operator=(mint const& x) {
			m_x = x.m_x;
			return *this;
		}
		mint& operator=(int const& x) {
			m_x = conv(x);
			return *this;
		}

		// relational operators
		bool operator<(mint const& x) {
			return m_x < x.m_x;
		}
		bool operator<(int const& x) {
			return m_x < x;
		}
		bool operator>(mint const& x) {
			return m_x > x.m_x;
		}
		bool operator>=(int const& x) {
			return m_x >= x;
		}
		bool operator>=(mint const& x) {
			return m_x >= x.m_x;
		}
		bool operator<=(mint const& x) {
			return m_x <= x.m_x;
		}
		bool operator<=(int const& x) {
			return m_x <= x;
		}
		bool operator==(mint const& x) {
			return m_x == x.m_x;
		}
		bool operator==(int const& x) {
			return m_x == x;
		}
	};

	std::ostream& operator<<(std::ostream& stream, const mint& x2) {
		stream << x2.m_x;
		return stream;
	}
	std::istream& operator>>(std::istream& stream, const mint& x2) {
		stream >> x2.m_x;
		return stream;
	}
}
