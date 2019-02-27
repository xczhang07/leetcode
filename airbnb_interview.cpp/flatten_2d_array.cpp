class TwoDListIterator
{
public:
	TwoDListIterator(vector<vector<int>>& matrix)
	{
		this->travel = matrix.begin();
		this->end = matrix.end();
		this->col = 0;
	}

	int next()
	{
		if (!hasNext())
			return -1;
		int val = (*travel)[col];
		col++;
		return val;
	}

	bool hasNext()
	{
		while (travel != end && col == travel->size())
		{
			travel++;
			col = 0;
		}

		return travel != end;
	}


	void remove()
	{
		if (this->col == 0)
		{
			auto prev = travel;
			int c = this->col;
			--prev;
			while (prev->size() == 0)
				--prev;
			c = prev->size() - 1;
			prev->erase(prev->begin()+c);
		}
		else
		{
			col -= 1;
			travel->erase(travel->begin()+col);
		}
	}
private:
	vector<vector<int>>::iterator travel, end;
	int col;
};

int main()
{
vector < vector<int>> TwoDArray = {
		{1,2,3},
		{4,5},
		{6},
		{7},
		{8,9},
		{10,11,12,13}
	};

	TwoDListIterator t_iter(TwoDArray);
	for (int i = 0; i < 7; ++i)
		cout << t_iter.next() << " ";
	cout << endl;
	t_iter.remove();
	t_iter.remove();
	for (int i = 0; i < TwoDArray.size(); ++i)
	{
		for (int j = 0; j < TwoDArray[i].size(); ++j)
			cout << TwoDArray[i][j] << " ";
		cout << endl;
	}
	cout << endl;
return 0;
}
