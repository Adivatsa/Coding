bool canJump(vector<int> &nums)
{

    // bas check kar lo agr require se jyada aaya hai new path pe update maaro warna naa karo

    int n = nums.size();
    int reach = 0; // hum start me bs 0 tk reach kar rhe hai jump se
    for (int i = 0; i < n; i++)
    {
        if (i > reach) // hum aage wale index pe pahuch gye but hum waha tak reach nai kar pa rhe hai
            return false;
        reach = max(reach, i + nums[i]); // update karo agr reach phle se jyada hai ya waha wale index se jump lagaye toh aur jyada durr pahuch jaayenge
    }
    return true; // last pe pahuch gye ho jum karte karte
}