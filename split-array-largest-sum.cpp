/*
  https://leetcode.com/problems/split-array-largest-sum/
  use binary try.  
  Dynamic Programming is fail: timeout.
  we can see log(n)*n is more fast than n*n 
*/
#include <map>
#include <memory>
#include <iostream>
#include <vector>
#include <stdio.h>
using namespace std;

typedef long long ENOUGN_INT;
typedef tuple<ENOUGN_INT,ENOUGN_INT> RANGE;

class Solution {
public:
	RANGE init_parameters(vector<int>& nums){
		ENOUGN_INT sum=0;
		ENOUGN_INT maxnum=0;
		for(const int& num:nums){
			sum += num;
			maxnum = max(maxnum,ENOUGN_INT(num)); 
		}
		
		return make_tuple(maxnum,sum);
	}
	
	int binary_try(vector<int>& nums, ENOUGN_INT _low, ENOUGN_INT _high, int m)
	{
		///printf("Entry(%lld,%lld)\n",_low,_high);
		if(_low == _high)return _low;
		
		ENOUGN_INT _mid = (_low+_high)/2;
		
		ENOUGN_INT _sum=0;
		ENOUGN_INT _index=0;
		int _m=m;
		while(_index < nums.size()){
			if(_sum + nums[_index] <= _mid){
				_sum += nums[_index++];
			}else{
				_m--;
				if(_m==0){
					return binary_try(nums,_mid+1,_high,m);
				}
				_sum=0;
			}
		}
		
		return binary_try(nums,_low,_mid,m);
		
	}
	
    int splitArray(vector<int>& nums, int m) {
		RANGE range = init_parameters(nums);
		return binary_try(nums,get<0>(range),get<1>(range),m);
    }
};
