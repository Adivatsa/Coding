// C++ program to print largest contiguous array sum with start and End index
#include<iostream>
#include<climits>
using namespace std;

int maxSubArraySum(int arr[], int size)
{
	int maxSum = INT_MIN, currSum = 0;
    int s=0,e=0;

	for (int i = 0; i < size; i++)
	{
		currSum = currSum + arr[i];

        if(currSum<arr[i])//update start
        {
            currSum=arr[i];
            s=i;
        }

        if(currSum>maxSum)//update end
        {
            maxSum=currSum;
            e=i;
        }
	}
    cout<<" Start is "<<s<<" and End is "<<e<<endl;
	return maxSum;
}

/*Driver program to test maxSubArraySum*/
int main()
{
	int a[] = {-2, -3, 4, -1, -2, 1, 5, -3};
	int n = sizeof(a)/sizeof(a[0]);
	int max_sum = maxSubArraySum(a, n);
	cout << "Maximum contiguous sum is " << max_sum;
	return 0;
}
