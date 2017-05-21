int hammingDistance(int x, int y) {
	int ret = 0;
	int val1 = 0;
	int val2 = 0;
	while(x != 0 || y != 0) {
		val1 = x & 1;
		val2 = y & 1;
		if (val1 != val2)
			++ret;
		x = x >> 1;
		y = y >> 1;
	}
	return ret;
}

