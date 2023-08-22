
class Solution { //Leetcode374 ������ 
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

class Solution { //Leetcode35 ��������λ�� 
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

class Solution { //Leetcode69 ��x��ƽ���������ֻ������������
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

class Solution { //Leetcode69 ��x��ƽ���������ֻ������������
public:
    int mySqrt(int x) { 
        int l=0,r=x,mid,ans;
        while(l<=r) {
            mid=l+(r-l)/2;
            if((long long)mid*mid<=x) {//�������� 
                ans=mid; //��¼�� 
                l=mid+1; //��С��Χ
        	}
            else r=mid-1;
        }
        return ans;
    }
};
