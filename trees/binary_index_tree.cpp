Binary Indexed Tree Solution:

class NumArray {
public:
	NumArray(vector<int> &nums):v(nums) {
		int len = nums.size();
		bitree.resize(len + 1, 0);

		for (int i = 0; i < len; i++) {
			int idx = i + 1;
			while (idx < len + 1) {
				bitree[idx] += nums[i];
				idx = idx + (idx & -idx);
			}
		}
	}

	void update(int i, int val) {
		int len = bitree.size();
		int idx = i + 1;

		while (idx < len) {
			bitree[idx] += val - v[i];
			idx = idx + (idx & -idx);
		}

		v[i] = val;
	}

	int sumRange(int i, int j) {
		int sumi = 0, sumj = 0;
		int idxi = i, idxj = j + 1;

		while (idxi) {
			sumi += bitree[idxi];
			idxi = idxi - (idxi & -idxi);
		}

		while (idxj) {
			sumj += bitree[idxj];
			idxj = idxj - (idxj & -idxj);
		}

		return sumj - sumi;
	}
private:
	vector<int> bitree;
	vector<int>& v;
};

Segment Tree Solution:

class NumArray {
public:
	NumArray(vector<int> &nums) {
		int size = nums.size();
		segtree.resize(2 * size);
		for (int i = size; i < 2 * size; i++) segtree[i] = nums[i - size];
		for (int i = size - 1; i > 0; i--) segtree[i] = segtree[i * 2] + segtree[i * 2 + 1];
	}

	void update(int i, int val) {
		int pos = i + segtree.size() / 2;
		int diff = val - segtree[pos];
		while (pos) {
			segtree[pos] += diff;
			pos /= 2;
		}
	}

	int sumRange(int i, int j) {
		int n = segtree.size() / 2;
		i += n;
		j += n;
		int sum = 0;
		while (i <= j) {
			if ((i % 2) == 1) sum += segtree[i];
			if ((j % 2) == 0) sum += segtree[j];
			i = (i + 1) / 2;
			j = (j - 1) / 2;
		}
		return sum;
	}
private:
	vector<int> segtree;
};