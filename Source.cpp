#include<iostream>
#include<vector>
using namespace std;

class Solution
{
public:
	//Moore's Voting Algoritm
	//Fuction to find the most repeated element
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
	/*Fuction to verify the most repeated element
		occurs more than n/2 times*/  
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
			return 0;
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
	cout << "The array is: ";
	// The array is
	for (int i = 0; i < n; i++)
		cout << arr[i] << " ";
	int maj_ele = s.majorityElement(arr, n);
	if (maj_ele)
		cout << "\n Majority element = " << maj_ele << endl;
	else
		cout << "\n No majority element " << endl;
	return 0;
}

