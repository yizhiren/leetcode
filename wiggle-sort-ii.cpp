class Solution {
public:
    void wiggleSort( vector<int> & nums )
    {
        int len = nums.size();
        if ( len <= 1 )
        {
            return;
        }
        
        nth_element( nums.begin(), nums.begin() + len / 2, nums.end() );
        int midValue = nums[len / 2];
        
        /* 把左边的midvalue移到奇数位 */
        /*
        {
            int    i    = 0;
            int    j    = len / 2 - 1;
            if ( j % 2 == 0 )
                j--;
            while ( i < len / 2 )
            {
                while ( j > 0 && nums[j] == midValue )
                {
                    j = j - 2;
                }
                if ( j < 0 )
                {
                    break;
                }
                while ( i < len / 2 && (nums[i] != midValue || (i % 2 == 1 && i > j) ) )
                {
                    i++;
                }
                if ( i < len / 2 )
                {
                    swap( nums[i], nums[j] );
                }
            }
        }
        */
        
        /* 把右边的midvalue移到偶数位 */
        /*
        {
            int i = len / 2 + 1;
            if ( i % 2 == 1 )
                i++;
            int j = len - 1;
            while ( j >= len / 2 )
            {
                while ( i < len && nums[i] == midValue )
                {
                    i = i + 2;
                }
                if ( i >= len )
                {
                    break;
                }
                while ( j >= len / 2 && (nums[j] != midValue || (j % 2 == 0 && j < i) ) )
                {
                    j--;
                }
                if ( j >= len / 2 )
                {
                    swap( nums[i], nums[j] );
                }
            }
        }
        */
        /* 把左边的奇数位换到右边的偶数位去 */
        {
            int i = (len-1)/2;
            if ( i % 2 == 0 )
                i--;
            int j = len - 1;
            if ( j % 2 == 1 )
                j--;
            
            while ( i > 0 )
            {
                swap( nums[i], nums[j] );
                i -= 2; j -= 2;
            }
        }
        
        /* 把偶数位的midvalue移到最左边 */
        {
            int    i    = 0;
            int    j    = len - 1;
            if ( j % 2 == 1 )
                j--;
            while ( i < j )
            {
                while ( i < j && nums[i] == midValue )
                {
                    i += 2;
                }
                while ( i < j && nums[j] != midValue )
                {
                    j -= 2;
                }
                if ( i < j )
                {
                    swap( nums[i], nums[j] );
                }
            }
        }
        
        /* 把奇数位的midvalue移到最右边 */
        {
            int    i    = 1;
            int    j    = len - 1;
            if ( j % 2 == 0 )
                j--;
            while ( i < j )
            {
                while ( i < j && nums[j] == midValue )
                {
                    j -= 2;
                }
                while ( i < j && nums[i] != midValue )
                {
                    i += 2;
                }
                if ( i < j )
                {
                    swap( nums[i], nums[j] );
                }
            }
        }
    }
};
