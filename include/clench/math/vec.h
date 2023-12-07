#ifndef _CLENCH_MATH_VEC_H_
#define _CLENCH_MATH_VEC_H_

#include <array>
#include <cassert>
#include <cmath>
#include <cstring>
#include <type_traits>

#include "matrix.h"

namespace clench {
	namespace math {
		template <typename T, int n>
		struct Vec {
			T data[n] = {};

			Vec() = default;
			inline Vec(std::array<T, n> data) {
				memcpy(this->data, data.data(), sizeof(this->data));
			}

			inline T& operator[](std::size_t i) {
				assert(i < n);
				return data[i];
			}

			inline Vec<T, n>& operator+=(T s) {
				data[0] += s;
				if constexpr (n > 1) {
					data[1] += s;
				}
				if constexpr (n > 2) {
					data[2] += s;
				}
				if constexpr (n > 3) {
					data[3] += s;
				}
				return *this;
			}

			inline Vec<T, n>& operator-=(T s) {
				data[0] -= s;
				if constexpr (n > 1) {
					data[1] -= s;
				}
				if constexpr (n > 2) {
					data[2] -= s;
				}
				if constexpr (n > 3) {
					data[3] -= s;
				}
				return *this;
			}

			inline Vec<T, n>& operator*=(T s) {
				data[0] *= s;
				if constexpr (n > 1) {
					data[1] *= s;
				}
				if constexpr (n > 2) {
					data[2] *= s;
				}
				if constexpr (n > 3) {
					data[3] *= s;
				}
				return *this;
			}

			inline Vec<T, n>& operator/=(T s) {
				data[0] /= s;
				if constexpr (n > 1) {
					data[1] /= s;
				}
				if constexpr (n > 2) {
					data[2] /= s;
				}
				if constexpr (n > 3) {
					data[3] /= s;
				}
				return *this;
			}

			inline Vec<T, n> operator+(T s) {
				Vec<T, n> result = *this;
				result += s;
				return result;
			}

			inline Vec<T, n> operator-(T s) {
				Vec<T, n> result = *this;
				result -= s;
				return result;
			}

			inline Vec<T, n> operator*(T s) {
				Vec<T, n> result = *this;
				result *= s;
				return result;
			}

			inline Vec<T, n> operator/(T s) {
				Vec<T, n> result = *this;
				result /= s;
				return result;
			}

			inline Vec<T, n>& operator+=(const Vec<T, n>& rhs) {
				data[0] += rhs.data[0];
				if constexpr (n > 1) {
					data[1] += rhs.data[1];
				}
				if constexpr (n > 2) {
					data[2] += rhs.data[2];
				}
				if constexpr (n > 3) {
					data[3] += rhs.data[3];
				}
				return *this;
			}

			inline Vec<T, n>& operator-=(const Vec<T, n>& rhs) {
				data[0] -= rhs.data[0];
				if constexpr (n > 1) {
					data[1] -= rhs.data[1];
				}
				if constexpr (n > 2) {
					data[2] -= rhs.data[2];
				}
				if constexpr (n > 3) {
					data[3] -= rhs.data[3];
				}
				return *this;
			}

			inline Vec<T, n>& operator*=(const Vec<T, n>& rhs) {
				data[0] *= rhs.data[0];
				if constexpr (n > 1) {
					data[1] *= rhs.data[1];
				}
				if constexpr (n > 2) {
					data[2] *= rhs.data[2];
				}
				if constexpr (n > 3) {
					data[3] *= rhs.data[3];
				}
				return *this;
			}

			inline Vec<T, n>& operator/=(const Vec<T, n>& rhs) {
				data[0] /= rhs.data[0];
				if constexpr (n > 1) {
					data[1] /= rhs.data[1];
				}
				if constexpr (n > 2) {
					data[2] /= rhs.data[2];
				}
				if constexpr (n > 3) {
					data[3] /= rhs.data[3];
				}
				return *this;
			}

			inline Vec<T, n> operator+(const Vec<T, n>& rhs) {
				Vec<T, n> result = *this;
				result += rhs;
				return result;
			}

			inline Vec<T, n> operator-(const Vec<T, n>& rhs) {
				Vec<T, n> result = *this;
				result -= rhs;
				return result;
			}

			inline Vec<T, n> operator*(const Vec<T, n>& rhs) {
				Vec<T, n> result = *this;
				result *= rhs;
				return result;
			}

			inline Vec<T, n> operator/(const Vec<T, n>& rhs) {
				Vec<T, n> result = *this;
				result /= rhs;
				return result;
			}

			inline bool operator==(const Vec<T, n>& rhs) {
				return !memcmp(data, rhs.data, sizeof(data));
			}
			inline bool operator!=(const Vec<T, n>& rhs) {
				return memcmp(data, rhs.data, sizeof(data));
			}

			inline operator bool() {
				return (data[0] || data[1] || data[2] || data[3]);
			}

			inline bool operator<(const Vec<T, n>& rhs) {
				if constexpr (n > 3) {
					if (data[3] < rhs.data[3])
						return true;
				}
				if constexpr (n > 2) {
					if (data[2] < rhs.data[2])
						return true;
				}
				if constexpr (n > 1) {
					if (data[1] < rhs.data[1])
						return true;
				}
				return rhs.data[0] < data[0];
			}

			inline bool operator>(const Vec<T, n>& rhs) {
				if constexpr (n > 3) {
					if (data[3] > rhs.data[3])
						return true;
				}
				if constexpr (n > 2) {
					if (data[2] > rhs.data[2])
						return true;
				}
				if constexpr (n > 1) {
					if (data[1] > rhs.data[1])
						return true;
				}
				return rhs.data[0] > data[0];
			}

			inline operator Mat<T, n, 1>() {
				return Mat<T, n, 1>(data);
			}
		};

#define __CLENCH_MATH_VEC_DEFS(c)           \
	using Vec##c##i = Vec<int, c>;          \
	using Vec##c##u = Vec<unsigned int, c>; \
	using Vec##c##f = Vec<float, c>;        \
	using Vec##c##d = Vec<double, c>;       \
	using Vec##c##b = Vec<bool, c>;

		__CLENCH_MATH_VEC_DEFS(1);
		__CLENCH_MATH_VEC_DEFS(2);
		__CLENCH_MATH_VEC_DEFS(3);
		__CLENCH_MATH_VEC_DEFS(4);
	}
}

#endif
