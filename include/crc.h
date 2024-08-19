#ifndef INCLUDE_REFLECTPP_GENERATOR_H
#define INCLUDE_REFLECTPP_GENERATOR_H
#include "stdinclude.h"

namespace refl
{
	namespace _private {

		template <unsigned c, int k = 8>
		struct crc_table_generator : crc_table_generator<((c & 1) ? 0xedb88320 : 0) ^ (c >> 1), k - 1> {};

		template <unsigned c>
		struct crc_table_generator<c, 0> {
			enum { value = c };
		};

#define _REFLECTIONPP_PRIVATE_CRC_TABLE_A(x) _REFLECTIONPP_PRIVATE_CRC_TABLE_B(x) _REFLECTIONPP_PRIVATE_CRC_TABLE_B(x + 128)
#define _REFLECTIONPP_PRIVATE_CRC_TABLE_B(x) _REFLECTIONPP_PRIVATE_CRC_TABLE_C(x) _REFLECTIONPP_PRIVATE_CRC_TABLE_C(x + 64)
#define _REFLECTIONPP_PRIVATE_CRC_TABLE_C(x) _REFLECTIONPP_PRIVATE_CRC_TABLE_D(x) _REFLECTIONPP_PRIVATE_CRC_TABLE_D(x + 32)
#define _REFLECTIONPP_PRIVATE_CRC_TABLE_D(x) _REFLECTIONPP_PRIVATE_CRC_TABLE_E(x) _REFLECTIONPP_PRIVATE_CRC_TABLE_E(x + 16)
#define _REFLECTIONPP_PRIVATE_CRC_TABLE_E(x) _REFLECTIONPP_PRIVATE_CRC_TABLE_F(x) _REFLECTIONPP_PRIVATE_CRC_TABLE_F(x + 8)
#define _REFLECTIONPP_PRIVATE_CRC_TABLE_F(x) _REFLECTIONPP_PRIVATE_CRC_TABLE_G(x) _REFLECTIONPP_PRIVATE_CRC_TABLE_G(x + 4)
#define _REFLECTIONPP_PRIVATE_CRC_TABLE_G(x) _REFLECTIONPP_PRIVATE_CRC_TABLE_H(x) _REFLECTIONPP_PRIVATE_CRC_TABLE_H(x + 2)
#define _REFLECTIONPP_PRIVATE_CRC_TABLE_H(x) _REFLECTIONPP_PRIVATE_CRC_TABLE_I(x) _REFLECTIONPP_PRIVATE_CRC_TABLE_I(x + 1)
#define _REFLECTIONPP_PRIVATE_CRC_TABLE_I(x) crc_table_generator<x>::value,

		constexpr unsigned crc_table[] = { _REFLECTIONPP_PRIVATE_CRC_TABLE_A(0) };

		// consteval implementation and helpers
		consteval uint32_t crc32(const uint8_t* p, size_t len) {
			uint32_t crc = ~0;
			for (size_t i = 0; i < len; i++, p++)
				crc = (crc >> 8) ^ crc_table[(crc & 0xFF) ^ *p];
			return ~crc;
		}

		consteval uint16_t crc16(const uint8_t* p, size_t len) {
			uint8_t x;
			uint16_t crc = 0xFFFF;

			while (len--) {
				x = crc >> 8 ^ *p++;
				x ^= x >> 4;
				crc = (crc << 8) ^ ((uint16_t)(x << 12)) ^ ((uint16_t)(x << 5)) ^ ((uint16_t)x);
			}
			return crc;
		}
	}  // namespace _private

	template<size_t inputSize>
	consteval uint32_t crc16(const char(&input)[inputSize]) {
		constexpr auto len = inputSize - 1;
		uint8_t buffer[len];
		for (size_t i = 0; i < len; i++)
			buffer[i] = static_cast<uint8_t>(input[i]);
		return _private::crc16(buffer, len);
	}

	template<size_t inputSize>
	consteval uint32_t crc32(const char(&input)[inputSize]) {
		constexpr auto len = inputSize - 1;
		uint8_t buffer[len];
		for (size_t i = 0; i < len; i++)
			buffer[i] = static_cast<uint8_t>(input[i]);
		return _private::crc32(buffer, len);
	}
}

#endif //INCLUDE_REFLECTPP_GENERATOR_H