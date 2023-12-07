#include <clench/math/matrix.h>
#include <clench/math/vec.h>

#include <cstdio>

int main() {
	{
		clench::math::Vec4d a({ 1.0, 2.0, 3.0, 4.0 }), b({ 4.0, 3.0, 2.0, 1.0 }), result;

		result = a + b;
		printf("a + b = { %f, %f, %f, %f }\n", result[0], result[1], result[2], result[3]);

		result = a - b;
		printf("a - b = { %f, %f, %f, %f }\n", result[0], result[1], result[2], result[3]);

		result = a * b;
		printf("a * b = { %f, %f, %f, %f }\n", result[0], result[1], result[2], result[3]);

		result = a / b;
		printf("a / b = { %f, %f, %f, %f }\n", result[0], result[1], result[2], result[3]);
	}

	{
		clench::math::Mat2x2d a(
			{ 1.0, 2.0,
				3.0, 4.0 }),
			b({ 5.0, 6.0,
				7.0, 8.0 }),
			result;

		result = a * b;

		printf("a * b = {\n");
		printf("\t%f, %f\n", result[0][0], result[0][1]);
		printf("\t%f, %f\n", result[1][0], result[1][1]);
		puts("}");
	}

	{
		clench::math::Mat2x4d
			a({ 1.0, 2.0, 3.0, 4.0,
				5.0, 6.0, 7.0, 8.0});

		clench::math::Mat4x2d
			b({ 12.0, 11.0,
				9.0, 8.0,
				6.0, 5.0,
				3.0, 2.0,});

		auto result = b * a;

		printf("a * b = {\n");
		for (int i = 0; i < 4; ++i) {
			printf("\t%f, %f, %f, %f\n", result[i][0], result[i][1], result[i][2], result[i][3]);
		}
		puts("}");
	}

	{
		clench::math::Mat3x4d
			a({ 1.0, 2.0, 3.0, 4.0,
				5.0,6.0,7.0,8.0,
				9.0,10.0,11.0,12.0});

		clench::math::Vec4d
			b({
				5.0,
				6.0,
				7.0,
				8.0
			});

		auto result = a * (clench::math::Mat4x1d)b;

		printf("a * b = {\n");
		for (int i = 0; i < 3; ++i) {
			printf("\t%f\n", result[i][0]);
		}
		puts("}");
	}

	return 0;
}
