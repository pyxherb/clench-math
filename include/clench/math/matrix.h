#ifndef _CLENCH_MATH_MATRIX_H_
#define _CLENCH_MATH_MATRIX_H_

#include <array>
#include <cassert>

namespace clench {
	namespace math {
		template <typename T, int row, int column>
		struct Mat {
			T data[column * row] = {};

			Mat() = default;
			inline Mat(T x) : data() {
				for (auto &i : data)
					i = x;
			}
			inline Mat(std::array<T, row * column> data) {
				(*this) = data;
			}
			inline Mat(T* data) {
				(*this) = data;
			}

			T* operator[](size_t i) {
				assert(i < row);
				return data + i * column;
			}

			inline Mat<T, row, column>& operator=(std::array<std::array<T, column>, row> rhs) {
				for (size_t i = 0; i < row; ++i)
					memcpy(data + column * i, rhs[i].data(), sizeof(T) * column);

				return *this;
			}

			inline Mat<T, row, column>& operator=(std::array<T, row * column> rhs) {
				memcpy(data, rhs.data(), sizeof(data));

				return *this;
			}

			inline Mat<T, row, column>& operator=(T* rhs) {
				memcpy(data, rhs, sizeof(data));

				return *this;
			}

			inline Mat<T, row, column>& operator=(Mat<T, row, column>& rhs) {
				memcpy(data, rhs.data, sizeof(data));

				return *this;
			}

			template <int c2>
			inline Mat<T, row, c2> operator*(Mat<T, column, c2>& rhs) {
				// r2 = column
				Mat<T, row, c2> result;

				for (size_t c = 0; c < c2; ++c) {
					for (size_t r = 0; r < row; ++r) {
						for (size_t i = 0; i < column; ++i) {
							result[r][c] += (*this)[r][i] * rhs[i][c];
						}
					}
				}

				return result;
			}
		};

#define __CLENCH_MATH_MATRIX_DEFS(c, r)              \
	using Mat##c##x##r##i = Mat<int, c, r>;          \
	using Mat##c##x##r##u = Mat<unsigned int, c, r>; \
	using Mat##c##x##r##f = Mat<float, c, r>;        \
	using Mat##c##x##r##d = Mat<double, c, r>;       \
	using Mat##c##x##r##b = Mat<bool, c, r>;

		__CLENCH_MATH_MATRIX_DEFS(1, 1);
		__CLENCH_MATH_MATRIX_DEFS(1, 2);
		__CLENCH_MATH_MATRIX_DEFS(1, 3);
		__CLENCH_MATH_MATRIX_DEFS(1, 4);
		__CLENCH_MATH_MATRIX_DEFS(2, 1);
		__CLENCH_MATH_MATRIX_DEFS(2, 2);
		__CLENCH_MATH_MATRIX_DEFS(2, 3);
		__CLENCH_MATH_MATRIX_DEFS(2, 4);
		__CLENCH_MATH_MATRIX_DEFS(3, 1);
		__CLENCH_MATH_MATRIX_DEFS(3, 2);
		__CLENCH_MATH_MATRIX_DEFS(3, 3);
		__CLENCH_MATH_MATRIX_DEFS(3, 4);
		__CLENCH_MATH_MATRIX_DEFS(4, 1);
		__CLENCH_MATH_MATRIX_DEFS(4, 2);
		__CLENCH_MATH_MATRIX_DEFS(4, 3);
		__CLENCH_MATH_MATRIX_DEFS(4, 4);

		template <typename T, int row, int column>
		inline Mat<T, column, row> transpose(Mat<T, row, column> matrix) {
			Mat<T, column, row> result;

			for (size_t i = 0; i < row; ++i)
				for (size_t j = 0; j < column; ++j)
					result[j][i] = matrix[i][j];

			return result;
		}
	}
}

#endif
