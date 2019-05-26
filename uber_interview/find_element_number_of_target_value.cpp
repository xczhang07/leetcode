int findFirstIndex(vector<int>& nums, int target)
{
	if (nums.size() == 0)
		return -1;
	if (nums[0] > target || nums[nums.size() - 1] < target)
		return -1;
	int start = 0;
	int end = nums.size() - 1;
	while (start <= end)
	{
		int mid = (end - start) / 2 + start;
		if (nums[mid] == target)
		{
			while(mid > 0 && nums[mid] == target)
				--mid;
			mid += 1;
			return mid;
		}
		else if (nums[mid] < target)
		{
			start = mid + 1;
		}
		else
			end = mid - 1;
	}
	return -1;
}

int findLastIndex(vector<int>& nums, int target)
{
	if (nums.size() == 0)
		return -1;
	if (nums[0] > target || nums[nums.size() - 1] < target)
		return -1;
	int start = 0;
	int end = nums.size() - 1;
	while (start <= end)
	{
		int mid = (end - start) / 2 + start;
		if (nums[mid] == target)
		{
			while (mid < nums.size() - 1 && nums[mid] == target)
				mid++;
			mid -= 1;
			return mid;
		}
		else if (nums[mid] < target)
			start = mid + 1;
		else
			end = mid - 1;
	}

	return -1;
}



int main()
{	
	vector<int> nums = {1,2,2,2,2,3,4,5,6,7};
	int target = 2;
	int first = findFirstIndex(nums, target);
	int end = findLastIndex(nums, target);
	cout << "first index is: " << first << endl;
	cout << "last index is: " << end << endl;
	cout << "apperance times is: " << end - first + 1 << endl;
	getchar();
	return 0;
}
