// https://leetcode.com/problems/two-sum/description/


var twoSum = function(nums, target) {
  var map = {};
  debugger
  for(var i = 0 ; i < nums.length ; i++){
      var n = nums[i];
      if(map[target-n] >= 0){
          return [map[target-n],i]
      }
      else {
          map[n] = i;   //use map to store the value and index position
      }
  }
};


twoSum([1, 5, 10, 7, 3], 8)
