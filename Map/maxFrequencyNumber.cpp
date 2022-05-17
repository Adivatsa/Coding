int maximumFrequency(vector<int> &arr, int n)
{
    unordered_map<int, int> m;
	int maxNum=-1;
	int freq=-1;
	for(int i=0; i<arr.size(); i++)
	{
		m[arr[i]]++;
		if(freq<m[arr[i]])
		{
			freq=m[arr[i]];

		}		
	}
	for(int i=0; i<arr.size(); i++)
		{
			if(m[arr[i]]==freq)
			{
				maxNum=arr[i];
				break;
			}
		}
	return maxNum;
}