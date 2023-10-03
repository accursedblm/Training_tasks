#pragma once

namespace Crypt
{
	struct crInt {
		int part1 : 16;
		int part2 : 16;
	};
	void encryptor(crInt& c);
	void decryptor(crInt& c);
}
