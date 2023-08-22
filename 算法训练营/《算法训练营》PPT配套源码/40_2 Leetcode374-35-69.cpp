
class Solution { //Leetcode374 猜数字 
public:
    int guessNumber(int n) {
        int l=1,r=n,mid;
		while(l<=r) {
			mid=l+(r-l)/2;
			int res=guess(mid);
			if(res==0)
				return mid;
			else if(res==1)
				l=mid+1;
			else r=mid-1;
		}
		return -1;
    }
};

class Solution { //Leetcode35 搜索插入位置 
public:
    int searchInsert(vector<int>& nums, int target) {
		int l=0,r=nums.size()-1,mid;
		while(l<=r) {
			mid=l+(r-l)/2;
			if(nums[mid]==target)
				return mid;
			else if(nums[mid]<target)
				l=mid+1;
			else r=mid-1;
		}
		return l;
	}
};

class Solution { //Leetcode69 求x的平方根，结果只保留整数部分
public:
    int mySqrt(int x) {
        int l=0,r=x,mid;
        while(l<=r) {
            mid=l+(r-l)/2;
            if((long long)mid*mid==x) 
                return mid;
            else if((long long)mid*mid<x) 
                l=mid+1;
            else r=mid-1;
        }
        return r;
    }
};

class Solution { //Leetcode69 求x的平方根，结果只保留整数部分
public:
    int mySqrt(int x) { 
        int l=0,r=x,mid,ans;
        while(l<=r) {
            mid=l+(r-l)/2;
            if((long long)mid*mid<=x) {//满足条件 
                ans=mid; //记录答案 
                l=mid+1; //缩小范围
        	}
            else r=mid-1;
        }
        return ans;
    }
};
