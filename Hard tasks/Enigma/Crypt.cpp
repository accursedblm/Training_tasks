#include "Crypt.h"

namespace Crypt
{
	void encryptor(crInt& c)
	{
		c.part1 = ~c.part1;
		c.part2 = c.part2 - 1;
	}
	void decryptor(crInt& c)
	{
		c.part1 = ~c.part1;
		c.part2 = c.part2 + 1;
	}
}