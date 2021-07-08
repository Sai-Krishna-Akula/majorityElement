#include<iostream>
#include<vector>
using namespace std;

class Solution
{
public:
	int candidate(vector <int> a, int size)
	{
		int count = 1, maj_index = 0;
		for (int i = 0; i < size; i++)
		{
			if (a[maj_index] == a[i])
				count++;
			else
				count--;
			if (count == 0)
			{
				maj_index = i;
				count = 1;
			}
		}
		return a[maj_index];
	}
	int majorityElement(vector <int> a, int size)
	{
		int count = 0, ele;
		ele = candidate(a, size);
		for (int i = 0; i < size; i++)
			if (a[i] == ele)
				count++;
		if (count > size / 2)
			return ele;
		else
			return -1;
	}
};
int main()
{
	int n;
	cout << "Enter array size = ";
	cin >> n;
	vector <int> arr;
	cout << "Enter " << n << " array elements: "<<endl;
	for (int i = 0; i < n; i++)
	{
		int ele;
		cin >> ele;
		arr.push_back(ele);
	}
	Solution s;
	//for (int i = 0; i < n; i++)
		//cout << arr[i];
	cout << "Majority element = " << s.majorityElement(arr, n);
	return 0;
}