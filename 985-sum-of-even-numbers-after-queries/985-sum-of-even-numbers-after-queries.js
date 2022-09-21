/**
 * @param {number[]} nums
 * @param {number[][]} queries
 * @return {number[]}
 */
var sumEvenAfterQueries = function(nums, queries) {
    var ans = [] ;
    var even_sum = 0 ; 
    for (let num of nums) {
        if (num % 2 == 0) {
            even_sum += num ;
        }
    }
    for (let query of queries) {
        if (nums[query[1]] % 2 == 0) {
            even_sum -= nums[query[1]] ;
        }
        nums[query[1]] += query[0] ;
        if (nums[query[1]] % 2 == 0) {
            even_sum += nums[query[1]] ;
        }
        ans.push(even_sum) ;
    }
    return ans ;
};